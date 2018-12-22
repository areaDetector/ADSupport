#if defined(WIN32) || defined(WIN64)
#include "magick_config_Win32.h"
#elif defined(__APPLE__)
#include "magick_config_Darwin.h"
#else
#include "magick_config_Linux.h"
#endif
