#include "../header_file.h"

void * debug_malloc( size_t len, char * file, int line )
{
  void *(*libc_malloc)(size_t) = dlsym(RTLD_NEXT, "malloc");
  printf("Malloc from %s:%d\n",file,line);
  return libc_malloc(len);
}

void debug_free( void * addr, char * file, int line )
{
  void (*libc_free)(void*) = dlsym(RTLD_NEXT, "free");
  printf("Free from %s:%d\n",file,line);
  libc_free(addr);
}