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
#include <stdexcept>
#include <cstring>

namespace fossil {
    class CString {
    public:
        /**
         * C++ constructor for creating a copy of a C string.
         * 
         * @param str The C string to copy.
         * @throws std::bad_alloc if memory allocation fails
         */
        CString(const_cstring str) {
            try {
                cstr_ = fossil_cstr_create(str);
            } catch (const std::bad_alloc& e) {
                // Handle memory allocation failure
                // You can log the error or take appropriate action
                throw e;
            }
        }

        /**
         * C++ default constructor.
         * 
         * Creates an empty CString object.
         */
        CString() : cstr_(cnullptr) {}

        /**
         * C++ move constructor.
         * 
         * Moves the content of the source CString object to the new object.
         * The source CString object will be left in a valid but unspecified state.
         * 
         * @param other The source CString object to move from.
         */
        CString(CString&& other) noexcept : cstr_(other.cstr_) {
            other.cstr_ = cnullptr;
        }

        /**
         * C++ destructor for erasing (freeing) a C string.
         */
        ~CString() {
            fossil_cstr_erase(cstr_);
        }

        /**
         * Get the length of a C string.
         * 
         * @return The length of the C string.
         */
        size_t length() const {
            return fossil_cstr_length(cstr_);
        }

        /**
         * Access a character at the specified index.
         * 
         * @param index The index of the character to access.
         * @return The character at the specified index.
         */
        cletter at(size_t index) const {
            if (index >= length()) {
                throw std::out_of_range("Index out of range");
            }
            return cstr_[index];
        }

        /**
         * Get a pointer to the underlying C string.
         * 
         * @return A pointer to the underlying C string.
         */
        const_cstring c_str() const {
            return cstr_;
        }

        /**
         * Concatenate two CStrings.
         * 
         * @param other The CString to concatenate with.
         * @return A new CString object containing the concatenated strings.
         */
        CString operator+(const CString& other) const {
            size_t len1 = length();
            size_t len2 = other.length();
            size_t newLen = len1 + len2;
            cstring newStr = new cletter[newLen + 1];
            std::memcpy(newStr, cstr_, len1);
            std::memcpy(newStr + len1, other.cstr_, len2);
            newStr[newLen] = '\0';
            return CString(newStr);
        }

        /**
         * Assign the value of another CString.
         * 
         * @param other The CString to assign from.
         * @return The updated CString object.
         */
        CString& operator=(const CString& other) {
            if (this != &other) {
                fossil_cstr_erase(cstr_);
                cstr_ = fossil_cstr_create(other.c_str());
            }
            return *this;
        }

        /**
         * Move the content of another CString.
         * 
         * @param other The CString to move from.
         * @return The updated CString object.
         */
        CString& operator=(CString&& other) noexcept {
            if (this != &other) {
                fossil_cstr_erase(cstr_);
                cstr_ = other.cstr_;
                other.cstr_ = cnullptr;
            }
            return *this;
        }

        /**
         * Compare two CStrings for equality.
         * 
         * @param other The CString to compare with.
         * @return true if the CStrings are equal, false otherwise.
         */
        bool operator==(const CString& other) const {
            return std::strcmp(cstr_, other.cstr_) == 0;
        }

        /**
         * Compare two CStrings for inequality.
         * 
         * @param other The CString to compare with.
         * @return true if the CStrings are not equal, false otherwise.
         */
        bool operator!=(const CString& other) const {
            return std::strcmp(cstr_, other.cstr_) != 0;
        }

        /**
         * Compare two CStrings lexicographically.
         * 
         * @param other The CString to compare with.
         * @return true if this CString is less than the other, false otherwise.
         */
        bool operator<(const CString& other) const {
            return std::strcmp(cstr_, other.cstr_) < 0;
        }

        /**
         * Compare two CStrings lexicographically.
         * 
         * @param other The CString to compare with.
         * @return true if this CString is less than or equal to the other, false otherwise.
         */
        bool operator<=(const CString& other) const {
            return std::strcmp(cstr_, other.cstr_) <= 0;
        }

        /**
         * Compare two CStrings lexicographically.
         * 
         * @param other The CString to compare with.
         * @return true if this CString is greater than the other, false otherwise.
         */
        bool operator>(const CString& other) const {
            return std::strcmp(cstr_, other.cstr_) > 0;
        }

        /**
         * Compare two CStrings lexicographically.
         * 
         * @param other The CString to compare with.
         * @return true if this CString is greater than or equal to the other, false otherwise.
         */
        bool operator>=(const CString& other) const {
            return std::strcmp(cstr_, other.cstr_) >= 0;
        }

    private:
        cstring cstr_;
    };
}

#endif

#endif
