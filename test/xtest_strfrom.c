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
#include "fossil/string/strfrom.h" // lib source code

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

FOSSIL_TEST(test_fossil_cstr_from_int) {
    int num = 12345;
    cstring result = fossil_cstr_from_int(num);
    TEST_ASSUME_EQUAL_CSTRING("12345", result);
    free(result);
}

FOSSIL_TEST(test_fossil_bstr_from_int) {
    int num = 12345;
    bstring result = fossil_bstr_from_int(num);
    TEST_ASSUME_EQUAL_CSTRING("12345", (cstring)result);
    fossil_bstr_erase(result);
}

// Convert double to string

FOSSIL_TEST(test_fossil_cstr_from_double) {
    double num = 123.456;
    cstring result = fossil_cstr_from_double(num);
    TEST_ASSUME_EQUAL_CSTRING("123.456000", result);  // Due to precision issues, we check up to 6 decimal places
    free(result);
}

FOSSIL_TEST(test_fossil_bstr_from_double) {
    double num = 123.456;
    bstring result = fossil_bstr_from_double(num);
    TEST_ASSUME_EQUAL_CSTRING("123.456000", (cstring)result);  // Due to precision issues, we check up to 6 decimal places
    fossil_bstr_erase(result);
}

// Convert long to string

FOSSIL_TEST(test_fossil_cstr_from_long) {
    long num = 1234567890;
    cstring result = fossil_cstr_from_long(num);
    TEST_ASSUME_EQUAL_CSTRING("1234567890", result);
    free(result);
}

FOSSIL_TEST(test_fossil_bstr_from_long) {
    long num = 1234567890;
    bstring result = fossil_bstr_from_long(num);
    TEST_ASSUME_EQUAL_CSTRING("1234567890", (cstring)result);
    fossil_bstr_erase(result);
}

// Convert unsigned long to string

FOSSIL_TEST(test_fossil_cstr_from_ulong) {
    unsigned long num = 1234567890;
    cstring result = fossil_cstr_from_ulong(num);
    TEST_ASSUME_EQUAL_CSTRING("1234567890", result);
    free(result);
}

FOSSIL_TEST(test_fossil_bstr_from_ulong) {
    unsigned long num = 1234567890;
    bstring result = fossil_bstr_from_ulong(num);
    TEST_ASSUME_EQUAL_CSTRING("1234567890", (cstring)result);
    fossil_bstr_erase(result);
}

// Convert long long to string

FOSSIL_TEST(test_fossil_cstr_from_llong) {
    long long num = 1234567890123456789LL;
    cstring result = fossil_cstr_from_llong(num);
    TEST_ASSUME_EQUAL_CSTRING("1234567890123456789", result);
    free(result);
}

FOSSIL_TEST(test_fossil_bstr_from_llong) {
    long long num = 1234567890123456789LL;
    bstring result = fossil_bstr_from_llong(num);
    TEST_ASSUME_EQUAL_CSTRING("1234567890123456789", (cstring)result);
    fossil_bstr_erase(result);
}

// Convert unsigned long long to string

FOSSIL_TEST(test_fossil_cstr_from_ullong) {
    unsigned long long num = 1234567890123456789ULL;
    cstring result = fossil_cstr_from_ullong(num);
    TEST_ASSUME_EQUAL_CSTRING("1234567890123456789", result);
    free(result);
}

FOSSIL_TEST(test_fossil_bstr_from_ullong) {
    unsigned long long num = 1234567890123456789ULL;
    bstring result = fossil_bstr_from_ullong(num);
    TEST_ASSUME_EQUAL_CSTRING("1234567890123456789", (cstring)result);
    fossil_bstr_erase(result);
}

// Convert integer to string

FOSSIL_TEST(test_fossil_wstr_from_int) {
    int num = 12345;
    wstring result = fossil_wstr_from_int(num);
    TEST_ASSUME_EQUAL_WSTRING(L"12345", result);
    free(result);
}

// Convert double to string

FOSSIL_TEST(test_fossil_wstr_from_double) {
    double num = 123.456;
    wstring result = fossil_wstr_from_double(num);
    TEST_ASSUME_EQUAL_WSTRING(L"123.456000", result);  // Due to precision issues, we check up to 6 decimal places
    free(result);
}

// Convert long to string

FOSSIL_TEST(test_fossil_wstr_from_long) {
    long num = 1234567890;
    wstring result = fossil_wstr_from_long(num);
    TEST_ASSUME_EQUAL_WSTRING(L"1234567890", result);
    free(result);
}

// Convert unsigned long to string

FOSSIL_TEST(test_fossil_wstr_from_ulong) {
    unsigned long num = 1234567890;
    wstring result = fossil_wstr_from_ulong(num);
    TEST_ASSUME_EQUAL_WSTRING(L"1234567890", result);
    free(result);
}

// Convert long long to string

FOSSIL_TEST(test_fossil_wstr_from_llong) {
    long long num = 1234567890123456789LL;
    wstring result = fossil_wstr_from_llong(num);
    TEST_ASSUME_EQUAL_WSTRING(L"1234567890123456789", result);
    free(result);
}

// Convert unsigned long long to string

FOSSIL_TEST(test_fossil_wstr_from_ullong) {
    unsigned long long num = 1234567890123456789ULL;
    wstring result = fossil_wstr_from_ullong(num);
    TEST_ASSUME_EQUAL_WSTRING(L"1234567890123456789", result);
    free(result);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(fossil_strfrom_group) {
    // Convert integer to string
    ADD_TEST(test_fossil_cstr_from_int);
    ADD_TEST(test_fossil_bstr_from_int);
    ADD_TEST(test_fossil_wstr_from_int);

    // Convert double to string
    ADD_TEST(test_fossil_cstr_from_double);
    ADD_TEST(test_fossil_bstr_from_double);
    ADD_TEST(test_fossil_wstr_from_double);

    // Convert long to string
    ADD_TEST(test_fossil_cstr_from_long);
    ADD_TEST(test_fossil_bstr_from_long);
    ADD_TEST(test_fossil_wstr_from_long);

    // Convert unsigned long to string
    ADD_TEST(test_fossil_cstr_from_ulong);
    ADD_TEST(test_fossil_bstr_from_ulong);
    ADD_TEST(test_fossil_wstr_from_ulong);

    // Convert long long to string
    ADD_TEST(test_fossil_cstr_from_llong);
    ADD_TEST(test_fossil_bstr_from_llong);
    ADD_TEST(test_fossil_wstr_from_llong);

    // Convert unsigned long long to string
    ADD_TEST(test_fossil_cstr_from_ullong);
    ADD_TEST(test_fossil_bstr_from_ullong);
    ADD_TEST(test_fossil_wstr_from_ullong);
} // end of function main
