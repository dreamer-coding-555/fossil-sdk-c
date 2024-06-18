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
#include "fossil/strings/wstring.h"
#include "fossil/common/common.h"
#include <stdlib.h>
#include <string.h>

// String library functions
wstring fossil_wstr_create(const_wstring str) {
    if (str == cnullptr) {
        return cnullptr;
    }

    size_t len = wcslen(str);
    wstring new_str = (wstring)malloc((len + 1) * sizeof(wletter));
    
    if (new_str == cnullptr) {
        // Handle memory allocation failure
        return cnullptr;
    }

    wcscpy(new_str, str);
    return new_str;
}

void fossil_wstr_erase(wstring str) {
    if (str != cnullptr) {
        free(str);
    }
}

size_t fossil_wstr_length(const_wstring str) {
    if (str == cnullptr) {
        return 0;
    }

    return wcslen(str);
}
