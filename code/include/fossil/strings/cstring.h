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
#ifndef FOSSIL_STR_CSTRING_H
#define FOSSIL_STR_CSTRING_H

/**
 * @brief C String Library Functions (ASCII)
 * 
 * This header file defines a set of functions for working with null-terminated C strings (ASCII).
 * The functions provide capabilities for accessing characters, checking properties, and performing conversions.
 * 
 * Usage:
 * 
 * Example:
 * 
 * @code
 * const_cstring str = "example";
 * cletter ch = fossil_cletter_at(str, 2); // Retrieves the character at index 2
 * int16_t is_alpha = fossil_cletter_is_alpha(ch); // Checks if the character is alphabetic
 * @endcode
 */

#include "letter.h"

// classic C string types
typedef cletter * cstring;             // cstring type
typedef cletter ** cstrings;           // cstring array
typedef const cletter * const_cstring; // constent cstrings
typedef cletter ** const_cstrings;     // constent cstring array

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
cstring fossil_cstr_create(const_cstring str);

/**
 * Erase (free) a C string.
 * 
 * Frees the memory allocated for the given C string.
 */
void fossil_cstr_erase(cstring str);

/**
 * Get the length of a C string.
 * 
 * Returns the length of the C string.
 */
size_t fossil_cstr_length(const_cstring str);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
namespace fossil {
    class CString {
    public:
        /**
         * Create a copy of a C string.
         * 
         * @param str The C string to copy.
         * @return A new C string containing a copy of the input string.
         */
        static cstring create(const_cstring str) {
            return fossil_cstr_create(str);
        }

        /**
         * Erase (free) a C string.
         * 
         * @param str The C string to erase.
         */
        static void erase(cstring str) {
            fossil_cstr_erase(str);
        }

        /**
         * Get the length of a C string.
         * 
         * @param str The C string to get the length of.
         * @return The length of the C string.
         */
        static size_t length(const_cstring str) {
            return fossil_cstr_length(str);
        }
    };
}

#endif

#endif
