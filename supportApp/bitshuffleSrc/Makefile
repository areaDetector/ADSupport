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

    INC += bitshuffle.h
    INC += bitshuffle_core.h
    INC += bshuf_h5filter.h
    bitshuffle_SRCS += bitshuffle.c
    bitshuffle_SRCS += bitshuffle_core.c
    bitshuffle_SRCS += iochain.c
    
    SRC_DIRS += $(BITSHUFFLE)/lz4
    INC += lz4.h
    bitshuffle_SRCS += lz4.c

    ifeq ($(WITH_HDF5),YES)
        LIBRARY_IOC += bitshuffle_hdf5
        bitshuffle_hdf5_SRCS += bshuf_h5filter.c
        bitshuffle_hdf5_SRCS += bshuf_h5plugin.c
        bitshuffle_hdf5_LIBS += bitshuffle hdf5
    endif # ($(WITH_HDF5),YES)

  endif # ($(BITSHUFFLE_EXTERNAL),NO)
endif # ($(WITH_BITSHUFFLE),YES)

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE
