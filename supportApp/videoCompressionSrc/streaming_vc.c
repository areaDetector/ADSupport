/* Streaming video compression high level functions */
/* Author: B.A. Sobhani <sobhaniba@ornl.gov> */

#include <libavcodec/avcodec.h>
#include <libavutil/imgutils.h>
#include <libavutil/opt.h>
#include "codec_tools.h"
extern int mutex_initialized;
int compress_buffer(CodecContext* c, char* source, int x_size, int y_size, char* dest){
	AVCodecContext* c_c = c->c_c;
	pthread_mutex_t* mutex = &(c->mutex);
	//if(c->mutex_initialized==0){
	if(mutex_initialized==0){
		pthread_mutex_init(mutex, NULL);
		c->mutex_initialized=1;
		mutex_initialized=1;
	}
	pthread_mutex_lock(mutex);
	int pix_size = 1;
	int uncompressed_size = pix_size*x_size*y_size;
	if(c_c==0){
		c_c = init_encoder_context(x_size, y_size); 
	}
	else if(c_c->width!=x_size || c_c->height!=y_size){
		avcodec_close(c_c);
		c_c = init_encoder_context(x_size, y_size); 
	}
		
	AVPacket* pkt;
	AVFrame* frame = uncompressed_buffer_to_frame(c_c, source);
	pkt = frame_to_packet(c_c, frame);
	free(frame->data[0]);
	av_frame_free(&frame);
	if(pkt==0){
		pthread_mutex_unlock(mutex);
		return -1;
	}
	//Fail if compressed size is larger than uncompressed - to prevent memory being written out of range
	if(pkt->size > uncompressed_size){
		pthread_mutex_unlock(mutex);
		return -1;
	}
	packet_to_buffer(pkt, dest);
	int r = pkt->size;
	av_packet_free(&pkt);
	//av_packet_unref(pkt);
	//return pkt->size;
	pthread_mutex_unlock(mutex);
	return r;
}
int decompress_buffer(char* buffer_in, int size_in, char* buffer_out, int* width, int* height){
	if(c_d==0) c_d = init_decoder_context();
	AVPacket* pkt;
	pkt = av_packet_alloc();
	pkt->pts = count_d;
	buffer_to_packet(buffer_in, size_in, pkt);
	AVFrame* frame = packet_to_frame(c_d, pkt);
	int pt = frame->pict_type;
	if(first==1 && pt != AV_PICTURE_TYPE_I){
		av_frame_free(&frame);
		av_packet_free(&pkt);
		return -1;
	}
	first = 0;
	count_d++;
	int decompressed_size = frame_to_buffer(frame, buffer_out, width, height);
	//free(frame->data[0]);
	av_frame_free(&frame);
	av_packet_free(&pkt);
	return decompressed_size;
}

