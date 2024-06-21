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
#ifndef FOSSIL_TOFU_ARRAYOF_H
#define FOSSIL_TOFU_ARRAYOF_H

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
#include "tofu.h"

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

// Struct for arrayof
typedef struct {
    fossil_tofu_t *array; // Array of fossil_tofu_t elements
    size_t size;          // Current size of the array
    size_t capacity;      // Capacity of the array
} fossil_tofu_arrayof_t;

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief Creates an arrayof with an initial set of elements.
 * 
 * @param type The type of the elements.
 * @param size The number of initial elements.
 * @param ... The initial values for the elements.
 * @return A newly created fossil_tofu_arrayof_t.
 */
fossil_tofu_arrayof_t fossil_tofu_arrayof_create(char *type, size_t size, ...);

/**
 * @brief Destroys the arrayof and frees allocated memory.
 * 
 * @param arrayof A pointer to the fossil_tofu_arrayof_t to be destroyed.
 */
void fossil_tofu_arrayof_erase(fossil_tofu_arrayof_t *arrayof);

/**
 * @brief Adds a fossil_tofu_t element to the end of the arrayof.
 * 
 * @param arrayof A pointer to the fossil_tofu_arrayof_t.
 * @param tofu The fossil_tofu_t element to add.
 */
void fossil_tofu_arrayof_add(fossil_tofu_arrayof_t *arrayof, fossil_tofu_t tofu);

/**
 * @brief Retrieves the fossil_tofu_t element at a specified index.
 * 
 * @param arrayof A pointer to the fossil_tofu_arrayof_t.
 * @param index The index of the element to retrieve.
 * @return The fossil_tofu_t element at the specified index.
 */
fossil_tofu_t fossil_tofu_arrayof_get(const fossil_tofu_arrayof_t *arrayof, size_t index);

/**
 * @brief Returns the current size of the arrayof.
 * 
 * @param arrayof A pointer to the fossil_tofu_arrayof_t.
 * @return The current number of elements in the arrayof.
 */
size_t fossil_tofu_arrayof_size(const fossil_tofu_arrayof_t *arrayof);

/**
 * @brief Checks if the arrayof is empty.
 * 
 * @param arrayof A pointer to the fossil_tofu_arrayof_t.
 * @return True if the arrayof is empty, false otherwise.
 */
bool fossil_tofu_arrayof_is_empty(const fossil_tofu_arrayof_t *arrayof);

/**
 * @brief Clears all elements from the arrayof.
 * 
 * @param arrayof A pointer to the fossil_tofu_arrayof_t.
 */
void fossil_tofu_arrayof_clear(fossil_tofu_arrayof_t *arrayof);

/**
 * @brief Prints all elements of the arrayof.
 * 
 * @param arrayof A pointer to the fossil_tofu_arrayof_t.
 */
void fossil_tofu_arrayof_print(const fossil_tofu_arrayof_t *arrayof);

#ifdef __cplusplus
}
#endif

#endif
