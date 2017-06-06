ADSupport
======
The home of the support libraries for the 
[EPICS](http://www.aps.anl.gov/epics/) 
[areaDetector](http://cars.uchicago.edu/software/epics/areaDetector.html) 
software.  It contains third party libraries required for some plugins and
drivers.  These are provided in source-code form compatible with the EPICS
build system.  This makes it convenient to use these libraries on systems
like Windows and vxWorks for which there are not binary packages available
as there are on Linux and Darwin.  For Linux and Darwin the code here can be 
useful when the system not have one of the packages installed, or
has a different version from the one required by areaDetector.

This module contains the following libraries:

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

Additional information:
* [Documentation](http://cars.uchicago.edu/software/epics/areaDetectorDoc.html).
* [Release notes and links to source code releases](RELEASE.md).
