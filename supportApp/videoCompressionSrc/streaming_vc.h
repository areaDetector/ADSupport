/* Streaming video compression high level functions */
/* Author: B.A. Sobhani <sobhaniba@ornl.gov> */

#include "codec_tools.h"
//AVFrame* packet_to_frame(AVCodecContext *c, AVPacket *pkt);
int decompress_buffer(char* buffer_in, int size_in, char* buffer_out, int* width, int* height);
//int compress_buffer(char* source, int source_size, char* dest);
int compress_buffer(CodecContext* c, char* source, int x_size, int y_size, char* dest);

void re_init_encoder_context();
