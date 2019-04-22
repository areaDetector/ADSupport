TOP = ..
include $(TOP)/configure/CONFIG

DIRS += jpegSrc

DIRS += zlibSrc

DIRS += bloscSrc
bloscSrc_DEPEND_DIRS += zlibSrc

DIRS += tiffSrc
tiffSrc_DEPEND_DIRS += zlibSrc jpegSrc

DIRS += xml2Src
xml2Src_DEPEND_DIRS += zlibSrc

DIRS += szipSrc

DIRS += bitshuffleSrc

DIRS += hdf5Src
hdf5Src_DEPEND_DIRS += szipSrc zlibSrc bloscSrc bitshuffleSrc jpegSrc

DIRS += hdf5_hlSrc
hdf5_hlSrc_DEPEND_DIRS += hdf5Src

DIRS += hdf5PluginSrc
hdf5PluginSrc_DEPEND_DIRS += hdf5Src

DIRS += netCDFSrc
# We are building netCDF without HDF5 support, but there are errors in their source files so we need this
netCDFSrc_DEPEND_DIRS += hdf5Src

DIRS += nexusSrc
nexusSrc_DEPEND_DIRS += hdf5Src

DIRS += GraphicsMagickSrc
GraphicsMagickSrc_DEPEND_DIRS += tiffSrc zlibSrc xml2Src jpegSrc

DIRS += cbfSrc

include $(TOP)/configure/RULES_DIRS

