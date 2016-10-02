TOP = ..
include $(TOP)/configure/CONFIG

DIRS += netCDFSrc

DIRS += jpegSrc

DIRS += tiffSrc

DIRS += xml2Src

DIRS += szipSrc

DIRS += zlibSrc

DIRS += hdf5Src
hsf5Src_DEPEND_DIRS += szipSrc zlibSrc

DIRS += nexusSrc
nexusSrc_DEPEND_DIRS += hdf5Src

include $(TOP)/configure/RULES_DIRS

