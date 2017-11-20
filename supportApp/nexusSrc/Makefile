TOP=../..
include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================


ifeq ($(WITH_NEXUS),YES)
  ifeq ($(NEXUS_EXTERNAL),NO)

    LIBRARY_IOC += NeXus  

    INC += napi.h
    INC += napiconfig.h
    INC += nxconfig.h

    NeXus_SRCS += napi.c
    NeXus_SRCS += napi5.c
    NeXus_SRCS += napiu.c
    NeXus_SRCS += nxdataset.c
    NeXus_SRCS += nxio.c
    NeXus_SRCS += nxstack.c
    NeXus_SRCS += nxxml.c
    NeXus_SRCS += stptok.c

    USR_CFLAGS += -DHDF5 -D_FILE_OFFSET_BITS=64

    # Travis/ubuntu 12.04 tweak: persuade the hdf5 library build to use API v18 over v16
    USR_CFLAGS += -DH5_NO_DEPRECATED_SYMBOLS -DH5Gopen_vers=2

    ifeq ($(SHARED_LIBRARIES),YES)
      USR_CFLAGS_WIN32 += -DDLL_NEXUS
      USR_CFLAGS_WIN32 += -DH5_BUILT_AS_DYNAMIC_LIB
      NeXus.dll: USR_CFLAGS_WIN32 += -DDLL_EXPORT
    endif

    ifeq ($(HDF5_STATIC_BUILD), NO)
      USR_CXXFLAGS_WIN32    += -DH5_BUILT_AS_DYNAMIC_LIB
      USR_CFLAGS_WIN32      += -DH5_BUILT_AS_DYNAMIC_LIB
    else
      USR_CXXFLAGS_WIN32    += -DH5_BUILT_AS_STATIC_LIB
      USR_CFLAGS_WIN32      += -DH5_BUILT_AS_STATIC_LIB
    endif

    ifeq ($(HDF5_EXTERNAL),YES)
      ifdef HDF5_INCLUDE
        USR_INCLUDES += -I$(HDF5_INCLUDE)
      endif
      ifdef HDF5_LIB
        hdf5_DIR             = $(HDF5_LIB)
        LIB_LIBS_default     += hdf5
      else
        LIB_SYS_LIBS_default  += hdf5
        LIB_SYS_LIBS_cygwin32 += libhdf5
      endif
    else
      LIB_LIBS += hdf5
    endif

    ifeq ($(SZIP_EXTERNAL),YES)
      ifdef SZIP_INCLUDE
        USR_INCLUDES += -I$(SZIP_INCLUDE)
      endif
      ifdef SZIP_LIB
        sz_DIR             = $(SZIP_LIB)
        LIB_LIBS_default   += sz
      else
        LIB_SYS_LIBS_default  += sz
      endif
    else
      LIB_LIBS += szip
    endif

    ifeq ($(ZLIB_EXTERNAL),YES)
      ifdef ZLIB_INCLUDE
        USR_INCLUDES += -I$(ZLIB_INCLUDE)
      endif
      ifdef ZLIB_LIB
        z_DIR             = $(ZLIB_LIB)
        LIB_LIBS_default  += z
      else
        LIB_SYS_LIBS_default  += z
        LIB_SYS_LIBS_cygwin32 += libz
      endif
    else
      LIB_LIBS += zlib
    endif


  endif # ($(NEXUS_EXTERNAL),NO)
endif # ($(WITH_NEXUS),YES)

#=============================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

