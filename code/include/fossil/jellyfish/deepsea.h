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
#ifndef FOSSIL_JELLYFISH_AI_DEEPSEA_H
#define FOSSIL_JELLYFISH_AI_DEEPSEA_H

#include "jellyfish.h"

// Define a structure for a neural network
typedef struct {
    int num_layers;
    jellyfish_layer_t** layers;
} jellyfish_network_t;

#ifdef __cplusplus
extern "C"
{
#endif

// ========================================================================
// create and erase functions
// ========================================================================

/**
 * Creates a Jellyfish network with the specified number of layers.
 *
 * @param num_layers The number of layers in the network.
 * @return A pointer to the created Jellyfish network.
 */
jellyfish_network_t* fossil_jellyfish_deepsea_create_network(int num_layers);

/**
 * Adds a layer to the Jellyfish network.
 *
 * @param network The Jellyfish network to add the layer to.
 * @param layer The layer to add to the network.
 */
void fossil_jellyfish_deepsea_add_layer(jellyfish_network_t* network, jellyfish_layer_t* layer);

/**
 * Performs a forward pass through the Jellyfish network.
 *
 * @param network The Jellyfish network to perform the forward pass on.
 * @param input The input matrix to the network.
 * @return The output matrix after the forward pass.
 */
jellyfish_matrix_t* fossil_jellyfish_deepsea_forward(jellyfish_network_t* network, jellyfish_matrix_t* input);

/**
 * Performs a backward pass through the Jellyfish network and updates the weights.
 *
 * @param network The Jellyfish network to perform the backward pass on.
 * @param input The input matrix to the network.
 * @param target The target matrix for the network.
 * @param learning_rate The learning rate for weight updates.
 */
void fossil_jellyfish_deepsea_backward(jellyfish_network_t* network, jellyfish_matrix_t* input, jellyfish_matrix_t* target, double learning_rate);

/**
 * Trains the Jellyfish network on the given inputs and targets for the specified number of epochs.
 *
 * @param network The Jellyfish network to train.
 * @param inputs The input matrices for training.
 * @param targets The target matrices for training.
 * @param epochs The number of epochs to train for.
 * @param learning_rate The learning rate for weight updates.
 */
void fossil_jellyfish_deepsea_train(jellyfish_network_t* network, jellyfish_matrix_t* inputs, jellyfish_matrix_t* targets, int epochs, double learning_rate);

/**
 * Erases the Jellyfish network and frees the allocated memory.
 *
 * @param network The Jellyfish network to erase.
 */
void fossil_jellyfish_deepsea_erase_network(jellyfish_network_t* network);

#ifdef __cplusplus
}
#endif

#endif
