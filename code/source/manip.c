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
#include "fossil/string/manip.h"
#include "fossil/common/common.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int fossil_bstr_compare(const_bstring str1, const_bstring str2) {
    return (str1 && str2) ? memcmp(str1, str2, fossil_bstr_length(str1) + 1) : -1;
}

bstring fossil_bstr_copy(bstring dest, const_bstring src) {
    return (dest && src) ? (bstring)memcpy(dest, src, fossil_bstr_length(src) + 1) : cnullptr;
}

bstring fossil_bstr_concat(bstring dest, const_bstring src) {
    if (!dest || !src) {
        return cnullptr;
    }
    size_t dest_len = fossil_bstr_length(dest);
    size_t src_len = fossil_bstr_length(src);
    bstring new_dest = realloc(dest, dest_len + src_len + 1);
    if (!new_dest) {
        return cnullptr;
    }
    memcpy(new_dest + dest_len, src, src_len + 1);
    return new_dest;
}

const_bstring fossil_bstr_find(const_bstring str, bletter ch) {
    return str ? memchr(str, ch, fossil_bstr_length(str)) : cnullptr;
}

const_bstring fossil_bstr_reverse(const_bstring str) {
    if (!str) {
        return cnullptr;
    }
    size_t len = fossil_bstr_length(str);
    bstring rev = malloc(len + 1);
    if (!rev) {
        return cnullptr;
    }
    for (size_t i = 0; i < len; i++) {
        rev[i] = str[len - i - 1];
    }
    rev[len] = cterminator;
    return rev;
}

void fossil_bstr_erase_splits(bstrings splits) {
    if (!splits) {
        return;
    }
    for (size_t i = 0; splits[i] != cnullptr; i++) {
        free(splits[i]);
    }
    free(splits);
}

bstrings fossil_bstr_split(const_bstring str, bletter delimiter) {
    if (!str) {
        return cnullptr;
    }
    size_t len = fossil_bstr_length(str);
    size_t count = 1;
    
    // Count the number of splits
    for (size_t i = 0; i < len; i++) {
        if (str[i] == delimiter) {
            count++;
        }
    }
    
    // Allocate memory for the array of byte strings
    bstrings splits = malloc((count + 1) * sizeof(bstring));
    if (!splits) {
        return cnullptr;
    }
    
    size_t start = 0;
    size_t index = 0;
    
    // Populate the array of byte strings
    for (size_t i = 0; i <= len; i++) {
        if (str[i] == delimiter || str[i] == cterminator) {
            size_t sublen = i - start;
            splits[index] = malloc(sublen + 1);
            if (!splits[index]) {
                fossil_bstr_erase_splits((bstrings)splits);
                return cnullptr;
            }
            memcpy(splits[index], str + start, sublen);
            splits[index][sublen] = cterminator;
            start = i + 1;
            index++;
        }
    }
    
    splits[count] = cnullptr;
    return splits;
}

bstring fossil_bstr_strdup(const_bstring str) {
    if (!str) {
        return cnullptr;
    }
    size_t len = fossil_bstr_length(str);
    bstring dup = malloc(len + 1);
    if (!dup) {
        return cnullptr;
    }
    return (bstring)memcpy(dup, str, len + 1);
}

int fossil_cstr_compare(const_cstring str1, const_cstring str2) {
    if (!str1 || !str2) {
        return -1;
    }
    return strcmp(str1, str2);
}

cstring fossil_cstr_copy(cstring dest, const_cstring src) {
    if (!dest || !src) {
        return cnullptr;
    }
    size_t src_len = fossil_cstr_length(src);
    if (src_len >= strlen(dest)) {
        return cnullptr; // buffer overflow prevention
    }
    return strcpy(dest, src);
}

cstring fossil_cstr_concat(cstring dest, const_cstring src) {
    if (!dest || !src) {
        return cnullptr;
    }
    size_t dest_len = fossil_cstr_length(dest);
    size_t src_len = fossil_cstr_length(src);
    if (dest_len + src_len >= strlen(dest)) {
        return cnullptr; // buffer overflow prevention
    }
    return strcat(dest, src);
}

const_cstring fossil_cstr_find(const_cstring str, cletter ch) {
    if (!str) {
        return cnullptr;
    }
    return strchr(str, ch);
}

const_cstring fossil_cstr_reverse(const_cstring str) {
    if (!str) {
        return cnullptr;
    }
    size_t len = fossil_cstr_length(str);
    cstring rev = malloc(len + 1);
    if (!rev) {
        return cnullptr;
    }
    for (size_t i = 0; i < len; i++) {
        rev[i] = str[len - i - 1];
    }
    rev[len] = cterminator;
    return rev;
}

void fossil_cstr_erase_splits(cstrings splits) {
    if (!splits) {
        return;
    }
    for (size_t i = 0; splits[i] != cnullptr; i++) {
        free(splits[i]);
    }
    free(splits);
}

cstrings fossil_cstr_split(const_cstring str, cletter delimiter) {
    if (!str) {
        return cnullptr;
    }
    size_t len = fossil_cstr_length(str);
    size_t count = 1;
    
    // Count the number of splits
    for (size_t i = 0; i < len; i++) {
        if (str[i] == delimiter) {
            count++;
        }
    }
    
    // Allocate memory for the array of strings
    cstrings splits = malloc((count + 1) * sizeof(cstring));
    if (!splits) {
        return cnullptr;
    }
    
    size_t start = 0;
    size_t index = 0;
    
    // Populate the array of strings
    for (size_t i = 0; i <= len; i++) {
        if (str[i] == delimiter || str[i] == cterminator) {
            size_t sublen = i - start;
            splits[index] = malloc(sublen + 1);
            if (!splits[index]) {
                fossil_cstr_erase_splits(splits);
                return cnullptr;
            }
            memcpy(splits[index], str + start, sublen);
            splits[index][sublen] = cterminator;
            start = i + 1;
            index++;
        }
    }
    
    splits[count] = cnullptr;
    return splits;
}

