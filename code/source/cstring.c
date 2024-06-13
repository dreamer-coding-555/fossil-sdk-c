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
#include "fossil/string/cstring.h"
#include "fossil/common/common.h"
#include <stdlib.h>
#include <string.h>

cstring fossil_cstr_create(const_cstring str) {
    if (!str) {
        return cnullptr; // Validate input to prevent NULL pointer dereference
    }
    return _custom_fossil_strdup(str); // Allocate memory and copy string using strdup
}

void fossil_cstr_erase(cstring str) {
    if (str) {
        free(str); // Free memory allocated by strdup
        str = cnullptr; // Reset the pointer to NULL
    }
}

size_t fossil_cstr_length(const_cstring str) {
    if (!str) {
        return 0;
    }
    return strlen(str); // Calculate string length using strlen
}
