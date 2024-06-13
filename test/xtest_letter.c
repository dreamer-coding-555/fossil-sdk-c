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
#include "fossil/string/letter.h" // lib source code

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

FOSSIL_TEST(test_fossil_cletter_is_alpha) {
    ASSUME_ITS_EQUAL_I32(1, fossil_cletter_is_alpha('a'));
    ASSUME_ITS_EQUAL_I32(1, fossil_cletter_is_alpha('Z'));
    ASSUME_ITS_EQUAL_I32(0, fossil_cletter_is_alpha('1'));
    ASSUME_ITS_EQUAL_I32(0, fossil_cletter_is_alpha('*'));
}

FOSSIL_TEST(test_fossil_cletter_is_digit) {
    ASSUME_ITS_EQUAL_I32(1, fossil_cletter_is_digit('0'));
    ASSUME_ITS_EQUAL_I32(1, fossil_cletter_is_digit('9'));
    ASSUME_ITS_EQUAL_I32(0, fossil_cletter_is_digit('a'));
    ASSUME_ITS_EQUAL_I32(0, fossil_cletter_is_digit('*'));
}

FOSSIL_TEST(test_fossil_cletter_is_alnum) {
    ASSUME_ITS_EQUAL_I32(1, fossil_cletter_is_alnum('a'));
    ASSUME_ITS_EQUAL_I32(1, fossil_cletter_is_alnum('Z'));
    ASSUME_ITS_EQUAL_I32(1, fossil_cletter_is_alnum('1'));
    ASSUME_ITS_EQUAL_I32(0, fossil_cletter_is_alnum('*'));
}

FOSSIL_TEST(test_fossil_cletter_is_lower) {
    ASSUME_ITS_EQUAL_I32(1, fossil_cletter_is_lower('a'));
    ASSUME_ITS_EQUAL_I32(0, fossil_cletter_is_lower('Z'));
    ASSUME_ITS_EQUAL_I32(0, fossil_cletter_is_lower('1'));
}

FOSSIL_TEST(test_fossil_cletter_is_upper) {
    ASSUME_ITS_EQUAL_I32(0, fossil_cletter_is_upper('a'));
    ASSUME_ITS_EQUAL_I32(1, fossil_cletter_is_upper('Z'));
    ASSUME_ITS_EQUAL_I32(0, fossil_cletter_is_upper('1'));
}

FOSSIL_TEST(test_fossil_cletter_to_lower) {
    ASSUME_ITS_EQUAL_I32('a', fossil_cletter_to_lower('A'));
    ASSUME_ITS_EQUAL_I32('z', fossil_cletter_to_lower('Z'));
    ASSUME_ITS_EQUAL_I32('1', fossil_cletter_to_lower('1'));
}

FOSSIL_TEST(test_fossil_cletter_to_upper) {
    ASSUME_ITS_EQUAL_I32('A', fossil_cletter_to_upper('a'));
    ASSUME_ITS_EQUAL_I32('Z', fossil_cletter_to_upper('z'));
    ASSUME_ITS_EQUAL_I32('1', fossil_cletter_to_upper('1'));
}

FOSSIL_TEST(test_fossil_cletter_is_space) {
    ASSUME_ITS_EQUAL_I32(1, fossil_cletter_is_space(' '));
    ASSUME_ITS_EQUAL_I32(0, fossil_cletter_is_space('a'));
}

FOSSIL_TEST(test_fossil_cletter_is_punct) {
    ASSUME_ITS_EQUAL_I32(1, fossil_cletter_is_punct('.'));
    ASSUME_ITS_EQUAL_I32(0, fossil_cletter_is_punct('a'));
}

FOSSIL_TEST(test_fossil_cletter_is_graph) {
    ASSUME_ITS_EQUAL_I32(1, fossil_cletter_is_graph('a'));
    ASSUME_ITS_EQUAL_I32(1, fossil_cletter_is_graph(' '));
    ASSUME_ITS_EQUAL_I32(0, fossil_cletter_is_graph('\n'));
}

FOSSIL_TEST(test_fossil_cletter_is_print) {
    ASSUME_ITS_EQUAL_I32(1, fossil_cletter_is_print('a'));
    ASSUME_ITS_EQUAL_I32(1, fossil_cletter_is_print(' '));
    ASSUME_ITS_EQUAL_I32(0, fossil_cletter_is_print('\n'));
}

FOSSIL_TEST(test_fossil_cletter_is_cntrl) {
    ASSUME_ITS_EQUAL_I32(0, fossil_cletter_is_cntrl('a'));
    ASSUME_ITS_EQUAL_I32(0, fossil_cletter_is_cntrl(' '));
    ASSUME_ITS_EQUAL_I32(1, fossil_cletter_is_cntrl('\n'));
}

