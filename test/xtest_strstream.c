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

XTEST(test_fossil_cstrstream_read) {
    const_cstring str = "Hello, world!";
    size_t pos = 0;
    size_t len = 5;

    cstring result = fossil_cstrstream_read(str, &pos, len);

    TEST_ASSUME_EQUAL_CSTRING("Hello", result);
    TEST_ASSUME_EQUAL_UINT(5, pos);
}

XTEST(test_fossil_cstrstream_read_line) {
    const_cstring str = "Line 1\nLine 2\nLine 3";
    size_t pos = 0;
    size_t end_pos;

    cstring result1 = fossil_cstrstream_read_line(str, &pos, &end_pos);
    TEST_ASSUME_EQUAL_CSTRING("Line 1", result1);
    TEST_ASSUME_EQUAL_UINT(7, end_pos);

    cstring result2 = fossil_cstrstream_read_line(str, &pos, &end_pos);
    TEST_ASSUME_EQUAL_CSTRING("Line 2", result2);
    TEST_ASSUME_EQUAL_UINT(14, end_pos);

    cstring result3 = fossil_cstrstream_read_line(str, &pos, &end_pos);
    TEST_ASSUME_EQUAL_CSTRING("Line 3", result3);
    TEST_ASSUME_EQUAL_UINT(21, end_pos);
}

XTEST(test_fossil_cstrstream_write) {
    const_cstring src = "world!";
    cstring dest = "Hello, ";
    size_t pos = 7;

    fossil_cstrstream_write(dest, &pos, src);
    TEST_ASSUME_EQUAL_CSTRING("Hello, world!", dest);
    TEST_ASSUME_EQUAL_UINT(13, pos);
}

XTEST(test_fossil_cstrstream_append) {
    const_cstring src = "world!";
    cstring dest = "Hello, ";
    size_t pos = 7;

    fossil_cstrstream_append(dest, &pos, src);
    TEST_ASSUME_EQUAL_CSTRING("Hello, world!", dest);
    TEST_ASSUME_EQUAL_UINT(13, pos);
}

XTEST(test_fossil_cstrstream_seek) {
    size_t pos = 0;
    size_t offset = 5;

    fossil_cstrstream_seek(&pos, offset);
    TEST_ASSUME_EQUAL_UINT(5, pos);
}

XTEST(test_fossil_cstrstream_tell) {
    const_cstring str = "Hello, world!";
    size_t pos = 7;

    size_t result = fossil_cstrstream_tell(str, pos);
    TEST_ASSUME_EQUAL_UINT(7, result);
}

XTEST(test_fossil_bstrstream_read) {
    const_bstring str = (bstring)"Hello, world!";
    size_t pos = 0;
    size_t len = 5;

    bstring result = fossil_bstrstream_read(str, &pos, len);

    TEST_ASSUME_EQUAL_CSTRING("Hello", (cstring)result);
    TEST_ASSUME_EQUAL_UINT(5, pos);
}

XTEST(test_fossil_bstrstream_read_line) {
    const_bstring str = (bstring)"Line 1\nLine 2\nLine 3";
    size_t pos = 0;
    size_t end_pos;

    bstring result1 = fossil_bstrstream_read_line(str, &pos, &end_pos);
    TEST_ASSUME_EQUAL_CSTRING("Line 1", (cstring)result1);
    TEST_ASSUME_EQUAL_UINT(7, end_pos);

    bstring result2 = fossil_bstrstream_read_line(str, &pos, &end_pos);
    TEST_ASSUME_EQUAL_CSTRING("Line 2", (cstring)result2);
    TEST_ASSUME_EQUAL_UINT(14, end_pos);

    bstring result3 = fossil_bstrstream_read_line(str, &pos, &end_pos);
    TEST_ASSUME_EQUAL_CSTRING("Line 3", (cstring)result3);
    TEST_ASSUME_EQUAL_UINT(21, end_pos);
}

XTEST(test_fossil_bstrstream_write) {
    const_bstring src = (bstring)"world!";
    bstring dest = (bstring)"Hello, ";
    size_t pos = 7;

    fossil_bstrstream_write(dest, &pos, src);
    TEST_ASSUME_EQUAL_CSTRING("Hello, world!", (cstring)dest);
    TEST_ASSUME_EQUAL_UINT(13, pos);
}

XTEST(test_fossil_bstrstream_append) {
    const_bstring src = (bstring)"world!";
    bstring dest = (bstring)"Hello, ";
    size_t pos = 7;

    fossil_bstrstream_append(dest, &pos, src);
    TEST_ASSUME_EQUAL_CSTRING("Hello, world!", (cstring)dest);
    TEST_ASSUME_EQUAL_UINT(13, pos);
}

