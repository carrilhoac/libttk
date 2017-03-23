
#include "ttk.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

TtkBuffer*
Ttk_BufAlloc(uint64_t buffer_size)
{
  TtkBuffer* buf = (TtkBuffer*) malloc(sizeof(TtkBuffer));

  if (!buf)
    return NULL;

  buf->data = (void*) malloc((size_t)buffer_size);

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
Ttk_BufFree(TtkBuffer* buf)
{
  if (!buf)
    return;

  if (buf->data)
    free(buf->data);

  free(buf);
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
}

int
Ttk_BufReSize (TtkBuffer* buf, uint64_t new_size)
{
}

int
Ttk_BufMemCmp (const TtkBuffer *lhs, const TtkBuffer *rhs)
{
}

void
Ttk_BufMemSet (TtkBuffer* buf, int val)
{
}

TtkBuffer*
Ttk_BufCropSelect (const TtkBuffer* buf, uint64_t start, uint64_t length)
{
}

TtkBuffer*
Ttk_BufGenCpy (const TtkBuffer* buf)
{
}

TtkBuffer*
Ttk_BufMemCpy (const void* src, uint64_t length)
{
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
