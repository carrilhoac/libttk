
#include "ttk.h"

#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*!
 * @brief Get the file size in bytes
 * @param String with the file path
 * @return File size in bytes
 */
uint64_t
Ttk_FileGetSize (const char* sz_path)
{
  struct stat file_details;
  if (!stat(sz_path, & file_details))
    return (uint64_t) file_details.st_size;
  return 0;
}

uint32_t
Ttk_FileGetCRC32 (const char* sz_path)
{
}

char*
Ttk_FileGetExt (const char* sz_path)
{
}

char*
Ttk_FileFixExt (const char* sz_path, const char* sz_ext)
{
}

/*!
 * @brief String comparison case insensitive
 * @param lhs First string to compare
 * @param rhs Seccond string to compare
 * @return 0 if the strings are equal or -1 if not
 * @see Ttk_StrCmpIn
 */
int
Ttk_StrCmpI (const char* sz_lhs, const char* sz_rhs)
{
  char *p1, *p2;

  if (!sz_lhs || !sz_rhs)
    return -1;

  p1 = (char*)sz_lhs;
  p2 = (char*)sz_rhs;

  while (*p1 && *p2)
    if (toupper(*p1++) - toupper(*p2++))
      return -1;

  return 0;
}

int
Ttk_StrCmpIn (const char* lhs, const char* rhs, uint64_t n)
{
}
