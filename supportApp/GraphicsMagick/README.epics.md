This directory contains the GraphicsMagick code (1.3.25).
It has been modified to build under the EPICS build system.

This work was done by Peter Heesterman.  The documentation in this file is based on a Word document he
produced describing what he did.  The following are the important issues and changes that were made.

- GraphicsMagick includes some libraries (xml2, tiff, jpeg, zlib) that already exist in ADSupport.  The versions
  in GraphicsMagick were deleted and the existing ones in ADSupport are used instead.

- GraphicsMagick generally uses AutoMake and therefore having make-files named ‘Makefile.am’, which were largely ignored. 
- In a small number of cases, the GraphicsMagick make-file was named ‘Makefile ‘, which will then have been overwritten by the EPICS Makefile. 
- Some of the new libraries (jp2, wmf didn’t have DLL import / DLL Export semantics enabled correctly, 
  and depended on a  ‘.DEF’ file to enable enabled this logic. Enabled the build semantics in the code concerned.
- The GraphicsMagick build requires not just pre-processor defines, but installation-time configuration of some config header files, as well. 
  Merged the config header files used for Win32, Win64, Linux32 and Linux64 use.
- Magick configuration and error logging. 
  - The Magick library depends on configuration files:
    - delegates.mgk
    - modules.mgk
    - log.mgk
  
  By hard-coded default, Magick logs nothing, not even errors or the fact that it couldn’t find it’s configuration files. 
  including the log.mgk configuration, nor where it might have looked to find these file(s).
  This makes it difficult to debug what is going wrong.
  It is helpful to define the environment variable MAGICK_DEBUG to log configure and error messages.
- Circular Dependency between the ‘coders’ and ‘magick’ libraries. 
  - The GraphicsMagick architecture includes 2 entirely separate build configurations:
    - Static 
    - Dynamic
  
  Processing code in the low-level ‘coders’ library is heavily dependent on code in the ‘magick’ library.
  This appears to be a dependency inversion. 
  In a static build, the file ‘magick/static.c’ invokes functions like ‘RegisterURLImage()’ and ‘UnregisterURLImage()’
  to bind registered processing code addresses to specific image types (e.g. URL).
  These functions exist in ‘coders/url.c’ and in turn invoke the functions 
  RegisterMagickInfo() and UnregisterMagickInfo() to populate information structures.
  But the (Un)registerMagickInfo functions are in the ‘Magick’ library! This is (doubly) a circular dependency. 
  It builds in a static build only because the linker can resolve it all at the final executable stage.
  In a dynamic build, the software instead seeks at run-time to load processing code DLLs or shared libraries, with names like IM_MOD_url, 
  thereby resolving the circular dependency problem, and allowing the code to build. 
  This dynamic architecture model is undesirable in the EPICS context and the code was changed to overcome the circular dependency
  - If ‘BuildMagickModules’ is defined the build architecture is dynamic. Otherwise static.  
  - If ‘_MAGICKMOD_’ is defined (which is required to build the ‘magick’ library to DLL), then ‘BuildMagickModules’ is defined.
  - Moved ‘static.c’ from the ‘magick’ into the ‘coders’ library.
  - Commented out #define BuildMagickModules.
  - Commented out (in ‘magick/magic.c’) the call to (Un)RegisterStaticModules().
  - Added the calls to (Un)RegisterStaticModules() to ‘Magick++/Image.cpp’.
    This higher-level library is dependent on both ‘coders’ and ‘magick’.
  - This means that static.c, static.h and (Un)RegisterStaticModules() are now inappropriately named.
  - This issue should be raised with the GraphicsMagick project team.

As time permits this file should be updated to describe exactly what files in the GraphicsMagick distriubtion were changed.
We should also generate .patch files is done in hdf5Src and nexusSrc,
which can be applied when a new version of GraphicsMagick is downloaded to this directory.