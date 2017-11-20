TOP=../..
include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================


ifeq ($(WITH_BLOSC),YES)
  ifeq ($(BLOSC_EXTERNAL),NO)

    LIBRARY_IOC = blosc
    LIBBLOSC = $(TOP)/supportApp/bloscSrc

    ifeq ($(SHARED_LIBRARIES), YES)
      USR_CFLAGS_WIN32 += -D BLOSC_SHARED_LIBRARY
    endif

    USR_INCLUDES_vxWorks += -I$(TOP)/supportApp/bloscSrc/os/vxWorks

    # ZSTANDARD
    USR_CFLAGS += -DHAVE_ZSTD
    SRC_DIRS += $(LIBBLOSC)/internal-complibs/zstd-1.3.0/
    SRC_DIRS += $(LIBBLOSC)/internal-complibs/zstd-1.3.0/common
    LIB_SRCS += entropy_common.c
    LIB_SRCS += error_private.c
    LIB_SRCS += fse_decompress.c
    LIB_SRCS += pool.c
    LIB_SRCS += threading.c
    LIB_SRCS += xxhash.c
    LIB_SRCS += zstd_common.c
    SRC_DIRS += $(LIBBLOSC)/internal-complibs/zstd-1.3.0/compress
    LIB_SRCS += fse_compress.c
    LIB_SRCS += zstd_compress.c
    LIB_SRCS += huf_compress.c
    LIB_SRCS += zstdmt_compress.c
    SRC_DIRS += $(LIBBLOSC)/internal-complibs/zstd-1.3.0/decompress
    LIB_SRCS += huf_decompress.c
    LIB_SRCS += zstd_decompress.c
    # SNAPPY
    USR_CFLAGS += -DHAVE_SNAPPY
    SRC_DIRS += $(LIBBLOSC)/internal-complibs/snappy-1.1.1
    LIB_SRCS += snappy.cc
    LIB_SRCS += snappy-c.cc
    LIB_SRCS += snappy-sinksource.cc
    LIB_SRCS += snappy-stubs-internal.cc
    # LZ4
    USR_CFLAGS += -DHAVE_LZ4
    SRC_DIRS += $(LIBBLOSC)/internal-complibs/lz4-1.7.5
    LIB_SRCS += lz4.c
    LIB_SRCS += lz4hc.c
    # BLOSC
    SRC_DIRS += $(LIBBLOSC)/blosc
    INC += blosc.h
    INC += blosc-export.h
    LIB_SRCS += blosc.c
    LIB_SRCS += blosclz.c
    LIB_SRCS += shuffle-generic.c
    LIB_SRCS += bitshuffle-generic.c
    LIB_SRCS += shuffle.c
    ifeq ($(BLOSC_SSE2),YES)
      LIB_SRCS += shuffle-sse2.c
      LIB_SRCS += bitshuffle-sse2.c
    endif
    ifeq ($(BLOSC_AVX2),YES)
      LIB_SRCS += shuffle-avx2.c 
      LIB_SRCS += bitshuffle-avx2.c
    endif

    USR_CFLAGS += -DHAVE_ZLIB
    ifeq ($(ZLIB_EXTERNAL),YES)
      ifdef ZLIB_INCLUDE
        USR_INCLUDES += -I$(ZLIB_INCLUDE)
      endif
      ifdef ZLIB_LIB
        z_DIR        = $(ZLIB_LIB)
        LIB_LIBS     += z
      else
        LIB_SYS_LIBS += z
      endif
    else
      LIB_LIBS += zlib
    endif

  endif # ($(BLOSC_EXTERNAL),NO)
endif # ($(WITH_BLOSC),YES)

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

