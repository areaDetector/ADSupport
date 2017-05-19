TOP = ../../../..
include $(TOP)/configure/CONFIG

LIBRARY = lcms

ifeq (windows-x64, $(findstring windows-x64, $(T_A)))
  USR_CFLAGS_WIN32 += -DWIN64
endif

ifeq (win32-x86, $(findstring win32-x86, $(T_A)))
  USR_CFLAGS_WIN32 += -DWIN32
endif

USR_CFLAGS_WIN32 += -D_VISUALC_

USR_CFLAGS += -D_LCMSLIB_

ifeq ($(SHARED_LIBRARIES),YES)
  USR_CFLAGS_WIN32 += -D_DLL
else
  USR_CFLAGS_WIN32 += -D_LIB
endif

USR_INCLUDES += -I$(TOP)/supportApp/GraphicsMagick/lcms/include

LIB_SRCS += cmsalpha.c
LIB_SRCS += cmscam02.c
LIB_SRCS += cmscgats.c
LIB_SRCS += cmscnvrt.c
LIB_SRCS += cmserr.c
LIB_SRCS += cmsgamma.c
LIB_SRCS += cmsgmt.c
LIB_SRCS += cmshalf.c
LIB_SRCS += cmsintrp.c
LIB_SRCS += cmsio0.c
LIB_SRCS += cmsio1.c
LIB_SRCS += cmslut.c
LIB_SRCS += cmsmd5.c
LIB_SRCS += cmsmtrx.c
LIB_SRCS += cmsnamed.c
LIB_SRCS += cmsopt.c
LIB_SRCS += cmspack.c
LIB_SRCS += cmspcs.c
LIB_SRCS += cmsplugin.c
LIB_SRCS += cmsps2.c
LIB_SRCS += cmssamp.c
LIB_SRCS += cmssm.c
LIB_SRCS += cmstypes.c
LIB_SRCS += cmsvirt.c
LIB_SRCS += cmswtpnt.c
LIB_SRCS += cmsxform.c

include $(TOP)/configure/RULES
