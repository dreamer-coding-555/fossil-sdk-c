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
#include "fossil/jellyfish/deepsea.h"
#include <stdlib.h>

// Create a neural network
jellyfish_network_t* fossil_jellyfish_deepsea_create_network(int num_layers) {
    jellyfish_network_t* network = (jellyfish_network_t*)malloc(sizeof(jellyfish_network_t));
    network->num_layers = num_layers;
    network->layers = (jellyfish_layer_t**)malloc(num_layers * sizeof(jellyfish_layer_t*));
    return network;
}

// Add a layer to the neural network
void fossil_jellyfish_deepsea_add_layer(jellyfish_network_t* network, jellyfish_layer_t* layer) {
    static int layer_index = 0;
    if (layer_index < network->num_layers) {
        network->layers[layer_index++] = layer;
    }
}

// Forward propagation through the network
jellyfish_matrix_t* fossil_jellyfish_deepsea_forward(jellyfish_network_t* network, jellyfish_matrix_t* input) {
    jellyfish_matrix_t* output = input;
    for (int i = 0; i < network->num_layers; i++) {
        output = fossil_jellyfish_forward(output, network->layers[i]);
    }
    return output;
}

// Backward propagation through the network
void fossil_jellyfish_deepsea_backward(jellyfish_network_t* network, jellyfish_matrix_t* input, jellyfish_matrix_t* target, double learning_rate) {
    jellyfish_matrix_t* d_output = fossil_jellyfish_subtract(fossil_jellyfish_deepsea_forward(network, input), target);
    for (int i = network->num_layers - 1; i >= 0; i--) {
        fossil_jellyfish_backward(network->layers[i], input, target, d_output, learning_rate);
    }
    fossil_jellyfish_erase_matrix(d_output);
}

// Train the network
void fossil_jellyfish_deepsea_train(jellyfish_network_t* network, jellyfish_matrix_t* inputs, jellyfish_matrix_t* targets, int epochs, double learning_rate) {
    for (int epoch = 0; epoch < epochs; epoch++) {
        for (int i = 0; i < inputs->rows; i++) {
            jellyfish_matrix_t* input = &inputs[i];
            jellyfish_matrix_t* target = &targets[i];
            fossil_jellyfish_deepsea_backward(network, input, target, learning_rate);
        }
    }
}

// Erase the network
void fossil_jellyfish_deepsea_erase_network(jellyfish_network_t* network) {
    for (int i = 0; i < network->num_layers; i++) {
        fossil_jellyfish_erase_layer(network->layers[i]);
    }
    free(network->layers);
    free(network);
}
