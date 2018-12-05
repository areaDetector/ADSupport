TOP=../..
include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================


ifeq ($(WITH_BITSHUFFLE),YES)
  ifeq ($(BITSHUFFLE_EXTERNAL),NO)

    LIBRARY_IOC = bitshuffle
    LIBBITSHUFFLE = $(TOP)/supportApp/bitshuffleSrc

    INC += bitshuffle.h
    INC += bshuf_h5filter.h
    LIB_SRCS += bitshuffle.c
    LIB_SRCS += bitshuffle_core.c
    LIB_SRCS += bshuf_h5filter.c
    LIB_SRCS += bshuf_h5plugin.c
    LIB_SRCS += iochain.c

  endif # ($(BITSHUFFLE_EXTERNAL),NO)
endif # ($(WITH_BITSHUFFLE),YES)

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

