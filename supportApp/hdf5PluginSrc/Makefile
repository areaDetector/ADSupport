TOP=../..
include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

# Unset STATIC_BUILD if it was set because we need to create loadable libraries
STATIC_BUILD = NO

ifeq ($(WITH_HDF5),YES)
  ifeq ($(HDF5_EXTERNAL),NO)

    USR_CFLAGS += -D NDEBUG
    USR_CFLAGS_Linux += -std=c99
    ifeq ($(SHARED_LIBRARIES), YES)
      USR_CFLAGS_WIN32 += -D H5_BUILT_AS_DYNAMIC_LIB 
      USR_CFLAGS_WIN32 += -D hdf5_shared_IMPORTS
    endif
    SRC_DIRS += $(TOP)/supportApp/hdf5Src
    LIB_SYS_LIBS_WIN32 += ws2_32
 
    ifeq ($(WITH_BLOSC),YES)
      LOADABLE_LIBRARY += HDF5_blosc_plugin
      HDF5_blosc_plugin_SRCS += blosc_filter.c
      HDF5_blosc_plugin_SRCS += blosc_plugin.c
      HDF5_blosc_plugin_LIBS += hdf5
      USR_CFLAGS += -DH5_HAVE_FILTER_BLOSC
      ifeq ($(BLOSC_EXTERNAL),YES)
        ifdef BLOSC_INCLUDE
          USR_INCLUDES += $(addprefix -I, $(BLOSC_INCLUDE))
        endif
        ifdef BLOSC_LIB
          blosc_DIR = $(BLOSC_LIB)
          HDF5_blosc_plugin_LIBS += blosc
        else
          HDF5_blosc_plugin_SYS_LIBS += blosc
        endif
      else
        HDF5_blosc_plugin_LIBS += blosc
      endif
    endif

    ifeq ($(WITH_BITSHUFFLE),YES)
      LOADABLE_LIBRARY += HDF5_bshuf_plugin
      HDF5_bshuf_plugin_SRCS += bshuf_h5filter.c
      HDF5_bshuf_plugin_SRCS += bshuf_h5plugin.c
      HDF5_bshuf_plugin_LIBS += hdf5
      USR_CFLAGS += -DH5_HAVE_FILTER_BSHUF
      ifeq ($(BITSHUFFLE_EXTERNAL),YES)
        ifdef BITSHUFFLE_INCLUDE
          USR_INCLUDES += $(addprefix -I, $(BITSHUFFLE_INCLUDE))
        endif
        ifdef BITSHUFFLE_LIB
          bshuf_DIR = $(BITSHUFFLE_LIB)
          HDF5_bshuf_plugin_LIBS += bitshuffle
        else
          HDF5_bshuf_plugin_SYS_LIBS += bitshuffle
        endif
      else
        HDF5_bshuf_plugin_LIBS += bitshuffle
      endif
    endif

    ifeq ($(WITH_BITSHUFFLE),YES)
      # Note: We are getting the lz4 codec from the bitshuffle source
      # So they are combined here.  They could be separated at a later time.
      LOADABLE_LIBRARY += HDF5_lz4_plugin
      HDF5_lz4_plugin_SRCS += H5Zlz4.c
      HDF5_lz4_plugin_SRCS += lz4_h5plugin.c
      HDF5_lz4_plugin_LIBS += hdf5
      USR_CFLAGS += -DH5_HAVE_FILTER_LZ4
      ifeq ($(BITSHUFFLE_EXTERNAL),YES)
        ifdef BITSHUFFLE_INCLUDE
          USR_INCLUDES += $(addprefix -I, $(BITSHUFFLE_INCLUDE))
        endif
        ifdef BITSHUFFLE_LIB
          bshuf_DIR = $(BITSHUFFLE_LIB)
          HDF5_lz4_plugin_LIBS += bitshuffle
        else
          HDF5_lz4_plugin_SYS_LIBS += bitshuffle
        endif
      else
        HDF5_lz4_plugin_LIBS += bitshuffle
      endif
    endif

  endif # ($(HDF5_EXTERNAL),NO)
endif # ($(WITH_HDF5),YES)

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE
