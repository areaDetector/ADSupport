TOP = ..
include $(TOP)/configure/CONFIG

DIRS += netCDFSrc

DIRS += jpegSrc

DIRS += zlibSrc

DIRS += bloscSrc
bloscSrc_DEPEND_DIRS += zlibSrc

DIRS += bitshuffleSrc
bitshuffleSrc_DEPEND_DIRS += bloscSrc

DIRS += tiffSrc
tiffSrc_DEPEND_DIRS += zlibSrc

DIRS += xml2Src
xml2Src_DEPEND_DIRS += zlibSrc

DIRS += szipSrc

DIRS += hdf5Src
hdf5Src_DEPEND_DIRS += szipSrc zlibSrc bloscSrc

DIRS += hdf5_hlSrc
hdf5_hlSrc_DEPEND_DIRS += hdf5Src

DIRS += nexusSrc
nexusSrc_DEPEND_DIRS += hdf5Src

DIRS += GraphicsMagickSrc
GraphicsMagickSrc_DEPEND_DIRS += tiffSrc zlibSrc xml2Src jpegSrc

DIRS += cbfSrc

include $(TOP)/configure/RULES_DIRS

