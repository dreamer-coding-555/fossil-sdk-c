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
#include "fossil/string/bstring.h" // lib source code
#include "fossil/string/cstring.h" // for the cstring types

#include <fossil/unittest.h>   // basic test tools
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

FOSSIL_TEST(test_fossil_bstr_create) {
    const_bstring test_str = (const_bstring)"Hello, World!";
    bstring result = fossil_bstr_create(test_str);

    ASSUME_NOT_CNULL(result);
    TEST_ASSUME_EQUAL_CSTRING((const_cstring)test_str, (const_cstring)result);

    fossil_bstr_erase(result);
}

FOSSIL_TEST(test_fossil_bstr_erase) {
    const_bstring test_str = (const_bstring)"Hello, World!";
    bstring str = fossil_bstr_create(test_str);
    fossil_bstr_erase(str);

    ASSUME_ITS_CNULL(str);
}

FOSSIL_TEST(test_fossil_bstr_length) {
    const_bstring test_str = (const_bstring)"Hello, World!";
    size_t len = fossil_bstr_length(test_str);

    ASSUME_ITS_EQUAL_I32(fossil_bstr_length(test_str), len);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(fossil_bstring_group) {
    ADD_TEST(test_fossil_bstr_create);
    ADD_TEST(test_fossil_bstr_erase);
    ADD_TEST(test_fossil_bstr_length);
} // end of function main
