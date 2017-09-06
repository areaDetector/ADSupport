/* Dummy and wrapper functions for vxWorks
 * Mark Rivers
 * September 25, 2016
 */

#include <H5vxWorks.h>
#include <H5private.h>

void *dlopen(const char *filename, int flag)
{
  return 0;
}

void *dlsym(void *handle, const char *symbol)
{
  return 0;
}

int dlclose(void *handle)
{
  return 0;
}

char *dlerror(void)
{
  return 0;
}

void tzset(void)
{
}

int vxWorks_ftruncate(int fd, off_t length)
{
  return 0;
}

int vxWorks_flock(int fd, int operation)
{
  return 0;
}

int
nanosleep(const struct timespec *req, struct timespec *rem)
{
    /* XXX: Currently just a placeholder */
    return 0;

} /* end nanosleep() */


long long
llround(double arg)
{
    return (long long)(arg < 0.0 ? HDceil(arg - 0.5) : HDfloor(arg + 0.5));
}

long long
llroundf(float arg)
{
    return (long long)(arg < 0.0F ? HDceil(arg - 0.5F) : HDfloor(arg + 0.5F));
}

long
lround(double arg)
{
    return (long)(arg < 0.0 ? HDceil(arg - 0.5) : HDfloor(arg + 0.5));
}

long
lroundf(float arg)
{
    return (long)(arg < 0.0F ? HDceil(arg - 0.5F) : HDfloor(arg + 0.5F));
}

double
round(double arg)
{
    return arg < 0.0 ? HDceil(arg - 0.5) : HDfloor(arg + 0.5);
}

float
roundf(float arg)
{
    return arg < 0.0F ? HDceil(arg - 0.5F) : HDfloor(arg + 0.5F);
}

float
powf(float x, float y)
{
    return (float)pow(x, y);
}
