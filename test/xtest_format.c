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
#include "fossil/string/format.h" // lib source code

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

FOSSIL_TEST(test_fossil_cstr_format) {
    cstring result = fossil_cstr_format("%s %d", "Hello", 123);
    TEST_ASSUME_EQUAL_CSTRING("Hello 123", result);
    free(result);
}

FOSSIL_TEST(test_fossil_bstr_format) {
    bstring result = fossil_bstr_format((bletter *)("%s %d"), "Hello", 123);
    TEST_ASSUME_EQUAL_CSTRING("Hello 123", (cstring)result);
    fossil_bstr_erase(result);
}

FOSSIL_TEST(test_fossil_cstr_format_phone) {
    cstring result = fossil_cstr_format_phone("1234567890");
    TEST_ASSUME_EQUAL_CSTRING("(123) 456-7890", result);
    free(result);
}

FOSSIL_TEST(test_fossil_bstr_format_phone) {
    bstring result = fossil_bstr_format_phone((const_bstring)"1234567890");
    TEST_ASSUME_EQUAL_CSTRING("(123) 456-7890", (cstring)result);
    fossil_bstr_erase(result);
}

FOSSIL_TEST(test_fossil_cstr_format_date) {
    cstring result = fossil_cstr_format_date("20220401");
    TEST_ASSUME_EQUAL_CSTRING("04/01/2022", result);
    free(result);
}

FOSSIL_TEST(test_fossil_bstr_format_date) {
    bstring result = fossil_bstr_format_date((const_bstring)"20220401");
    TEST_ASSUME_EQUAL_CSTRING("04/01/2022", (cstring)result);
    fossil_bstr_erase(result);
}

FOSSIL_TEST(test_fossil_cstr_format_time) {
    cstring result = fossil_cstr_format_time("1430");
    TEST_ASSUME_EQUAL_CSTRING("14:30", result);
    free(result);
}

FOSSIL_TEST(test_fossil_bstr_format_time) {
    bstring result = fossil_bstr_format_time((const_bstring)"1430");
    TEST_ASSUME_EQUAL_CSTRING("14:30", (cstring)result);
    fossil_bstr_erase(result);
}

FOSSIL_TEST(test_fossil_cstr_format_currency) {
    cstring result = fossil_cstr_format_currency("123456");
    TEST_ASSUME_EQUAL_CSTRING("$123,456.00", result);
    free(result);
}

FOSSIL_TEST(test_fossil_bstr_format_currency) {
    bstring result = fossil_bstr_format_currency((const_bstring)"123456");
    TEST_ASSUME_EQUAL_CSTRING("$123,456.00", (cstring)result);
    fossil_bstr_erase(result);
}

FOSSIL_TEST(test_fossil_cstr_format_percentage) {
    cstring result = fossil_cstr_format_percentage("0.1234");
    TEST_ASSUME_EQUAL_CSTRING("12.34%", result);
    free(result);
}

FOSSIL_TEST(test_fossil_bstr_format_percentage) {
    bstring result = fossil_bstr_format_percentage((const_bstring)"0.1234");
    TEST_ASSUME_EQUAL_CSTRING("12.34%", (cstring)result);
    fossil_bstr_erase(result);
}

FOSSIL_TEST(test_fossil_cstr_format_postal_code) {
    cstring result = fossil_cstr_format_postal_code("123456789");
    TEST_ASSUME_EQUAL_CSTRING("12345-6789", result);
    free(result);
}

FOSSIL_TEST(test_fossil_bstr_format_postal_code) {
    bstring result = fossil_bstr_format_postal_code((const_bstring)"123456789");
    TEST_ASSUME_EQUAL_CSTRING("12345-6789", (cstring)result);
    fossil_bstr_erase(result);
}

FOSSIL_TEST(test_fossil_cstr_format_ssn) {
    cstring result = fossil_cstr_format_ssn("123456789");
    TEST_ASSUME_EQUAL_CSTRING("123-45-6789", result);
    free(result);
}

