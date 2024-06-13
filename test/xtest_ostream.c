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
#include <fossil/stdio/ostream.h> // library under test

#include <fossil/unittest.h>   // basic test tools
#include <fossil/xassume.h> // extra asserts
#include <fossil/mockup/output.h>

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


// Test case for fstr feature in fossil_console_out function
FOSSIL_TEST(fossil_console_out_fstr_test) {
    fossil_mockup_output_t *mock_output = fossil_mockup_output_create("fossil_console_out");

    // Capture console output
    fossil_mockup_output_capture(mock_output, "This is an fstr test");

    // Call fossil_console_out function with fstr feature
    fossil_console_out("f{str}", "This is an fstr test");

    // Verify that the output is correct
    ASSUME_ITS_TRUE(fossil_mockup_output_verify(mock_output, "This is an fstr test", 0));

    // Verify call count
    ASSUME_ITS_TRUE(fossil_mockup_output_verify_call_count(mock_output, 1));

    // Erase the mock output object
    fossil_mockup_output_erase(mock_output);
}

// Test case for fstr feature with different types in fossil_console_out function
FOSSIL_TEST(fossil_console_out_fstr_types_test) {
    fossil_mockup_output_t *mock_output = fossil_mockup_output_create("fossil_console_out");

    // Capture console output
    fossil_mockup_output_capture(mock_output, "10 20 30 40 50 60 70 80 123 83 a hello 0x12345678 3.14 3.14159");

    // Test different types with fossil_console_out function and fstr feature
    fossil_console_out("f{i8}", (int8_t)10);
    fossil_console_out("f{i16}", (int16_t)20);
    fossil_console_out("f{i32}", (int32_t)30);
    fossil_console_out("f{i64}", (int64_t)40);
    fossil_console_out("f{u8}", (uint8_t)50);
    fossil_console_out("f{u16}", (uint16_t)60);
    fossil_console_out("f{u32}", (uint32_t)70);
    fossil_console_out("f{u64}", (uint64_t)80);
    fossil_console_out("f{h32}", (uint32_t)0x123);
    fossil_console_out("f{o32}", (uint32_t)0123);
    fossil_console_out("f{char}", 'a');
    fossil_console_out("f{str}", "hello");
    fossil_console_out("f{ptr}", (void*)0x12345678);
    fossil_console_out("f{f32}", 3.14f);
    fossil_console_out("f{f64}", 3.14159);

    // Verify that the output is correct
    ASSUME_ITS_TRUE(fossil_mockup_output_verify(mock_output, "10 20 30 40 50 60 70 80 123 83 a hello 0x12345678 3.14 3.14159", 0));

    // Verify call count
    ASSUME_ITS_TRUE(fossil_mockup_output_verify_call_count(mock_output, 15));

    // Erase the mock output object
    fossil_mockup_output_erase(mock_output);
}

// Test case for mixing classic and fstr formatting in fossil_console_out function
FOSSIL_TEST(fossil_console_out_mix_classic_fstring_test) {
    fossil_mockup_output_t *mock_output = fossil_mockup_output_create("fossil_console_out");

    // Capture console output
    fossil_mockup_output_capture(mock_output, "This is a classic string with a formatted number: 42 and here's an fstr string: \033[1mbold text\033[0m");

    // Test mixing classic and fstr formatting with fossil_console_out function
    fossil_console_out("This is a classic string with a formatted number: %i32 and here's an fstr string: f{str:bold}", 42, "bold text");

    // Verify that the output is correct
    ASSUME_ITS_TRUE(fossil_mockup_output_verify(mock_output, "This is a classic string with a formatted number: 42 and here's an fstr string: \033[1mbold text\033[0m", 0));

    // Verify call count
    ASSUME_ITS_TRUE(fossil_mockup_output_verify_call_count(mock_output, 1));

    // Erase the mock output object
    fossil_mockup_output_erase(mock_output);
}

