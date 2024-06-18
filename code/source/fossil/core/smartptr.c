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
#include "fossil/core/smartptr.h"
#include "fossil/common/common.h"

static void log_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
}

fossil_bool_t fossil_smartptr_create(fossil_smartptr_t *sp, void *ptr, void (*deleter)(void *)) {
    if (sp == cnullptr || ptr == cnullptr) {
        log_error("Invalid argument to fossil_smartptr_create");
        return FOSSIL_FALSE;
    }

    sp->ptr = ptr;
    sp->ref_count = (int32_t *)malloc(sizeof(int32_t));
    if (sp->ref_count == cnullptr) {
        log_error("Memory allocation failed in fossil_smartptr_create");
        return FOSSIL_FALSE;
    }
    *sp->ref_count = 1;

    sp->deleter = deleter;
    return FOSSIL_TRUE;
}

fossil_bool_t fossil_smartptr_acquire(fossil_smartptr_t *sp) {
    if (sp == cnullptr || sp->ref_count == cnullptr) {
        log_error("Invalid smart pointer in fossil_smartptr_acquire");
        return FOSSIL_FALSE;
    }

    (*sp->ref_count)++;

    return FOSSIL_TRUE;
}

fossil_bool_t fossil_smartptr_erase(fossil_smartptr_t *sp) {
    if (sp == cnullptr || sp->ref_count == cnullptr) {
        log_error("Invalid smart pointer in fossil_smartptr_erase");
        return FOSSIL_FALSE;
    }

   (*sp->ref_count)--;
    if (*sp->ref_count == 0) {
        if (sp->deleter != cnullptr) {
            sp->deleter(sp->ptr);
        } else {
            free(sp->ptr);
        }
        free(sp->ref_count);
        sp->ptr = cnullptr;
        sp->ref_count = cnullptr;
    }

    return FOSSIL_TRUE;
}

void *fossil_smartptr_get(fossil_smartptr_t *sp) {
    if (sp == cnullptr || sp->ptr == cnullptr) {
        log_error("Invalid smart pointer in fossil_smartptr_get");
        return cnullptr;
    }

    return sp->ptr;
}
