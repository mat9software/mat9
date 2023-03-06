#include "common/allocators.h"

#include <stdlib.h>

static struct allocators default_allocators =
{
 .malloc=&malloc,
 .realloc=&realloc,
 .free=&free
};

struct allocators allocator_get_default()
{
  return default_allocators;
}

void allocator_set_default(struct allocators cbs)
{
  default_allocators = cbs;
}
