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
#include "fossil/string/strstream.h" // lib source code

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

FOSSIL_TEST(test_fossil_cstrstream_read) {
    const_cstring str = "Hello, world!";
    size_t pos = 0;
    size_t len = 5;

    cstring result = fossil_cstrstream_read(str, &pos, len);

    ASSUME_ITS_EQUAL_CSTR("Hello", result);
    ASSUME_ITS_EQUAL_U32(5, pos);
}

FOSSIL_TEST(test_fossil_cstrstream_read_line) {
    const_cstring str = "Line 1\nLine 2\nLine 3";
    size_t pos = 0;
    size_t end_pos;

    cstring result1 = fossil_cstrstream_read_line(str, &pos, &end_pos);
    ASSUME_ITS_EQUAL_CSTR("Line 1", result1);
    ASSUME_ITS_EQUAL_U32(7, end_pos);

    cstring result2 = fossil_cstrstream_read_line(str, &pos, &end_pos);
    ASSUME_ITS_EQUAL_CSTR("Line 2", result2);
    ASSUME_ITS_EQUAL_U32(14, end_pos);

    cstring result3 = fossil_cstrstream_read_line(str, &pos, &end_pos);
    ASSUME_ITS_EQUAL_CSTR("Line 3", result3);
    ASSUME_ITS_EQUAL_U32(21, end_pos);
}

FOSSIL_TEST(test_fossil_cstrstream_write) {
    const_cstring src = "world!";
    cstring dest = "Hello, ";
    size_t pos = 7;

    fossil_cstrstream_write(dest, &pos, src);
    ASSUME_ITS_EQUAL_CSTR("Hello, world!", dest);
    ASSUME_ITS_EQUAL_U32(13, pos);
}

FOSSIL_TEST(test_fossil_cstrstream_append) {
    const_cstring src = "world!";
    cstring dest = "Hello, ";
    size_t pos = 7;

    fossil_cstrstream_append(dest, &pos, src);
    ASSUME_ITS_EQUAL_CSTR("Hello, world!", dest);
    ASSUME_ITS_EQUAL_U32(13, pos);
}

FOSSIL_TEST(test_fossil_cstrstream_seek) {
    size_t pos = 0;
    size_t offset = 5;

    fossil_cstrstream_seek(&pos, offset);
    ASSUME_ITS_EQUAL_U32(5, pos);
}

FOSSIL_TEST(test_fossil_cstrstream_tell) {
    const_cstring str = "Hello, world!";
    size_t pos = 7;

    size_t result = fossil_cstrstream_tell(str, pos);
    ASSUME_ITS_EQUAL_U32(7, result);
}

FOSSIL_TEST(test_fossil_bstrstream_read) {
    const_bstring str = (bstring)"Hello, world!";
    size_t pos = 0;
    size_t len = 5;

    bstring result = fossil_bstrstream_read(str, &pos, len);

    ASSUME_ITS_EQUAL_CSTR("Hello", (cstring)result);
    ASSUME_ITS_EQUAL_U32(5, pos);
}

FOSSIL_TEST(test_fossil_bstrstream_read_line) {
    const_bstring str = (bstring)"Line 1\nLine 2\nLine 3";
    size_t pos = 0;
    size_t end_pos;

    bstring result1 = fossil_bstrstream_read_line(str, &pos, &end_pos);
    ASSUME_ITS_EQUAL_CSTR("Line 1", (cstring)result1);
    ASSUME_ITS_EQUAL_U32(7, end_pos);

    bstring result2 = fossil_bstrstream_read_line(str, &pos, &end_pos);
    ASSUME_ITS_EQUAL_CSTR("Line 2", (cstring)result2);
    ASSUME_ITS_EQUAL_U32(14, end_pos);

    bstring result3 = fossil_bstrstream_read_line(str, &pos, &end_pos);
    ASSUME_ITS_EQUAL_CSTR("Line 3", (cstring)result3);
    ASSUME_ITS_EQUAL_U32(21, end_pos);
}

FOSSIL_TEST(test_fossil_bstrstream_write) {
    const_bstring src = (bstring)"world!";
    bstring dest = (bstring)"Hello, ";
    size_t pos = 7;

    fossil_bstrstream_write(dest, &pos, src);
    ASSUME_ITS_EQUAL_CSTR("Hello, world!", (cstring)dest);
    ASSUME_ITS_EQUAL_U32(13, pos);
}

