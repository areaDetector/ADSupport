TOP=../..
include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

INC += lz4hdf5.h

LIBRARY_IOC  += lz4hdf5
lz4hdf5_SRCS += lz4hdf5.c
lz4hdf5_LIBS += bitshuffle
lz4hdf5_SYS_LIBS += ws2_32

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE
