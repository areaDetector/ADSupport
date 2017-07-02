TOP = ../../../..
include $(TOP)/configure/CONFIG

ifeq ($(WITH_GRAPHICSMAGICK),YES)
  ifeq ($(GRAPHICSMAGICK_EXTERNAL),NO)
  
    LIBRARY = wmf
    
    ifeq (windows-x64, $(findstring windows-x64, $(T_A)))
      USR_CFLAGS_WIN32 += -DWIN64
    endif
    
    ifeq (win32-x86, $(findstring win32-x86, $(T_A)))
      USR_CFLAGS_WIN32 += -DWIN32
    endif
    
    USR_CFLAGS_WIN32 += -D_VISUALC_
    USR_CFLAGS       += -DHAVE_CONFIG_H
    USR_CFLAGS       += -D_EXPORT
    
    ifeq ($(SHARED_LIBRARIES),YES)
      USR_CFLAGS_WIN32 += -D_DLL
    else
      USR_CFLAGS_WIN32 += -D_LIB
    endif
    
    USR_INCLUDES += -I$(TOP)/supportApp/GraphicsMagickSrc
    USR_INCLUDES += -I$(TOP)/supportApp/GraphicsMagickSrc/wmf
    USR_INCLUDES += -I$(TOP)/supportApp/GraphicsMagickSrc/wmf/include
    USR_INCLUDES += -I$(TOP)/supportApp/GraphicsMagickSrc/ttf/include
    
    LIB_SRCS += api.c
    LIB_SRCS += bbuf.c
    LIB_SRCS += meta.c
    LIB_SRCS += player.c
    LIB_SRCS += recorder.c

  endif # ($(GRAPHICSMAGICK_EXTERNAL),NO)
endif # ($(WITH_GRAPHICSMAGICK),YES)

include $(TOP)/configure/RULES