FOSSIL_TEST(test_fossil_cletter_is_xdigit) {
    ASSUME_ITS_EQUAL_I32(1, fossil_cletter_is_xdigit('0'));
    ASSUME_ITS_EQUAL_I32(1, fossil_cletter_is_xdigit('A'));
    ASSUME_ITS_EQUAL_I32(0, fossil_cletter_is_xdigit('g'));
    ASSUME_ITS_EQUAL_I32(0, fossil_cletter_is_xdigit('*'));
}

// Test cases for bletter functions
FOSSIL_TEST(test_fossil_bletter_is_alpha) {
    ASSUME_ITS_EQUAL_I32(1, fossil_bletter_is_alpha((bletter)'a'));
    ASSUME_ITS_EQUAL_I32(1, fossil_bletter_is_alpha((bletter)'Z'));
    ASSUME_ITS_EQUAL_I32(0, fossil_bletter_is_alpha((bletter)'1'));
    ASSUME_ITS_EQUAL_I32(0, fossil_bletter_is_alpha((bletter)'*'));
}

FOSSIL_TEST(test_fossil_bletter_is_digit) {
    ASSUME_ITS_EQUAL_I32(1, fossil_bletter_is_digit((bletter)'0'));
    ASSUME_ITS_EQUAL_I32(1, fossil_bletter_is_digit((bletter)'9'));
    ASSUME_ITS_EQUAL_I32(0, fossil_bletter_is_digit((bletter)'a'));
    ASSUME_ITS_EQUAL_I32(0, fossil_bletter_is_digit((bletter)'*'));
}

FOSSIL_TEST(test_fossil_bletter_is_alnum) {
    ASSUME_ITS_EQUAL_I32(1, fossil_bletter_is_alnum((bletter)'a'));
    ASSUME_ITS_EQUAL_I32(1, fossil_bletter_is_alnum((bletter)'Z'));
    ASSUME_ITS_EQUAL_I32(1, fossil_bletter_is_alnum((bletter)'1'));
    ASSUME_ITS_EQUAL_I32(0, fossil_bletter_is_alnum((bletter)'*'));
}

FOSSIL_TEST(test_fossil_bletter_is_lower) {
    ASSUME_ITS_EQUAL_I32(1, fossil_bletter_is_lower((bletter)'a'));
    ASSUME_ITS_EQUAL_I32(0, fossil_bletter_is_lower((bletter)'Z'));
    ASSUME_ITS_EQUAL_I32(0, fossil_bletter_is_lower((bletter)'1'));
}

FOSSIL_TEST(test_fossil_bletter_is_upper) {
    ASSUME_ITS_EQUAL_I32(0, fossil_bletter_is_upper((bletter)'a'));
    ASSUME_ITS_EQUAL_I32(1, fossil_bletter_is_upper((bletter)'Z'));
    ASSUME_ITS_EQUAL_I32(0, fossil_bletter_is_upper((bletter)'1'));
}

FOSSIL_TEST(test_fossil_bletter_to_lower) {
    ASSUME_ITS_EQUAL_I32('a', fossil_bletter_to_lower((bletter)'A'));
    ASSUME_ITS_EQUAL_I32('z', fossil_bletter_to_lower((bletter)'Z'));
    ASSUME_ITS_EQUAL_I32('1', fossil_bletter_to_lower((bletter)'1'));
}

FOSSIL_TEST(test_fossil_bletter_to_upper) {
    ASSUME_ITS_EQUAL_I32('A', fossil_bletter_to_upper((bletter)'a'));
    ASSUME_ITS_EQUAL_I32('Z', fossil_bletter_to_upper((bletter)'z'));
    ASSUME_ITS_EQUAL_I32('1', fossil_bletter_to_upper((bletter)'1'));
}

FOSSIL_TEST(test_fossil_bletter_is_space) {
    ASSUME_ITS_EQUAL_I32(1, fossil_bletter_is_space((bletter)' '));
    ASSUME_ITS_EQUAL_I32(0, fossil_bletter_is_space((bletter)'a'));
}

FOSSIL_TEST(test_fossil_bletter_is_punct) {
    ASSUME_ITS_EQUAL_I32(1, fossil_bletter_is_punct((bletter)'.'));
    ASSUME_ITS_EQUAL_I32(0, fossil_bletter_is_punct((bletter)'a'));
}

