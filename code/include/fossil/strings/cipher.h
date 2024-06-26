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
#ifndef FOSSIL_STR_CIPHER_H
#define FOSSIL_STR_CIPHER_H

/**
 * @brief Cipher Functions for Classic C Strings
 * 
 * This header file contains functions for encrypting and decrypting messages using various classic ciphers.
 * 
 * Usage:
 * 
 * Example:
 * 
 * @code
 * cstring message = "Hello, World!";
 * fossil_cipher_caesar_encrypt(message, 3); // Encrypt message using Caesar cipher with shift 3
 * @endcode
 */

#include "cstring.h"

#ifdef __cplusplus
extern "C"
{
#endif

// =================================================================
// Available Functions
// =================================================================

/**
 * Cipher functions for classic C strings
 */

/**
 * Encrypt a message using the Caesar cipher with a given shift.
 * 
 * @param message The message to encrypt.
 * @param shift The shift value for encryption.
 */
void fossil_cipher_caesar_encrypt(cstring message, int shift);

/**
 * Decrypt a message encrypted using the Caesar cipher with a given shift.
 * 
 * @param message The message to decrypt.
 * @param shift The shift value for decryption.
 */
void fossil_cipher_caesar_decrypt(cstring message, int shift);

/**
 * Encrypt a message using the Atbash cipher.
 * 
 * @param message The message to encrypt.
 */
void fossil_cipher_atbash_encrypt(cstring message);

/**
 * Decrypt a message encrypted using the Atbash cipher.
 * 
 * @param message The message to decrypt.
 */
void fossil_cipher_atbash_decrypt(cstring message);

/**
 * Encrypt a message using the substitution cipher with a given key.
 * 
 * @param message The message to encrypt.
 * @param key The substitution key.
 */
void fossil_cipher_substitution_encrypt(cstring message, const_cstring key);

/**
 * Decrypt a message encrypted using the substitution cipher with a given key.
 * 
 * @param message The message to decrypt.
 * @param key The substitution key.
 */
void fossil_cipher_substitution_decrypt(cstring message, const_cstring key);

/**
 * Encrypt a message using the Haxor cipher.
 * 
 * @param message The message to encrypt.
 */
void fossil_cipher_haxor_encrypt(cstring message);

/**
 * Decrypt a message encrypted using the Haxor cipher.
 * 
 * @param message The message to decrypt.
 */
void fossil_cipher_haxor_decrypt(cstring message);

/**
 * Encrypt a message using the Morse code.
 * 
 * @param message The message to encrypt.
 */
void fossil_cipher_morse_encrypt(cstring message);

/**
 * Decrypt a message encrypted using the Morse code.
 * 
 * @param message The message to decrypt.
 */
void fossil_cipher_morse_decrypt(cstring message);

/**
 * Encrypt a message using the ROT13 cipher.
 * 
 * @param message The message to encrypt.
 */
void fossil_cipher_rot13_encrypt(cstring message);

/**
 * Decrypt a message encrypted using the ROT13 cipher.
 * 
 * @param message The message to decrypt.
 */
void fossil_cipher_rot13_decrypt(cstring message);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include <stdexcept>

namespace fossil {
    class Cipher {
    public:
        /**
         * Encrypt a message using the Caesar cipher with a given shift.
         * 
         * @param message The message to encrypt.
         * @param shift The shift value for encryption.
         * @throws std::invalid_argument if the message is empty.
         */
        static void caesar_encrypt(cstring message, int shift) {
            if (message == cnullptr) {
                throw std::invalid_argument("Message cannot be empty");
            }
            /** Encrypt the message using the Caesar cipher with the given shift */
            fossil_cipher_caesar_encrypt(message, shift);
        }

        /**
         * Decrypt a message encrypted using the Caesar cipher with a given shift.
         * 
         * @param message The message to decrypt.
         * @param shift The shift value for decryption.
         * @throws std::invalid_argument if the message is empty.
         */
        static void caesar_decrypt(cstring message, int shift) {
            if (message == cnullptr) {
                throw std::invalid_argument("Message cannot be empty");
            }
            /** Decrypt the message using the Caesar cipher with the given shift */
            fossil_cipher_caesar_decrypt(message, shift);
        }

        /**
         * Encrypt a message using the Atbash cipher.
         * 
         * @param message The message to encrypt.
         * @throws std::invalid_argument if the message is empty.
         */
        static void atbash_encrypt(cstring message) {
            if (message == cnullptr) {
                throw std::invalid_argument("Message cannot be empty");
            }
            /** Encrypt the message using the Atbash cipher */
            fossil_cipher_atbash_encrypt(message);
        }

        /**
         * Decrypt a message encrypted using the Atbash cipher.
         * 
         * @param message The message to decrypt.
         * @throws std::invalid_argument if the message is empty.
         */
        static void atbash_decrypt(cstring message) {
            if (message == cnullptr) {
                throw std::invalid_argument("Message cannot be empty");
            }
            /** Decrypt the message using the Atbash cipher */
            fossil_cipher_atbash_decrypt(message);
        }

        /**
         * Encrypt a message using the substitution cipher with a given key.
         * 
         * @param message The message to encrypt.
         * @param key The substitution key.
         * @throws std::invalid_argument if the message is empty or the key is empty.
         */
        static void substitution_encrypt(cstring message, const_cstring key) {
            if (message == cnullptr) {
                throw std::invalid_argument("Message cannot be empty");
            }
            if (key == cnullptr) {
                throw std::invalid_argument("Key cannot be empty");
            }
            /** Encrypt the message using the substitution cipher with the given key */
            fossil_cipher_substitution_encrypt(message, key);
        }

        /**
         * Decrypt a message encrypted using the substitution cipher with a given key.
         * 
         * @param message The message to decrypt.
         * @param key The substitution key.
         * @throws std::invalid_argument if the message is empty or the key is empty.
         */
        static void substitution_decrypt(cstring message, const_cstring key) {
            if (message == cnullptr) {
                throw std::invalid_argument("Message cannot be empty");
            }
            if (key == cnullptr) {
                throw std::invalid_argument("Key cannot be empty");
            }
            /** Decrypt the message using the substitution cipher with the given key */
            fossil_cipher_substitution_decrypt(message, key);
        }

        /**
         * Encrypt a message using the Haxor cipher.
         * 
         * @param message The message to encrypt.
         * @throws std::invalid_argument if the message is empty.
         */
        static void haxor_encrypt(cstring message) {
            if (message == cnullptr) {
                throw std::invalid_argument("Message cannot be empty");
            }
            /** Encrypt the message using the Haxor cipher */
            fossil_cipher_haxor_encrypt(message);
        }

        /**
         * Decrypt a message encrypted using the Haxor cipher.
         * 
         * @param message The message to decrypt.
         * @throws std::invalid_argument if the message is empty.
         */
        static void haxor_decrypt(cstring message) {
            if (message == cnullptr) {
                throw std::invalid_argument("Message cannot be empty");
            }
            /** Decrypt the message using the Haxor cipher */
            fossil_cipher_haxor_decrypt(message);
        }

        /**
         * Encrypt a message using the Morse code.
         * 
         * @param message The message to encrypt.
         * @throws std::invalid_argument if the message is empty.
         */
        static void morse_encrypt(cstring message) {
            if (message == cnullptr) {
                throw std::invalid_argument("Message cannot be empty");
            }
            /** Encrypt the message using the Morse code */
            fossil_cipher_morse_encrypt(message);
        }

        /**
         * Decrypt a message encrypted using the Morse code.
         * 
         * @param message The message to decrypt.
         * @throws std::invalid_argument if the message is empty.
         */
        static void morse_decrypt(cstring message) {
            if (message == cnullptr) {
                throw std::invalid_argument("Message cannot be empty");
            }
            /** Decrypt the message using the Morse code */
            fossil_cipher_morse_decrypt(message);
        }

        /**
         * Encrypt a message using the ROT13 cipher.
         * 
         * @param message The message to encrypt.
         * @throws std::invalid_argument if the message is empty.
         */
        static void rot13_encrypt(cstring message) {
            if (message == cnullptr) {
                throw std::invalid_argument("Message cannot be empty");
            }
            /** Encrypt the message using the ROT13 cipher */
            fossil_cipher_rot13_encrypt(message);
        }

        /**
         * Decrypt a message encrypted using the ROT13 cipher.
         * 
         * @param message The message to decrypt.
         * @throws std::invalid_argument if the message is empty.
         */
        static void rot13_decrypt(cstring message) {
            if (message == cnullptr) {
                throw std::invalid_argument("Message cannot be empty");
            }
            /** Decrypt the message using the ROT13 cipher */
            fossil_cipher_rot13_decrypt(message);
        }
    };
}

#endif

#endif
