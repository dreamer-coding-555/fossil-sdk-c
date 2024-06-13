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
#include "fossil/string/manip.h" // lib source code

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

FOSSIL_TEST(test_fossil_cstr_compare) {
    const_cstring str1 = "Hello";
    const_cstring str2 = "World";
    int result = fossil_cstr_compare(str1, str2);
    TEST_ASSUME_TRUE(result < 0);

    result = fossil_cstr_compare(str2, str1);
    TEST_ASSUME_TRUE(result > 0);

    result = fossil_cstr_compare(str1, str1);
    ASSUME_ITS_EQUAL_I32(0, result);
}

FOSSIL_TEST(test_fossil_cstr_copy) {
    cstring dest = malloc(10);
    const_cstring src = "Hello";
    fossil_cstr_copy(dest, src);
    TEST_ASSUME_EQUAL_CSTRING(src, dest);
    free(dest);
}

FOSSIL_TEST(test_fossil_cstr_concat) {
    cstring dest = malloc(20);
    const_cstring src = " World!";
    const_cstring base = "Hello";
    fossil_cstr_copy(dest, base);
    fossil_cstr_concat(dest, src);
    TEST_ASSUME_EQUAL_CSTRING("Hello World!", dest);
    free(dest);
}

FOSSIL_TEST(test_fossil_cstr_find) {
    const_cstring str = "Hello, World!";
    const_cstring result = fossil_cstr_find(str, ',');
    TEST_ASSUME_EQUAL_CSTRING(", World!", result);
}

FOSSIL_TEST(test_fossil_cstr_reverse) {
    const_cstring str = "Hello";
    const_cstring result = fossil_cstr_reverse(str);
    TEST_ASSUME_EQUAL_CSTRING("olleH", result);
}

FOSSIL_TEST(test_fossil_cstr_split) {
    const_cstring str = "Hello,World,!";
    cstrings result = fossil_cstr_split(str, ',');
    TEST_ASSUME_EQUAL_CSTRING("Hello", result[0]);
    TEST_ASSUME_EQUAL_CSTRING("World", result[1]);
    TEST_ASSUME_EQUAL_CSTRING("!", result[2]);
    free(result[0]);
    free(result[1]);
    free(result[2]);
    free(result);
}

FOSSIL_TEST(test_fossil_cstr_strdup) {
    const_cstring str = "Hello";
    cstring result = fossil_cstr_strdup(str);
    TEST_ASSUME_EQUAL_CSTRING("Hello", result);
    free(result);
}

// Byte string library functions

FOSSIL_TEST(test_fossil_bstr_compare) {
    const_bstring str1 = (const_bstring)"Hello";
    const_bstring str2 = (const_bstring)"World";
    int result = fossil_bstr_compare(str1, str2);
    TEST_ASSUME_TRUE(result < 0);

    result = fossil_bstr_compare(str2, str1);
    TEST_ASSUME_TRUE(result > 0);

    result = fossil_bstr_compare(str1, str1);
    ASSUME_ITS_EQUAL_I32(0, result);
}

FOSSIL_TEST(test_fossil_bstr_copy) {
    bstring dest = malloc(10);
    const_bstring src = (const_bstring)"Hello";
    fossil_bstr_copy(dest, src);
    TEST_ASSUME_EQUAL_CSTRING("Hello", (cstring)dest);
    fossil_bstr_erase(dest);
}

FOSSIL_TEST(test_fossil_bstr_concat) {
    bstring dest = malloc(20);
    const_bstring src = (const_bstring)" World!";
    const_bstring base = (const_bstring)"Hello";
    fossil_bstr_copy(dest, base);
    fossil_bstr_concat(dest, src);
    TEST_ASSUME_EQUAL_CSTRING("Hello World!", (cstring)dest);
    fossil_bstr_erase(dest);
}

FOSSIL_TEST(test_fossil_bstr_find) {
    const_bstring str = (const_bstring)"Hello, World!";
    const_bstring result = fossil_bstr_find(str, ',');
    TEST_ASSUME_EQUAL_CSTRING(", World!", (cstring)result);
}

FOSSIL_TEST(test_fossil_bstr_split) {
    const_bstring str = (const_bstring)"Hello,World,!";
    bstrings result = fossil_bstr_split(str, ',');
    TEST_ASSUME_EQUAL_CSTRING("Hello", (cstring)result[0]);
    TEST_ASSUME_EQUAL_CSTRING("World", (cstring)result[1]);
    TEST_ASSUME_EQUAL_CSTRING("!", (cstring)result[2]);
    fossil_bstr_erase(result[0]);
    fossil_bstr_erase(result[1]);
    fossil_bstr_erase(result[2]);
    free(result);
}

FOSSIL_TEST(test_fossil_bstr_strdup) {
    const_bstring str = (const_bstring)"Hello";
    bstring result = fossil_bstr_strdup(str);
    TEST_ASSUME_EQUAL_CSTRING("Hello", (cstring)result);
    fossil_bstr_erase(result);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(fossil_manip_group) {
    // C string library functions
    ADD_TEST(test_fossil_cstr_compare);
    ADD_TEST(test_fossil_cstr_copy);
    ADD_TEST(test_fossil_cstr_concat);
    ADD_TEST(test_fossil_cstr_find);
    ADD_TEST(test_fossil_cstr_reverse);
    ADD_TEST(test_fossil_cstr_split);
    ADD_TEST(test_fossil_cstr_strdup);

    // Byte string library functions
    ADD_TEST(test_fossil_bstr_compare);
    ADD_TEST(test_fossil_bstr_copy);
    ADD_TEST(test_fossil_bstr_concat);
    ADD_TEST(test_fossil_bstr_find);
    ADD_TEST(test_fossil_bstr_split);
    ADD_TEST(test_fossil_bstr_strdup);
} // end of function main
