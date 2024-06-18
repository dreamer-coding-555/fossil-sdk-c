/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#include "fossil/core/memory.h"
#include "fossil/common/common.h"

fossil_memory_t fossil_memory_alloc(size_t size) {
    if (size == 0) {
        fprintf(stderr, "Error: Cannot allocate zero bytes.\n");
        exit(FOSSIL_FAILURE);
    }
    
    fossil_memory_t ptr = malloc(size);
    if (!ptr) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        exit(FOSSIL_FAILURE);
    }
    return ptr;
}

fossil_memory_t fossil_memory_realloc(fossil_memory_t ptr, size_t size) {
    if (ptr == cnullptr) {
        fprintf(stderr, "Error: Cannot reallocate NULL pointer.\n");
        exit(FOSSIL_FAILURE);
    }

    fossil_memory_t new_ptr;
    if (size == 0) {
        fossil_memory_free(ptr);
        new_ptr = cnullptr;
    } else {
        new_ptr = realloc(ptr, size);
        if (!new_ptr) {
            fprintf(stderr, "Error: Memory reallocation failed.\n");
            exit(FOSSIL_FAILURE);
        }
    }
    return new_ptr;
}

void fossil_memory_free(fossil_memory_t ptr) {
    if (ptr) {
        // Freeing memory
        free(ptr);
    } else {
        fprintf(stderr, "Error: Attempt to free NULL pointer.\n");
        exit(FOSSIL_FAILURE);
    }
}

fossil_memory_t fossil_memory_copy(fossil_memory_t dest, const fossil_memory_t src, size_t size) {
    if (!dest || !src) {
        fprintf(stderr, "Error: Invalid memory copy arguments. Source or destination is NULL.\n");
        exit(FOSSIL_FAILURE);
    }
    
    if (size == 0) {
        fprintf(stderr, "Error: Cannot copy zero bytes.\n");
        exit(FOSSIL_FAILURE);
    }
    
    fossil_memory_t result = memcpy(dest, src, size);
    if (!result) {
        fprintf(stderr, "Error: Memory copy failed.\n");
        exit(FOSSIL_FAILURE);
    }
    return result;
}

fossil_memory_t fossil_memory_set(fossil_memory_t ptr, int32_t value, size_t size) {
    if (!ptr) {
        fprintf(stderr, "Error: Invalid memory set argument. Pointer is NULL.\n");
        exit(FOSSIL_FAILURE);
    }
    
    if (size == 0) {
        fprintf(stderr, "Error: Cannot set zero bytes.\n");
        exit(FOSSIL_FAILURE);
    }
    
    fossil_memory_t result = memset(ptr, value, size);
    if (!result) {
        fprintf(stderr, "Error: Memory set failed.\n");
        exit(FOSSIL_FAILURE);
    }
    return result;
}
