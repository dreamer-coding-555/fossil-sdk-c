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
#include "fossil/string/cipher.h" // lib source code

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

FOSSIL_TEST(test_fossil_cipher_caesar_encrypt) {
    cstring message = "Hello, World!";
    int shift = 3;
    fossil_cipher_caesar_encrypt(message, shift);

    TEST_ASSUME_EQUAL_CSTRING("Khoor, Zruog!", message);

    // Decrypt to original message
    fossil_cipher_caesar_decrypt(message, shift);
    TEST_ASSUME_EQUAL_CSTRING("Hello, World!", message);
}

FOSSIL_TEST(test_fossil_cipher_caesar_decrypt) {
    cstring message = "Khoor, Zruog!";
    int shift = 3;
    fossil_cipher_caesar_decrypt(message, shift);

    TEST_ASSUME_EQUAL_CSTRING("Hello, World!", message);
}

FOSSIL_TEST(test_fossil_cipher_atbash_encrypt) {
    cstring message = "Hello, World!";
    fossil_cipher_atbash_encrypt(message);

    TEST_ASSUME_EQUAL_CSTRING("Svool, Dliow!", message);

    // Decrypt to original message
    fossil_cipher_atbash_decrypt(message);
    TEST_ASSUME_EQUAL_CSTRING("Hello, World!", message);
}

FOSSIL_TEST(test_fossil_cipher_atbash_decrypt) {
    cstring message = "Svool, Dliow!";
    fossil_cipher_atbash_decrypt(message);

    TEST_ASSUME_EQUAL_CSTRING("Hello, World!", message);
}

FOSSIL_TEST(test_fossil_cipher_substitution_encrypt) {
    cstring message = "Hello, World!";
    const_cstring key = "zyxwvutsrqponmlkjihgfedcba";
    fossil_cipher_substitution_encrypt(message, key);

    TEST_ASSUME_EQUAL_CSTRING("Svool, Dliow!", message);

    // Decrypt to original message
    fossil_cipher_substitution_decrypt(message, key);
    TEST_ASSUME_EQUAL_CSTRING("Hello, World!", message);
}

FOSSIL_TEST(test_fossil_cipher_substitution_decrypt) {
    cstring message = "Svool, Dliow!";
    const_cstring key = "zyxwvutsrqponmlkjihgfedcba";
    fossil_cipher_substitution_decrypt(message, key);

    TEST_ASSUME_EQUAL_CSTRING("Hello, World!", message);
}

FOSSIL_TEST(test_fossil_cipher_haxor_encrypt) {
    cstring message = "Hello, World!";
    fossil_cipher_haxor_encrypt(message);

    TEST_ASSUME_EQUAL_CSTRING("H3ll0, W0rld!", message);

    // Decrypt to original message
    fossil_cipher_haxor_decrypt(message);
    TEST_ASSUME_EQUAL_CSTRING("Hello, World!", message);
}

FOSSIL_TEST(test_fossil_cipher_haxor_decrypt) {
    cstring message = "H3ll0, W0rld!";
    fossil_cipher_haxor_decrypt(message);

    TEST_ASSUME_EQUAL_CSTRING("Hello, World!", message);
}

FOSSIL_TEST(test_fossil_cipher_morse_encrypt) {
    cstring message = "Hello, World!";
    fossil_cipher_morse_encrypt(message);

    TEST_ASSUME_EQUAL_CSTRING(".... . .-.. .-.. --- --..-- / .-- --- .-. .-.. -.. -.-.--", message);

    // Decrypt to original message
    fossil_cipher_morse_decrypt(message);
    TEST_ASSUME_EQUAL_CSTRING("Hello, World!", message);
}

FOSSIL_TEST(test_fossil_cipher_morse_decrypt) {
    cstring message = ".... . .-.. .-.. --- --..-- / .-- --- .-. .-.. -.. -.-.--";
    fossil_cipher_morse_decrypt(message);

    TEST_ASSUME_EQUAL_CSTRING("Hello, World!", message);
}

FOSSIL_TEST(test_fossil_cipher_rot13_encrypt) {
    cstring message = "Hello, World!";
    fossil_cipher_rot13_encrypt(message);

    TEST_ASSUME_EQUAL_CSTRING("Uryyb, Jbeyq!", message);

    // Decrypt to original message
    fossil_cipher_rot13_decrypt(message);
    TEST_ASSUME_EQUAL_CSTRING("Hello, World!", message);
}

FOSSIL_TEST(test_fossil_cipher_rot13_decrypt) {
    cstring message = "Uryyb, Jbeyq!";
    fossil_cipher_rot13_decrypt(message);

    TEST_ASSUME_EQUAL_CSTRING("Hello, World!", message);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(fossil_cipher_group) {
    ADD_TEST(test_fossil_cipher_caesar_encrypt);
    ADD_TEST(test_fossil_cipher_caesar_decrypt);
    ADD_TEST(test_fossil_cipher_atbash_encrypt);
    ADD_TEST(test_fossil_cipher_atbash_decrypt);
    ADD_TEST(test_fossil_cipher_substitution_encrypt);
    ADD_TEST(test_fossil_cipher_substitution_decrypt);
    ADD_TEST(test_fossil_cipher_haxor_encrypt);
    ADD_TEST(test_fossil_cipher_haxor_decrypt);
    ADD_TEST(test_fossil_cipher_morse_encrypt);
    ADD_TEST(test_fossil_cipher_morse_decrypt);
    ADD_TEST(test_fossil_cipher_rot13_encrypt);
    ADD_TEST(test_fossil_cipher_rot13_decrypt);
} // end of function main
