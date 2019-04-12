ADSupport
======
The home of the support libraries for the 
[EPICS](http://www.aps.anl.gov/epics/) 
[areaDetector](https://cars.uchicago.edu/software/epics/areaDetector.html) 
software.  It contains third party libraries required for some plugins and
drivers.  These are provided in source-code form compatible with the EPICS
build system.  This makes it convenient to use these libraries on systems
like Windows and vxWorks for which there are not binary packages available
as there are on Linux and Darwin.  For Linux and Darwin the code here can be 
useful when the system not have one of the packages installed, or
has a different version from the one required by areaDetector.

This module contains the following libraries:

- [Bitshuffle and lz4] (https://github.com/kiyo-masui/bitshuffle/)
- [Blosc] (https://github.com/Blosc/c-blosc)
- [CBF] (https://sourceforge.net/projects/cbflib/)
- [GraphicsMagick] (http://www.graphicsmagick.org/)
- [HDF5]   (https://support.hdfgroup.org/HDF5/)
- [JPEG]   (http://www.ijg.org/)
- [netCDF] (http://www.unidata.ucar.edu/software/netcdf/)  
- [NeXus]  (http://www.nexusformat.org/)
- [SZIP]   (https://support.hdfgroup.org/doc_resource/SZIP/)
- [TIFF]   (http://simplesystems.org/libtiff/)
- [XML2]   (http://www.xmlsoft.org/index.html)
- [ZLIB]   (http://www.zlib.net/)

These libraries have had minor changes made so they will build with the EPICS
build system on all of the supported platforms.  These changes are documented
in a README.epics file in each library source directory.

The build system will build each library XXX only if the following make variables
are set.

    WITH_XXX=YES
    XXX_EXTERNAL=NO

    For example:
    WITH_HDF5=YES
    HDF5_EXTERNAL=NO

This allows areaDetector to not use a library at all (WITH_XXX=NO) or to 
use an external version of the library if desired (XXX_EXTERNAL=YES)
rather than the version in ADSupport.

These can be defined for each library and for each build target in the files 
CONFIG_SITE.local.* files in in the configure/ directory of the appropriate release of the 
[top-level areaDetector](https://github.com/areaDetector/areaDetector) repository
or in ADSupport/configure/CONFIG_SITE.*.

This module also builds shareable libraries for HDF5 compression filter plugins.  
These plugins can be used with any HDF5 application built with HDF5 1.8.11 or later.
The plugin libraries that are built are HDF5_blosc_plugin.so, HDF5_bshuf_plugin.so, and HDF5_lz4_plugin.so.
The library extensions will be .dll on Windows and .dylib on Mac.
In order for the HDF5 application to find these plugins at run-time the following environment variable
must be set.

On Linux:
```
HDF5_PLUGIN_PATH=ADSupport/lib/linux-x86_64
```

On Windows:
```
HDF5_PLUGIN_PATH=ADSupport/bin/windows-x64
```
Using these plugins HDF5 applications can read files written by NDFileHDF5 with any of the supported compressions.
The files can be compressed in the HDF5 library, or compressed elsewhere (e.g. NDPluginCodec, 
ADEiger compressed NDArrays) and written with HDF5 direct chunk write.

Additional information:
* [Documentation](https://cars.uchicago.edu/software/epics/areaDetectorDoc.html).
* [Release notes and links to source code releases](RELEASE.md).