FOSSIL_TEST(test_fossil_bstr_format_ssn) {
    bstring result = fossil_bstr_format_ssn((const_bstring)"123456789");
    TEST_ASSUME_EQUAL_CSTRING("123-45-6789", (cstring)result);
    fossil_bstr_erase(result);
}

// Test cases for wide string functions
FOSSIL_TEST(test_fossil_wstr_format) {
    wstring result = fossil_wstr_format(L"%ls %d", L"Hello", 123);
    TEST_ASSUME_EQUAL_WSTRING(L"Hello 123", result);
    free(result);
}

FOSSIL_TEST(test_fossil_wstr_format_phone) {
    wstring result = fossil_wstr_format_phone(L"1234567890");
    TEST_ASSUME_EQUAL_WSTRING(L"(123) 456-7890", result);
    free(result);
}

FOSSIL_TEST(test_fossil_wstr_format_date) {
    wstring result = fossil_wstr_format_date(L"20220401");
    TEST_ASSUME_EQUAL_WSTRING(L"04/01/2022", result);
    free(result);
}

FOSSIL_TEST(test_fossil_wstr_format_time) {
    wstring result = fossil_wstr_format_time(L"1430");
    TEST_ASSUME_EQUAL_WSTRING(L"14:30", result);
    free(result);
}

FOSSIL_TEST(test_fossil_wstr_format_currency) {
    wstring result = fossil_wstr_format_currency(L"123456");
    TEST_ASSUME_EQUAL_WSTRING(L"$123,456.00", result);
    free(result);
}

FOSSIL_TEST(test_fossil_wstr_format_percentage) {
    wstring result = fossil_wstr_format_percentage(L"0.1234");
    TEST_ASSUME_EQUAL_WSTRING(L"12.34%", result);
    free(result);
}

FOSSIL_TEST(test_fossil_wstr_format_postal_code) {
    wstring result = fossil_wstr_format_postal_code(L"123456789");
    TEST_ASSUME_EQUAL_WSTRING(L"12345-6789", result);
    free(result);
}

FOSSIL_TEST(test_fossil_wstr_format_ssn) {
    wstring result = fossil_wstr_format_ssn(L"123456789");
    TEST_ASSUME_EQUAL_WSTRING(L"123-45-6789", result);
    free(result);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(fossil_format_group) {
    ADD_TEST(test_fossil_cstr_format);
    ADD_TEST(test_fossil_bstr_format);
    ADD_TEST(test_fossil_cstr_format_phone);
    ADD_TEST(test_fossil_bstr_format_phone);
    ADD_TEST(test_fossil_cstr_format_date);
    ADD_TEST(test_fossil_bstr_format_date);
    ADD_TEST(test_fossil_cstr_format_time);
    ADD_TEST(test_fossil_bstr_format_time);
    ADD_TEST(test_fossil_cstr_format_currency);
    ADD_TEST(test_fossil_bstr_format_currency);
    ADD_TEST(test_fossil_cstr_format_percentage);
    ADD_TEST(test_fossil_bstr_format_percentage);
    ADD_TEST(test_fossil_cstr_format_postal_code);
    ADD_TEST(test_fossil_bstr_format_postal_code);
    ADD_TEST(test_fossil_cstr_format_ssn);
    ADD_TEST(test_fossil_bstr_format_ssn);
    ADD_TEST(test_fossil_wstr_format);
    ADD_TEST(test_fossil_wstr_format_phone);
    ADD_TEST(test_fossil_wstr_format_date);
    ADD_TEST(test_fossil_wstr_format_time);
    ADD_TEST(test_fossil_wstr_format_currency);
    ADD_TEST(test_fossil_wstr_format_percentage);
    ADD_TEST(test_fossil_wstr_format_postal_code);
    ADD_TEST(test_fossil_wstr_format_ssn);
} // end of function main
