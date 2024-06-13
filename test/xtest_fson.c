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
#include "fossil/core/fson.h" // lib source code
#include "fossil/common/common.h" // lib source code

#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassume.h> // extra asserts

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilites
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

// Function to read the content of a file
char* read_file_content(const char* file_path) {
    FILE *file = fopen(file_path, "r");
    if (!file) {
        return cnullptr;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *content = malloc(length + 1);
    if (content) {
        size_t read_length = fread(content, 1, length, file);
        content[read_length] = '\0'; // Ensure null termination
    }

    fclose(file);
    return content;
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(test_simple_namespace) {
    const char* input = "{ 'namespace': { 'user': { 'name': {'value': 'John Doe', 'type': 'str'} } } }";
    fson_token* tokens = fossil_fson_tokenize(input);
    fson_namespace* ns = fossil_fson_namespace_parse(&tokens);

    // Validate namespace structure
    ASSUME_NOT_CNULL(ns);

    // Test finding values
    fson_value* name_value = fossil_fson_value_find(ns, "name");
    ASSUME_NOT_CNULL(name_value);
    ASSUME_ITS_EQUAL_CSTR("John Doe", name_value->value);

    // Free memory
    fossil_fson_erase_tokens(tokens);
    fossil_fson_namespace_erase(ns);
}

FOSSIL_TEST(test_intermediate_namespace) {
    const char* input = "{ 'namespace': { 'user': { 'name': {'value': 'John Doe', 'type': 'str'}, 'email': {'value': 'johndoe@example.com', 'type': 'str'} }, 'preferences': { 'theme': {'value': 'dark', 'type': 'str'}, 'notifications': {'value': true, 'type': 'bool'} } } }";
    fson_token* tokens = fossil_fson_tokenize(input);
    fson_namespace* ns = fossil_fson_namespace_parse(&tokens);

    // Validate namespace structure
    ASSUME_NOT_CNULL(ns);

    // Test finding values
    fson_value* name_value = fossil_fson_value_find(ns, "name");
    ASSUME_NOT_CNULL(name_value);
    ASSUME_ITS_EQUAL_CSTR("John Doe", name_value->value);

    // Test finding other values and validate their types

    // Free memory
    fossil_fson_erase_tokens(tokens);
    fossil_fson_namespace_erase(ns);
}

FOSSIL_TEST(test_complex_namespace) {
    const char* input = "{ 'namespace': { 'user': { 'name': {'value': 'John Doe', 'type': 'str'}, 'email': {'value': 'johndoe@example.com', 'type': 'str'} }, 'preferences': { 'theme': {'value': 'dark', 'type': 'str'}, 'notifications': {'value': true, 'type': 'bool'} } }, 'other_namespace': { 'data': { 'integer': {'value': 42, 'type': 'i32'}, 'float_number': {'value': 3.14, 'type': 'double'} } } }";
    fson_token* tokens = fossil_fson_tokenize(input);
    fson_namespace* ns = fossil_fson_namespace_parse(&tokens);

    // Validate namespace structure
    ASSUME_NOT_CNULL(ns);

    // Test finding values
    fson_value* name_value = fossil_fson_value_find(ns, "name");
    ASSUME_NOT_CNULL(name_value);
    ASSUME_ITS_EQUAL_CSTR("John Doe", name_value->value);

    // Test finding other values and validate their types

    // Free memory
    fossil_fson_erase_tokens(tokens);
    fossil_fson_namespace_erase(ns);
}

// Test function for loading and parsing FSON file
FOSSIL_TEST(test_load_xson_file) {
    const char* file_path = "sample-data.fson";
    char* xson_content = read_file_content(file_path);
    ASSUME_NOT_CNULL(xson_content);

    // Tokenize the content
    fson_token* tokens = fossil_fson_tokenize(xson_content);
    ASSUME_NOT_CNULL(tokens);

    // Parse the tokens into namespaces
    fson_namespace* ns = fossil_fson_namespace_parse(&tokens);
    ASSUME_NOT_CNULL(ns);

    // Verify user namespace data
    fson_namespace* user_ns = fossil_fson_namespace_find(ns, 1, "user");
    ASSUME_NOT_CNULL(user_ns);

    fson_value* name_value = fossil_fson_value_find(user_ns, "name");
    ASSUME_NOT_CNULL(name_value);
    ASSUME_ITS_EQUAL_CSTR("John Doe", name_value->value);
    ASSUME_ITS_EQUAL_I32(FSON_TYPE_STR, name_value->type);

    fson_value* email_value = fossil_fson_value_find(user_ns, "email");
    ASSUME_NOT_CNULL(email_value);
    ASSUME_ITS_EQUAL_CSTR("johndoe@example.com", email_value->value);
    ASSUME_ITS_EQUAL_I32(FSON_TYPE_STR, email_value->type);

    // Verify preferences namespace data
    fson_namespace* preferences_ns = fossil_fson_namespace_find(ns, 1, "preferences");
    ASSUME_NOT_CNULL(preferences_ns);

    fson_value* theme_value = fossil_fson_value_find(preferences_ns, "theme");
    ASSUME_NOT_CNULL(theme_value);
    ASSUME_ITS_EQUAL_CSTR("dark", theme_value->value);
    ASSUME_ITS_EQUAL_I32(FSON_TYPE_STR, theme_value->type);

    fson_value* notifications_value = fossil_fson_value_find(preferences_ns, "notifications");
    ASSUME_NOT_CNULL(notifications_value);
    ASSUME_ITS_EQUAL_CSTR("true", notifications_value->value);
    ASSUME_ITS_EQUAL_I32(FSON_TYPE_BOOL, notifications_value->type);

    // Verify other_namespace data
    fson_namespace* other_ns = fossil_fson_namespace_find(ns, 1, "other_namespace");
    ASSUME_NOT_CNULL(other_ns);

    fson_value* integer_value = fossil_fson_value_find(other_ns, "integer");
    ASSUME_NOT_CNULL(integer_value);
    ASSUME_ITS_EQUAL_CSTR("42", integer_value->value);
    ASSUME_ITS_EQUAL_I32(FSON_TYPE_I32, integer_value->type);

    fson_value* float_value = fossil_fson_value_find(other_ns, "float_number");
    ASSUME_NOT_CNULL(float_value);
    ASSUME_ITS_EQUAL_CSTR("3.14", float_value->value);
    ASSUME_ITS_EQUAL_I32(FSON_TYPE_DOUBLE, float_value->type);

    // Cleanup
    free(xson_content);
    fossil_fson_erase_tokens(tokens);
    fossil_fson_namespace_erase(ns);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(test_fson_group) {
    ADD_TEST(test_simple_namespace);
    ADD_TEST(test_intermediate_namespace);
    ADD_TEST(test_complex_namespace);
    ADD_TEST(test_load_xson_file);
} // end of function main
