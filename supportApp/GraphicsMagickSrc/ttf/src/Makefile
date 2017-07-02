TOP = ../../../..
include $(TOP)/configure/CONFIG

ifeq ($(WITH_GRAPHICSMAGICK),YES)
  ifeq ($(GRAPHICSMAGICK_EXTERNAL),NO)
  
    LIBRARY = ttf
    
    ifeq (windows-x64, $(findstring windows-x64, $(T_A)))
      USR_CFLAGS_WIN32 += -DWIN64
    endif
    
    ifeq (win32-x86, $(findstring win32-x86, $(T_A)))
      USR_CFLAGS_WIN32 += -DWIN32
    endif
    
    USR_CFLAGS_WIN32 += -D_VISUALC_
    
    USR_CFLAGS += -D_TTFLIB_
    USR_CFLAGS += -DFT2_BUILD_LIBRARY
    USR_CFLAGS += -DFT_USE_T1CID
    USR_CFLAGS += -DHAVE_FT2BUILD_H
    
    
    ifeq ($(SHARED_LIBRARIES),YES)
      USR_FLAGS += -D_DLL
    else
      USR_CFLAGS += -D_LIB
    endif
    
    TTF = $(TOP)/supportApp/GraphicsMagickSrc/ttf
    
    USR_INCLUDES += -I$(TTF)/include
    
    SRC = $(TTF)/src
    
    include $(SRC)/autofit/Makefile
    include $(SRC)/base/Makefile
    include $(SRC)/cache/Makefile
    include $(SRC)/gzip/Makefile
    include $(SRC)/lzw/Makefile
    include $(SRC)/pcf/Makefile
    include $(SRC)/pfr/Makefile
    include $(SRC)/psaux/Makefile
    include $(SRC)/pshinter/Makefile
    include $(SRC)/psnames/Makefile
    include $(SRC)/raster/Makefile
    include $(SRC)/sfnt/Makefile
    include $(SRC)/smooth/Makefile
    include $(SRC)/truetype/Makefile
    include $(SRC)/type1/Makefile
    include $(SRC)/cid/Makefile
    include $(SRC)/type42/Makefile
    include $(SRC)/winfonts/Makefile
    include $(SRC)/bdf/Makefile
    include $(SRC)/cff/Makefile
    
    # LIB_RCS = ttf.rc
    # D:\downloads\GraphicsMagickSrc\GraphicsMagickSrc-1.3.25\VisualMagick\ttf\ttf.rc

  endif # ($(GRAPHICSMAGICK_EXTERNAL),NO)
endif # ($(WITH_GRAPHICSMAGICK),YES)

include $(TOP)/configure/RULES