FOSSIL_TEST(test_fossil_bletter_is_graph) {
    ASSUME_ITS_EQUAL_I32(1, fossil_bletter_is_graph((bletter)'a'));
    ASSUME_ITS_EQUAL_I32(1, fossil_bletter_is_graph((bletter)' '));
    ASSUME_ITS_EQUAL_I32(0, fossil_bletter_is_graph((bletter)'\n'));
}

FOSSIL_TEST(test_fossil_bletter_is_print) {
    ASSUME_ITS_EQUAL_I32(1, fossil_bletter_is_print((bletter)'a'));
    ASSUME_ITS_EQUAL_I32(1, fossil_bletter_is_print((bletter)' '));
    ASSUME_ITS_EQUAL_I32(0, fossil_bletter_is_print((bletter)'\n'));
}

FOSSIL_TEST(test_fossil_bletter_is_cntrl) {
    ASSUME_ITS_EQUAL_I32(0, fossil_bletter_is_cntrl((bletter)'a'));
    ASSUME_ITS_EQUAL_I32(0, fossil_bletter_is_cntrl((bletter)' '));
    ASSUME_ITS_EQUAL_I32(1, fossil_bletter_is_cntrl((bletter)'\n'));
}

FOSSIL_TEST(test_fossil_bletter_is_xdigit) {
    ASSUME_ITS_EQUAL_I32(1, fossil_bletter_is_xdigit((bletter)'0'));
    ASSUME_ITS_EQUAL_I32(1, fossil_bletter_is_xdigit((bletter)'A'));
    ASSUME_ITS_EQUAL_I32(0, fossil_bletter_is_xdigit((bletter)'g'));
    ASSUME_ITS_EQUAL_I32(0, fossil_bletter_is_xdigit((bletter)'*'));
}

FOSSIL_TEST(test_fossil_wletter_is_alpha) {
    wletter ch1 = L'A';
    wletter ch2 = L'5';
    wletter ch3 = L' ';

    ASSUME_ITS_EQUAL_I32(1, fossil_wletter_is_alpha(ch1));
    ASSUME_ITS_EQUAL_I32(0, fossil_wletter_is_alpha(ch2));
    ASSUME_ITS_EQUAL_I32(0, fossil_wletter_is_alpha(ch3));
}

FOSSIL_TEST(test_fossil_wletter_is_digit) {
    wletter ch1 = L'A';
    wletter ch2 = L'5';
    wletter ch3 = L' ';

    ASSUME_ITS_EQUAL_I32(0, fossil_wletter_is_digit(ch1));
    ASSUME_ITS_EQUAL_I32(1, fossil_wletter_is_digit(ch2));
    ASSUME_ITS_EQUAL_I32(0, fossil_wletter_is_digit(ch3));
}

FOSSIL_TEST(test_fossil_wletter_is_alnum) {
    wletter ch1 = L'A';
    wletter ch2 = L'5';
    wletter ch3 = L' ';

    ASSUME_ITS_EQUAL_I32(1, fossil_wletter_is_alnum(ch1));
    ASSUME_ITS_EQUAL_I32(1, fossil_wletter_is_alnum(ch2));
    ASSUME_ITS_EQUAL_I32(0, fossil_wletter_is_alnum(ch3));
}

FOSSIL_TEST(test_fossil_wletter_is_lower) {
    wletter ch1 = L'a';
    wletter ch2 = L'A';

    ASSUME_ITS_EQUAL_I32(1, fossil_wletter_is_lower(ch1));
    ASSUME_ITS_EQUAL_I32(0, fossil_wletter_is_lower(ch2));
}

FOSSIL_TEST(test_fossil_wletter_is_upper) {
    wletter ch1 = L'a';
    wletter ch2 = L'A';

    ASSUME_ITS_EQUAL_I32(0, fossil_wletter_is_upper(ch1));
    ASSUME_ITS_EQUAL_I32(1, fossil_wletter_is_upper(ch2));
}

FOSSIL_TEST(test_fossil_wletter_to_lower) {
    wletter ch = L'A';
    wletter result = fossil_wletter_to_lower(ch);

    ASSUME_ITS_EQUAL_I32(L'a', result);
}

FOSSIL_TEST(test_fossil_wletter_to_upper) {
    wletter ch = L'a';
    wletter result = fossil_wletter_to_upper(ch);

    ASSUME_ITS_EQUAL_I32(L'A', result);
}

FOSSIL_TEST(test_fossil_wletter_is_space) {
    wletter ch1 = L' ';
    wletter ch2 = L'A';

    ASSUME_ITS_EQUAL_I32(1, fossil_wletter_is_space(ch1));
    ASSUME_ITS_EQUAL_I32(0, fossil_wletter_is_space(ch2));
}

