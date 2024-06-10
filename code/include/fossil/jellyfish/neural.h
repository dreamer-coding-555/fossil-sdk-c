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
#ifndef FOSSIL_JELLYFISH_AI_NEURAL_H
#define FOSSIL_JELLYFISH_AI_NEURAL_H

#include "jellyfish.h"

#ifdef __cplusplus
extern "C"
{
#endif

// ========================================================================
// create and erase functions
// ========================================================================

/**
 * Perform forward propagation in the neural network.
 *
 * @param input The input matrix.
 * @param layer The layer of the neural network.
 * @return The output matrix after forward propagation.
 */
jellyfish_matrix* fossil_jellyfish_neural_forward(jellyfish_matrix* input, jellyfish_layer* layer);

/**
 * Create a new layer in the neural network.
 *
 * @param input_size The size of the input.
 * @param output_size The size of the output.
 * @param activation The activation function for the layer.
 * @return The created layer.
 */
jellyfish_layer* fossil_jellyfish_neural_create_layer(int input_size, int output_size, void (*activation)(jellyfish_matrix*));

/**
 * Erase a layer from the neural network.
 *
 * @param layer The layer to erase.
 */
void fossil_jellyfish_neural_erase_layer(jellyfish_layer* layer);

/**
 * Perform backward propagation in the neural network.
 *
 * @param layer The layer of the neural network.
 * @param input The input matrix.
 * @param target The target matrix.
 * @param d_output The derivative of the output matrix.
 * @param learning_rate The learning rate for the network.
 */
void fossil_jellyfish_neural_backward(jellyfish_layer* layer, jellyfish_matrix* input, jellyfish_matrix* target, jellyfish_matrix* d_output, double learning_rate);

/**
 * Update the weights of a layer in the neural network.
 *
 * @param layer The layer to update.
 * @param d_weights The derivative of the weights matrix.
 * @param d_bias The derivative of the bias matrix.
 * @param learning_rate The learning rate for the network.
 */
void fossil_jellyfish_neural_update_weights(jellyfish_layer* layer, jellyfish_matrix* d_weights, jellyfish_matrix* d_bias, double learning_rate);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
namespace fossil {
#endif

// C++ interface in the fossil namespace...

#ifdef __cplusplus
}
#endif

#endif
