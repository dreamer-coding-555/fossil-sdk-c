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
#include <fossil/stdio/istream.h> // library under test

#include <fossil/unittest.h>   // basic test tools
#include <fossil/xassume.h> // extra asserts
#include <fossil/mockup.h>   // mocking tools

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilites
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

// Mock input object
static mockup_input_t *mock_input = xnull;

// Validation function for testing
XMOCK_FUNC_DEF(bool, validate_input, const char* input) {
    int32_t num;
    if (sscanf(input, "%d", &num) == 1 && num >= 1 && num <= 100) {
        return true;
    }
    return false;
}

XFIXTURE(input_fixture);
XSETUP(input_fixture) {
    // Create mock input object for fossil_console_in_get_input
    mock_input = mockup_input_create("fossil_console_in_get_input");
    mockup_input_set_inputs(mock_input, 8, "42", "150", "yes", "no", "1 3", "1 4", "exit", "not_exit");
}

XTEARDOWN(input_fixture) {
    mockup_input_erase(mock_input);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(reader_let_reader_valid_input_valid) {
    // Test valid input validation
    ASSUME_ITS_TRUE(fossil_console_in_valid_input("Enter a valid number (1-100)", mockup_validate_input));
    ASSUME_ITS_TRUE(mockup_input_verify_call_count(mock_input, 1));
}

FOSSIL_TEST(reader_let_reader_valid_input_invalid) {
    // Test invalid input validation
    ASSUME_ITS_FALSE(fossil_console_in_valid_input("Enter a valid number (1-100)", mockup_validate_input));
    ASSUME_ITS_TRUE(mockup_input_verify_call_count(mock_input, 1));
}

FOSSIL_TEST(reader_let_reader_confirm_yes_no_yes) {
    // Test confirming "yes"
    ASSUME_ITS_TRUE(fossil_console_in_confirm_yes_no("Do you like programming?"));
    ASSUME_ITS_TRUE(mockup_input_verify_call_count(mock_input, 1));
}

FOSSIL_TEST(reader_let_reader_confirm_yes_no_no) {
    // Test confirming "no"
    ASSUME_ITS_FALSE(fossil_console_in_confirm_yes_no("Do you like programming?"));
}

FOSSIL_TEST(reader_let_reader_confirm_multi_menu) {
    // Test multi-choice menu
    const char* menu[] = { "Option 1", "Option 2", "Option 3" };
    size_t num_options = sizeof(menu) / sizeof(menu[0]);
    int32_t selections[num_options];
    memset(selections, false, sizeof(selections));

    // Simulate user input "1 3" (selecting the first and third options)
    fossil_console_in_confirm_multi_menu("Choose multiple options", menu, selections, num_options);
    ASSUME_ITS_TRUE(selections[0]);
    ASSUME_ITS_FALSE(selections[1]);
    ASSUME_ITS_TRUE(selections[2]);
}

FOSSIL_TEST(reader_let_reader_confirm_exit) {
    // Test confirming exit
    ASSUME_ITS_TRUE(fossil_console_in_confirm_exit());
}

// Additional test cases for reader_valid_input
FOSSIL_TEST(reader_let_reader_valid_input_valid_upper_bound) {
    // Test valid input at upper bound
    ASSUME_ITS_TRUE(fossil_console_in_valid_input("Enter a valid number (1-100)", mockup_validate_input));
}

FOSSIL_TEST(reader_let_reader_valid_input_valid_lower_bound) {
    // Test valid input at lower bound
    ASSUME_ITS_TRUE(fossil_console_in_valid_input("Enter a valid number (1-100)", mockup_validate_input));
}

FOSSIL_TEST(reader_let_reader_valid_input_invalid_upper_bound) {
    // Test invalid input at upper bound
    ASSUME_ITS_FALSE(fossil_console_in_valid_input("Enter a valid number (1-100)", mockup_validate_input));
}

FOSSIL_TEST(reader_let_reader_valid_input_invalid_lower_bound) {
    // Test invalid input at lower bound
    ASSUME_ITS_FALSE(fossil_console_in_valid_input("Enter a valid number (1-100)", mockup_validate_input));
}

// Additional test cases for reader_confirm_yes_no
FOSSIL_TEST(reader_let_reader_confirm_yes_no_invalid_response) {
    // Test invalid response
    ASSUME_ITS_FALSE(fossil_console_in_confirm_yes_no("Do you like programming?"));
}

// Additional test cases for reader_confirm_multi_menu
FOSSIL_TEST(reader_let_reader_confirm_multi_menu_invalid_input) {
    // Test invalid input for multi-choice menu
    const char* menu[] = { "Option 1", "Option 2", "Option 3" };
    size_t num_options = sizeof(menu) / sizeof(menu[0]);
    int32_t selections[num_options];
    memset(selections, false, sizeof(selections));

    // Simulate user input "1 4" (selecting the first and an invalid fourth option)
    fossil_console_in_confirm_multi_menu("Choose multiple options", menu, selections, num_options);
    ASSUME_ITS_TRUE(selections[0]);
    ASSUME_ITS_FALSE(selections[1]);
    ASSUME_ITS_FALSE(selections[2]);
}

// Additional test cases for reader_confirm_exit
FOSSIL_TEST(reader_let_reader_confirm_exit_invalid_response) {
    // Test invalid response for confirming exit
    ASSUME_ITS_FALSE(fossil_console_in_confirm_exit());
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(test_reader_group) {
    ADD_TEST(reader_let_reader_valid_input_valid);
    ADD_TEST(reader_let_reader_valid_input_invalid);
    ADD_TEST(reader_let_reader_confirm_yes_no_yes);
    ADD_TEST(reader_let_reader_confirm_yes_no_no);
    ADD_TEST(reader_let_reader_confirm_multi_menu);
    ADD_TEST(reader_let_reader_confirm_exit);
    ADD_TEST(reader_let_reader_valid_input_valid_upper_bound);
    ADD_TEST(reader_let_reader_valid_input_valid_lower_bound);
    ADD_TEST(reader_let_reader_valid_input_invalid_upper_bound);
    ADD_TEST(reader_let_reader_valid_input_invalid_lower_bound);
    ADD_TEST(reader_let_reader_confirm_yes_no_invalid_response);
    ADD_TEST(reader_let_reader_confirm_multi_menu_invalid_input);
    ADD_TEST(reader_let_reader_confirm_exit_invalid_response);
}
