#ifdef __MINGW32__
  #include "H5Tinit_mingw32.c"
#else
  #ifdef _M_X64
    #include "H5Tinit_win64.c"
  #else
    #include "H5Tinit_win32.c"
  #endif
#endif
