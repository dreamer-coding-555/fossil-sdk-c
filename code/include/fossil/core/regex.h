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
#ifndef FOSSIl_CORE_REGEX_H
#define FOSSIl_CORE_REGEX_H

/**
 * @brief Regular Expression Library
 * 
 * This library provides functions for working with regular expressions (regex) in C.
 * It includes functions to create a new regex pattern instance, match a text against
 * a compiled regex pattern, reset the pattern instance, match and extract substrings,
 * and get the matched substring from the last successful match.
 * 
 * Key Features:
 * - Compile and match regular expressions against text.
 * - Extract matched substrings from text.
 * - Reset regex pattern instances for reuse.
 * 
 * Usage:
 * 
 * 1. Create a regex pattern:
 *    @code
 *    fossil_regex_t pattern;
 *    if (fossil_regex_create(&pattern, "\\d{3}-\\d{2}-\\d{4}") != 0) {
 *        // Handle error
 *    }
 *    @endcode
 * 
 * 2. Match a text against the compiled pattern:
 *    @code
 *    const char *text = "123-45-6789";
 *    if (fossil_regex_match(&pattern, text) == 0) {
 *        // Text matches the regex pattern
 *    }
 *    @endcode
 * 
 * 3. Extract matched substrings:
 *    @code
 *    const char *matched_substring = fossil_regex_match_and_extract(&pattern, text);
 *    if (matched_substring != NULL) {
 *        // Use the matched substring
 *    }
 *    @endcode
 * 
 * 4. Reset the regex pattern instance:
 *    @code
 *    fossil_regex_reset(&pattern);
 *    @endcode
 * 
 */

#include "fossil/common/common.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <pthread.h>
#endif

// Enumeration for regex operation statuses
enum {
    FOSSIL_REGEX_STATUS_SUCCESS = 0,  // Operation succeeded
    FOSSIL_REGEX_STATUS_FAILURE = -1  // Operation failed
};

// Enumeration for regex limits
enum {
    FOSSIL_REGEX_LIMIT_PATTERN_LENGTH = 255  // Maximum length of regex pattern
};

// Structure to hold regex pattern and matched substring, with optional threading support
typedef struct {
    const char *pattern;                // Pointer to the regex pattern
    const char *matched_substring;      // Pointer to the matched substring

    #ifdef _WIN32
        // Mutex for Windows to ensure thread-safe operations
        HANDLE mutex;
    #else
        // Mutex for POSIX to ensure thread-safe operations
        pthread_mutex_t mutex;
    #endif
} fossil_regex_t;

#ifdef __cplusplus
extern "C"
{
#endif

// =================================================================
// Create and erase
// =================================================================

/**
 * Create a new regex pattern instance.
 *
 * @param preg    Pointer to the fossil_regex_t structure to store the created regex pattern.
 * @param pattern The regex pattern to be compiled.
 * @return        0 on success, non-zero on failure.
 */
int32_t fossil_regex_create(fossil_regex_t *preg, const char*  pattern);

/**
 * Match a text against a compiled regex pattern.
 *
 * @param preg Pointer to the fossil_regex_t structure containing the compiled pattern.
 * @param text The text to be matched against the regex pattern.
 * @return     0 if there is a match, non-zero otherwise.
 */
int32_t fossil_regex_match(fossil_regex_t *preg, const char*  text);

// =================================================================
// Available Functions
// =================================================================

/**
 * Reset the regex pattern instance to the initial state.
 *
 * @param preg Pointer to the fossil_regex_t structure.
 */
void fossil_regex_reset(fossil_regex_t *preg);

/**
 * Match a text against a compiled regex pattern and extract the matched substring.
 *
 * @param preg Pointer to the fossil_regex_t structure containing the compiled pattern.
 * @param text The text to be matched against the regex pattern.
 * @return     A constant string containing the matched substring or NULL if no match.
 */
const char *fossil_regex_match_and_extract(fossil_regex_t *preg, const char*  text);

/**
 * Get the matched substring from the last successful match.
 *
 * @param preg Pointer to the fossil_regex_t structure.
 * @return     A constant string containing the matched substring or NULL if no match.
 */
const char *fossil_regex_get_matched_substring(fossil_regex_t *preg);

#ifdef __cplusplus
}
#endif

#endif
