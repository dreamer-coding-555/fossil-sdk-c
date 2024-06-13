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
#include "fossil/string/strto.h" // lib source code

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

FOSSIL_TEST(test_fossil_cstr_to_int) {
    const_cstring str1 = "12345";
    const_cstring str2 = "-6789";
    const_cstring str3 = "123abc";

    int result1 = fossil_cstr_to_int(str1);
    int result2 = fossil_cstr_to_int(str2);
    int result3 = fossil_cstr_to_int(str3);

    ASSUME_ITS_EQUAL_I32(12345, result1);
    ASSUME_ITS_EQUAL_I32(-6789, result2);
    ASSUME_ITS_EQUAL_I32(123, result3);  // atoi stops at first non-numeric character
}

FOSSIL_TEST(test_fossil_bstr_to_int) {
    const_bstring str1 = (bstring)"12345";
    const_bstring str2 = (bstring)"-6789";
    const_bstring str3 = (bstring)"123abc";

    int result1 = fossil_bstr_to_int(str1);
    int result2 = fossil_bstr_to_int(str2);
    int result3 = fossil_bstr_to_int(str3);

    ASSUME_ITS_EQUAL_I32(12345, result1);
    ASSUME_ITS_EQUAL_I32(-6789, result2);
    ASSUME_ITS_EQUAL_I32(123, result3);  // atoi stops at first non-numeric character
}

FOSSIL_TEST(test_fossil_cstr_to_double) {
    const_cstring str1 = "123.45";
    const_cstring str2 = "-67.89";
    const_cstring str3 = "123.abc";

    double result1 = fossil_cstr_to_double(str1);
    double result2 = fossil_cstr_to_double(str2);
    double result3 = fossil_cstr_to_double(str3);

    ASSUME_ITS_EQUAL_F64(123.45, result1);
    ASSUME_ITS_EQUAL_F64(-67.89, result2);
    ASSUME_ITS_EQUAL_F64(123.0, result3);  // atof stops at first non-numeric character
}

FOSSIL_TEST(test_fossil_bstr_to_double) {
    const_bstring str1 = (bstring)"123.45";
    const_bstring str2 = (bstring)"-67.89";
    const_bstring str3 = (bstring)"123.abc";

    double result1 = fossil_bstr_to_double(str1);
    double result2 = fossil_bstr_to_double(str2);
    double result3 = fossil_bstr_to_double(str3);

    ASSUME_ITS_EQUAL_F64(123.45, result1);
    ASSUME_ITS_EQUAL_F64(-67.89, result2);
    ASSUME_ITS_EQUAL_F64(123.0, result3);  // atof stops at first non-numeric character
}

FOSSIL_TEST(test_fossil_cstr_to_long) {
    const_cstring str1 = "1234567890";
    const_cstring str2 = "-9876543210";
    const_cstring str3 = "123abc";

    long result1 = fossil_cstr_to_long(str1);
    long result2 = fossil_cstr_to_long(str2);
    long result3 = fossil_cstr_to_long(str3);

    ASSUME_ITS_EQUAL_I32(1234567890, result1);
    ASSUME_ITS_EQUAL_I32(-9876543210, result2);
    ASSUME_ITS_EQUAL_I32(123, result3);  // atol stops at first non-numeric character
}

FOSSIL_TEST(test_fossil_bstr_to_long) {
    const_bstring str1 = (bstring)"1234567890";
    const_bstring str2 = (bstring)"-9876543210";
    const_bstring str3 = (bstring)"123abc";

    long result1 = fossil_bstr_to_long(str1);
    long result2 = fossil_bstr_to_long(str2);
    long result3 = fossil_bstr_to_long(str3);

    ASSUME_ITS_EQUAL_I32(1234567890, result1);
    ASSUME_ITS_EQUAL_I32(-9876543210, result2);
    ASSUME_ITS_EQUAL_I32(123, result3);  // atol stops at first non-numeric character
}

