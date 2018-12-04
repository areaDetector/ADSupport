ADSupport Releases
===============

The latest untagged master branch can be obtained at
https://github.com/areaDetector/ADSupport.

The versions of EPICS base, asyn, and other synApps modules used for each release can be obtained from 
the EXAMPLE_RELEASE_PATHS.local, EXAMPLE_RELEASE_LIBS.local, and EXAMPLE_RELEASE_PRODS.local
files respectively, in the configure/ directory of the appropriate release of the 
[top-level areaDetector](https://github.com/areaDetector/areaDetector) repository.


Release Notes
=============

R1-6 (December 3, 2018)
========================
* Added a new library, decompressJPEG. This contains a small C function to do all of the calls to libjpeg
  to decompress a JPEG encoded buffer.  It is intended to be called from Java for the ImageJ EPICS_NTNDA_Viewer.
  It could also be called from other languages.
* Fixed a minor problem with netCDFSrc/libdispatch/dauth.c
* Fixes to netCDFSrc to work with vxWorks 5.5, 6.8, and 6.9.


R1-5 (November 12, 2018)
========================
* Added support for reading MJPEG streams to GraphicsMagickSrc and xml2Src.  This allows ADURL to stream
  data from Web cameras. Thanks to Peter Heesterman for this.
* Updated netCDFSrc from netCDF 4.1.3 to 4.6.1.  Updated netCDFSrc/README.epics to document how this was done.
* Fixed a problem when closing netCDF files > 2 GB on Windows when building with Visual Studio 2015 or 2017.


R1-4 (January 27, 2018)
========================
* Added support for Blosc filter library.  This is used by NDFileHDF5.  Thanks to Xiaoqiang Wang for this.
* Fixed a bug in GraphicsMagickSrc.  We had changed Magick++/lib/Image.cpp to call UnregisterStaticModules in
  a cleanup destructor.  The problem was that this destructor is always called, even if GraphicsMagick has not
  ever been initialized.  That will happen if an application is built with GraphicsMagick but NDFileMagick is
  not loaded in the startup script.  The symptom was an assertion failure when exiting the IOC.  This occurred
  on both Linux and Windows.  Fixed the problem by ensuring that UnregisterStaticModules is not called if
  GraphicsMagick has not been initialized.
* Fixes to Makefiles in GraphicsMagickSrc to allow it to be built with external libraries 
  for jpeg, tiff, xml2, and zlib.
* Fixed Darwin support in tiffSrc.
* Fixed several problems on vxWorks.  
  * xml2Src was previously not compiling nanohttp.c and nanoftp.c.
    This led to undefined symbols when booting vxWorks, because xmlIO.c references these functions.
    The correct fix is not to define LIBXML_HTTP_ENABLED and LIBXML_FTP_ENABLED on vxWorks. 
    This change was made to xml2Src/os/default/libxml/xmlversion.h, and the Makefile was changed to 
    compile nanohttp.c and nanoftp.c on all architectures.
  * tiffSrc/os/vxWorks/tif_config.h was defining HAVE_MMAP on vxWorks 6.x. This was incorrect, 
    vxWorks 6.x does not generally have mmap, so now HAVE_MMAP is never defined on vxWorks.
  * Fixed missing functions which showed up only when booting vxWorks, not when linking.
    Added definitions of nanosleep(), llround(), llroundf(), lround(), lroundf(), round(), and roundf()
    to hdf5Src/H5vxWorks.c.  These were taken almost directly from the WIN32 functions in H5system.c.
    Added powf() which just calls pow().
* Fixed .gitignore file.  It was previously ignoring all include/ directories, but those in GraphicsMagick
  should not be ignored.


R1-3 (July 3, 2017)
========================
* Added support for GraphicsMagick.  It is based on GraphicsMagick version 1.3.25.
  This support is used by NDFileMagick in ADCore and by the ADURL driver.
  This has been tested on Windows and Linux.  It is disabled for vxWorks.  
  Thanks to Peter Heesterman for doing this. 
* Modified xml2Src to enable building nanoftp.c and nanohttp.c which are used for transferring files
  in GraphicsMagick.
* Added support for the HDF5 hl (high-level) library.  This is in a new hdf5_hlSrc directory.  


R1-2 (May 5, 2017)
========================
* Updated HDF5 to 1.10.1 which was officially released on May 1, 2017.  
  This release fixes the SWMR problems and adds some new performance features.
* Updated Nexus to release 4.4.3.  This fixes some problems on 64-bit systems.
* Modified XML2 so it will build on vxWorks 5.5.  ADCore previously contained and used TinyXml,
  but now requires libxml2, so it needs to build on all platforms.


R1-1 (February 19, 2017)
========================
* Fixed a problem with XML2 on vxWorks.  xml2Src/os/vxWorks/config.h was previously defining HAVE_ZLIB_H.
  However, on vxWorks we do have zlib.h, but xmlIO.c requires the dup() function to use zlib, and vxWorks 
  does not have dup(), at least not in 6.9.4.  Fix is not to define HAVE_ZLIB_H.
* The HDF5 Group has not yet released 1.10.1, and is now estimating sometime after March 1, 2017.  
  ADSupport thus still has 2 branches as discussed in the R1-0 release notes below.


R1-0 (October 28, 2016)
========================
Initial release.  The versions of each support library are:

Library | Version
------- | -------
HDF5    | 1.10.0-patch1 (see below)
JPEG    | 9b
netCDF  | 4.1.3  
NeXus   | 4.3.1
SZIP    | 2.1
TIFF    | 4.0.6
XML2    | 2.9.4
ZLIB    | 1.2.8

For HDF5 we discovered shortly before releasing ADSupport R1-0 and ADCore R2-5 that the
Single Writer Multiple Reader (SWMR) support in HDF5 1.10.0-patch1 was broken.
It can return errors if any of the datasets are of type H5_C_S1 (fixed length strings).
We were able to reproduce the errors with a simple C program, and sent that to the HDF Group.
They quickly produced a new unreleased version of HDF5 called 1.10-swmr-fixes that fixed the problem.

The HDF5 Group plans to release 1.10.1, hopefully before the end of 2016.  That should be
the first official release that will correctly support SWMR.

As of the R1-0 release ADSupport contains 2 branches. 
- master contains the HDF5 1.10.0-patch1 release from the HDF5 Group with only the minor changes
  required to build with the EPICS build system, and to work on vxWorks and mingw.
  These changes are documented in README.epics.  This version should not be used with SWMR
  support enabled because of the known problems described above.
- swmr-fixes contains the 1.10-swmr-fixes code that the HDF Group provided.
  We had to make some changes to this code to get it to work on Windows.
  It is not an official release, but does appear to correctly support SWMR.
  Users who would like to begin to use SWMR before HDF5 1.10.1 is released can use
  this branch, but must be aware that it is not officially supported. 
