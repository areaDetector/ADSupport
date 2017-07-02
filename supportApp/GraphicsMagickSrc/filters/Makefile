TOP = ../../..
include $(TOP)/configure/CONFIG

ifeq ($(WITH_GRAPHICSMAGICK),YES)
  ifeq ($(GRAPHICSMAGICK_EXTERNAL),NO)

    LIBRARY = filters
    
    ifeq (windows-x64, $(findstring windows-x64, $(T_A)))
      USR_CFLAGS_WIN32 += -DWIN64
    endif
    
    ifeq (win32-x86, $(findstring win32-x86, $(T_A)))
      USR_CFLAGS_WIN32 += -DWIN32
    endif
    
    USR_CFLAGS_WIN32 += -D_VISUALC_
    
    USR_CFLAGS += -D_MAGICKLIB_
    
    ifeq ($(GRAPHICSMAGICK_PREFIX_SYMBOLS),YES)
      USR_CFLAGS += -DPREFIX_MAGICK_SYMBOLS
    endif
    
    ifeq ($(SHARED_LIBRARIES),YES)
      USR_CFLAGS_WIN32 += -D_DLL
    else
      USR_CFLAGS_WIN32 += -D_LIB
    endif
    
    USR_INCLUDES += -I$(TOP)/supportApp/GraphicsMagickSrc
    USR_INCLUDES += -I$(TOP)/supportApp/GraphicsMagickSrc/lcms/inc
    
    LIB_SRCS += analyze.c
    
    LIB_LIBS += Magick ttf

  endif # ($(GRAPHICSMAGICK_EXTERNAL),NO)
endif # ($(WITH_GRAPHICSMAGICK),YES)

include $(TOP)/configure/RULES
