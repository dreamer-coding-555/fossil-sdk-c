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
#include "fossil/core/fossil.h" // lib source code
#include "fossil/common/common.h"

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

// Test case for fossil_dsl_set_error function
FOSSIL_TEST(test_fossil_dsl_set_error) {
    fossil_dsl_parser *parser = fossil_dsl_parser_create();
    fossil_dsl_set_error(parser, FOSSIL_DSL_STATUS_ERROR, "Test error message");

    // Verify the error is set correctly
    ASSUME_ITS_TRUE(FOSSIL_DSL_STATUS_ERROR == parser->last_error);
    ASSUME_ITS_TRUE(strcmp("Test error message", parser->error_message) == 0);

    // Clean up
    fossil_dsl_parser_erase(parser);
}

// Test case for fossil_dsl_tokens_create function
FOSSIL_TEST(test_fossil_dsl_tokens_create) {
    fossil_dsl_tokens *token_list = fossil_dsl_tokens_create();

    // Verify the token list is created successfully
    ASSUME_NOT_CNULL(token_list);
    ASSUME_ITS_EQUAL_I32(0, token_list->token_count);

    // Clean up
    fossil_dsl_tokens_erase(token_list);
}

// Test case for fossil_dsl_tokens_erase function
FOSSIL_TEST(test_fossil_dsl_tokens_erase) {
    fossil_dsl_tokens *token_list = fossil_dsl_tokens_create();
    // Populate token list or perform necessary setup

    fossil_dsl_tokens_erase(token_list);

    // Verify the token list is erased successfully
    ASSUME_ITS_EQUAL_I32(0, token_list->token_count);
}

// Test case for fossil_dsl_get_token_type function
FOSSIL_TEST(test_fossil_dsl_get_token_type) {
    // Test cases for various token values
    ASSUME_ITS_TRUE(TOKEN_TYPE_CLASS == fossil_dsl_get_token_type("class"));
    ASSUME_ITS_TRUE(TOKEN_TYPE_FUNCTION == fossil_dsl_get_token_type("fossil"));
}

// Test case for fossil_dsl_tokenize function
FOSSIL_TEST(test_fossil_dsl_tokenize) {
    const char *script = "class MyClass { fossil myFunction() { print(\"Hello, World!\"); } }";
    fossil_dsl_parser *parser = fossil_dsl_parser_create();
    fossil_dsl_tokens *tokens = fossil_dsl_tokenize(script, parser);

    // Verify the tokenization process
    ASSUME_NOT_CNULL(tokens);
    // Add more assertions to validate the token list
    // Verify parser error status if any

    // Clean up
    fossil_dsl_parser_erase(parser);
    fossil_dsl_tokens_erase(tokens);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(test_fossil_dsl) {
    ADD_TEST(test_fossil_dsl_set_error);
    ADD_TEST(test_fossil_dsl_tokens_create);
    ADD_TEST(test_fossil_dsl_tokens_erase);
    ADD_TEST(test_fossil_dsl_get_token_type);
    ADD_TEST(test_fossil_dsl_tokenize);
}
