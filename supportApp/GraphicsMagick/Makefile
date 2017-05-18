TOP = ../..
include $(TOP)/configure/CONFIG

#---------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=======================================

ifeq ($(WITH_GRAPHICSMAGICK),YES)
  ifeq ($(GRAPHICSMAGICK_EXTERNAL),NO)

    DIRS += filters
    filters_DEPEND_DIRS += magick ttf
    DIRS += wmf
    DIRS += webp
    DIRS += png
    png_DEPEND_DIRS += bzlib
    DIRS += jp2
    DIRS += jbig
    DIRS += coders
    coders_DEPEND_DIRS += bzlib jbig jp2 magick png ttf webp wmf
    DIRS += lcms
    DIRS += bzlib
    DIRS += ttf
    DIRS += magick
    magick_DEPEND_DIRS += bzlib lcms ttf
    DIRS += Magick++
    Magick++_DEPEND_DIRS += magick coders

  endif # ($(GRAPHICSMAGICK_EXTERNAL),NO)
endif # ($(WITH_GRAPHICSMAGICK),YES)

include $(TOP)/configure/RULES_DIRS

#----------------------------------------
#  ADD RULES AFTER THIS LINE
