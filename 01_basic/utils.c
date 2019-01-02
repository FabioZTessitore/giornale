/* utils.c */

#include <string.h>

void strSafeCopy(char *dst, const char * const src, const int maxLen)
{
  strncpy(dst, src, maxLen);
  dst[maxLen-1] = '\0';
}
