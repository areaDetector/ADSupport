/* Dummy and wrapper functions for vxWorks
 * Mark Rivers
 * September 25, 2016
 */

#include <H5vxWorks.h>

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
