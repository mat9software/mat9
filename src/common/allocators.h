#ifndef COMMON_ALLOCATOR_CBS_H
#define COMMON_ALLOCATOR_CBS_H

#include <stddef.h>

struct allocators {
void* (*malloc) (size_t size); 
void* (*realloc) (void* ptr, size_t size); 
void (*free) (void* ptr); 
};

struct allocators allocator_get_default();
void allocator_set_default(struct allocators cbs);

#endif
