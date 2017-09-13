TOP = ../../..
include $(TOP)/configure/CONFIG

ifeq ($(WITH_GRAPHICSMAGICK),YES)
  ifeq ($(GRAPHICSMAGICK_EXTERNAL),NO)
    
    LIBRARY = coders
    
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
      USR_CFLAGS += -DLIBXML_STATIC
    endif
    
    USR_CFLAGS += -DHAVE_VSNPRINTF
    
    ifeq ($(GRAPHICSMAGICK_PREFIX_SYMBOLS),YES)
      USR_CFLAGS += -DPREFIX_MAGICK_SYMBOLS
    endif
    
    USR_INCLUDES += -I$(TOP)/supportApp/GraphicsMagickSrc
    USR_INCLUDES += -I$(TOP)/supportApp/GraphicsMagickSrc/jbig/libjbig
    USR_INCLUDES += -I$(TOP)/supportApp/GraphicsMagickSrc/jp2/src/libjasper/include
    USR_INCLUDES += -I$(TOP)/supportApp/GraphicsMagickSrc/bzlib
    USR_INCLUDES += -I$(TOP)/supportApp/GraphicsMagickSrc/png
    USR_INCLUDES += -I$(TOP)/supportApp/GraphicsMagickSrc/webp/src
    USR_INCLUDES += -I$(TOP)/supportApp/GraphicsMagickSrc/ttf/include
    USR_INCLUDES += -I$(TOP)/supportApp/GraphicsMagickSrc/wmf/include
    
    INC += static.h
    
    LIB_SRCS += art.c
    LIB_SRCS += avi.c
    LIB_SRCS += avs.c
    LIB_SRCS += bmp.c
    LIB_SRCS += cals.c
    LIB_SRCS += caption.c
    LIB_SRCS += cineon.c
    LIB_SRCS += clipboard.c
    LIB_SRCS += cmyk.c
    LIB_SRCS += cut.c
    LIB_SRCS += dcm.c
    LIB_SRCS += dcraw.c
    LIB_SRCS += dib.c
    LIB_SRCS += dps.c
    LIB_SRCS += dpx.c
    LIB_SRCS += emf.c
    LIB_SRCS += ept.c
    LIB_SRCS += fax.c
    LIB_SRCS += fits.c
    LIB_SRCS += fpx.c
    LIB_SRCS += gif.c
    LIB_SRCS += gradient.c
    LIB_SRCS += gray.c
    LIB_SRCS += hdf.c
    LIB_SRCS += histogram.c
    LIB_SRCS += hrz.c
    LIB_SRCS += html.c
    LIB_SRCS += icon.c
    LIB_SRCS += identity.c
    LIB_SRCS += info.c
    LIB_SRCS += jbig.c
    LIB_SRCS += jnx.c
    LIB_SRCS += jp2.c
    LIB_SRCS += jpeg.c
    LIB_SRCS += label.c
    LIB_SRCS += locale.c
    LIB_SRCS += logo.c
    LIB_SRCS += mac.c
    LIB_SRCS += map.c
    LIB_SRCS += mat.c
    LIB_SRCS += matte.c
    LIB_SRCS += meta.c
    LIB_SRCS += miff.c
    LIB_SRCS += mono.c
    LIB_SRCS += mpc.c
    LIB_SRCS += mpeg.c
    LIB_SRCS += mpr.c
    LIB_SRCS += msl.c
    LIB_SRCS += mtv.c
    LIB_SRCS += mvg.c
    LIB_SRCS += null.c
    LIB_SRCS += otb.c
    LIB_SRCS += palm.c
    LIB_SRCS += pcd.c
    LIB_SRCS += pcl.c
    LIB_SRCS += pcx.c
    LIB_SRCS += pdb.c
    LIB_SRCS += pdf.c
    LIB_SRCS += pict.c
    LIB_SRCS += pix.c
    LIB_SRCS += plasma.c
    LIB_SRCS += png.c
    LIB_SRCS += pnm.c
    LIB_SRCS += preview.c
    LIB_SRCS += ps.c
    LIB_SRCS += ps2.c
    LIB_SRCS += ps3.c
    LIB_SRCS += psd.c
    LIB_SRCS += pwp.c
    LIB_SRCS += rgb.c
    LIB_SRCS += rla.c
    LIB_SRCS += rle.c
    LIB_SRCS += sct.c
    LIB_SRCS += sfw.c
    LIB_SRCS += sgi.c
    LIB_SRCS += stegano.c
    LIB_SRCS += sun.c
    LIB_SRCS += svg.c
    LIB_SRCS += tga.c
    LIB_SRCS += tiff.c
    LIB_SRCS += tile.c
    LIB_SRCS += tim.c
    LIB_SRCS += topol.c
    LIB_SRCS += ttf.c
    LIB_SRCS += txt.c
    LIB_SRCS += uil.c
    LIB_SRCS += url.c
    LIB_SRCS += uyvy.c
    LIB_SRCS += vicar.c
    LIB_SRCS += vid.c
    LIB_SRCS += viff.c
    LIB_SRCS += wbmp.c
    LIB_SRCS += webp.c
    LIB_SRCS += wmf.c
    LIB_SRCS += wpg.c
    LIB_SRCS += x.c
    LIB_SRCS += xbm.c
    LIB_SRCS += xc.c
    LIB_SRCS += xcf.c
    LIB_SRCS += xpm.c
    LIB_SRCS += xtrn.c
    LIB_SRCS += xwd.c
    LIB_SRCS += yuv.c
    LIB_SRCS += static.c
    
    LIB_LIBS += bzlib jbig jp2 Magick png ttf webp wmf

    ifeq ($(TIFF_EXTERNAL), NO)
      LIB_LIBS += tiff
    else
      ifdef TIFF_INCLUDE
        USR_INCLUDES += -I$(TIFF_INCLUDE)
      endif
      ifdef TIFF_LIB
        jpeg_DIR     = $(TIFF_LIB)
        LIB_LIBS     += tiff
      else
        LIB_SYS_LIBS += tiff
      endif
    endif

    ifeq ($(JPEG_EXTERNAL), NO)
      LIB_LIBS += jpeg
    else
      ifdef JPEG_INCLUDE
        USR_INCLUDES += -I$(JPEG_INCLUDE)
      endif
      ifdef JPEG_LIB
        jpeg_DIR     = $(JPEG_LIB)
        LIB_LIBS     += jpeg
      else
        LIB_SYS_LIBS += jpeg
      endif
    endif

    ifeq ($(XML2_EXTERNAL), NO)
      LIB_LIBS += xml2
    else
      ifdef XML2_INCLUDE
        USR_INCLUDES += -I$(XML2_INCLUDE)
      endif
      ifdef XML2_LIB
        xml2_DIR     = $(XML2_LIB)
        LIB_LIBS     += xml2
      else
        LIB_SYS_LIBS += xml2
      endif
    endif
    
    ifeq ($(ZLIB_EXTERNAL),NO)
      LIB_LIBS += zlib
    else
      ifdef ZLIB_INCLUDE
        USR_INCLUDES += -I$(ZLIB_INCLUDE)
      endif
      ifdef ZLIB_LIB
        z_DIR        = $(ZLIB_LIB)
        LIB_LIBS     += z
      else
        LIB_SYS_LIBS += z
      endif
    endif

    LIB_SYS_LIBS_WIN32 += User32 Gdi32 OleAut32

  endif # ($(GRAPHICSMAGICK_EXTERNAL),NO)
endif # ($(WITH_GRAPHICSMAGICK),YES)

include $(TOP)/configure/RULES
