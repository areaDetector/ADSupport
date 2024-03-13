/* Streaming video compression tools for libavcodec */
/* Author: B.A. Sobhani <sobhaniba@ornl.gov> */

#ifndef CODEC_TOOLS
#define CODEC_TOOLS
#include <pthread.h>
#include <libavcodec/avcodec.h>
#include <libavutil/imgutils.h>
#include <libavutil/opt.h>

typedef struct{
	AVCodecContext *c_c;
	pthread_mutex_t mutex;
	int mutex_initialized;
} CodecContext;

extern CodecContext* vc_c;


CodecContext* init_decoder_context();
CodecContext* init_encoder_context(int width, int height);
void buffer_to_packet(char* buffer, int size, AVPacket* pkt);
AVFrame* packet_to_frame(AVCodecContext *c, AVPacket *pkt);
AVFrame* uncompressed_buffer_to_frame(AVCodecContext* c, char* buffer);
AVPacket* frame_to_packet(AVCodecContext *c, AVFrame* frame);
void packet_to_buffer(AVPacket* pkt, char* buffer);
void frame_to_compressed_buffer(AVCodecContext* c, AVFrame* frame, char* buffer);
void re_init_encoder_context();
void write_buffer_8(char* buffer, int i, int val);
void write_buffer_16(char* buffer, int i, int val);
int frame_to_buffer(AVFrame* frame, char* buffer, int* width, int* height);
void set_gop_size(CodecContext* c, int gop_size);
//void set_q_min_max(CodecContext* c, int q);
void set_q_min_max(int q);
//pthread_mutex_t mutex;
int mutex_initialized;


//extern AVCodecContext *c_c; 
extern int first;
extern AVCodecContext *c_d; 
extern int count_d;

#endif
