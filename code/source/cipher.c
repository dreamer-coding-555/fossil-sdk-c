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
#include "fossil/string/cipher.h"
#include "fossil/common/common.h"
#include "fossil/string/manip.h"
#include <string.h>
#include <stdlib.h>

enum {
    CIPHER_ROT13 = 13
};

// Helper function for Caesar cipher
static cletter fossil_cipher_caesar_shift_char(cletter ch, int shift) {
    if (fossil_cletter_is_alpha(ch)) {
        cletter base = (fossil_cletter_is_lower(ch) ? 'a' : 'A');
        return ((ch - base + shift) % 26) + base;
    }
    return ch;
}

// Helper function for Atbash cipher
static cletter fossil_cipher_atbash_encrypt_char(cletter ch) {
    if (fossil_cletter_is_alpha(ch)) {
        cletter base = (fossil_cletter_is_lower(ch) ? 'a' : 'A');
        return (25 - (ch - base)) + base;
    }
    return ch;
}

// Helper function for Substitution cipher
static cletter fossil_cipher_substitution_encrypt_char(cletter ch, const_cstring key) {
    if (fossil_cletter_is_alpha(ch)) {
        cletter base = (fossil_cletter_is_lower(ch) ? 'a' : 'A');
        return key[ch - base];
    }
    return ch;
}

// Helper function for Haxor cipher
static cletter fossil_cipher_haxor_encrypt_char(cletter ch) {
    if (fossil_cletter_is_alpha(ch)) {
        if (fossil_cletter_is_lower(ch)) {
            return '0' + (ch - 'a');
        } else {
            return '0' + (ch - 'A');
        }
    }
    return ch;
}

// Helper function for Morse code cipher
static const_cstring morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", 
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", 
    "..-", "...-", ".--", "-..-", "-.--", "--.."
};

static const_cstring fossil_cipher_morse_encrypt_char(cletter ch) {
    if (fossil_cletter_is_alpha(ch)) {
        return morse_code[fossil_cletter_to_lower(ch) - 'a'];
    }
    return "";
}

// Cipher functions

void fossil_cipher_caesar_encrypt(cstring message, int shift) {
    if (!message) {
        return;
    }
    size_t len = fossil_cstr_length(message);
    for (size_t i = 0; i < len; i++) {
        message[i] = fossil_cipher_caesar_shift_char(message[i], shift);
    }
}

void fossil_cipher_caesar_decrypt(cstring message, int shift) {
    if (!message) {
        return;
    }
    size_t len = fossil_cstr_length(message);
    for (size_t i = 0; i < len; i++) {
        message[i] = fossil_cipher_caesar_shift_char(message[i], -shift);
    }
}

void fossil_cipher_atbash_encrypt(cstring message) {
    if (!message) {
        return;
    }
    size_t len = fossil_cstr_length(message);
    for (size_t i = 0; i < len; i++) {
        message[i] = fossil_cipher_atbash_encrypt_char(message[i]);
    }
}

void fossil_cipher_atbash_decrypt(cstring message) {
    // Atbash decryption is the same as encryption
    fossil_cipher_atbash_encrypt(message);
}

void fossil_cipher_substitution_encrypt(cstring message, const_cstring key) {
    if (!message || !key) {
        return;
    }
    size_t len = fossil_cstr_length(message);
    for (size_t i = 0; i < len; i++) {
        message[i] = fossil_cipher_substitution_encrypt_char(message[i], key);
    }
}

void fossil_cipher_substitution_decrypt(cstring message, const_cstring key) {
    if (!message || !key) {
        return;
    }
    // For decryption, we need to reverse the key
    char reverse_key[26];
    for (int i = 0; i < 26; i++) {
        reverse_key[key[i] - 'a'] = 'a' + i;
    }
    size_t len = fossil_cstr_length(message);
    for (size_t i = 0; i < len; i++) {
        message[i] = fossil_cipher_substitution_encrypt_char(message[i], reverse_key);
    }
}

void fossil_cipher_haxor_encrypt(cstring message) {
    if (!message) {
        return;
    }
    size_t len = fossil_cstr_length(message);
    for (size_t i = 0; i < len; i++) {
        message[i] = fossil_cipher_haxor_encrypt_char(message[i]);
    }
}

void fossil_cipher_haxor_decrypt(cstring message) {
    // Haxor decryption is the same as encryption
    fossil_cipher_haxor_encrypt(message);
}

void fossil_cipher_morse_encrypt(cstring message) {
    if (!message) {
        return;
    }
    size_t len = fossil_cstr_length(message);
    cstring encrypted = malloc(len * 5 + 1); // Assuming the maximum length of Morse code for each character is 5
    encrypted[0] = '\0';
    for (size_t i = 0; i < len; i++) {
        if (fossil_cletter_is_alpha(message[i])) {
            fossil_cstr_concat(encrypted, fossil_cipher_morse_encrypt_char(message[i]));
            fossil_cstr_concat(encrypted, " ");
        } else if (message[i] == ' ') {
            fossil_cstr_concat(encrypted, "/ ");
        }
    }
    fossil_cstr_copy(message, encrypted);
    free(encrypted);
}

void fossil_cipher_morse_decrypt(cstring message) {
    if (!message) {
        return;
    }
    size_t len = fossil_cstr_length(message);
    cstring decrypted = malloc(len / 4 + 1); // Assuming the maximum length of Morse code for each character is 5 and space between characters is 1
    decrypted[0] = '\0';
    
    const char delimiter[] = " / ";
    cstring token = strtok(message, delimiter);
    while (token != cnullptr) {
        for (int i = 0; i < 26; i++) {
            if (strcmp(morse_code[i], token) == 0) {
                char ch = 'a' + i;
                if (fossil_cletter_is_upper(message[0])) {
                    ch = fossil_cletter_to_upper(ch);
                }
                fossil_cstr_concat(decrypted, &ch);
                break;
            }
        }
        token = strtok(cnullptr, delimiter);
    }
    
    fossil_cstr_copy(message, decrypted);
    free(decrypted);
}

void fossil_cipher_rot13_encrypt(cstring message) {
    fossil_cipher_caesar_encrypt(message, CIPHER_ROT13);
}

void fossil_cipher_rot13_decrypt(cstring message) {
    fossil_cipher_caesar_decrypt(message, CIPHER_ROT13);
}
