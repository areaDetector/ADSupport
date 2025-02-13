#include <stdio.h>
#include <stdlib.h>
//#include "packet_io.h"
#include "streaming_vc.h"


//int H264_compress(CodecContext* c, const char* source, char* dest, int x_size, int y_size)
extern CodecContext* vc_c;

int vc_size(){
	return sizeof(CodecContext);
}

int H264_compress(void** p_vc_c, const char* source, char* dest, int x_size, int y_size)
{
	CodecContext** p_c = (CodecContext**) p_vc_c;
	if(*p_c==0) *p_c = init_encoder_context(x_size, y_size);
	int num_bytes = compress_buffer(*p_c, source, x_size, y_size, dest);
	return num_bytes;
}

void reset_context(){
	printf("inside reset context function\n");
	re_init_encoder_context();
}

int H264_decompress(const char* source, char* dest, int originalSize)
{

        int width, height;
        decompress_buffer(source, originalSize, dest, &width, &height);
	return width*height;

}



