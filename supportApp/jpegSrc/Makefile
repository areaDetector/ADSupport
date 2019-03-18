TOP=../..
include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

ifeq ($(WITH_JPEG),YES)
  ifeq ($(JPEG_EXTERNAL),NO)

  INC += jpeglib.h 
  INC += jconfig.h 
  INC += jmorecfg.h 
  INC += jerror.h 

  LIBRARY = jpeg
  ifeq ($(SHARED_LIBRARIES),YES)
    USR_CFLAGS_WIN32 += -DDLL_JPEG
    jpeg.dll: USR_CFLAGS_WIN32 += -DDLL_EXPORT
  endif

  jpeg_SRCS += jaricom.c 
  jpeg_SRCS += jcapimin.c 
  jpeg_SRCS += jcapistd.c 
  jpeg_SRCS += jcarith.c 
  jpeg_SRCS += jccoefct.c 
  jpeg_SRCS += jccolor.c
  jpeg_SRCS += jcdctmgr.c 
  jpeg_SRCS += jchuff.c 
  jpeg_SRCS += jcinit.c 
  jpeg_SRCS += jcmainct.c 
  jpeg_SRCS += jcmarker.c 
  jpeg_SRCS += jcmaster.c
  jpeg_SRCS += jcomapi.c 
  jpeg_SRCS += jcparam.c 
  jpeg_SRCS += jcprepct.c 
  jpeg_SRCS += jcsample.c 
  jpeg_SRCS += jctrans.c 
  jpeg_SRCS += jdapimin.c
  jpeg_SRCS += jdapistd.c 
  jpeg_SRCS += jdarith.c 
  jpeg_SRCS += jdatadst.c 
  jpeg_SRCS += jdatasrc.c 
  jpeg_SRCS += jdcoefct.c 
  jpeg_SRCS += jdcolor.c
  jpeg_SRCS += jddctmgr.c 
  jpeg_SRCS += jdhuff.c 
  jpeg_SRCS += jdinput.c 
  jpeg_SRCS += jdmainct.c 
  jpeg_SRCS += jdmarker.c 
  jpeg_SRCS += jdmaster.c
  jpeg_SRCS += jdmerge.c 
  jpeg_SRCS += jdpostct.c 
  jpeg_SRCS += jdsample.c 
  jpeg_SRCS += jdtrans.c 
  jpeg_SRCS += jerror.c 
  jpeg_SRCS += jfdctflt.c
  jpeg_SRCS += jfdctfst.c 
  jpeg_SRCS += jfdctint.c
  jpeg_SRCS += jidctflt.c 
  jpeg_SRCS += jidctfst.c 
  jpeg_SRCS += jidctint.c 
  jpeg_SRCS += jquant1.c
  jpeg_SRCS += jquant2.c 
  jpeg_SRCS += jutils.c 
  jpeg_SRCS += jmemmgr.c
  jpeg_SRCS += jmemnobs.c

  endif # ($(JPEG_EXTERNAL),NO)

  LIBRARY  += decompressJPEG
  decompressJPEG_SRCS += decompressJPEG.c
  ifeq ($(JPEG_EXTERNAL),NO)
    decompressJPEG_LIBS += jpeg
  else
    ifdef JPEG_LIB
      jpeg_DIR     = $(JPEG_LIB)
      decompressJPEG_LIBS += jpeg
    else
      decompressJPEG_SYS_LIBS += jpeg
    endif
  endif
  decompressJPEG_SYS_LIBS_WIN32 += ws2_32

endif # ($(WITH_JPEG),YES)

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

