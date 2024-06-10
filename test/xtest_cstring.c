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
#include "fossil/string/cstring.h" // lib source code

#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassume.h> // extra asserts

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilites
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

// placeholder

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

XTEST(test_fossil_cstr_create) {
    const_cstring test_str = "Hello, World!";
    cstring result = fossil_cstr_create(test_str);

    TEST_ASSUME_NOT_CNULLPTR(result);
    TEST_ASSUME_EQUAL_CSTRING(test_str, result);

    fossil_cstr_erase(result);
}

XTEST(test_fossil_cstr_erase) {
    const_cstring test_str = "Hello, World!";
    cstring str = fossil_cstr_create(test_str);
    fossil_cstr_erase(str);

    TEST_ASSUME_CNULLPTR(str);
}

XTEST(test_fossil_cstr_length) {
    const_cstring test_str = "Hello, World!";
    size_t len = fossil_cstr_length(test_str);

    TEST_ASSUME_EQUAL_INT(strlen(test_str), len);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
XTEST_DEFINE_POOL(fossil_cstring_group) {
    XTEST_RUN_UNIT(test_fossil_cstr_create);
    XTEST_RUN_UNIT(test_fossil_cstr_erase);
    XTEST_RUN_UNIT(test_fossil_cstr_length);
} // end of function main
