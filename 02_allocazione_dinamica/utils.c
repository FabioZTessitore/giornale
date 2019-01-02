/* utils.c */

#include <stdlib.h>
#include <string.h>

char *strAllocAndSafeCopy(const char * const src)
{
  int dstLen = strlen(src) + 1;
  char *dst = (char *)malloc(dstLen);

  strncpy(dst, src, dstLen);
  dst[dstLen-1] = '\0';

  return dst;
}

void strSafeFree(char **s)
{
  if (*s) {
    free(*s);
    *s = NULL;
  }
}
