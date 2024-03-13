#include <stdio.h>
#include <stdlib.h>
//#include "packet_io.h"
#include "streaming_vc.h"


//int H264_compress(CodecContext* c, const char* source, char* dest, int x_size, int y_size)
extern CodecContext* vc_c;
int H264_compress(const char* source, char* dest, int x_size, int y_size)
{
	if(vc_c==0) vc_c = init_encoder_context(x_size, y_size);
	int num_bytes = compress_buffer(vc_c, source, x_size, y_size, dest);
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



