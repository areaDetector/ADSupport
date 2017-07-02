TOP = ../../../..
include $(TOP)/configure/CONFIG

ifeq ($(WITH_GRAPHICSMAGICK),YES)
  ifeq ($(GRAPHICSMAGICK_EXTERNAL),NO)
  
    LIBRARY = webp
    
    ifeq (windows-x64, $(findstring windows-x64, $(T_A)))
      USR_CFLAGS_WIN32 += -DWIN64
    endif
    
    ifeq (win32-x86, $(findstring win32-x86, $(T_A)))
      USR_CFLAGS_WIN32 += -DWIN32
    endif
    
    USR_CFLAGS_WIN32 += -D_VISUALC_
    
    USR_CFLAGS += -D_WEBPLIB_
    
    ifeq ($(SHARED_LIBRARIES),YES)
      USR_CFLAGS_WIN32 += -D_DLL
    else
      USR_CFLAGS_WIN32 += -D_LIB
    endif
    
    USR_INCLUDES += -I$(TOP)/supportApp/GraphicsMagickSrc
    
    WEBP = $(TOP)/supportApp/GraphicsMagickSrc/webp
    WEBPSRC = $(WEBP)/src
    
    include $(WEBPSRC)/dec/Makefile
    include $(WEBPSRC)/demux/Makefile
    include $(WEBPSRC)/dsp/Makefile
    include $(WEBPSRC)/enc/Makefile
    include $(WEBPSRC)/mux/Makefile
    include $(WEBPSRC)/utils/Makefile

  endif # ($(GRAPHICSMAGICK_EXTERNAL),NO)
endif # ($(WITH_GRAPHICSMAGICK),YES)

include $(TOP)/configure/RULES