FOSSIL_TEST(test_fossil_bstrstream_append) {
    const_bstring src = (bstring)"world!";
    bstring dest = (bstring)"Hello, ";
    size_t pos = 7;

    fossil_bstrstream_append(dest, &pos, src);
    ASSUME_ITS_EQUAL_CSTR("Hello, world!", (cstring)dest);
    ASSUME_ITS_EQUAL_U32(13, pos);
}

FOSSIL_TEST(test_fossil_bstrstream_seek) {
    size_t pos = 0;
    size_t offset = 5;

    fossil_bstrstream_seek(&pos, offset);
    ASSUME_ITS_EQUAL_U32(5, pos);
}

FOSSIL_TEST(test_fossil_bstrstream_tell) {
    const_bstring str = (bstring)"Hello, world!";
    size_t pos = 7;

    size_t result = fossil_bstrstream_tell(str, pos);
    ASSUME_ITS_EQUAL_U32(7, result);
}

FOSSIL_TEST(test_fossil_wstrstream_read) {
    const_wstring str = L"Hello, world!";
    size_t pos = 0;
    size_t len = 5;

    wstring result = fossil_wstrstream_read(str, &pos, len);

    ASSUME_ITS_EQUAL_WSTR(L"Hello", result);
    ASSUME_ITS_EQUAL_U32(5, pos);
}

FOSSIL_TEST(test_fossil_wstrstream_read_line) {
    const_wstring str = L"Line 1\nLine 2\nLine 3";
    size_t pos = 0;
    size_t end_pos;

    wstring result1 = fossil_wstrstream_read_line(str, &pos, &end_pos);
    ASSUME_ITS_EQUAL_WSTR(L"Line 1", result1);
    ASSUME_ITS_EQUAL_U32(7, end_pos);

    wstring result2 = fossil_wstrstream_read_line(str, &pos, &end_pos);
    ASSUME_ITS_EQUAL_WSTR(L"Line 2", result2);
    ASSUME_ITS_EQUAL_U32(14, end_pos);

    wstring result3 = fossil_wstrstream_read_line(str, &pos, &end_pos);
    ASSUME_ITS_EQUAL_WSTR(L"Line 3", result3);
    ASSUME_ITS_EQUAL_U32(21, end_pos);
}

FOSSIL_TEST(test_fossil_wstrstream_write) {
    const_wstring src = L"world!";
    wstring dest = L"Hello, ";
    size_t pos = 7;

    fossil_wstrstream_write(dest, &pos, src);
    ASSUME_ITS_EQUAL_WSTR(L"Hello, world!", dest);
    ASSUME_ITS_EQUAL_U32(13, pos);
}

FOSSIL_TEST(test_fossil_wstrstream_append) {
    const_wstring src = L"world!";
    wstring dest = L"Hello, ";
    size_t pos = 7;

    fossil_wstrstream_append(dest, &pos, src);
    ASSUME_ITS_EQUAL_WSTR(L"Hello, world!", dest);
    ASSUME_ITS_EQUAL_U32(13, pos);
}

FOSSIL_TEST(test_fossil_wstrstream_seek) {
    size_t pos = 0;
    size_t offset = 5;

    fossil_wstrstream_seek(&pos, offset);
    ASSUME_ITS_EQUAL_U32(5, pos);
}

FOSSIL_TEST(test_fossil_wstrstream_tell) {
    const_wstring str = L"Hello, world!";
    size_t pos = 7;

    size_t result = fossil_wstrstream_tell(str, pos);
    ASSUME_ITS_EQUAL_U32(7, result);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(fossil_strstream_group) {
    ADD_TEST(test_fossil_cstrstream_read);
    ADD_TEST(test_fossil_cstrstream_read_line);
    ADD_TEST(test_fossil_cstrstream_write);
    ADD_TEST(test_fossil_cstrstream_append);
    ADD_TEST(test_fossil_cstrstream_seek);
    ADD_TEST(test_fossil_cstrstream_tell);
    ADD_TEST(test_fossil_bstrstream_read);
    ADD_TEST(test_fossil_bstrstream_read_line);
    ADD_TEST(test_fossil_bstrstream_write);
    ADD_TEST(test_fossil_bstrstream_append);
    ADD_TEST(test_fossil_bstrstream_seek);
    ADD_TEST(test_fossil_bstrstream_tell);
    ADD_TEST(test_fossil_wstrstream_read);  // New wide string stream test cases
    ADD_TEST(test_fossil_wstrstream_read_line);
    ADD_TEST(test_fossil_wstrstream_write);
    ADD_TEST(test_fossil_wstrstream_append);
    ADD_TEST(test_fossil_wstrstream_seek);
    ADD_TEST(test_fossil_wstrstream_tell);
} // end of function main
