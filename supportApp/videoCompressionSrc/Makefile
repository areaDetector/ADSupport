TOP=../..
include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================


ifeq ($(WITH_VC),YES)
  ifeq ($(VC_EXTERNAL),NO)

    LIBRARY_IOC = videoCompression
    VC = $(TOP)/supportApp/videoCompressionSrc
    USR_CFLAGS_Linux += -std=c99
    USR_SYS_LIBS += avcodec
    #USR_CFLAGS_WIN32 += -DLZ4_DLL_EXPORT=1
    #USR_CFLAGS_WIN32 += -DBITSHUFFLE_DLL_EXPORT=1

    INC += video_compression.h
    LIB_SRCS += video_compression.c
    
    #SRC_DIRS += $(VC)/video_compression_tools
    #SRC_DIRS += $(VC)/video_compression_tools/src
    USR_INCLUDES += -I/usr/include/ffmpeg
    #INC += packet_io.h
    INC += streaming_vc.h
    #INC += pgm.h
    INC += codec_tools.h
    #LIB_SRCS += packet_io.c
    LIB_SRCS += streaming_vc.c
    #LIB_SRCS += pgm.c
    LIB_SRCS += codec_tools.c

  endif # ($(VC_EXTERNAL),NO)
endif # ($(WITH_VC),YES)

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE
