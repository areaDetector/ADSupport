TOP = ../../..
include $(TOP)/configure/CONFIG

LIBRARY = bzlib

USR_CFLAGS_WIN32 += -D_VISUALC_

ifeq (windows-x64, $(findstring windows-x64, $(T_A)))
  USR_CFLAGS_WIN32 += -DWIN64
endif

ifeq (win32-x86, $(findstring win32-x86, $(T_A)))
  USR_CFLAGS_WIN32 += -DWIN32
endif

ifeq ($(SHARED_LIBRARIES),YES)
  USR_CFLAGS_WIN32 += -D_DLL
else
  USR_CFLAGS_WIN32 += -D_LIB
endif

USR_CFLAGS += -DBZ_EXPORT

INC += bzlib.h

LIB_SRCS += blocksort.c
LIB_SRCS += bzlib.c
LIB_SRCS += compress.c
LIB_SRCS += crctable.c
LIB_SRCS += decompress.c
LIB_SRCS += huffman.c
LIB_SRCS += randtable.c
LIB_RCS  += bzlib.rc


include $(TOP)/configure/RULES
