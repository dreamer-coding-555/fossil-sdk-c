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
#include "fossil/string/number.h" // lib source code

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

XTEST(test_fossil_cstr_to_numeric) {
    cstring number = "12345";
    int result = fossil_cstr_to_numeric(number);
    TEST_ASSUME_EQUAL_INT(12345, result);

    number = "invalid";
    result = fossil_cstr_to_numeric(number);
    TEST_ASSUME_EQUAL_INT(0, result);
}

XTEST(test_fossil_cstr_expression_to_numeric) {
    cstring expression = "10 + 20 * 3";
    int result = fossil_cstr_expression_to_numeric(expression);
    TEST_ASSUME_EQUAL_INT(70, result);

    expression = "invalid";
    result = fossil_cstr_expression_to_numeric(expression);
    TEST_ASSUME_EQUAL_INT(0, result);
}

XTEST(test_fossil_cstr_from_numeric) {
    long long number = 12345;
    cstring result = fossil_cstr_from_numeric(number);
    TEST_ASSUME_EQUAL_CSTRING("12345", (cstring)result);
    free(result);
}

// Byte string to numeric conversion functions

XTEST(test_fossil_bstr_to_numeric) {
    const_bstring number = (const_bstring)"12345";
    int result = fossil_bstr_to_numeric(number);
    TEST_ASSUME_EQUAL_INT(12345, result);

    const_bstring invalid = (const_bstring)"invalid";
    result = fossil_bstr_to_numeric(invalid);
    TEST_ASSUME_EQUAL_INT(0, result);
}

XTEST(test_fossil_bstr_expression_to_numeric) {
    const_bstring expression = (const_bstring)"10 + 20 * 3";
    int result = fossil_bstr_expression_to_numeric(expression);
    TEST_ASSUME_EQUAL_INT(70, result);

    const_bstring invalid = (const_bstring)"invalid";
    result = fossil_bstr_expression_to_numeric(invalid);
    TEST_ASSUME_EQUAL_INT(0, result);
}

XTEST(test_fossil_bstr_from_numeric) {
    long long number = 12345;
    bstring result = fossil_bstr_from_numeric(number);
    TEST_ASSUME_EQUAL_BSTRING("12345", result);
    fossil_bstr_erase(result);
}

// Wide string to numeric conversion functions

XTEST(test_fossil_wstr_to_numeric) {
    const_wstring number = L"12345";
    int result = fossil_wstr_to_numeric(number);
    TEST_ASSUME_EQUAL_INT(12345, result);

    const_wstring invalid = L"invalid";
    result = fossil_wstr_to_numeric(invalid);
    TEST_ASSUME_EQUAL_INT(0, result);
}

XTEST(test_fossil_wstr_expression_to_numeric) {
    const_wstring expression = L"10 + 20 * 3";
    int result = fossil_wstr_expression_to_numeric(expression);
    TEST_ASSUME_EQUAL_INT(70, result);

    const_wstring invalid = L"invalid";
    result = fossil_wstr_expression_to_numeric(invalid);
    TEST_ASSUME_EQUAL_INT(0, result);
}

XTEST(test_fossil_wstr_from_numeric) {
    long long number = 12345;
    wstring result = fossil_wstr_from_numeric(number);
    TEST_ASSUME_EQUAL_WSTRING(L"12345", (const_wstring)result);
    free(result);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
XTEST_DEFINE_POOL(fossil_number_group) {
    // C string to numeric conversion functions
    XTEST_RUN_UNIT(test_fossil_cstr_to_numeric);
    XTEST_RUN_UNIT(test_fossil_cstr_expression_to_numeric);
    XTEST_RUN_UNIT(test_fossil_cstr_from_numeric);

    // Byte string to numeric conversion functions
    XTEST_RUN_UNIT(test_fossil_bstr_to_numeric);
    XTEST_RUN_UNIT(test_fossil_bstr_expression_to_numeric);
    XTEST_RUN_UNIT(test_fossil_bstr_from_numeric);

    // Wide string to numeric conversion functions
    XTEST_RUN_UNIT(test_fossil_wstr_to_numeric);
    XTEST_RUN_UNIT(test_fossil_wstr_expression_to_numeric);
    XTEST_RUN_UNIT(test_fossil_wstr_from_numeric);

} // end of function main
