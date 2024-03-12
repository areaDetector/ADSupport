/* Streaming video compression tools for libavcodec */
/* Author: B.A. Sobhani <sobhaniba@ornl.gov> */

#include <libavcodec/avcodec.h>
#include <libavutil/imgutils.h>
#include <libavutil/opt.h>
#include "streaming_vc.h"
//#include "pgm.h"
#include "codec_tools.h"

AVCodecContext *c_c = 0; 
int first = 1;
AVCodecContext *c_d = 0; 
int count_d = 0;
int mutex_initialized=0;


const AVCodec *codec;

AVCodecContext* init_decoder_context(){
	AVCodecContext *c= NULL;
	const AVCodec *codec;
	avcodec_register_all();
	codec = avcodec_find_decoder(AV_CODEC_ID_H264);
	c = avcodec_alloc_context3(codec);
	avcodec_open2(c, codec, NULL);
	return c;
}

AVCodecContext* init_encoder_context(int width, int height){
	AVCodecContext *c= NULL;
	avcodec_register_all();
	codec = avcodec_find_encoder(AV_CODEC_ID_H264);
	c = avcodec_alloc_context3(codec);
	c->bit_rate = 400000;
	c->width = width;
	c->height = height;
	//c->qmin = 1;
	//c->qmax = 20;
	c->time_base = (AVRational){1, 25};
	c->framerate = (AVRational){25, 1};
	//av_opt_set(c->priv_data, "crf", "1", AV_OPT_SEARCH_CHILDREN);
	//av_opt_set(c->priv_data, "crf", "0", 0);
	//av_opt_set(c->priv_data, "crf", "20", 0);
	c->gop_size = 100;
	//c->max_b_frames = 1;
	c->max_b_frames = 0;
	//c->pix_fmt = AV_PIX_FMT_YUV420P;
	//c->pix_fmt = AV_PIX_FMT_YUV422P10;
	c->pix_fmt = AV_PIX_FMT_YUV422P;
	c->flags |= AV_CODEC_FLAG_QSCALE;

	int ret = avcodec_open2(c, codec, NULL);

	if (ret < 0) {
		fprintf(stderr, "Could not open codec: %s\n", av_err2str(ret));
		exit(1);
	}
	return c;
}



void buffer_to_packet(char* buffer, int size, AVPacket* pkt){
	pkt->size = size;
	pkt->data = (unsigned char*) malloc(sizeof(unsigned char)*size);
	for(int i=0; i<size; ++i){
		pkt->data[i] = buffer[i];
	}
}


AVFrame* packet_to_frame(AVCodecContext *c, AVPacket *pkt){
	
	AVFrame* frame;
	int i = 1;
	frame = av_frame_alloc();
	int ret = avcodec_send_packet(c, pkt);
	
	do{
		ret = avcodec_receive_frame(c, frame);
		++i;
	} while(ret && i<10);
	return frame;
}



int pts_i = 0;
AVFrame* uncompressed_buffer_to_frame(AVCodecContext* c, char* buffer){
	AVFrame* frame = av_frame_alloc();
	av_frame_make_writable(frame);

	frame->format = c->pix_fmt;
	frame->width  = c->width;
	frame->height = c->height;
	frame->pts = pts_i;
	pts_i++;
	unsigned char* frame_buffer = (unsigned char*)malloc(sizeof(unsigned char)*3*frame->width*frame->height);
	int ret = av_image_fill_arrays(frame->data, (int*) frame->linesize, frame_buffer, c->pix_fmt, c->width, c->height, 1);
	//free(frame_buffer);
	if (ret < 0) {
		fprintf(stderr, "Could not allocate the video frame data\n");
		exit(1);
	}
	for(int i=0; i<frame->width*frame->height; ++i){
		frame->data[0][i] = (unsigned char) (buffer[i]);
		frame->data[1][i] = (char)128;
		frame->data[2][i] = (char)128;
	}
	return frame;
}

AVPacket* frame_to_packet(AVCodecContext *c, AVFrame* frame){
	AVPacket *pkt = av_packet_alloc();
	int ret = avcodec_send_frame(c, frame);
	if (ret < 0) {
		fprintf(stderr, "Error sending a frame for encoding\n");
		exit(1);
	}

	while(ret >= 0){
        	ret = avcodec_receive_packet(c, pkt);

		if (ret == AVERROR(EAGAIN) || ret == AVERROR_EOF)
			return 0;
		else if (ret < 0) {
			fprintf(stderr, "Error during encoding\n");
			exit(1);
		}

		return pkt;
		//av_packet_unref(pkt);
	}
	return pkt;
}

void packet_to_buffer(AVPacket* pkt, char* buffer){
	for(int i=0; i<pkt->size; ++i){
		buffer[i] = pkt->data[i];
	}
}

void frame_to_compressed_buffer(AVCodecContext* c, AVFrame* frame, char* buffer){
	AVPacket* pkt = frame_to_packet(c, frame);
	packet_to_buffer(pkt, buffer);
}

void reset_encoder_context(){
	avcodec_close(c_c);
	avcodec_open2(c_c, codec, NULL);
}
void set_gop_size(int gop_size){
	//maybe lock/unlock can go in reset function instead of every setter function?
	pthread_mutex_lock(&mutex);
	c_c->gop_size = gop_size;
	reset_encoder_context();
	pthread_mutex_unlock(&mutex);
}
void set_q_min_max(int q){
	pthread_mutex_lock(&mutex);
	printf("in set_q_min_max function\n");
	//c_c->global_quality = quality;
	//avcodec_close(c_c);
	if(c_c==0){
		printf("ERROR c_c is NULL!! could not set qminmax to %d\n", q);
		pthread_mutex_unlock(&mutex);
		return;
	}
	c_c->qmin = q;
	c_c->qmax = q;
	//avcodec_open2(c_c, codec, NULL);
	reset_encoder_context();
	pthread_mutex_unlock(&mutex);
}
void re_init_encoder_context(){
	printf("inside re_init_encoder_context\n");
	int width, height;
	if(c_c!=0){
		width = c_c->width;
		height = c_c->height;
		avcodec_close(c_c);
	}
	else{
		printf("encoder cannot be reinitialized because it is not initialized\n");
		return;
	}
	printf("initializing with width,height %d,%d\n", width, height); 
	c_c = init_encoder_context(width, height); 
}

	
//for later support of 16- or 32-bit images
//void write_buffer_8(char* buffer, int i, int val){
//	buffer[i] = val;
//}
//void write_buffer_16(char* buffer, int i, int val){
//	char bytes[2];
//	memcpy(bytes, &val, 2);
//	buffer[2*i] = val;
//	buffer[2*i+1] = 0;
//}

int frame_to_buffer(AVFrame* frame, char* buffer, int* width, int* height){
	*width = frame->width;
	*height = frame->height;
	int pix_size = 1;

	int b_i = 0;
	for(int i=0; i<(frame->linesize[0])*(*height); ++i){
		if(i%frame->linesize[0] < frame->width){
			//for later support of 16- or 32-bit images
			//if(pix_size==1){
			//	write_buffer_8(buffer, b_i, frame->data[0][i]);
			//}
			//else if(pix_size==2){
			//	write_buffer_16(buffer, b_i, frame->data[0][2*i]);
			//}
			buffer[b_i] = frame->data[0][i];
			b_i++;
		}
	}
	return (*width)*(*height)*pix_size;
}





