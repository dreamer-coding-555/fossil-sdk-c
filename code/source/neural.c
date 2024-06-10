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
#include "fossil/jellyfish/neural.h"

// Neural network wrapper functions
jellyfish_matrix* fossil_jellyfish_neural_forward(jellyfish_matrix* input, jellyfish_layer* layer) {
    return fossil_jellyfish_forward(input, layer);
}

jellyfish_layer* fossil_jellyfish_neural_create_layer(int input_size, int output_size, void (*activation)(jellyfish_matrix*)) {
    return fossil_jellyfish_create_layer(input_size, output_size, activation);
}

void fossil_jellyfish_neural_erase_layer(jellyfish_layer* layer) {
    fossil_jellyfish_erase_layer(layer);
}

void fossil_jellyfish_neural_backward(jellyfish_layer* layer, jellyfish_matrix* input, jellyfish_matrix* target, jellyfish_matrix* d_output, double learning_rate) {
    fossil_jellyfish_backward(layer, input, target, d_output, learning_rate);
}

void fossil_jellyfish_neural_update_weights(jellyfish_layer* layer, jellyfish_matrix* d_weights, jellyfish_matrix* d_bias, double learning_rate) {
    fossil_jellyfish_update_weights(layer, d_weights, d_bias, learning_rate);
}