FOSSIL_TEST(test_fossil_cstr_to_ulong) {
    const_cstring str1 = "1234567890";
    const_cstring str2 = "4294967295";
    const_cstring str3 = "123abc";

    unsigned long result1 = fossil_cstr_to_ulong(str1);
    unsigned long result2 = fossil_cstr_to_ulong(str2);
    unsigned long result3 = fossil_cstr_to_ulong(str3);

    ASSUME_ITS_EQUAL_U32(1234567890, result1);
    ASSUME_ITS_EQUAL_U32(4294967295, result2);
    ASSUME_ITS_EQUAL_U32(123, result3);  // strtoul stops at first non-numeric character
}

FOSSIL_TEST(test_fossil_bstr_to_ulong) {
    const_bstring str1 = (bstring)"1234567890";
    const_bstring str2 = (bstring)"4294967295";
    const_bstring str3 = (bstring)"123abc";

    unsigned long result1 = fossil_bstr_to_ulong(str1);
    unsigned long result2 = fossil_bstr_to_ulong(str2);
    unsigned long result3 = fossil_bstr_to_ulong(str3);

    ASSUME_ITS_EQUAL_U32(1234567890, result1);
    ASSUME_ITS_EQUAL_U32(4294967295, result2);
    ASSUME_ITS_EQUAL_U32(123, result3);  // strtoul stops at first non-numeric character
}

FOSSIL_TEST(test_fossil_cstr_to_llong) {
    const_cstring str1 = "1234567890123456789";
    const_cstring str3 = "123abc";

    long long result1 = fossil_cstr_to_llong(str1);
    long long result3 = fossil_cstr_to_llong(str3);

    ASSUME_ITS_EQUAL_I32(1234567890123456789LL, result1);
    ASSUME_ITS_EQUAL_I32(123, result3);  // atoll stops at first non-numeric character
}

FOSSIL_TEST(test_fossil_bstr_to_llong) {
    const_bstring str1 = (bstring)"1234567890123456789";
    const_bstring str3 = (bstring)"123abc";

    long long result1 = fossil_bstr_to_llong(str1);
    long long result3 = fossil_bstr_to_llong(str3);

    ASSUME_ITS_EQUAL_I32(1234567890123456789LL, result1);
    ASSUME_ITS_EQUAL_I32(123, result3);  // atoll stops at first non-numeric character
}

FOSSIL_TEST(test_fossil_cstr_to_ullong) {
    const_cstring str1 = "12345678901234567890";
    const_cstring str2 = "18446744073709551615";
    const_cstring str3 = "123abc";

    unsigned long long result1 = fossil_cstr_to_ullong(str1);
    unsigned long long result2 = fossil_cstr_to_ullong(str2);
    unsigned long long result3 = fossil_cstr_to_ullong(str3);

    ASSUME_ITS_EQUAL_U3264(12345678901234567890ULL, result1);
    ASSUME_ITS_EQUAL_U3264(18446744073709551615ULL, result2);
    ASSUME_ITS_EQUAL_U3264(123, result3);  // strtoull stops at first non-numeric character
}

FOSSIL_TEST(test_fossil_bstr_to_ullong) {
    const_bstring str1 = (bstring)"12345678901234567890";
    const_bstring str2 = (bstring)"18446744073709551615";
    const_bstring str3 = (bstring)"123abc";

    unsigned long long result1 = fossil_bstr_to_ullong(str1);
    unsigned long long result2 = fossil_bstr_to_ullong(str2);
    unsigned long long result3 = fossil_bstr_to_ullong(str3);

    ASSUME_ITS_EQUAL_U3264(12345678901234567890ULL, result1);
    ASSUME_ITS_EQUAL_U3264(18446744073709551615ULL, result2);
    ASSUME_ITS_EQUAL_U3264(123, result3);  // strtoull stops at first non-numeric character
}

FOSSIL_TEST(test_fossil_wstr_to_int) {
    const_wstring str1 = L"12345";
    const_wstring str2 = L"-6789";
    const_wstring str3 = L"123abc";

    int result1 = fossil_wstr_to_int(str1);
    int result2 = fossil_wstr_to_int(str2);
    int result3 = fossil_wstr_to_int(str3);

    ASSUME_ITS_EQUAL_I32(12345, result1);
    ASSUME_ITS_EQUAL_I32(-6789, result2);
    ASSUME_ITS_EQUAL_I32(123, result3);  // atoi stops at first non-numeric character
}

