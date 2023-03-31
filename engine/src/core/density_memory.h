#pragma once

#include "defines.h"

typedef enum memory_tag
{
    MEMORY_TAG_UNKOWN,
    MEMORY_TAG_ARRAY,
    MEMORY_TAG_DARRAY,
    MEMORY_TAG_DICT,
    MEMORY_TAG_RING_QUEUE,
    MEMORY_TAG_BST,
    MEMORY_TAG_STRING,
    MEMORY_TAG_APPLICATION,
    MEMORY_TAG_JOB,
    MEMORY_TAG_TEXTURE,
    MEMORY_TAG_MATERIAL_INSTANCE,
    MEMORY_TAG_RENDERER,
    MEMORY_TAG_GAME,
    MEMORY_TAG_TRANSFORM,
    MEMORY_TAG_ENTITY,
    MEMORY_TAG_ENTITY_NODE,
    MEMORY_TAG_SCENCE,
    MEMORY_TAG_PLATFORM,
    MEMORY_TAG_MAX_TAGS
} memory_tag;

DENSITY void initialize_memory();
DENSITY void shutdown_memory();

DENSITY void *density_allocate_memory(u64 size, memory_tag tag);
DENSITY void density_free_memory(void *block, u64 size, memory_tag tag);
DENSITY void *density_zero_memory(void *block, u64 size);
DENSITY void *density_copy_memory(void *dest, const void *source, u64 size);
DENSITY void *density_set_memory(void *dest, i32 value, u64 size);

DENSITY char *get_memory_usage_str();