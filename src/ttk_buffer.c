
#include "ttk.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

TtkBuffer*
Ttk_BufAlloc (uint64_t buffer_size)
{
  TtkBuffer* buf = (TtkBuffer*) malloc (sizeof (TtkBuffer));

  if (!buf)
    return NULL;

  buf->data = (void*) malloc ((size_t) buffer_size);

  if (!buf->data)
    {
      free (buf);
      return NULL;
    }

  buf->offset = 0;
  buf->length = buffer_size;
  return buf;
}

void
Ttk_BufFree (TtkBuffer* buf)
{
  if (!buf)
    return;

  if (buf->data)
    free (buf->data);

  free (buf);
  buf = NULL;
}

TtkBuffer*
Ttk_BufDiskLoad (const char *sz_path)
{
}

int
Ttk_BufDiskSave (const char *sz_path, const TtkBuffer *buf)
{
}

int
Ttk_BufReSizeEx (TtkBuffer* buf, uint64_t new_size, int keep_data)
{
  uint64_t min_size;
  void* new_ptr;

  if (!buf)
    return TTK_FAILURE;

  if (keep_data == TTK_TRUE)
    {
      if (buf->data)
        free (buf->data);

      buf->data = (void*) malloc (new_size);

      if (!buf->data)
        return TTK_FAILURE;
    }
  else if (keep_data == TTK_FALSE)
    {
      buf->data = (void*) realloc (buf->data, new_size);

      if (!buf->data)
        {
          new_ptr = (void*) malloc (new_size);

          if (!new_ptr)
            return TTK_FAILURE;

          min_size = ((new_size < buf->length) ? (new_size) : (buf->length));
          memcpy (new_ptr, buf->data, min_size);

          free (buf->data);
          buf->data = new_ptr;
        }
    }
  else
    return TTK_FAILURE;

  buf->length = new_size;
  if (buf->offset > buf->length)
    buf->offset = buf->length;

  return TTK_SUCCESS;
}

int
Ttk_BufReSize (TtkBuffer* buf, uint64_t new_size)
{
  return Ttk_BufReSizeEx (buf, new_size, TTK_TRUE);
}

int
Ttk_BufMemCmp (const TtkBuffer *lhs, const TtkBuffer *rhs)
{
  if (!lhs || !rhs)
    return 0;

  if (lhs->length != rhs->length)
    return lhs->length - rhs->length;

  return memcmp (lhs->data, rhs->data, (size_t) lhs->length);
}

void
Ttk_BufMemSet (TtkBuffer* buf, int val)
{
  if (!buf)
    return;

  memset (buf->data, val, buf->length);
}

TtkBuffer*
Ttk_BufCropSelect (const TtkBuffer* buf, uint64_t start, uint64_t length)
{
  TtkBuffer* ret;

  if (!buf || !length)
    return NULL;

  if (buf->length < (start + length))
    return NULL;

  ret = Ttk_BufAlloc(length);
  memcpy(ret->data, buf->data + start, length);
  return ret;
}

TtkBuffer*
Ttk_BufGenCpy (const TtkBuffer* buf)
{
  TtkBuffer *ret;

  if (!buf)
    return NULL;

  ret = Ttk_BufAlloc(buf->length);
  memcpy(ret->data, buf->data, (size_t) bug->length);
  return ret;
}

TtkBuffer*
Ttk_BufMemCpy (const void* src, uint64_t length)
{
  TtkBuffer *buf;

  if (!src || !length)
    return NULL;

  buf = Ttk_BufAlloc(length);
  memcpy(buf->data, src, (size_t)length);
  return buf;
}

uint64_t
Ttk_BufRead (void* dst, uint64_t entry_size, uint64_t entry_count,
             TtkBuffer* buf)
{
}

uint64_t
Ttk_BufWrite (const void* src, uint64_t entry_size, uint64_t entry_count,
              TtkBuffer* dst)
{
}

uint64_t
Ttk_BufSeek (TtkBuffer* buf, uint64_t offset, uint64_t origin)
{
}

uint64_t
Ttk_BufReadBuf (TtkBuffer *dst, TtkBuffer *src, uint64_t length)
{
}

uint64_t
Ttk_BufWriteBuf (TtkBuffer *dst, TtkBuffer *src, uint64_t length)
{
}

char*
Ttk_BufGenStrUTF8 (const TtkBuffer* buf, uint64_t* dst_len)
{
}

wchar_t*
Ttk_BufGenStrUTF16 (const TtkBuffer* buf, uint64_t* dst_len)
{
}

float
Ttk_BufStrToFlt32 (TtkBuffer* buf)
{
}

double
Ttk_BufStrToFlt64 (TtkBuffer* buf)
{
}

int32_t
Ttk_BufStrToInt32 (TtkBuffer* buf)
{
}

int64_t
Ttk_BufStrToInt64 (TtkBuffer* buf)
{
}
