TOP = ../../../..
include $(TOP)/configure/CONFIG

ifeq ($(WITH_GRAPHICSMAGICK),YES)
  ifeq ($(GRAPHICSMAGICK_EXTERNAL),NO)

    LIBRARY = Magick++
    
    ifeq (windows-x64, $(findstring windows-x64, $(T_A)))
      USR_CXXFLAGS_WIN32 += -DWIN64
    endif
    
    ifeq (win32-x86, $(findstring win32-x86, $(T_A)))
      USR_CXXFLAGS_WIN32 += -DWIN32
    endif
    
    USR_CXXFLAGS_WIN32 += -D_VISUALC_
    
    ifeq ($(SHARED_LIBRARIES),YES)
      USR_CXXFLAGS_WIN32 += -D_DLL
      USR_CXXFLAGS_WIN32 += -D_MAGICKDLL_
    else
      USR_CXXFLAGS_WIN32 += -D_LIB
    endif
    
    ifeq ($(GRAPHICSMAGICK_PREFIX_SYMBOLS),YES)
      USR_CXXFLAGS += -DPREFIX_MAGICK_SYMBOLS
    endif
    
    USR_INCLUDES += -I$(TOP)/supportApp/GraphicsMagickSrc
    USR_INCLUDES += -I$(TOP)/supportApp/GraphicsMagickSrc/lcms/include
    USR_INCLUDES += -I$(TOP)/supportApp/GraphicsMagickSrc/Magick++/lib
    
    INC += Magick++.h
    INC += Magick++/Include.h
    INC += Magick++/Image.h
    INC += Magick++/Pixels.h
    INC += Magick++/STL.h
    INC += Magick++/Blob.h
    INC += Magick++/Color.h
    INC += Magick++/Drawable.h
    INC += Magick++/BlobRef.h
    INC += Magick++/CoderInfo.h
    INC += Magick++/Exception.h
    INC += Magick++/Geometry.h
    INC += Magick++/ImageRef.h
    INC += Magick++/Functions.h
    INC += Magick++/Montage.h
    INC += Magick++/Options.h
    INC += Magick++/Thread.h
    INC += Magick++/TypeMetric.h
    
    LIB_SRCS += Blob.cpp
    LIB_SRCS += BlobRef.cpp
    LIB_SRCS += CoderInfo.cpp
    LIB_SRCS += Color.cpp
    LIB_SRCS += Drawable.cpp
    LIB_SRCS += Exception.cpp
    LIB_SRCS += Functions.cpp
    LIB_SRCS += Geometry.cpp
    LIB_SRCS += Image.cpp
    LIB_SRCS += ImageRef.cpp
    LIB_SRCS += Montage.cpp
    LIB_SRCS += Options.cpp
    LIB_SRCS += Pixels.cpp
    LIB_SRCS += STL.cpp
    LIB_SRCS += Thread.cpp
    LIB_SRCS += TypeMetric.cpp
    
    LIB_LIBS += Magick
    LIB_LIBS += coders
    
    LIB_SYS_LIBS_Linux += Xext

  endif # ($(GRAPHICSMAGICK_EXTERNAL),NO)
endif # ($(WITH_GRAPHICSMAGICK),YES)

include $(TOP)/configure/RULES
