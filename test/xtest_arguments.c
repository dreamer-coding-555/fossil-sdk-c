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
#include "fossil/stdtool/arguments.h" // lib source code

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

XTEST(test_fossil_arg_parse_has) {
    // Test fossil_arg_parse_has function
    fossil_option_t options[] = {
        {"option1", COPTION_TYPE_BOOL, {.bool_val = 0}, NULL, 0, 0},
        {"option2", COPTION_TYPE_INT, {.int_val = 42}, NULL, 0, 0}
    };
    int num_options = sizeof(options) / sizeof(options[0]);

    // Assuming fossil_arg_parse_has returns 1 for the existing option
    ASSUME_ITS_EQUAL_I32(1, fossil_arg_parse_has(options, num_options, "option1"));
}

XTEST(test_fossil_arg_parse) {
    // Test fossil_arg_parse function
    const char* argv[] = {"program", "-number", "42", "-name", "John", "-flag", "-choice", "choice2", "-feature", "enable"};
    const int argc = sizeof(argv) / sizeof(argv[0]);

    fossil_command_line_t cmd = {argc, (char **)argv};
    
    fossil_option_t options[] = {
        {"option1", COPTION_TYPE_INT, {.int_val = 0}, NULL, 0, 0},
        {"option2", COPTION_TYPE_BOOL, {.bool_val = 0}, NULL, 0, 0}
    };
    int num_options = sizeof(options) / sizeof(options[0]);

    // Assuming fossil_arg_parse modifies the options array
    fossil_arg_parse(&cmd, options, num_options);

    ASSUME_ITS_EQUAL_I32(42, options[0].value.int_val);
    ASSUME_ITS_EQUAL_I32(0, options[1].value.bool_val);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
XTEST_DEFINE_POOL(test_parser_group) {
    ADD_TEST(test_fossil_arg_parse_has);
    ADD_TEST(test_fossil_arg_parse);
} // end of function main
