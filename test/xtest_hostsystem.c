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
#include "fossil/stdtool/hostsystem.h" // lib source code

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


FOSSIL_TEST(test_fossil_hostsys_get) {
    fossil_hostsystem_t info;
    ASSUME_ITS_TRUE(fossil_hostsys_get(&info));
    ASSUME_NOT_EQUAL_CSTRING("", info.os_name);
    ASSUME_NOT_EQUAL_CSTRING("", info.os_version);
    ASSUME_NOT_EQUAL_CSTRING("", info.cpu_model);
    ASSUME_ITS_MORE_OR_EQUAL_I32(0, info.cpu_cores);
    ASSUME_ITS_MORE_OR_EQUAL_I32(0, info.total_memory);
    ASSUME_ITS_MORE_OR_EQUAL_I32(0, info.free_memory);
}

FOSSIL_TEST(test_fossil_hostsys_endian) {
    fossil_hostsystem_t info;
    fossil_hostsys_get(&info);
    ASSUME_ITS_TRUE(fossil_hostsys_endian(&info) != NULL);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(test_hostsystem_group) {
    ADD_TEST(test_fossil_hostsys_get);
    ADD_TEST(test_fossil_hostsys_endian);
} // end of function main
