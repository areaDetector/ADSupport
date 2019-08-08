ADSupport Releases
===============

Introduction
------------

The latest untagged master branch can be obtained at
https://github.com/areaDetector/ADSupport.

The versions of EPICS base, asyn, and other synApps modules used for each release can be obtained from 
the EXAMPLE_RELEASE_PATHS.local, EXAMPLE_RELEASE_LIBS.local, and EXAMPLE_RELEASE_PRODS.local
files respectively, in the configure/ directory of the appropriate release of the 
[top-level areaDetector](https://github.com/areaDetector/areaDetector) repository.
 
 ## __R1-9 (August 8, 2019)__
  * Fixed memory allocation functions used in the blosc, lz4, bslz4, and JPEG HDF5 filters.
    In R1-8 it was consistently using H5allocate_memory() and H5free_memory, rather than malloc() and free().
    This prevented crashes when the compressors were called by NDFileHDF5.
    However, it did not work with third-party applications built with HDF5 1.8.11 through 1.8.14 because
    H5allocate_memory() and H5free_memory were added in 1.8.15.
    This was a problem for Matlab, which currently uses 1.8.12.
    The HDF5 Group also said that we should be using malloc() and free().
    We determined that the reason for the access violation in the compressors when using malloc() and free()
    was because we were building on Linux with the macro H5_MEMORY_ALLOC_SANITY_CHECK defined.
    For some reason if that is defined then calling free() on an array allocated by the HDF5 library
    causes an access violation.
    Changed the code not to define that macro and used malloc() and free() everywhere.
    It now works both on Matlab and in the NDFileHDF5 compressors.

## __R1-8 (May 24, 2019)__
  * Added HDF5 filter and dynamically loaded filter plugin for JPEG.
  * Fixed memory allocation functions used in blosc and lz4 HDF5 filters.
  * Fixed problem with hdf5PluginSrc/Makefile, only build plugins if SHAREABLE_LIBRARIES=YES.

## __R1-7 (April 12, 2019)__
  * Added bitshuffle, which includes lz4.
    This is used by ADEiger to read streams that are compressed with bitshuffle/lz4.
  * Builds the HDF5 filter for bitshuffle/lz4 (without Blosc) which can be useful for writing and reading HDF5 files
    with this compression, including those written by the Eiger server.
  * Builds the HDF5 filter for lz4 (without bitshuffle or Blosc) which can be useful for writing and reading HDF5 files
    with this compression, including those written by the Eiger server.
  * Builds dynamically loaded filter plugins for Blosc, Bitshuffle/lz4, and lz4.  These are built for Linux, Windows and Mac.
    These plugins can be used with any HDF5 program using HDF5 1.8.11 or later to read files compressed with these filters.
  * Moved the CBF file support code from ADPilatus/pilatusApp/cbfSrc to supportApp/cbfSrc.
    This allows other detectors, such as ADMMPAD to use it as well.
  * Fixed warnings about redefinition of LOCAL on vxWorks.
  * Fixed problem building decompressJPEG in jpegSrc if JPEG_EXTERNAL=YES.
  * Fixes for Darwin builds of GraphicsMagick and netCDF.

## __R1-6 (December 3, 2018)__
  * Added a new library, decompressJPEG. This contains a small C function to do all of the calls to libjpeg
    to decompress a JPEG encoded buffer.  It is intended to be called from Java for the ImageJ EPICS_NTNDA_Viewer.
    It could also be called from other languages.
  * Fixed a minor problem with netCDFSrc/libdispatch/dauth.c
  * Fixes to netCDFSrc to work with vxWorks 5.5, 6.8, and 6.9.


## __R1-5 (November 12, 2018)__
  * Added support for reading MJPEG streams to GraphicsMagickSrc and xml2Src.  This allows ADURL to stream
    data from Web cameras. Thanks to Peter Heesterman for this.
  * Updated netCDFSrc from netCDF 4.1.3 to 4.6.1.  Updated netCDFSrc/README.epics to document how this was done.
  * Fixed a problem when closing netCDF files > 2 GB on Windows when building with Visual Studio 2015 or 2017.


## __R1-4 (January 27, 2018)__
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


## __R1-3 (July 3, 2017)__
  * Added support for GraphicsMagick.  It is based on GraphicsMagick version 1.3.25.
    This support is used by NDFileMagick in ADCore and by the ADURL driver.
    This has been tested on Windows and Linux.  It is disabled for vxWorks.  
    Thanks to Peter Heesterman for doing this. 
  * Modified xml2Src to enable building nanoftp.c and nanohttp.c which are used for transferring files
    in GraphicsMagick.
  * Added support for the HDF5 hl (high-level) library.  This is in a new hdf5_hlSrc directory.  


## __R1-2 (May 5, 2017)__
  * Updated HDF5 to 1.10.1 which was officially released on May 1, 2017.  
    This release fixes the SWMR problems and adds some new performance features.
  * Updated Nexus to release 4.4.3.  This fixes some problems on 64-bit systems.
  * Modified XML2 so it will build on vxWorks 5.5.  ADCore previously contained and used TinyXml,
    but now requires libxml2, so it needs to build on all platforms.


## __R1-1 (February 19, 2017)__
  * Fixed a problem with XML2 on vxWorks.  xml2Src/os/vxWorks/config.h was previously defining HAVE_ZLIB_H.
    However, on vxWorks we do have zlib.h, but xmlIO.c requires the dup() function to use zlib, and vxWorks 
    does not have dup(), at least not in 6.9.4.  Fix is not to define HAVE_ZLIB_H.
  * The HDF5 Group has not yet released 1.10.1, and is now estimating sometime after March 1, 2017.  
    ADSupport thus still has 2 branches as discussed in the R1-0 release notes below.


## __R1-0 (October 28, 2016)__
  * Initial release.  The versions of each support library are:

| Library | Version
| ------- | -------
| HDF5    | 1.10.0-patch1 (see below)
| JPEG    | 9b
| netCDF  | 4.1.3  
| NeXus   | 4.3.1
| SZIP    | 2.1
| TIFF    | 4.0.6
| XML2    | 2.9.4
| ZLIB    | 1.2.8
  
  * For HDF5 we discovered shortly before releasing ADSupport R1-0 and ADCore R2-5 that the
    Single Writer Multiple Reader (SWMR) support in HDF5 1.10.0-patch1 was broken.
    It can return errors if any of the datasets are of type H5_C_S1 (fixed length strings).
    We were able to reproduce the errors with a simple C program, and sent that to the HDF Group.
    They quickly produced a new unreleased version of HDF5 called 1.10-swmr-fixes that fixed the problem.
    
  * The HDF5 Group plans to release 1.10.1, hopefully before the end of 2016.  That should be
    the first official release that will correctly support SWMR.
  
  * As of the R1-0 release ADSupport contains 2 branches. 
    - master contains the HDF5 1.10.0-patch1 release from the HDF5 Group with only the minor changes
      required to build with the EPICS build system, and to work on vxWorks and mingw.
      These changes are documented in README.epics.  This version should not be used with SWMR
      support enabled because of the known problems described above.
    - swmr-fixes contains the 1.10-swmr-fixes code that the HDF Group provided.
      We had to make some changes to this code to get it to work on Windows.
      It is not an official release, but does appear to correctly support SWMR.
      Users who would like to begin to use SWMR before HDF5 1.10.1 is released can use
      this branch, but must be aware that it is not officially supported. 
