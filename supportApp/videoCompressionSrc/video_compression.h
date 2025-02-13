#ifndef VIDEO_COMPRESSION_H
#define VIDEO_COMPRESSION_H

#if defined (__cplusplus)
extern "C" {
#endif
//#include "codec_tools.h"

//int H264_compress(CodecContext* c, const char* source, char* dest, int x_size, int y_size);
//int H264_compress(const char* source, char* dest, int x_size, int y_size);
int H264_compress(void** p_vc_c, const char* source, char* dest, int x_size, int y_size);


void reset_context();
//void set_gop_size(int gop_size);
void set_gop_size(void* c, int gop_size);
void set_q_min_max(void* c, int q);
int vc_size();

//int LZ4_compressBound(int inputSize);
#if defined (__cplusplus)
}
#endif

#endif
