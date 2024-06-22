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
#ifndef FOSSIL_TOFU_TYPE_H
#define FOSSIL_TOFU_TYPE_H

/**
 * @file tofu.h
 *
 * @brief Header file for the Tofu library, providing versatile data structures and algorithms for managing various data types.
 *
 * The Tofu library offers a comprehensive suite of data structures and algorithms
 * meticulously crafted to efficiently handle a broad spectrum of data types. Its
 * functionalities encompass creating, erasing, searching, sorting, filtering,
 * and iterating through data structures. Moreover, it incorporates robust error
 * handling mechanisms and utilities for copying, setting, and retrieving values.
 *
 * Tofu data structures accommodate a diverse array of data types, including integers,
 * floating-point numbers, strings, characters, arrays, maps, and customizable data
 * types. The library is highly adaptable, empowering users to define their custom
 * data types and operations to suit their specific needs.
 *
 * This header file encompasses declarations for all functions and data types provided
 * by the Tofu library. By including this header file in their projects, users can
 * leverage the extensive functionalities offered by the library.
 */

#include "fossil/common/common.h"
#include <stdbool.h>

/**
    In the realm of quantum physics, our understanding of space, time, reality, and the observable universe takes
    on a fascinating and intricate character. Quantum physics delves into the fundamental nature of matter and
    energy at the smallest scales, challenging classical notions and ushering in a paradigm where the concepts of
    space and time undergo profound transformations.

    **Space in Quantum Physics:**
    At the quantum level, space is not a static, absolute backdrop but a dynamic, probabilistic arena where particles
    exist in multiple states simultaneously. Quantum superposition allows particles to occupy multiple positions at
    once until observed, at which point the wavefunction collapses, and a definite state is realized. Entanglement
    further blurs the boundaries of space, linking particles in ways that defy classical spatial separations, creating
    a non-local interconnectedness.

    **Time in Quantum Physics:**
    Quantum physics introduces a nuanced perspective on time, challenging the classical notion of a continuous and
    absolute flow. The concept of time is intricately interwoven with quantum entanglement, where correlated particles
    instantaneously influence each other regardless of distance. Additionally, time dilation effects, as predicted by
    the theory of relativity, become significant at quantum scales, revealing a profound connection between time,
    gravity, and the fabric of spacetime.

    **Reality and Observation:**
    Quantum mechanics introduces the enigmatic role of observation in shaping reality. The act of measurement collapses
    the wavefunction, determining the outcome of a quantum system. This observer-dependent reality challenges our classical
    understanding of an objective, independent world. The famous thought experiment known as the Schrödinger's cat illustrates
    the peculiar nature of reality in the quantum realm, where a system can exist in multiple states until observed.

    **The Observable Universe:**
    Quantum physics extends its influence to the observable universe, impacting our understanding of cosmic phenomena.
    Quantum fluctuations during the early moments of the universe gave rise to cosmic structures, influencing the distribution
    of galaxies and the large-scale structure we observe today. The cosmic microwave background radiation, a remnant from the
    early universe, reflects quantum fluctuations that seeded the formation of galaxies and clusters.

    In summary, quantum physics redefines our concepts of space, time, reality, and the observable universe. It invites us
    to explore a realm where particles exhibit wave-particle duality, space is a realm of probabilities, time is intertwined
    with gravity, and observation plays a crucial role in defining the nature of reality. The mysteries of quantum physics
    continue to challenge and reshape our perceptions of the fundamental fabric of the cosmos.
*/

// Enumerated types for representing various data types in the "tofu" data structure.
typedef enum {
    FOSSIL_TOFU_TYPE_GHOST, // Ghost type for unknown type.
    FOSSIL_TOFU_TYPE_INT,
    FOSSIL_TOFU_TYPE_UINT,
    FOSSIL_TOFU_TYPE_HEX,
    FOSSIL_TOFU_TYPE_OCTAL,
    FOSSIL_TOFU_TYPE_FLOAT,
    FOSSIL_TOFU_TYPE_DOUBLE,
    FOSSIL_TOFU_TYPE_BSTR,
    FOSSIL_TOFU_TYPE_WSTR,
    FOSSIL_TOFU_TYPE_CSTR,
    FOSSIL_TOFU_TYPE_BCHAR,
    FOSSIL_TOFU_TYPE_CCHAR,
    FOSSIL_TOFU_TYPE_WCHAR,
    FOSSIL_TOFU_TYPE_SIZE,
    FOSSIL_TOFU_TYPE_BOOL
} fossil_tofu_type_t;