FOSSIL_TEST(test_fossil_wletter_is_punct) {
    wletter ch1 = L'.';
    wletter ch2 = L'A';

    ASSUME_ITS_EQUAL_I32(1, fossil_wletter_is_punct(ch1));
    ASSUME_ITS_EQUAL_I32(0, fossil_wletter_is_punct(ch2));
}

FOSSIL_TEST(test_fossil_wletter_is_graph) {
    wletter ch1 = L'A';
    wletter ch2 = L' ';

    ASSUME_ITS_EQUAL_I32(1, fossil_wletter_is_graph(ch1));
    ASSUME_ITS_EQUAL_I32(0, fossil_wletter_is_graph(ch2));
}

FOSSIL_TEST(test_fossil_wletter_is_print) {
    wletter ch1 = L'A';
    wletter ch2 = L' ';

    ASSUME_ITS_EQUAL_I32(1, fossil_wletter_is_print(ch1));
    ASSUME_ITS_EQUAL_I32(1, fossil_wletter_is_print(ch2));
}

FOSSIL_TEST(test_fossil_wletter_is_cntrl) {
    wletter ch1 = L'\n';
    wletter ch2 = L'A';

    ASSUME_ITS_EQUAL_I32(1, fossil_wletter_is_cntrl(ch1));
    ASSUME_ITS_EQUAL_I32(0, fossil_wletter_is_cntrl(ch2));
}

FOSSIL_TEST(test_fossil_wletter_is_xdigit) {
    wletter ch1 = L'A';
    wletter ch2 = L'5';
    wletter ch3 = L'G';

    ASSUME_ITS_EQUAL_I32(1, fossil_wletter_is_xdigit(ch1));
    ASSUME_ITS_EQUAL_I32(1, fossil_wletter_is_xdigit(ch2));
    ASSUME_ITS_EQUAL_I32(0, fossil_wletter_is_xdigit(ch3));
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(fossil_cletter_group) {
    // Run cletter tests
    ADD_TEST(test_fossil_cletter_is_alpha);
    ADD_TEST(test_fossil_cletter_is_digit);
    ADD_TEST(test_fossil_cletter_is_alnum);
    ADD_TEST(test_fossil_cletter_is_lower);
    ADD_TEST(test_fossil_cletter_is_upper);
    ADD_TEST(test_fossil_cletter_to_lower);
    ADD_TEST(test_fossil_cletter_to_upper);
    ADD_TEST(test_fossil_cletter_is_space);
    ADD_TEST(test_fossil_cletter_is_punct);
    ADD_TEST(test_fossil_cletter_is_graph);
    ADD_TEST(test_fossil_cletter_is_print);
    ADD_TEST(test_fossil_cletter_is_cntrl);
    ADD_TEST(test_fossil_cletter_is_xdigit);

    // Run bletter tests
    ADD_TEST(test_fossil_bletter_is_alpha);
    ADD_TEST(test_fossil_bletter_is_digit);
    ADD_TEST(test_fossil_bletter_is_alnum);
    ADD_TEST(test_fossil_bletter_is_lower);
    ADD_TEST(test_fossil_bletter_is_upper);
    ADD_TEST(test_fossil_bletter_to_lower);
    ADD_TEST(test_fossil_bletter_to_upper);
    ADD_TEST(test_fossil_bletter_is_space);
    ADD_TEST(test_fossil_bletter_is_punct);
    ADD_TEST(test_fossil_bletter_is_graph);
    ADD_TEST(test_fossil_bletter_is_print);
    ADD_TEST(test_fossil_bletter_is_cntrl);
    ADD_TEST(test_fossil_bletter_is_xdigit);

    // Run wletter tests
    ADD_TEST(test_fossil_wletter_is_alpha);
    ADD_TEST(test_fossil_wletter_is_digit);
    ADD_TEST(test_fossil_wletter_is_alnum);
    ADD_TEST(test_fossil_wletter_is_lower);
    ADD_TEST(test_fossil_wletter_is_upper);
    ADD_TEST(test_fossil_wletter_to_lower);
    ADD_TEST(test_fossil_wletter_to_upper);
    ADD_TEST(test_fossil_wletter_is_space);
    ADD_TEST(test_fossil_wletter_is_punct);
    ADD_TEST(test_fossil_wletter_is_graph);
    ADD_TEST(test_fossil_wletter_is_print);
    ADD_TEST(test_fossil_wletter_is_cntrl);
    ADD_TEST(test_fossil_wletter_is_xdigit);
} // end of function main