FOSSIL_TEST(test_fossil_wstr_to_double) {
    const_wstring str1 = L"123.45";
    const_wstring str2 = L"-67.89";
    const_wstring str3 = L"123.abc";

    double result1 = fossil_wstr_to_double(str1);
    double result2 = fossil_wstr_to_double(str2);
    double result3 = fossil_wstr_to_double(str3);

    ASSUME_ITS_EQUAL_F64(123.45, result1);
    ASSUME_ITS_EQUAL_F64(-67.89, result2);
    ASSUME_ITS_EQUAL_F64(123.0, result3);  // atof stops at first non-numeric character
}

FOSSIL_TEST(test_fossil_wstr_to_long) {
    const_wstring str1 = L"1234567890";
    const_wstring str2 = L"-9876543210";
    const_wstring str3 = L"123abc";

    long result1 = fossil_wstr_to_long(str1);
    long result2 = fossil_wstr_to_long(str2);
    long result3 = fossil_wstr_to_long(str3);

    ASSUME_ITS_EQUAL_I32(1234567890, result1);
    ASSUME_ITS_EQUAL_I32(-9876543210, result2);
    ASSUME_ITS_EQUAL_I32(123, result3);  // atol stops at first non-numeric character
}

FOSSIL_TEST(test_fossil_wstr_to_ulong) {
    const_wstring str1 = L"1234567890";
    const_wstring str2 = L"4294967295";
    const_wstring str3 = L"123abc";

    unsigned long result1 = fossil_wstr_to_ulong(str1);
    unsigned long result2 = fossil_wstr_to_ulong(str2);
    unsigned long result3 = fossil_wstr_to_ulong(str3);

    ASSUME_ITS_EQUAL_U32(1234567890, result1);
    ASSUME_ITS_EQUAL_U32(4294967295, result2);
    ASSUME_ITS_EQUAL_U32(123, result3);  // strtoul stops at first non-numeric character
}

FOSSIL_TEST(test_fossil_wstr_to_llong) {
    const_wstring str1 = L"1234567890123456789";
    const_wstring str3 = L"123abc";

    long long result1 = fossil_wstr_to_llong(str1);
    long long result3 = fossil_wstr_to_llong(str3);

    ASSUME_ITS_EQUAL_I32(1234567890123456789LL, result1);
    ASSUME_ITS_EQUAL_I32(123, result3);  // atoll stops at first non-numeric character
}

FOSSIL_TEST(test_fossil_wstr_to_ullong) {
    const_wstring str1 = L"12345678901234567890";
    const_wstring str2 = L"18446744073709551615";
    const_wstring str3 = L"123abc";

    unsigned long long result1 = fossil_wstr_to_ullong(str1);
    unsigned long long result2 = fossil_wstr_to_ullong(str2);
    unsigned long long result3 = fossil_wstr_to_ullong(str3);

    ASSUME_ITS_EQUAL_U3264(12345678901234567890ULL, result1);
    ASSUME_ITS_EQUAL_U3264(18446744073709551615ULL, result2);
    ASSUME_ITS_EQUAL_U3264(123, result3);  // strtoull stops at first non-numeric character
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(fossil_strto_group) {
    ADD_TEST(test_fossil_cstr_to_int);
    ADD_TEST(test_fossil_bstr_to_int);
    ADD_TEST(test_fossil_cstr_to_double);
    ADD_TEST(test_fossil_bstr_to_double);
    ADD_TEST(test_fossil_cstr_to_long);
    ADD_TEST(test_fossil_bstr_to_long);
    ADD_TEST(test_fossil_cstr_to_ulong);
    ADD_TEST(test_fossil_bstr_to_ulong);
    ADD_TEST(test_fossil_cstr_to_llong);
    ADD_TEST(test_fossil_bstr_to_llong);
    ADD_TEST(test_fossil_cstr_to_ullong);
    ADD_TEST(test_fossil_bstr_to_ullong);
    ADD_TEST(test_fossil_wstr_to_int);
    ADD_TEST(test_fossil_wstr_to_double);
    ADD_TEST(test_fossil_wstr_to_long);
    ADD_TEST(test_fossil_wstr_to_ulong);
    ADD_TEST(test_fossil_wstr_to_llong);
    ADD_TEST(test_fossil_wstr_to_ullong);
} // end of function main
