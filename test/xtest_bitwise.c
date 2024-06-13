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
#include "fossil/stdtool/bitwise.h" // lib source code

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

XTEST(test_fossil_binary_and) {
    // 8-bit AND
    ASSUME_ITS_EQUAL_U8(0x01, fossil_binary_and8(0x0F, 0x01));
    
    // 16-bit AND
    ASSUME_ITS_EQUAL_U16(0x0001, fossil_binary_and16(0x00FF, 0x0001));
    
    // 32-bit AND
    ASSUME_ITS_EQUAL_U32(0x00000001, fossil_binary_and(0x0000000F, 0x00000001));
    
    // 64-bit AND
    ASSUME_ITS_EQUAL_U64(0x0000000000000001, fossil_binary_and64(0x00000000000000FF, 0x0000000000000001));
}

XTEST(test_fossil_binary_or) {
    // 8-bit OR
    ASSUME_ITS_EQUAL_U8(0x0F, fossil_binary_or8(0x0F, 0x01));
    
    // 16-bit OR
    ASSUME_ITS_EQUAL_U16(0x00FF, fossil_binary_or16(0x00FF, 0x0001));
    
    // 32-bit OR
    ASSUME_ITS_EQUAL_U32(0x0000000F, fossil_binary_or(0x0000000F, 0x00000001));
    
    // 64-bit OR
    ASSUME_ITS_EQUAL_U64(0x00000000000000FF, fossil_binary_or64(0x00000000000000FF, 0x0000000000000001));
}

XTEST(test_fossil_binary_xor) {
    // 8-bit XOR
    ASSUME_ITS_EQUAL_U8(0x0E, fossil_binary_xor8(0x0F, 0x01));
    
    // 16-bit XOR
    ASSUME_ITS_EQUAL_U16(0x00FE, fossil_binary_xor16(0x00FF, 0x0001));
    
    // 32-bit XOR
    ASSUME_ITS_EQUAL_U32(0x0000000E, fossil_binary_xor(0x0000000F, 0x00000001));
    
    // 64-bit XOR
    ASSUME_ITS_EQUAL_U64(0x00000000000000FE, fossil_binary_xor64(0x00000000000000FF, 0x0000000000000001));
}

XTEST(test_fossil_binary_left_shift) {
    // 8-bit Left Shift
    ASSUME_ITS_EQUAL_U8(0x1E, fossil_binary_left_shift8(0x0F, 1));
    
    // 16-bit Left Shift
    ASSUME_ITS_EQUAL_U16(0x0002, fossil_binary_left_shift16(0x0001, 1));
    
    // 32-bit Left Shift
    ASSUME_ITS_EQUAL_U32(0x0000001E, fossil_binary_left_shift(0x0000000F, 1));
    
    // 64-bit Left Shift
    ASSUME_ITS_EQUAL_U64(0x00000000000000FE, fossil_binary_left_shift64(0x000000000000007F, 1));
}

XTEST(test_fossil_binary_right_shift) {
    // 8-bit Right Shift
    ASSUME_ITS_EQUAL_U8(0x07, fossil_binary_right_shift8(0x0F, 1));
    
    // 16-bit Right Shift
    ASSUME_ITS_EQUAL_U16(0x0000, fossil_binary_right_shift16(0x0001, 1));
    
    // 32-bit Right Shift
    ASSUME_ITS_EQUAL_U32(0x00000007, fossil_binary_right_shift(0x0000000F, 1));
    
    // 64-bit Right Shift
    ASSUME_ITS_EQUAL_U64(0x000000000000003F, fossil_binary_right_shift64(0x000000000000007F, 1));
}

XTEST(test_fossil_binary_count_set_bits) {
    // 8-bit Count Set Bits
    ASSUME_ITS_EQUAL_I32(4, fossil_binary_count_set_bits8(0x0F));
    
    // 16-bit Count Set Bits
    ASSUME_ITS_EQUAL_I32(8, fossil_binary_count_set_bits16(0xFFFF));
    
    // 32-bit Count Set Bits
    ASSUME_ITS_EQUAL_I32(16, fossil_binary_count_set_bits(0xFFFFFFFF));
    
    // 64-bit Count Set Bits
    ASSUME_ITS_EQUAL_I32(32, fossil_binary_count_set_bits64(0xFFFFFFFFFFFFFFFF));
}

XTEST(test_fossil_binary_toggle_bits) {
    // 8-bit Toggle Bits
    ASSUME_ITS_EQUAL_U8(0xF0, fossil_binary_toggle_bits8(0x0F));
    
    // 16-bit Toggle Bits
    ASSUME_ITS_EQUAL_U16(0xFF00, fossil_binary_toggle_bits16(0x00FF));
    
    // 32-bit Toggle Bits
    ASSUME_ITS_EQUAL_U32(0xFFFFFFF0, fossil_binary_toggle_bits(0x0000000F));
    
    // 64-bit Toggle Bits
    ASSUME_ITS_EQUAL_U64(0xFFFFFFFFFFFFFFF0, fossil_binary_toggle_bits64(0x000000000000000F));
}

XTEST(test_fossil_binary_rotate_left) {
    // 8-bit Rotate Left
    ASSUME_ITS_EQUAL_U8(0xF0, fossil_binary_rotate_left8(0x0F, 4));
    
    // 16-bit Rotate Left
    ASSUME_ITS_EQUAL_U16(0xFF00, fossil_binary_rotate_left16(0x00FF, 8));
    
    // 32-bit Rotate Left
    ASSUME_ITS_EQUAL_U32(0xF000000F, fossil_binary_rotate_left(0x0000000F, 4));
    
    // 64-bit Rotate Left
    ASSUME_ITS_EQUAL_U64(0xF00000000000000F, fossil_binary_rotate_left64(0x000000000000000F, 4));
}

XTEST(test_fossil_binary_rotate_right) {
    // 8-bit Rotate Right
    ASSUME_ITS_EQUAL_U8(0xF0, fossil_binary_rotate_right8(0x0F, 4));
    
    // 16-bit Rotate Right
    ASSUME_ITS_EQUAL_U16(0xFF00, fossil_binary_rotate_right16(0x00FF, 8));
    
    // 32-bit Rotate Right
    ASSUME_ITS_EQUAL_U32(0xF000000F, fossil_binary_rotate_right(0x0000000F, 4));
    
    // 64-bit Rotate Right
    ASSUME_ITS_EQUAL_U64(0xF00000000000000F, fossil_binary_rotate_right64(0x000000000000000F, 4));
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
XTEST_DEFINE_POOL(test_bitwise_group) {
    ADD_TEST(test_fossil_binary_and);
    ADD_TEST(test_fossil_binary_or);
    ADD_TEST(test_fossil_binary_xor);
    ADD_TEST(test_fossil_binary_left_shift);
    ADD_TEST(test_fossil_binary_right_shift);
    ADD_TEST(test_fossil_binary_count_set_bits);
    ADD_TEST(test_fossil_binary_toggle_bits);
    ADD_TEST(test_fossil_binary_rotate_left);
    ADD_TEST(test_fossil_binary_rotate_right);
} // end of function main