// Test case for various fstring features in fossil_console_out function
FOSSIL_TEST(fossil_console_out_fstring_features_test) {
    fossil_mockup_output_t *mock_output = mockup_output_create("fossil_console_out");

    // Capture console output
    mockup_output_capture(mock_output, "This is a bold string");
    mockup_output_capture(mock_output, "This is an underlined string");
    mockup_output_capture(mock_output, "This is a red string");
    mockup_output_capture(mock_output, "This is a bold green string");
    mockup_output_capture(mock_output, "This is an underlined blue string");
    mockup_output_capture(mock_output, "This is a bold and underlined yellow string");

    // Test various fstring features with fossil_console_out function
    fossil_console_out("f{str:bold}", "This is a bold string");
    fossil_console_out("f{str:underline}", "This is an underlined string");
    fossil_console_out("f{str:red}", "This is a red string");
    fossil_console_out("f{str:green:bold}", "This is a bold green string");
    fossil_console_out("f{str:blue:underline}", "This is an underlined blue string");
    fossil_console_out("f{str:yellow:bold:underline}", "This is a bold and underlined yellow string");

    // Verify that the outputs are correct
    ASSUME_ITS_TRUE(mockup_output_verify(mock_output, "This is a bold string", 0));
    ASSUME_ITS_TRUE(mockup_output_verify(mock_output, "This is an underlined string", 1));
    ASSUME_ITS_TRUE(mockup_output_verify(mock_output, "This is a red string", 2));
    ASSUME_ITS_TRUE(mockup_output_verify(mock_output, "This is a bold green string", 3));
    ASSUME_ITS_TRUE(mockup_output_verify(mock_output, "This is an underlined blue string", 4));
    ASSUME_ITS_TRUE(mockup_output_verify(mock_output, "This is a bold and underlined yellow string", 5));

    // Verify call count
    ASSUME_ITS_TRUE(fossil_mockup_output_verify_call_count(mock_output, 6));

    // Erase the mock output object
    mockup_output_erase(mock_output);
}

// Additional test cases for mixing fstring and classic formatting
FOSSIL_TEST(fossil_console_out_mix_fstring_classic_test) {
    fossil_mockup_output_t *mock_output = fossil_mockup_output_create("fossil_console_out");

    // Capture console output
    fossil_mockup_output_capture(mock_output, "This is a bold string and this is a classic string");

    // Test mixing fstring and classic formatting with fossil_console_out function
    fossil_console_out("f{str:bold} and this is an %s string", "This is a bold string", "classic");

    // Verify that the output is correct
    ASSUME_ITS_TRUE(fossil_mockup_output_verify(mock_output, "This is a bold string and this is a classic string", 0));

    // Verify call count
    ASSUME_ITS_TRUE(fossil_mockup_output_verify_call_count(mock_output, 1));

    // Erase the mock output object
    fossil_mockup_output_erase(mock_output);
}

// Test case for classic formatting with different types in fossil_console_out function
FOSSIL_TEST(fossil_console_out_classic_format_types_test) {
    fossil_mockup_output_t *mock_output = fossil_mockup_output_create("fossil_console_out");

    // Capture console output
    fossil_mockup_output_capture(mock_output, "10 20 30 40 50 60 70 80 123 83 a hello 0x12345678 3.14 3.14159");

    // Test different types with fossil_console_out function and classic formatting
    fossil_console_out("%i8 %i16 %i32 %i64 %u8 %u16 %u32 %u64 %x %o %c %s %p %f %lf",
                     (int8_t)10, (int16_t)20, (int32_t)30, (int64_t)40,
                     (uint8_t)50, (uint16_t)60, (uint32_t)70, (uint64_t)80,
                     (uint32_t)0x123, (uint32_t)0123, 'a', "hello",
                     (void*)0x12345678, 3.14f, 3.14159);

    // Verify that the output is correct
    ASSUME_ITS_TRUE(fossil_mockup_output_verify(mock_output, "10 20 30 40 50 60 70 80 123 83 a hello 0x12345678 3.14 3.14159", 0));

    // Verify call count
    ASSUME_ITS_TRUE(fossil_mockup_output_verify_call_count(mock_output, 1));

    // Erase the mock output object
    fossil_mockup_output_erase(mock_output);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(test_output_group) {
    ADD_TEST(fossil_console_out_fstr_test);
    ADD_TEST(fossil_console_out_fstr_types_test);
    ADD_TEST(fossil_console_out_mix_classic_fstring_test);
    ADD_TEST(fossil_console_out_classic_format_types_test);
    ADD_TEST(fossil_console_out_fstring_features_test);
    ADD_TEST(fossil_console_out_mix_fstring_classic_test);
}
