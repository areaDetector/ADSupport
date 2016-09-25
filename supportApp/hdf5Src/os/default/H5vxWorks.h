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
int fseeko(FILE *stream, off_t offset, int whence);
off_t ftello(FILE *stream);
int ftruncate(int fd, off_t length);
