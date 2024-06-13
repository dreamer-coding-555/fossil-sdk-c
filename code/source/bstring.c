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
#include "fossil/string/bstring.h"
#include "fossil/common/common.h"
#include <stdlib.h>
#include <string.h>

bstring fossil_bstr_create(const_bstring str) {
    if (!str) {
        return cnullptr; // Validate input to prevent NULL pointer dereference
    }
    return (bstring)_custom_fossil_strdup((const char *)str); // Allocate memory and copy string using strdup
}

void fossil_bstr_erase(bstring str) {
    if (str) {
        free(str); // Free memory allocated for the byte string
        str = cnullptr; // Reset the pointer to NULL
    }
}

size_t fossil_bstr_length(const_bstring str) {
    if (!str) {
        return 0;
    }
    return strlen((const char *)str); // Calculate byte string length using strlen
}
