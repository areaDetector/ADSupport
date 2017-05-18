TOP = ../../../..
include $(TOP)/configure/CONFIG

LIBRARY = jbig

ifeq (windows-x64, $(findstring windows-x64, $(T_A)))
  USR_CFLAGS_WIN32 += -DWIN64
endif

ifeq (win32-x86, $(findstring win32-x86, $(T_A)))
  USR_CFLAGS_WIN32 += -DWIN32
endif

USR_CFLAGS_WIN32 += -D_VISUALC_

ifeq ($(SHARED_LIBRARIES),YES)
  USR_CFLAGS_WIN32 += -D_DLL
else
  USR_CFLAGS_WIN32 += -D_LIB
endif

USR_INCLUDES += -I$(TOP)/supportApp/GraphicsMagick

#INC += jbig.h
LIB_SRCS += jbig.c
LIB_SRCS += jbig_tab.c
LIB_RCS +=  jbig.rc
include $(TOP)/configure/RULES
