TOP=../..
include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================



ifeq ($(WITH_SZIP),YES)
  ifeq ($(SZIP_EXTERNAL),NO)

    LIBRARY_IOC = szip

    ifeq ($(SHARED_LIBRARIES),YES)
      USR_CFLAGS_WIN32 += -DSZ_BUILT_AS_DYNAMIC_LIB -Dszip_EXPORTS
    endif

    INC += SZconfig.h
    INC += rice.h
    INC += ricehdf.h
    INC += szip_adpt.h
    INC += szlib.h

    LIB_SRCS += encoding.c
    LIB_SRCS += rice.c
    LIB_SRCS += sz_api.c

  endif # ($(SZIP_EXTERNAL),NO)
endif # ($(WITH_SZIP),YES)

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

