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
