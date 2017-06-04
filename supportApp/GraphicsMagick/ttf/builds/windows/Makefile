TOP = ../../../../..
include $(TOP)/configure/CONFIG

ifeq ($(WITH_GRAPHICSMAGICK),YES)
  ifeq ($(GRAPHICSMAGICK_EXTERNAL),NO)
  
    LIB_SRCS_WIN32 += ftdebug.c

  endif # ($(GRAPHICSMAGICK_EXTERNAL),NO)
endif # ($(WITH_GRAPHICSMAGICK),YES)

include $(TOP)/configure/RULES
