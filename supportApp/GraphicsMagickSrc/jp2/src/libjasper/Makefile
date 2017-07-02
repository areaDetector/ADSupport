TOP = ../../../../..
include $(TOP)/configure/CONFIG

ifeq ($(WITH_GRAPHICSMAGICK),YES)
  ifeq ($(GRAPHICSMAGICK_EXTERNAL),NO)

    LIBRARY = jp2
    
    ifeq (windows-x64, $(findstring windows-x64, $(T_A)))
      USR_CFLAGS_WIN32 += -DWIN64
    endif
    
    ifeq (win32-x86, $(findstring win32-x86, $(T_A)))
      USR_CFLAGS_WIN32 += -DWIN32
    endif
    
    USR_CFLAGS_WIN32 += -D_VISUALC_
    USR_CFLAGS_WIN32 += -DJAS_WIN_MSVC_BUILD
    
    USR_CFLAGS += -DEXCLUDE_MIF_SUPPORT
    USR_CFLAGS += -DEXCLUDE_PNM_SUPPORT
    USR_CFLAGS += -DEXCLUDE_BMP_SUPPORT
    USR_CFLAGS += -DEXCLUDE_RAS_SUPPORT
    USR_CFLAGS += -DEXCLUDE_JPG_SUPPORT
    USR_CFLAGS += -DEXCLUDE_PGX_SUPPORT
    
    ifeq ($(SHARED_LIBRARIES),YES)
      USR_CFLAGS_WIN32 += -D_DLL
      USR_CFLAGS += -D_EXPORT
    else
      USR_CFLAGS_WIN32 += -D_LIB
    endif
    
    USR_INCLUDES += -I$(TOP)/supportApp/GraphicsMagickSrc
    
    LIBJASPER = $(TOP)/supportApp/GraphicsMagickSrc/jp2/src/libjasper
    
    USR_INCLUDES += -I$(LIBJASPER)/include
    
    include $(LIBJASPER)/base/Makefile
    include $(LIBJASPER)/jp2/Makefile
    include $(LIBJASPER)/jpc/Makefile

  endif # ($(GRAPHICSMAGICK_EXTERNAL),NO)
endif # ($(WITH_GRAPHICSMAGICK),YES)

include $(TOP)/configure/RULES