cstring fossil_cstr_strdup(const_cstring str) {
    if (!str) {
        return cnullptr;
    }
    size_t len = fossil_cstr_length(str);
    cstring dup = malloc(len + 1);
    if (!dup) {
        return cnullptr;
    }
    return strcpy(dup, str);
}

cstring fossil_cstr_substr(const_cstring str, size_t start, size_t len) {
    if (str == cnullptr) return cnullptr;

    size_t str_len = strlen(str);

    if (start >= str_len) return cnullptr;

    if (start + len > str_len) {
        len = str_len - start;
    }

    cstring substr = (cstring)malloc(len + 1);
    if (substr == cnullptr) {
        // Handle memory allocation failure
        return cnullptr;
    }

    strncpy(substr, str + start, len);
    substr[len] = cterminator;

    return substr;
}

bstring fossil_bstr_substr(const_bstring str, size_t start, size_t len) {
    // Check if the input string is NULL
    if (str == cnullptr) return cnullptr;

    // Get the length of the input string
    size_t str_len = fossil_bstr_length(str);

    // Check if the starting index is out of bounds
    if (start >= str_len) return cnullptr;

    // Adjust the length if the specified substring extends beyond the input string's length
    if (start + len > str_len) {
        len = str_len - start;
    }

    // Allocate memory for the substring
    bstring substr = fossil_bstr_create(str);
    if (substr == cnullptr) {
        // Handle memory allocation failure
        return cnullptr;
    }

    // Copy the substring using the provided fossil_bstr_copy function
    fossil_bstr_copy(substr, str + start);

    // Return the substring
    return substr;
}

int fossil_wstr_compare(const_wstring str1, const_wstring str2) {
    if (str1 == cnullptr || str2 == cnullptr) {
        return (str1 == cnullptr && str2 == cnullptr) ? 0 : (str1 == cnullptr) ? -1 : 1;
    }

    return wcscmp(str1, str2);
}

wstring fossil_wstr_copy(wstring dest, const_wstring src) {
    if (src == cnullptr) {
        return dest;
    }

    size_t len = wcslen(src);
    if (dest == cnullptr) {
        dest = (wstring)malloc((len + 1) * sizeof(wletter));
        if (dest == cnullptr) {
            return cnullptr; // Memory allocation failed
        }
    }

    wcscpy(dest, src);
    return dest;
}

wstring fossil_wstr_concat(wstring dest, const_wstring src) {
    if (src == cnullptr) {
        return dest;
    }

    size_t dest_len = (dest != cnullptr) ? wcslen(dest) : 0;
    size_t src_len = wcslen(src);
    wstring new_str = (wstring)realloc(dest, (dest_len + src_len + 1) * sizeof(wletter));
    
    if (new_str == cnullptr) {
        return cnullptr; // Memory allocation failed
    }

    wcscat(new_str, src);
    return new_str;
}

const_wstring fossil_wstr_find(const_wstring str, wletter ch) {
    if (str == cnullptr) {
        return cnullptr;
    }

    return wcschr(str, ch);
}

const_wstring fossil_wstr_reverse(const_wstring str) {
    if (str == cnullptr) {
        return cnullptr;
    }

    size_t len = wcslen(str);
    wstring rev_str = (wstring)malloc((len + 1) * sizeof(wletter));
    
    if (rev_str == cnullptr) {
        return cnullptr; // Memory allocation failed
    }

    for (size_t i = 0; i < len; i++) {
        rev_str[i] = str[len - 1 - i];
    }
    rev_str[len] = wterminator;

    return rev_str;
}

wstrings fossil_wstr_split(const_wstring str, wletter delimiter) {
    if (str == cnullptr) {
        return cnullptr;
    }

    size_t len = wcslen(str);
    wstrings splits = (wstrings)malloc((len + 1) * sizeof(wstring));
    
    if (splits == cnullptr) {
        return cnullptr; // Memory allocation failed
    }

    size_t count = 0;
    const_wstring start = str;
    for (size_t i = 0; i <= len; i++) {
        if (str[i] == delimiter || str[i] == wterminator) {
            size_t sub_len = &str[i] - start;
            splits[count] = (wstring)malloc((sub_len + 1) * sizeof(wletter));
            
            if (splits[count] == cnullptr) {
                fossil_wstr_erase_splits(splits);
                return cnullptr; // Memory allocation failed
            }

            wcsncpy(splits[count], start, sub_len);
            splits[count][sub_len] = wterminator;
            count++;
            start = &str[i + 1];
        }
    }
    splits[count] = cnullptr;

    return splits;
}

wstring fossil_wstr_strdup(const_wstring str) {
    return fossil_wstr_copy(cnullptr, str);
}

wstring fossil_wstr_substr(const_wstring str, size_t start, size_t len) {
    if (str == cnullptr) {
        return cnullptr;
    }

    size_t str_len = wcslen(str);
    if (start >= str_len) {
        return cnullptr; // Start index out of range
    }

    if (start + len > str_len) {
        len = str_len - start;
    }

    wstring substr = (wstring)malloc((len + 1) * sizeof(wletter));
    if (substr == cnullptr) {
        return cnullptr; // Memory allocation failed
    }

    wcsncpy(substr, &str[start], len);
    substr[len] = wterminator;

    return substr;
}

void fossil_wstr_erase_splits(wstrings splits) {
    if (splits == cnullptr) {
        return;
    }

    for (size_t i = 0; splits[i] != cnullptr; i++) {
        free(splits[i]);
    }
    free(splits);
}
