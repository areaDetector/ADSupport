TOP=../..
include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================


ifeq ($(WITH_HDF5),YES)
  ifeq ($(HDF5_EXTERNAL),NO)

    LIBRARY_IOC = hdf5_hl

    USR_INCLUDES += -I../../hdf5Src

    USR_CFLAGS += -D NDEBUG
    ifeq ($(SHARED_LIBRARIES), YES)
      USR_CFLAGS_WIN32 += -D H5_BUILT_AS_DYNAMIC_LIB 
      USR_CFLAGS_WIN32 += -D hdf5_hl_shared_EXPORTS
      ifeq (mingw, $(findstring mingw, $(T_A)))
        USR_CFLAGS_WIN32 += -D__MSVCRT_VERSION__=0x800
      else
        # The thread code on mingw needs work, get compiler errors
        USR_CFLAGS_WIN32 += -D H5_HAVE_THREADSAFE
      endif
    endif

    INC += H5DOpublic.h
    INC += H5DSpublic.h
    INC += H5IMpublic.h
    INC += H5LDpublic.h
    INC += H5LTpublic.h
    INC += H5PTpublic.h
    INC += H5TBpublic.h
    INC += hdf5_hl.h

    LIB_SRCS += H5DO.c
    LIB_SRCS += H5DS.c
    LIB_SRCS += H5IM.c
    LIB_SRCS += H5LD.c
    LIB_SRCS += H5LT.c
    LIB_SRCS += H5LTanalyze.c
    LIB_SRCS += H5LTparse.c
    LIB_SRCS += H5PT.c
    LIB_SRCS += H5TB.c

    LIB_LIBS += hdf5

    ifeq ($(SZIP_EXTERNAL),YES)
      ifdef SZIP_INCLUDE
        USR_INCLUDES += $(addprefix -I, $(SZIP_INCLUDE))
      endif
      ifdef SZIP_LIB
        sz_DIR       = $(SZIP_LIB)
        LIB_LIBS     += sz
      else
        LIB_SYS_LIBS += sz
      endif
    else
      LIB_LIBS += szip
    endif

    ifeq ($(ZLIB_EXTERNAL),YES)
      ifdef ZLIB_INCLUDE
        USR_INCLUDES += $(addprefix -I, $(ZLIB_INCLUDE))
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

    LIB_SYS_LIBS_WIN32 += ws2_32

  endif # ($(HDF5_EXTERNAL),NO)
endif # ($(WITH_HDF5),YES)

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

