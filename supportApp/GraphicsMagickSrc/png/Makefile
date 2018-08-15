TOP = ../../..
include $(TOP)/configure/CONFIG

ifeq ($(WITH_GRAPHICSMAGICK),YES)
  ifeq ($(GRAPHICSMAGICK_EXTERNAL),NO)

    LIBRARY = png
    
    ifeq (windows-x64, $(findstring windows-x64, $(T_A)))
      USR_CFLAGS_WIN32 += -DWIN64
    endif
    
    ifeq (win32-x86, $(findstring win32-x86, $(T_A)))
      USR_CFLAGS_WIN32 += -DWIN32
    endif
    
    USR_CFLAGS_WIN32 += -D_VISUALC_
    
    USR_CFLAGS += -D_PNGLIB_
    USR_CFLAGS += -DPNG_NO_MODULEDEF
    USR_CFLAGS += -D__FLAT__
    
    USR_CFLAGS_WIN32 += -D__WIN32DLL__
    
    ifeq ($(SHARED_LIBRARIES),YES)
      USR_CFLAGS_WIN32 += -D_DLL
      USR_CFLAGS_WIN32 += -DPNG_BUILD_DLL
    else
      USR_CFLAGS_WIN32 += -D_LIB
    endif
    
    LIB_SRCS +=png.c
    LIB_SRCS += pngerror.c
    LIB_SRCS += pngget.c
    LIB_SRCS += pngmem.c
    LIB_SRCS += pngpread.c
    LIB_SRCS += pngrio.c
    LIB_SRCS += pngrtran.c
    LIB_SRCS += pngrutil.c
    LIB_SRCS += pngset.c
    LIB_SRCS += pngtrans.c
    LIB_SRCS += pngwio.c
    LIB_SRCS += pngwrite.c
    LIB_SRCS += pngwtran.c
    LIB_SRCS += pngwutil.c
    LIB_SRCS += pngread.c
    
    LIB_RCS  += png.rc
    
    LIB_LIBS += bzlib

    ifeq ($(ZLIB_EXTERNAL),NO)
      LIB_LIBS += zlib
    else
      ifdef ZLIB_INCLUDE
        USR_INCLUDES += $(addprefix -I, $(ZLIB_INCLUDE))
      endif
      ifdef ZLIB_LIB
        z_DIR        = $(ZLIB_LIB)
        LIB_LIBS     += z
      else
        LIB_SYS_LIBS += z
      endif
    endif


  endif # ($(GRAPHICSMAGICK_EXTERNAL),NO)
endif # ($(WITH_GRAPHICSMAGICK),YES)

include $(TOP)/configure/RULES
