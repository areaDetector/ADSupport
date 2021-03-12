/* Dummy and wrapper functions for vxWorks
 * Mark Rivers
 * September 25, 2016
 */

#include <stdio.h>

void *dlopen(const char *filename, int flag);
void *dlsym(void *handle, const char *symbol);
int dlclose(void *handle);
char *dlerror(void);
void tzset(void);
#define HDftruncate(F,L)   vxWorks_ftruncate(F,L)
int vxWorks_ftruncate(int fd, off_t length);
#define HDflock(F,L)   vxWorks_flock(F,L)
int vxWorks_flock(int fd, int operation);
long long llround(double arg);
long long llroundf(float arg);
long lround(double arg);
long lroundf(float arg);
double round(double arg);
float roundf(float arg);
float powf(float x, float y);