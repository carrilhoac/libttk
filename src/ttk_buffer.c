
#include "ttk.h"
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
