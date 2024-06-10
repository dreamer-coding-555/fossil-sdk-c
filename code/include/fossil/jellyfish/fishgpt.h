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
    jellyfish_layer** layers;
    jellyfish_matrix* embedding_matrix;
} Jellyfish_FishGPT;

#ifdef __cplusplus
extern "C"
{
#endif

// ========================================================================
// create and erase functions
// ========================================================================

/**
 * Creates a new Jellyfish_FishGPT model.
 *
 * @param vocab_size The size of the vocabulary.
 * @param embedding_dim The dimension of the embedding layer.
 * @param num_layers The number of layers in the model.
 * @param layer_size The size of each layer.
 * @return A pointer to the created Jellyfish_FishGPT model.
 */
Jellyfish_FishGPT* fossil_jellyfish_fishgpt_create(int vocab_size, int embedding_dim, int num_layers, int layer_size);

/**
 * Adds a layer to the Jellyfish_FishGPT model.
 *
 * @param model A pointer to the Jellyfish_FishGPT model.
 * @param layer A pointer to the jellyfish_layer to be added.
 */
void fossil_jellyfish_fishgpt_add_layer(Jellyfish_FishGPT* model, jellyfish_layer* layer);

/**
 * Performs a forward pass through the Jellyfish_FishGPT model.
 *
 * @param model A pointer to the Jellyfish_FishGPT model.
 * @param input A pointer to the input jellyfish_matrix.
 * @return A pointer to the output jellyfish_matrix.
 */
jellyfish_matrix* fossil_jellyfish_fishgpt_forward(Jellyfish_FishGPT* model, jellyfish_matrix* input);

/**
 * Performs a backward pass through the Jellyfish_FishGPT model and updates the weights.
 *
 * @param model A pointer to the Jellyfish_FishGPT model.
 * @param input A pointer to the input jellyfish_matrix.
 * @param target A pointer to the target jellyfish_matrix.
 * @param learning_rate The learning rate for weight updates.
 */
void fossil_jellyfish_fishgpt_backward(Jellyfish_FishGPT* model, jellyfish_matrix* input, jellyfish_matrix* target, double learning_rate);

/**
 * Trains the Jellyfish_FishGPT model on the given inputs and targets for the specified number of epochs.
 *
 * @param model A pointer to the Jellyfish_FishGPT model.
 * @param inputs A pointer to the input jellyfish_matrix.
 * @param targets A pointer to the target jellyfish_matrix.
 * @param epochs The number of training epochs.
 * @param learning_rate The learning rate for weight updates.
 */
void fossil_jellyfish_fishgpt_train(Jellyfish_FishGPT* model, jellyfish_matrix* inputs, jellyfish_matrix* targets, int epochs, double learning_rate);

/**
 * Erases the Jellyfish_FishGPT model and frees the allocated memory.
 *
 * @param model A pointer to the Jellyfish_FishGPT model.
 */
void fossil_jellyfish_fishgpt_erase(Jellyfish_FishGPT* model);

#ifdef __cplusplus
}
#endif

#endif