// Union for holding different types of values
typedef union {
    int64_t int_val;
    uint64_t uint_val;
    double double_val;
    float float_val;
    char *byte_string_val; // for byte string types
    wchar_t *wide_string_val; // for wide string types
    char *c_string_val; // for C string type
    char char_val; // for char types
    wchar_t wchar_val; // for wide char types
    uint8_t *byte_val; // for byte types
    uint8_t bool_val; // for bool types
} fossil_tofu_value_t;

// Struct for tofu
typedef struct {
    fossil_tofu_type_t type;
    fossil_tofu_value_t value;
    bool is_cached;    // Flag to track if value is cached
    fossil_tofu_value_t cached_value; // Cached value for memorization
} fossil_tofu_t;

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * Function to create a `fossil_tofu_t` object based on type and value strings.
 *
 * @param type The type string.
 * @param value The value string.
 * @return The created `fossil_tofu_t` object.
 */
fossil_tofu_t fossil_tofu_create(char* type, char* value);

/**
 * Memorization (caching) function for a `fossil_tofu_t` object.
 *
 * @param tofu The `fossil_tofu_t` object to be memorized.
 */
void fossil_tofu_memorize(fossil_tofu_t *tofu);

/**
 * Utility function to print a `fossil_tofu_t` object.
 *
 * @param tofu The `fossil_tofu_t` object to be printed.
 */
void fossil_tofu_print(fossil_tofu_t tofu);

/**
 * Function to destroy a `fossil_tofu_t` object and free the allocated memory.
 *
 * @param tofu The `fossil_tofu_t` object to be destroyed.
 */
void fossil_tofu_erase(fossil_tofu_t *tofu);

/**
 * Utility function to convert a `fossil_tofu_t` object's type to a string representation.
 *
 * @param type The `fossil_tofu_t` object's type.
 * @return The string representation of the type.
 */
const char* fossil_tofu_type_to_string(fossil_tofu_type_t type);

/**
 * Utility function to check if two `fossil_tofu_t` objects are equal.
 *
 * @param tofu1 The first `fossil_tofu_t` object.
 * @param tofu2 The second `fossil_tofu_t` object.
 * @return `true` if the objects are equal, `false` otherwise.
 */
bool fossil_tofu_equals(fossil_tofu_t tofu1, fossil_tofu_t tofu2);

/**
 * Utility function to copy a `fossil_tofu_t` object.
 *
 * @param tofu The `fossil_tofu_t` object to be copied.
 * @return The copied `fossil_tofu_t` object.
 */
fossil_tofu_t fossil_tofu_copy(fossil_tofu_t tofu);

/**
 * Utility function to compare two `fossil_tofu_t` objects.
 *
 * @param tofu1 The first `fossil_tofu_t` object.
 * @param tofu2 The second `fossil_tofu_t` object.
 * @return `true` if the objects are equal, `false` otherwise.
 */
bool fossil_tofu_compare(fossil_tofu_t *tofu1, fossil_tofu_t *tofu2);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include <utility>
#include <algorithm>
#include <stdexcept>

namespace fossil {

    template<typename T>
    class Tofu {
    public:
        Tofu() = default;

        Tofu(const std::string& type, const T& value) {
            tofu_ = fossil_tofu_create(const_cast<char*>(type.c_str()), const_cast<char*>(std::to_string(value).c_str()));
        }

        Tofu(Tofu&& other) noexcept {
            tofu_ = std::move(other.tofu_);
            other.tofu_ = nullptr;
        }

        Tofu(const Tofu& other) {
            tofu_ = fossil_tofu_copy(other.tofu_);
        }

        ~Tofu() {
            fossil_tofu_erase(&tofu_);
        }

        void memorize() {
            fossil_tofu_memorize(&tofu_);
        }

        void print() {
            fossil_tofu_print(tofu_);
        }

        const char* getTypeString() {
            return fossil_tofu_type_to_string(tofu_.type);
        }
        
        bool equals(const Tofu<T>& other) {
            return fossil_tofu_equals(tofu_, other.tofu_);
        }

        Tofu<T> copy() {
            return Tofu<T>(fossil_tofu_copy(tofu_));
        }

        bool compare(const Tofu<T>& other) {
            return fossil_tofu_compare(&tofu_, &other.tofu_);
        }

    private:
        fossil_tofu_t tofu_;
    };

} // namespace fossil
#endif

#endif
