TOP = ../../..
include $(TOP)/configure/CONFIG

LIBRARY = filters

ifeq (windows-x64, $(findstring windows-x64, $(T_A)))
  USR_CFLAGS_WIN32 += -DWIN64
endif

ifeq (win32-x86, $(findstring win32-x86, $(T_A)))
  USR_CFLAGS_WIN32 += -DWIN32
endif

USR_CFLAGS_WIN32 += -D_VISUALC_

USR_CFLAGS += -D_MAGICKLIB_

ifeq ($(SHARED_LIBRARIES),YES)
  USR_CFLAGS_WIN32 += -D_DLL
else
  USR_CFLAGS_WIN32 += -D_LIB
endif

USR_INCLUDES += -I$(TOP)/supportApp/GraphicsMagick
USR_INCLUDES += -I$(TOP)/supportApp/GraphicsMagick/lcms/inc

LIB_SRCS += analyze.c

LIB_LIBS += Magick ttf

include $(TOP)/configure/RULES
