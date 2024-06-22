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
#ifndef FOSSIL_COMMON_COMMON_H
#define FOSSIL_COMMON_COMMON_H

#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#ifdef __cplusplus
extern "C"
{
#endif

// null type declaration for compatibility with C11, C23, and C++
#ifndef FOSSIL_CNULL

#if __cplusplus >= 201103L || (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L)
/**
 * @brief Definition for xnull pointers in C++11 and later or C23 and later.
 *
 * In C++11 or later, `xnullptr` is a keyword representing a xnull pointer constant.
 * In C23 or later, `_xnullptr` is recognized in the same way as C++.
 */
    #define cnull    nullptr
    #define cnullptr nullptr
#else
    #if defined(_WIN64) || defined(_WIN32)
/**
 * @brief Definition for xnull pointers on Windows systems.
 *
 * For Windows (both 32-bit and 64-bit), we define `xnull` and `xnullptr` as 0.
 */
    #define cnull    0
    #define cnullptr 0
#else
/**
 * @brief Definition for xnull pointers on POSIX systems, macOS, and embedded systems.
 *
 * For POSIX, macOS, and embedded systems, we define `xnull` and `xnullptr` as a void pointer to 0.
 */
    #define cnull    (void *)(0)
    #define cnullptr (void *)(0)
    #endif
#endif
#define cterminator '\0'
#define wterminator L'\0'
#define cterm '\0'
#define wterm L'\0'
#endif

#define FOSSIL_STATIC_CAST(type, value) ((type)(value))

// flag type declarations for Fossil Logic flag types
#ifndef FOSSIL_BOOL
/* 
 * Feature control types: Enable, Disable, Auto
 * Usage: cfeature myFeature = FOSSIL_ENABLE;
 */
typedef enum {
    FOSSIL_ENABLE,
    FOSSIL_DISABLE,
    FOSSIL_AUTO
} fossil_feature_t;

/* 
 * Boolean types: True or False
 * Usage: fossil_bool_t flag = fossil_TRUE;
 */
typedef enum {
    FOSSIL_TRUE,
    FOSSIL_FALSE
} fossil_bool_t;

/* 
 * Switch types: On or Off
 * Usage: cswitch power = fossil_ON;
 */
typedef enum {
    FOSSIL_ON,
    FOSSIL_OFF
} fossil_switch_t;

/* 
 * Status types: Success or Failure
 * Usage: return FOSSIL_SUCCESS;
 */
enum {
    FOSSIL_SUCCESS,
    FOSSIL_FAILURE,
    FOSSIL_ERROR = -1
};
#endif

/**
 * Get the version number of the library.
 *
 * @return A constant string representing the library's version number.
 */
inline const char* fossil_version(void) {
    return "1.0.2";
}

/**
 * Get the codename associated with the library.
 *
 * @return A constant string representing the library's codename.
 */
inline const char* fossil_codename(void) {
    return "Paleozoic Dimetrodon";
}

/**
 * Return a greeting message.
 *
 * @return A constant string containing a simple greeting message.
 */
inline const char* fossil_hello(void) {
    return "Hello, World!";
}

static inline char* _custom_fossil_strdup(const char* str) {
    if (!str) return cnull; // Handle NULL pointer gracefully

    size_t len = 0;
    while (str[len] != cterminator) len++; // Calculate the length of the string

    char* dup = (char*)malloc((len + 1) * sizeof(char)); // Allocate memory for the duplicate string
    if (!dup) return cnull; // Check if malloc failed

    for (size_t i = 0; i < len; i++) {
        dup[i] = str[i]; // Copy each character from the original string to the duplicate
    }
    dup[len] = cterminator; // Add null terminator to the end of the duplicate string

    return dup;
}

// Custom implementation of strndup
static inline char* _custom_fossil_strndup(const char* str, size_t len) {
    char* copy = (char*)malloc(len + 1);
    if (copy) {
        strncpy(copy, str, len);
        copy[len] = cterminator;
    }
    return copy;
}

#ifdef __cplusplus
}
#endif

#endif
