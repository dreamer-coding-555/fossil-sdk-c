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
#ifndef FOSSIL_JELLYFISH_AI_GPT_H
#define FOSSIL_JELLYFISH_AI_GPT_H

#include "jellyfish.h"

// Define a structure for the GPT model
typedef struct {
    int num_layers;
    jellyfish_layer_t** layers;
    jellyfish_matrix_t* embedding_matrix;
} jellyfish_fishgpt_t;

#ifdef __cplusplus
extern "C"
{
#endif

// ========================================================================
// create and erase functions
// ========================================================================

/**
 * Creates a new jellyfish_fishgpt_t model.
 *
 * @param vocab_size The size of the vocabulary.
 * @param embedding_dim The dimension of the embedding layer.
 * @param num_layers The number of layers in the model.
 * @param layer_size The size of each layer.
 * @return A pointer to the created jellyfish_fishgpt_t model.
 */
jellyfish_fishgpt_t* fossil_jellyfish_fishgpt_create(int vocab_size, int embedding_dim, int num_layers, int layer_size);

/**
 * Adds a layer to the jellyfish_fishgpt_t model.
 *
 * @param model A pointer to the jellyfish_fishgpt_t model.
 * @param layer A pointer to the jellyfish_layer_t to be added.
 */
void fossil_jellyfish_fishgpt_add_layer(jellyfish_fishgpt_t* model, jellyfish_layer_t* layer);

/**
 * Performs a forward pass through the jellyfish_fishgpt_t model.
 *
 * @param model A pointer to the jellyfish_fishgpt_t model.
 * @param input A pointer to the input jellyfish_matrix_t.
 * @return A pointer to the output jellyfish_matrix_t.
 */
jellyfish_matrix_t* fossil_jellyfish_fishgpt_forward(jellyfish_fishgpt_t* model, jellyfish_matrix_t* input);

/**
 * Performs a backward pass through the jellyfish_fishgpt_t model and updates the weights.
 *
 * @param model A pointer to the jellyfish_fishgpt_t model.
 * @param input A pointer to the input jellyfish_matrix_t.
 * @param target A pointer to the target jellyfish_matrix_t.
 * @param learning_rate The learning rate for weight updates.
 */
void fossil_jellyfish_fishgpt_backward(jellyfish_fishgpt_t* model, jellyfish_matrix_t* input, jellyfish_matrix_t* target, double learning_rate);

/**
 * Trains the jellyfish_fishgpt_t model on the given inputs and targets for the specified number of epochs.
 *
 * @param model A pointer to the jellyfish_fishgpt_t model.
 * @param inputs A pointer to the input jellyfish_matrix_t.
 * @param targets A pointer to the target jellyfish_matrix_t.
 * @param epochs The number of training epochs.
 * @param learning_rate The learning rate for weight updates.
 */
void fossil_jellyfish_fishgpt_train(jellyfish_fishgpt_t* model, jellyfish_matrix_t* inputs, jellyfish_matrix_t* targets, int epochs, double learning_rate);

/**
 * Erases the jellyfish_fishgpt_t model and frees the allocated memory.
 *
 * @param model A pointer to the jellyfish_fishgpt_t model.
 */
void fossil_jellyfish_fishgpt_erase(jellyfish_fishgpt_t* model);

#ifdef __cplusplus
}
#endif

#endif
