TOP=../..
include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================



ifeq ($(WITH_NETCDF),YES)
  ifeq ($(NETCDF_EXTERNAL),NO)

    LIBRARY_IOC = netCDF
    NETCDF = $(TOP)/supportApp/netCDFSrc
    USR_CFLAGS += -DHAVE_CONFIG_H

    ifeq ($(SHARED_LIBRARIES),YES)
      USR_CFLAGS_WIN32 += -DDLL_NETCDF
      netCDF.dll: USR_CFLAGS_WIN32 += -DDLL_EXPORT
    endif

    SRC_DIRS += $(NETCDF)/inc
    INC += netcdf.h

    SRC_DIRS += $(NETCDF)/libsrc
    LIB_SRCS += v1hpg.c
    LIB_SRCS += putget.c
    LIB_SRCS += attr.c
    LIB_SRCS += nc3dispatch.c
    LIB_SRCS += nc3internal.c
    LIB_SRCS += var.c
    LIB_SRCS += dim.c
    LIB_SRCS += ncx.c
    LIB_SRCS += nc_hashmap.c
    LIB_SRCS += lookup3.c
    LIB_SRCS += ncio.c
    LIB_SRCS += memio.c
    LIB_SRCS += posixio.c

    SRC_DIRS += $(NETCDF)/libdispatch
    LIB_SRCS += dparallel.c
    LIB_SRCS += dcopy.c
    LIB_SRCS += dfile.c
    LIB_SRCS += ddim.c
    LIB_SRCS += datt.c
    LIB_SRCS += dattinq.c
    LIB_SRCS += dattput.c
    LIB_SRCS += dattget.c
    LIB_SRCS += derror.c
    LIB_SRCS += dvar.c
    LIB_SRCS += dvarget.c
    LIB_SRCS += dvarput.c
    LIB_SRCS += dvarinq.c
    LIB_SRCS += dinternal.c
    LIB_SRCS += ddispatch.c
    LIB_SRCS += dutf8.c
    LIB_SRCS += nclog.c
    LIB_SRCS += dstring.c
    LIB_SRCS += ncuri.c
    LIB_SRCS += nclist.c
    LIB_SRCS += ncbytes.c
    LIB_SRCS += nchashmap.c
    LIB_SRCS += nctime.c
    LIB_SRCS += nc.c
    LIB_SRCS += nclistmgr.c
    LIB_SRCS += drc.c
    LIB_SRCS += dauth.c
    LIB_SRCS += doffsets.c
    LIB_SRCS += dwinpath.c
    LIB_SRCS += dutil.c
    LIB_SRCS += utf8proc.c

    SRC_DIRS += $(NETCDF)/liblib
    LIB_SRCS += nc_initialize.c

    PROD_IOC += test_big_classic
    PROD_LIBS += netCDF

  endif # ($(NETCDF_EXTERNAL),NO)
endif # ($(WITH_NETCDF),YES)

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

