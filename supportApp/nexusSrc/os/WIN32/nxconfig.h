/* $Id:$ */

/* #undef HAVE_HDF4 */
/* #undef WITH_HDF4 */

#define HAVE_HDF5
#define WITH_HDF5

/* #undef HAVE_MXML */
/* #undef WITH_MXML */

#define HAVE_FTIME

#define HAVE_TZSET

#define HAVE_STRDUP

#define HAVE_LONG_LONG_INT 1

#define HAVE_UNSIGNED_LONG_LONG_INT 1

/* #define HAVE_STDINT_H 1 */

/* #define HAVE_INTTYPES_H 1 */

#define PRINTF_INT64			lld

#define PRINTF_UINT64			llu

#define SIZEOF_INT 				4 

#define SIZEOF_LONG_INT 4

/* Define to the type of a signed integer type of width exactly 64 bits if
   such a type exists and the standard includes do not define it. */
typedef long long int64_t;


#ifdef _MSC_VER
  #ifdef _M_X64
    #define SIZEOF_SIZE_T 8
    #define SIZEOF_VOIDP 	8
  #else
    #define SIZEOF_SIZE_T 4
    #define SIZEOF_VOIDP 	4
  #endif
#endif

#define SIZEOF_LONG_LONG_INT 	8 

