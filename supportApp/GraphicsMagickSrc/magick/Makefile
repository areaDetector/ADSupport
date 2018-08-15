TOP = ../../..
include $(TOP)/configure/CONFIG

ifeq ($(WITH_GRAPHICSMAGICK),YES)
  ifeq ($(GRAPHICSMAGICK_EXTERNAL),NO)

    LIBRARY = Magick
    
    ifeq (windows-x64, $(findstring windows-x64, $(T_A)))
      USR_CFLAGS_WIN32 += -DWIN64
    endif
    
    ifeq (win32-x86, $(findstring win32-x86, $(T_A)))
      USR_CFLAGS_WIN32 += -DWIN32
    endif
    
    USR_CFLAGS_WIN32 += -D_VISUALC_
    
    USR_INCLUDES += -I$(TOP)/supportApp/GraphicsMagickSrc
    USR_INCLUDES += -I$(TOP)/supportApp/GraphicsMagickSrc/lcms/include
    USR_INCLUDES += -I$(TOP)/supportApp/GraphicsMagickSrc/ttf/include
    
    ifeq ($(SHARED_LIBRARIES),YES)
      USR_CFLAGS_WIN32 += -D_DLL
    else
      USR_CFLAGS_WIN32 += -D_LIB
    endif
    
    USR_CFLAGS += -D_MAGICKLIB_
    USR_CFLAGS += -DHAVE_VSNPRINTF
    ifeq ($(GRAPHICSMAGICK_PREFIX_SYMBOLS),YES)
      USR_CFLAGS += -DPREFIX_MAGICK_SYMBOLS
    endif
    
    # Here overriding the default header file install location.
    # This allows Magick++ headers files (at $(INSTALL_LOCATION)/include/Magick++) to
    # include magick header files at relative path e.g. "magick/magick_config.h
    INSTALL_INCLUDE           = $(INSTALL_LOCATION)/include/magick
    INC += magick_config.h
    INC += magick_config_Win32.h
    INC += magick_config_Linux.h
    INC += api.h
    INC += enum_strings.h
    INC += common.h
    INC += magick_types.h
    INC += analyze.h
    INC += image.h
    INC += forward.h
    INC += colorspace.h
    INC += error.h
    INC += log.h
    INC += timer.h
    INC += attribute.h
    INC += average.h
    INC += blob.h
    INC += cdl.h
    INC += channel.h
    INC += color.h
    INC += color_lookup.h
    INC += colormap.h
    INC += command.h
    INC += compare.h
    INC += composite.h
    INC += compress.h
    INC += confirm_access.h
    INC += constitute.h
    INC += decorate.h
    INC += delegate.h
    INC += deprecate.h
    INC += describe.h
    INC += draw.h
    INC += effect.h
    INC += enhance.h
    INC += error.h
    INC += fx.h
    INC += gem.h
    INC += gradient.h
    INC += hclut.h
    INC += image.h
    INC += list.h
    INC += log.h
    INC += magic.h
    INC += magick.h
    INC += memory.h
    INC += module.h
    INC += monitor.h
    INC += montage.h
    INC += operator.h
    INC += paint.h
    INC += pixel_cache.h
    INC += pixel_iterator.h
    INC += plasma.h
    INC += profile.h
    INC += random.h
    INC += quantize.h
    INC += registry.h
    INC += render.h
    INC += resize.h
    INC += resource.h
    INC += shear.h
    INC += signature.h
    INC += statistics.h
    INC += symbols.h
    INC += texture.h
    INC += timer.h
    INC += transform.h
    INC += type.h
    INC += utility.h
    INC += version.h
    
    
    LIB_SRCS_DEFAULT += analyze_Linux.c
    LIB_SRCS_WIN32 += analyze_Win32.c
    
    LIB_SRCS += animate.c
    LIB_SRCS += annotate.c
    LIB_SRCS += attribute.c
    LIB_SRCS += average.c
    LIB_SRCS += bit_stream.c
    LIB_SRCS += blob.c
    LIB_SRCS += cdl.c
    LIB_SRCS += channel.c
    LIB_SRCS += color.c
    LIB_SRCS += colormap.c
    LIB_SRCS += colorspace.c
    LIB_SRCS += color_lookup.c
    LIB_SRCS += command.c
    LIB_SRCS += compare.c
    LIB_SRCS += composite.c
    LIB_SRCS += compress.c
    LIB_SRCS += confirm_access.c
    LIB_SRCS += constitute.c
    LIB_SRCS += decorate.c
    LIB_SRCS += delegate.c
    LIB_SRCS += deprecate.c
    LIB_SRCS += describe.c
    LIB_SRCS += display.c
    LIB_SRCS += draw.c
    LIB_SRCS += effect.c
    LIB_SRCS += enhance.c
    LIB_SRCS += enum_strings.c
    LIB_SRCS += error.c
    LIB_SRCS += export.c
    LIB_SRCS += floats.c
    LIB_SRCS += fx.c
    LIB_SRCS += gem.c
    LIB_SRCS += gradient.c
    LIB_SRCS += hclut.c
    LIB_SRCS += image.c
    LIB_SRCS += import.c
    LIB_SRCS += list.c
    LIB_SRCS += locale.c
    LIB_SRCS += log.c
    LIB_SRCS += magic.c
    LIB_SRCS += magick.c
    LIB_SRCS += magick_endian.c
    LIB_SRCS += map.c
    LIB_SRCS += memory.c
    LIB_SRCS += module.c
    LIB_SRCS += monitor.c
    LIB_SRCS += montage.c
    LIB_SRCS += nt_base.c
    LIB_SRCS += nt_feature.c
    LIB_SRCS += omp_data_view.c
    LIB_SRCS += operator.c
    LIB_SRCS += paint.c
    LIB_SRCS += pixel_cache.c
    LIB_SRCS += pixel_iterator.c
    LIB_SRCS += plasma.c
    LIB_SRCS += PreRvIcccm.c
    LIB_SRCS += profile.c
    LIB_SRCS += quantize.c
    LIB_SRCS += random.c
    LIB_SRCS += registry.c
    LIB_SRCS += render.c
    LIB_SRCS += resize.c
    LIB_SRCS += resource.c
    LIB_SRCS += segment.c
    LIB_SRCS += semaphore.c
    LIB_SRCS += shear.c
    LIB_SRCS += signature.c
    LIB_SRCS += statistics.c
    LIB_SRCS += tempfile.c
    LIB_SRCS += texture.c
    LIB_SRCS += timer.c
    LIB_SRCS += transform.c
    LIB_SRCS += tsd.c
    LIB_SRCS += type.c
    LIB_SRCS += unix_port.c
    LIB_SRCS += utility.c
    LIB_SRCS += version.c
    LIB_SRCS += widget.c
    LIB_SRCS += xwindow.c
    
    LIB_LIBS += bzlib lcms ttf

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
    
    LIB_SYS_LIBS_WIN32 += Advapi32 User32 Gdi32
    LIB_SYS_LIBS_Linux += Xext

  endif # ($(GRAPHICSMAGICK_EXTERNAL),NO)
endif # ($(WITH_GRAPHICSMAGICK),YES)

include $(TOP)/configure/RULES
