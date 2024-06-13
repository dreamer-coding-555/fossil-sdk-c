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
#include "fossil/stdtool/random.h" // lib source code

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

FOSSIL_TEST(test_fossil_random_seed) {
    fossil_random_t rng;
    uint32_t seed = 12345;
    fossil_random_seed(&rng, seed);
    ASSUME_ITS_EQUAL_U32(seed, rng.current_seed);
}

FOSSIL_TEST(test_fossil_random_uint32) {
    fossil_random_t rng;
    fossil_random_seed(&rng, 12345);
    uint32_t value = fossil_random_uint32(&rng);
    ASSUME_ITS_LESS_THAN_U32(65536, value);
}

FOSSIL_TEST(test_fossil_random_uint64) {
    fossil_random_t rng;
    fossil_random_seed(&rng, 12345);
    uint64_t value = fossil_random_uint64(&rng);
    ASSUME_ITS_LESS_THAN_U32(65536, value);
}

FOSSIL_TEST(test_fossil_random_int_range) {
    fossil_random_t rng;
    fossil_random_seed(&rng, 12345);
    fossil_random_int_range(&rng, 0, 10);
}

FOSSIL_TEST(test_fossil_random_float) {
    fossil_random_t rng;
    fossil_random_seed(&rng, 12345);
    float value = fossil_random_float(&rng);
    ASSUME_ITS_TRUE(value >= 0.0f && value < 1.0f); // Check if value is between 0 and 1
}

FOSSIL_TEST(test_fossil_random_double) {
    fossil_random_t rng;
    fossil_random_seed(&rng, 12345);
    double value = fossil_random_double(&rng);
    ASSUME_ITS_TRUE(value >= 0.0 && value < 1.0); // Check if value is between 0 and 1
}

FOSSIL_TEST(test_fossil_random_hex) {
    fossil_random_t rng;
    fossil_random_seed(&rng, 12345);
    uint32_t value = fossil_random_hex(&rng, 16); // 16-bit hexadecimal
    ASSUME_ITS_LESS_THAN_U32(0x10000, value); // Check if value is within range 0-0xFFFF
}

FOSSIL_TEST(test_fossil_random_oct) {
    fossil_random_t rng;
    fossil_random_seed(&rng, 12345);
    uint32_t value = fossil_random_oct(&rng, 9); // 9-bit octal
    ASSUME_ITS_LESS_THAN_U32(0x200, value); // Check if value is within range 0-0x1FF
}

FOSSIL_TEST(test_fossil_random_binary) {
    fossil_random_t rng;
    fossil_random_seed(&rng, 12345);
    uint32_t value = fossil_random_binary(&rng, 8); // 8-bit binary
    ASSUME_ITS_LESS_THAN_U32(0x100, value); // Check if value is within range 0-0xFF
}

FOSSIL_TEST(test_fossil_random_yield_seed) {
    uint32_t seed = fossil_random_yield_seed();
    // Since seed is based on time and other factors, just check if it's non-zero
    ASSUME_NOT_EQUAL_I32(0, seed);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(test_spawn_group) {
    ADD_TEST(test_fossil_random_seed);
    ADD_TEST(test_fossil_random_uint32);
    ADD_TEST(test_fossil_random_uint64);
    ADD_TEST(test_fossil_random_int_range);
    ADD_TEST(test_fossil_random_float);
    ADD_TEST(test_fossil_random_double);
    ADD_TEST(test_fossil_random_hex);
    ADD_TEST(test_fossil_random_oct);
    ADD_TEST(test_fossil_random_binary);
    ADD_TEST(test_fossil_random_yield_seed);
} // end of func
