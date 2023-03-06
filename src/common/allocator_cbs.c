#include "common/allocator_cbs.h"

#include <stdlib.h>

static struct allocator_cbs default_allocators =
{
 .malloc=&malloc,
 .realloc=&realloc,
 .free=&free
};

struct allocator_cbs allocator_get_default()
{
  return default_allocators;
}

void allocator_set_default(struct allocator_cbs cbs)
{
  default_allocators = cbs;
}
