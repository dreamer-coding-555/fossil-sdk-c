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
#ifndef FOSSIL_STR_BSTRING_H
#define FOSSIL_STR_BSTRING_H

/**
 * @brief Byte String Library Functions
 * 
 * This header file defines a set of functions for working with byte strings. The functions
 * provide capabilities for creating, erasing, and measuring the length of byte strings.
 * 
 * Usage:
 * 
 * Example:
 * 
 * @code
 * const_bstring original = (const_bstring)"example";
 * bstring copy = fossil_bstr_create(original);  // Creates a copy of the byte string
 * size_t length = fossil_bstr_length(copy);  // Gets the length of the byte string
 * fossil_bstr_erase(copy);  // Frees the memory allocated for the byte string
 * @endcode
 */

#include "string/letter.h"

// byte string types
typedef bletter * bstring;               // byte string type
typedef bletter ** bstrings;             // byte string array
typedef const bletter * const_bstring;   // constent byte strings
typedef const bletter ** const_bstrings; // constent byte string array

#ifdef __cplusplus
extern "C"
{
#endif

// =================================================================
// String and Strings Management Functions
// =================================================================

/**
 * Byte string library functions
 */

/**
 * Create a copy of a byte string.
 * 
 * Returns a new byte string containing a copy of the input byte string.
 */
bstring fossil_bstr_create(const_bstring str);

/**
 * Erase (free) a byte string.
 * 
 * Frees the memory allocated for the given byte string.
 */
void fossil_bstr_erase(bstring str);

/**
 * Get the length of a byte string.
 * 
 * Returns the length of the byte string.
 */
size_t fossil_bstr_length(const_bstring str);

#ifdef __cplusplus
}
#endif

#endif
