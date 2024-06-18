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

#include "letter.h"

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

#ifdef __cplusplus
namespace fossil {
    
    class WString {
    public:
        WString() : _str(nullptr) {} // Default constructor
        
        /**
         * @brief Constructor with parameter
         * 
         * Creates a WString object with a copy of the input string.
         * 
         * @param str The input string
         */
        WString(const_wstring str) : _str(fossil_wstr_create(str)) {} 
        
        /**
         * @brief Move constructor
         * 
         * Moves the content of another WString object to this object.
         * 
         * @param other The other WString object to move from
         */
        WString(WString&& other) noexcept : _str(other._str) {
            other._str = nullptr;
        } 
        
        /**
         * @brief Destructor
         * 
         * Frees the memory allocated for the WString object.
         */
        ~WString() {
            fossil_wstr_erase(_str);
        }
        
        /**
         * @brief Get the length of the string
         * 
         * Returns the length of the string.
         * 
         * @return The length of the string
         */
        size_t length() const {
            return fossil_wstr_length(_str);
        }
        
        /**
         * @brief Get the character at the specified index
         * 
         * Returns the character at the specified index.
         * 
         * @param index The index of the character
         * @return The character at the specified index
         */
        const_wletter at(size_t index) const {
            return fossil_wletter_at(_str, index);
        }
        
        /**
         * @brief Get the C-style string representation
         * 
         * Returns the C-style string representation of the WString object.
         * 
         * @return The C-style string representation
         */
        const_wstring c_str() const {
            return _str;
        }

    private:
        const_wstring _str;
    };
    
}

#endif

#endif
