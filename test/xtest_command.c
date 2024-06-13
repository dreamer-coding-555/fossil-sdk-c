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
#include "fossil/stdtool/command.h" // lib source code

#include <fossil/unittest.h>   // basic test tools
#include <fossil/xassume.h> // extra asserts


// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilites
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

// Define Meson build commands for testing
fossil_command_t meson_configure_cmd = "meson build";
fossil_command_t ninja_build_cmd = "ninja -C build";

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(test_meson_configure) {
    ASSUME_ITS_EQUAL_I32(0, fossil_command_success(meson_configure_cmd));
}

FOSSIL_TEST(test_ninja_build) {
    ASSUME_ITS_EQUAL_I32(0, fossil_command_success(ninja_build_cmd));
}

FOSSIL_TEST(test_command_exists) {
    // Assuming that 'ls' is a valid command
    ASSUME_ITS_EQUAL_I32(1, fossil_command_exists("ls"));

    // Assuming that 'nonexistentcommand' is not a valid command
    ASSUME_ITS_EQUAL_I32(0, fossil_command_exists("nonexistentcommand"));
}

FOSSIL_TEST(test_command_strcat_safe) {
    char result[100] = "start";
    fossil_command_strcat_safe(result, " && ", sizeof(result));
    fossil_command_strcat_safe(result, "echo Hello", sizeof(result));

    ASSUME_ITS_EQUAL_CSTR("start && echo Hello", result);
}

FOSSIL_TEST(test_fossil_filesys_exists) {
    // Assuming that the directory 'build' does not exist initially
    ASSUME_ITS_EQUAL_I32(0, fossil_command_erase_exists("build"));

    // Creating the directory for testing purposes
    fossil_command_success("mkdir build");

    ASSUME_ITS_EQUAL_I32(1, fossil_command_erase_exists("build"));

    // Cleaning up: Remove the created directory
    fossil_command_success("rmdir build");
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(test_command_group) {
    ADD_TEST(test_meson_configure);
    ADD_TEST(test_ninja_build);
    ADD_TEST(test_command_exists);
    ADD_TEST(test_command_strcat_safe);
    ADD_TEST(test_fossil_filesys_exists);
} // end of function main
