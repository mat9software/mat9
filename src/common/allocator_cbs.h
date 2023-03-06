#ifndef COMMON_ALLOCATOR_CBS_H
#define COMMON_ALLOCATOR_CBS_H

#include <stddef.h>

struct allocator_cbs {
void* (*malloc) (size_t size); 
void* (*realloc) (void* ptr, size_t size); 
void (*free) (void* ptr); 
};

struct allocator_cbs allocator_get_default();
void allocator_set_default(struct allocator_cbs cbs);

#endif