XTEST(test_fossil_bstrstream_seek) {
    size_t pos = 0;
    size_t offset = 5;

    fossil_bstrstream_seek(&pos, offset);
    TEST_ASSUME_EQUAL_UINT(5, pos);
}

XTEST(test_fossil_bstrstream_tell) {
    const_bstring str = (bstring)"Hello, world!";
    size_t pos = 7;

    size_t result = fossil_bstrstream_tell(str, pos);
    TEST_ASSUME_EQUAL_UINT(7, result);
}

XTEST(test_fossil_wstrstream_read) {
    const_wstring str = L"Hello, world!";
    size_t pos = 0;
    size_t len = 5;

    wstring result = fossil_wstrstream_read(str, &pos, len);

    TEST_ASSUME_EQUAL_WSTRING(L"Hello", result);
    TEST_ASSUME_EQUAL_UINT(5, pos);
}

XTEST(test_fossil_wstrstream_read_line) {
    const_wstring str = L"Line 1\nLine 2\nLine 3";
    size_t pos = 0;
    size_t end_pos;

    wstring result1 = fossil_wstrstream_read_line(str, &pos, &end_pos);
    TEST_ASSUME_EQUAL_WSTRING(L"Line 1", result1);
    TEST_ASSUME_EQUAL_UINT(7, end_pos);

    wstring result2 = fossil_wstrstream_read_line(str, &pos, &end_pos);
    TEST_ASSUME_EQUAL_WSTRING(L"Line 2", result2);
    TEST_ASSUME_EQUAL_UINT(14, end_pos);

    wstring result3 = fossil_wstrstream_read_line(str, &pos, &end_pos);
    TEST_ASSUME_EQUAL_WSTRING(L"Line 3", result3);
    TEST_ASSUME_EQUAL_UINT(21, end_pos);
}

XTEST(test_fossil_wstrstream_write) {
    const_wstring src = L"world!";
    wstring dest = L"Hello, ";
    size_t pos = 7;

    fossil_wstrstream_write(dest, &pos, src);
    TEST_ASSUME_EQUAL_WSTRING(L"Hello, world!", dest);
    TEST_ASSUME_EQUAL_UINT(13, pos);
}

XTEST(test_fossil_wstrstream_append) {
    const_wstring src = L"world!";
    wstring dest = L"Hello, ";
    size_t pos = 7;

    fossil_wstrstream_append(dest, &pos, src);
    TEST_ASSUME_EQUAL_WSTRING(L"Hello, world!", dest);
    TEST_ASSUME_EQUAL_UINT(13, pos);
}

XTEST(test_fossil_wstrstream_seek) {
    size_t pos = 0;
    size_t offset = 5;

    fossil_wstrstream_seek(&pos, offset);
    TEST_ASSUME_EQUAL_UINT(5, pos);
}

XTEST(test_fossil_wstrstream_tell) {
    const_wstring str = L"Hello, world!";
    size_t pos = 7;

    size_t result = fossil_wstrstream_tell(str, pos);
    TEST_ASSUME_EQUAL_UINT(7, result);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
XTEST_DEFINE_POOL(fossil_strstream_group) {
    XTEST_RUN_UNIT(test_fossil_cstrstream_read);
    XTEST_RUN_UNIT(test_fossil_cstrstream_read_line);
    XTEST_RUN_UNIT(test_fossil_cstrstream_write);
    XTEST_RUN_UNIT(test_fossil_cstrstream_append);
    XTEST_RUN_UNIT(test_fossil_cstrstream_seek);
    XTEST_RUN_UNIT(test_fossil_cstrstream_tell);
    XTEST_RUN_UNIT(test_fossil_bstrstream_read);
    XTEST_RUN_UNIT(test_fossil_bstrstream_read_line);
    XTEST_RUN_UNIT(test_fossil_bstrstream_write);
    XTEST_RUN_UNIT(test_fossil_bstrstream_append);
    XTEST_RUN_UNIT(test_fossil_bstrstream_seek);
    XTEST_RUN_UNIT(test_fossil_bstrstream_tell);
    XTEST_RUN_UNIT(test_fossil_wstrstream_read);  // New wide string stream test cases
    XTEST_RUN_UNIT(test_fossil_wstrstream_read_line);
    XTEST_RUN_UNIT(test_fossil_wstrstream_write);
    XTEST_RUN_UNIT(test_fossil_wstrstream_append);
    XTEST_RUN_UNIT(test_fossil_wstrstream_seek);
    XTEST_RUN_UNIT(test_fossil_wstrstream_tell);
} // end of function main
