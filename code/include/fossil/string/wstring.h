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
#ifndef FOSSIL_STR_WSTRING_H
#define FOSSIL_STR_WSTRING_H

/**
 * @brief Wide C String Library Functions
 * 
 * This header file defines a set of functions for working with null-terminated wide C strings.
 * The functions provide capabilities for accessing wide characters, checking properties, and performing conversions.
 * 
 * Usage:
 * 
 * Example:
 * 
 * @code
 * const_wstring wstr = L"example";
 * wletter wch = fossil_wletter_at(wstr, 2); // Retrieves the wide character at index 2
 * int16_t is_alpha = fossil_wletter_is_alpha(wch); // Checks if the wide character is alphabetic
 * @endcode
 */

#include "string/letter.h"

// classic wysiwyg C string types
typedef wletter * wstring;             // cstring type
typedef wletter ** wstrings;           // cstring array
typedef const_wletter * const_wstring; // constent wstrings
typedef wletter ** const_wstrings;     // constent wstring array

#ifdef __cplusplus
extern "C"
{
#endif

// =================================================================
// String and Strings Management Functions
// =================================================================

/**
 * String library functions for classic C strings
 */

/**
 * Create a copy of a C string.
 * 
 * Returns a new C string containing a copy of the input string.
 */
wstring fossil_wstr_create(const_wstring str);

/**
 * Erase (free) a C string.
 * 
 * Frees the memory allocated for the given C string.
 */
void fossil_wstr_erase(wstring str);

/**
 * Get the length of a C string.
 * 
 * Returns the length of the C string.
 */
size_t fossil_wstr_length(const_wstring str);

#ifdef __cplusplus
}
#endif

#endif
