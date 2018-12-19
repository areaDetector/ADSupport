TOP=../..
include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================


ifeq ($(WITH_BITSHUFFLE),YES)
  ifeq ($(BITSHUFFLE_EXTERNAL),NO)

    LIBRARY_IOC = bitshuffle
    BITSHUFFLE = $(TOP)/supportApp/bitshuffleSrc
    USR_CFLAGS_Linux += -std=c99
    USR_CFLAGS_WIN32 += -DLZ4_DLL_EXPORT=1
    USR_CFLAGS_WIN32 += -DBITSHUFFLE_DLL_EXPORT=1

    INC += bitshuffle.h
    INC += bitshuffle_core.h
    LIB_SRCS += bitshuffle.c
    LIB_SRCS += bitshuffle_core.c
    LIB_SRCS += iochain.c
    
    SRC_DIRS += $(BITSHUFFLE)/lz4
    INC += lz4.h
    LIB_SRCS += lz4.c

  endif # ($(BITSHUFFLE_EXTERNAL),NO)
endif # ($(WITH_BITSHUFFLE),YES)

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE
