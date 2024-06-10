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

XTEST(test_fossil_cletter_is_alpha) {
    TEST_ASSUME_EQUAL_INT16(1, fossil_cletter_is_alpha('a'));
    TEST_ASSUME_EQUAL_INT16(1, fossil_cletter_is_alpha('Z'));
    TEST_ASSUME_EQUAL_INT16(0, fossil_cletter_is_alpha('1'));
    TEST_ASSUME_EQUAL_INT16(0, fossil_cletter_is_alpha('*'));
}

XTEST(test_fossil_cletter_is_digit) {
    TEST_ASSUME_EQUAL_INT16(1, fossil_cletter_is_digit('0'));
    TEST_ASSUME_EQUAL_INT16(1, fossil_cletter_is_digit('9'));
    TEST_ASSUME_EQUAL_INT16(0, fossil_cletter_is_digit('a'));
    TEST_ASSUME_EQUAL_INT16(0, fossil_cletter_is_digit('*'));
}

XTEST(test_fossil_cletter_is_alnum) {
    TEST_ASSUME_EQUAL_INT16(1, fossil_cletter_is_alnum('a'));
    TEST_ASSUME_EQUAL_INT16(1, fossil_cletter_is_alnum('Z'));
    TEST_ASSUME_EQUAL_INT16(1, fossil_cletter_is_alnum('1'));
    TEST_ASSUME_EQUAL_INT16(0, fossil_cletter_is_alnum('*'));
}

XTEST(test_fossil_cletter_is_lower) {
    TEST_ASSUME_EQUAL_INT16(1, fossil_cletter_is_lower('a'));
    TEST_ASSUME_EQUAL_INT16(0, fossil_cletter_is_lower('Z'));
    TEST_ASSUME_EQUAL_INT16(0, fossil_cletter_is_lower('1'));
}

XTEST(test_fossil_cletter_is_upper) {
    TEST_ASSUME_EQUAL_INT16(0, fossil_cletter_is_upper('a'));
    TEST_ASSUME_EQUAL_INT16(1, fossil_cletter_is_upper('Z'));
    TEST_ASSUME_EQUAL_INT16(0, fossil_cletter_is_upper('1'));
}

XTEST(test_fossil_cletter_to_lower) {
    TEST_ASSUME_EQUAL_INT16('a', fossil_cletter_to_lower('A'));
    TEST_ASSUME_EQUAL_INT16('z', fossil_cletter_to_lower('Z'));
    TEST_ASSUME_EQUAL_INT16('1', fossil_cletter_to_lower('1'));
}

XTEST(test_fossil_cletter_to_upper) {
    TEST_ASSUME_EQUAL_INT16('A', fossil_cletter_to_upper('a'));
    TEST_ASSUME_EQUAL_INT16('Z', fossil_cletter_to_upper('z'));
    TEST_ASSUME_EQUAL_INT16('1', fossil_cletter_to_upper('1'));
}

XTEST(test_fossil_cletter_is_space) {
    TEST_ASSUME_EQUAL_INT16(1, fossil_cletter_is_space(' '));
    TEST_ASSUME_EQUAL_INT16(0, fossil_cletter_is_space('a'));
}

XTEST(test_fossil_cletter_is_punct) {
    TEST_ASSUME_EQUAL_INT16(1, fossil_cletter_is_punct('.'));
    TEST_ASSUME_EQUAL_INT16(0, fossil_cletter_is_punct('a'));
}

XTEST(test_fossil_cletter_is_graph) {
    TEST_ASSUME_EQUAL_INT16(1, fossil_cletter_is_graph('a'));
    TEST_ASSUME_EQUAL_INT16(1, fossil_cletter_is_graph(' '));
    TEST_ASSUME_EQUAL_INT16(0, fossil_cletter_is_graph('\n'));
}

XTEST(test_fossil_cletter_is_print) {
    TEST_ASSUME_EQUAL_INT16(1, fossil_cletter_is_print('a'));
    TEST_ASSUME_EQUAL_INT16(1, fossil_cletter_is_print(' '));
    TEST_ASSUME_EQUAL_INT16(0, fossil_cletter_is_print('\n'));
}

XTEST(test_fossil_cletter_is_cntrl) {
    TEST_ASSUME_EQUAL_INT16(0, fossil_cletter_is_cntrl('a'));
    TEST_ASSUME_EQUAL_INT16(0, fossil_cletter_is_cntrl(' '));
    TEST_ASSUME_EQUAL_INT16(1, fossil_cletter_is_cntrl('\n'));
}

XTEST(test_fossil_cletter_is_xdigit) {
    TEST_ASSUME_EQUAL_INT16(1, fossil_cletter_is_xdigit('0'));
    TEST_ASSUME_EQUAL_INT16(1, fossil_cletter_is_xdigit('A'));
    TEST_ASSUME_EQUAL_INT16(0, fossil_cletter_is_xdigit('g'));
    TEST_ASSUME_EQUAL_INT16(0, fossil_cletter_is_xdigit('*'));
}

// Test cases for bletter functions
XTEST(test_fossil_bletter_is_alpha) {
    TEST_ASSUME_EQUAL_INT16(1, fossil_bletter_is_alpha((bletter)'a'));
    TEST_ASSUME_EQUAL_INT16(1, fossil_bletter_is_alpha((bletter)'Z'));
    TEST_ASSUME_EQUAL_INT16(0, fossil_bletter_is_alpha((bletter)'1'));
    TEST_ASSUME_EQUAL_INT16(0, fossil_bletter_is_alpha((bletter)'*'));
}

XTEST(test_fossil_bletter_is_digit) {
    TEST_ASSUME_EQUAL_INT16(1, fossil_bletter_is_digit((bletter)'0'));
    TEST_ASSUME_EQUAL_INT16(1, fossil_bletter_is_digit((bletter)'9'));
    TEST_ASSUME_EQUAL_INT16(0, fossil_bletter_is_digit((bletter)'a'));
    TEST_ASSUME_EQUAL_INT16(0, fossil_bletter_is_digit((bletter)'*'));
}

XTEST(test_fossil_bletter_is_alnum) {
    TEST_ASSUME_EQUAL_INT16(1, fossil_bletter_is_alnum((bletter)'a'));
    TEST_ASSUME_EQUAL_INT16(1, fossil_bletter_is_alnum((bletter)'Z'));
    TEST_ASSUME_EQUAL_INT16(1, fossil_bletter_is_alnum((bletter)'1'));
    TEST_ASSUME_EQUAL_INT16(0, fossil_bletter_is_alnum((bletter)'*'));
}

XTEST(test_fossil_bletter_is_lower) {
    TEST_ASSUME_EQUAL_INT16(1, fossil_bletter_is_lower((bletter)'a'));
    TEST_ASSUME_EQUAL_INT16(0, fossil_bletter_is_lower((bletter)'Z'));
    TEST_ASSUME_EQUAL_INT16(0, fossil_bletter_is_lower((bletter)'1'));
}

XTEST(test_fossil_bletter_is_upper) {
    TEST_ASSUME_EQUAL_INT16(0, fossil_bletter_is_upper((bletter)'a'));
    TEST_ASSUME_EQUAL_INT16(1, fossil_bletter_is_upper((bletter)'Z'));
    TEST_ASSUME_EQUAL_INT16(0, fossil_bletter_is_upper((bletter)'1'));
}

XTEST(test_fossil_bletter_to_lower) {
    TEST_ASSUME_EQUAL_INT16('a', fossil_bletter_to_lower((bletter)'A'));
    TEST_ASSUME_EQUAL_INT16('z', fossil_bletter_to_lower((bletter)'Z'));
    TEST_ASSUME_EQUAL_INT16('1', fossil_bletter_to_lower((bletter)'1'));
}

XTEST(test_fossil_bletter_to_upper) {
    TEST_ASSUME_EQUAL_INT16('A', fossil_bletter_to_upper((bletter)'a'));
    TEST_ASSUME_EQUAL_INT16('Z', fossil_bletter_to_upper((bletter)'z'));
    TEST_ASSUME_EQUAL_INT16('1', fossil_bletter_to_upper((bletter)'1'));
}

XTEST(test_fossil_bletter_is_space) {
    TEST_ASSUME_EQUAL_INT16(1, fossil_bletter_is_space((bletter)' '));
    TEST_ASSUME_EQUAL_INT16(0, fossil_bletter_is_space((bletter)'a'));
}

XTEST(test_fossil_bletter_is_punct) {
    TEST_ASSUME_EQUAL_INT16(1, fossil_bletter_is_punct((bletter)'.'));
    TEST_ASSUME_EQUAL_INT16(0, fossil_bletter_is_punct((bletter)'a'));
}

XTEST(test_fossil_bletter_is_graph) {
    TEST_ASSUME_EQUAL_INT16(1, fossil_bletter_is_graph((bletter)'a'));
    TEST_ASSUME_EQUAL_INT16(1, fossil_bletter_is_graph((bletter)' '));
    TEST_ASSUME_EQUAL_INT16(0, fossil_bletter_is_graph((bletter)'\n'));
}

XTEST(test_fossil_bletter_is_print) {
    TEST_ASSUME_EQUAL_INT16(1, fossil_bletter_is_print((bletter)'a'));
    TEST_ASSUME_EQUAL_INT16(1, fossil_bletter_is_print((bletter)' '));
    TEST_ASSUME_EQUAL_INT16(0, fossil_bletter_is_print((bletter)'\n'));
}

XTEST(test_fossil_bletter_is_cntrl) {
    TEST_ASSUME_EQUAL_INT16(0, fossil_bletter_is_cntrl((bletter)'a'));
    TEST_ASSUME_EQUAL_INT16(0, fossil_bletter_is_cntrl((bletter)' '));
    TEST_ASSUME_EQUAL_INT16(1, fossil_bletter_is_cntrl((bletter)'\n'));
}

XTEST(test_fossil_bletter_is_xdigit) {
    TEST_ASSUME_EQUAL_INT16(1, fossil_bletter_is_xdigit((bletter)'0'));
    TEST_ASSUME_EQUAL_INT16(1, fossil_bletter_is_xdigit((bletter)'A'));
    TEST_ASSUME_EQUAL_INT16(0, fossil_bletter_is_xdigit((bletter)'g'));
    TEST_ASSUME_EQUAL_INT16(0, fossil_bletter_is_xdigit((bletter)'*'));
}

XTEST(test_fossil_wletter_is_alpha) {
    wletter ch1 = L'A';
    wletter ch2 = L'5';
    wletter ch3 = L' ';

    TEST_ASSUME_EQUAL_INT16(1, fossil_wletter_is_alpha(ch1));
    TEST_ASSUME_EQUAL_INT16(0, fossil_wletter_is_alpha(ch2));
    TEST_ASSUME_EQUAL_INT16(0, fossil_wletter_is_alpha(ch3));
}

XTEST(test_fossil_wletter_is_digit) {
    wletter ch1 = L'A';
    wletter ch2 = L'5';
    wletter ch3 = L' ';

    TEST_ASSUME_EQUAL_INT16(0, fossil_wletter_is_digit(ch1));
    TEST_ASSUME_EQUAL_INT16(1, fossil_wletter_is_digit(ch2));
    TEST_ASSUME_EQUAL_INT16(0, fossil_wletter_is_digit(ch3));
}

XTEST(test_fossil_wletter_is_alnum) {
    wletter ch1 = L'A';
    wletter ch2 = L'5';
    wletter ch3 = L' ';

    TEST_ASSUME_EQUAL_INT16(1, fossil_wletter_is_alnum(ch1));
    TEST_ASSUME_EQUAL_INT16(1, fossil_wletter_is_alnum(ch2));
    TEST_ASSUME_EQUAL_INT16(0, fossil_wletter_is_alnum(ch3));
}

XTEST(test_fossil_wletter_is_lower) {
    wletter ch1 = L'a';
    wletter ch2 = L'A';

    TEST_ASSUME_EQUAL_INT16(1, fossil_wletter_is_lower(ch1));
    TEST_ASSUME_EQUAL_INT16(0, fossil_wletter_is_lower(ch2));
}

XTEST(test_fossil_wletter_is_upper) {
    wletter ch1 = L'a';
    wletter ch2 = L'A';

    TEST_ASSUME_EQUAL_INT16(0, fossil_wletter_is_upper(ch1));
    TEST_ASSUME_EQUAL_INT16(1, fossil_wletter_is_upper(ch2));
}

XTEST(test_fossil_wletter_to_lower) {
    wletter ch = L'A';
    wletter result = fossil_wletter_to_lower(ch);

    TEST_ASSUME_EQUAL_INT(L'a', result);
}

XTEST(test_fossil_wletter_to_upper) {
    wletter ch = L'a';
    wletter result = fossil_wletter_to_upper(ch);

    TEST_ASSUME_EQUAL_INT(L'A', result);
}

XTEST(test_fossil_wletter_is_space) {
    wletter ch1 = L' ';
    wletter ch2 = L'A';

    TEST_ASSUME_EQUAL_INT16(1, fossil_wletter_is_space(ch1));
    TEST_ASSUME_EQUAL_INT16(0, fossil_wletter_is_space(ch2));
}

XTEST(test_fossil_wletter_is_punct) {
    wletter ch1 = L'.';
    wletter ch2 = L'A';

    TEST_ASSUME_EQUAL_INT16(1, fossil_wletter_is_punct(ch1));
    TEST_ASSUME_EQUAL_INT16(0, fossil_wletter_is_punct(ch2));
}

XTEST(test_fossil_wletter_is_graph) {
    wletter ch1 = L'A';
    wletter ch2 = L' ';

    TEST_ASSUME_EQUAL_INT16(1, fossil_wletter_is_graph(ch1));
    TEST_ASSUME_EQUAL_INT16(0, fossil_wletter_is_graph(ch2));
}

XTEST(test_fossil_wletter_is_print) {
    wletter ch1 = L'A';
    wletter ch2 = L' ';

    TEST_ASSUME_EQUAL_INT16(1, fossil_wletter_is_print(ch1));
    TEST_ASSUME_EQUAL_INT16(1, fossil_wletter_is_print(ch2));
}

XTEST(test_fossil_wletter_is_cntrl) {
    wletter ch1 = L'\n';
    wletter ch2 = L'A';

    TEST_ASSUME_EQUAL_INT16(1, fossil_wletter_is_cntrl(ch1));
    TEST_ASSUME_EQUAL_INT16(0, fossil_wletter_is_cntrl(ch2));
}

XTEST(test_fossil_wletter_is_xdigit) {
    wletter ch1 = L'A';
    wletter ch2 = L'5';
    wletter ch3 = L'G';

    TEST_ASSUME_EQUAL_INT16(1, fossil_wletter_is_xdigit(ch1));
    TEST_ASSUME_EQUAL_INT16(1, fossil_wletter_is_xdigit(ch2));
    TEST_ASSUME_EQUAL_INT16(0, fossil_wletter_is_xdigit(ch3));
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
XTEST_DEFINE_POOL(fossil_cletter_group) {
    // Run cletter tests
    XTEST_RUN_UNIT(test_fossil_cletter_is_alpha);
    XTEST_RUN_UNIT(test_fossil_cletter_is_digit);
    XTEST_RUN_UNIT(test_fossil_cletter_is_alnum);
    XTEST_RUN_UNIT(test_fossil_cletter_is_lower);
    XTEST_RUN_UNIT(test_fossil_cletter_is_upper);
    XTEST_RUN_UNIT(test_fossil_cletter_to_lower);
    XTEST_RUN_UNIT(test_fossil_cletter_to_upper);
    XTEST_RUN_UNIT(test_fossil_cletter_is_space);
    XTEST_RUN_UNIT(test_fossil_cletter_is_punct);
    XTEST_RUN_UNIT(test_fossil_cletter_is_graph);
    XTEST_RUN_UNIT(test_fossil_cletter_is_print);
    XTEST_RUN_UNIT(test_fossil_cletter_is_cntrl);
    XTEST_RUN_UNIT(test_fossil_cletter_is_xdigit);

    // Run bletter tests
    XTEST_RUN_UNIT(test_fossil_bletter_is_alpha);
    XTEST_RUN_UNIT(test_fossil_bletter_is_digit);
    XTEST_RUN_UNIT(test_fossil_bletter_is_alnum);
    XTEST_RUN_UNIT(test_fossil_bletter_is_lower);
    XTEST_RUN_UNIT(test_fossil_bletter_is_upper);
    XTEST_RUN_UNIT(test_fossil_bletter_to_lower);
    XTEST_RUN_UNIT(test_fossil_bletter_to_upper);
    XTEST_RUN_UNIT(test_fossil_bletter_is_space);
    XTEST_RUN_UNIT(test_fossil_bletter_is_punct);
    XTEST_RUN_UNIT(test_fossil_bletter_is_graph);
    XTEST_RUN_UNIT(test_fossil_bletter_is_print);
    XTEST_RUN_UNIT(test_fossil_bletter_is_cntrl);
    XTEST_RUN_UNIT(test_fossil_bletter_is_xdigit);

    // Run wletter tests
    XTEST_RUN_UNIT(test_fossil_wletter_is_alpha);
    XTEST_RUN_UNIT(test_fossil_wletter_is_digit);
    XTEST_RUN_UNIT(test_fossil_wletter_is_alnum);
    XTEST_RUN_UNIT(test_fossil_wletter_is_lower);
    XTEST_RUN_UNIT(test_fossil_wletter_is_upper);
    XTEST_RUN_UNIT(test_fossil_wletter_to_lower);
    XTEST_RUN_UNIT(test_fossil_wletter_to_upper);
    XTEST_RUN_UNIT(test_fossil_wletter_is_space);
    XTEST_RUN_UNIT(test_fossil_wletter_is_punct);
    XTEST_RUN_UNIT(test_fossil_wletter_is_graph);
    XTEST_RUN_UNIT(test_fossil_wletter_is_print);
    XTEST_RUN_UNIT(test_fossil_wletter_is_cntrl);
    XTEST_RUN_UNIT(test_fossil_wletter_is_xdigit);
} // end of function main
