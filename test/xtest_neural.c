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
#include <fossil/unittest.h>   // basic test tools
#include <fossil/xassume.h> // extra asserts

#include <fossil/jellyfish/neural.h> // library under test

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilites
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

// placeholder

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(test_fossil_jellyfish_neural_create_layer) {
    int input_size = 3;
    int output_size = 2;
    jellyfish_layer_t* layer = fossil_jellyfish_neural_create_layer(input_size, output_size, fossil_jellyfish_sigmoid);

    // Check if layer is not NULL and has correct dimensions
    ASSUME_NOT_CNULL(layer);
    ASSUME_NOT_CNULL(layer->weights);
    ASSUME_ITS_EQUAL_I32(output_size, layer->weights->rows);
    ASSUME_ITS_EQUAL_I32(input_size, layer->weights->cols);
    ASSUME_NOT_CNULL(layer->bias);
    ASSUME_ITS_EQUAL_I32(output_size, layer->bias->rows);
    ASSUME_ITS_EQUAL_I32(1, layer->bias->cols);
    ASSUME_NOT_CNULL(layer->activation);

    fossil_jellyfish_neural_erase_layer(layer);
}

FOSSIL_TEST(test_fossil_jellyfish_neural_forward) {
    int input_size = 3;
    int output_size = 2;
    jellyfish_layer_t* layer = fossil_jellyfish_neural_create_layer(input_size, output_size, fossil_jellyfish_sigmoid);
    jellyfish_matrix_t* input = fossil_jellyfish_create_matrix(1, input_size);

    // Initialize input with some dummy values
    input->data[0][0] = 1.0;
    input->data[0][1] = 2.0;
    input->data[0][2] = 3.0;

    jellyfish_matrix_t* output = fossil_jellyfish_neural_forward(input, layer);

    // Check if output is not NULL and has correct dimensions
    ASSUME_NOT_CNULL(output);
    ASSUME_ITS_EQUAL_I32(1, output->rows);
    ASSUME_ITS_EQUAL_I32(output_size, output->cols);

    fossil_jellyfish_erase_matrix(input);
    fossil_jellyfish_erase_matrix(output);
    fossil_jellyfish_neural_erase_layer(layer);
}

FOSSIL_TEST(test_fossil_jellyfish_neural_backward) {
    int input_size = 3;
    int output_size = 2;
    jellyfish_layer_t* layer = fossil_jellyfish_neural_create_layer(input_size, output_size, fossil_jellyfish_sigmoid);
    jellyfish_matrix_t* input = fossil_jellyfish_create_matrix(1, input_size);
    jellyfish_matrix_t* target = fossil_jellyfish_create_matrix(1, output_size);
    jellyfish_matrix_t* d_output = fossil_jellyfish_create_matrix(1, output_size);

    // Initialize input, target, and d_output with some dummy values
    input->data[0][0] = 1.0;
    input->data[0][1] = 2.0;
    input->data[0][2] = 3.0;
    target->data[0][0] = 0.5;
    target->data[0][1] = 0.8;
    d_output->data[0][0] = 0.1;
    d_output->data[0][1] = 0.2;

    double learning_rate = 0.01;

    fossil_jellyfish_neural_backward(layer, input, target, d_output, learning_rate);

    // Check if weights and biases are updated (this is a basic check for non-zero values)
    for (int i = 0; i < layer->weights->rows; i++) {
        for (int j = 0; j < layer->weights->cols; j++) {
            ASSUME_NOT_EQUAL_I32(0.0, layer->weights->data[i][j]);
        }
    }

    for (int i = 0; i < layer->bias->rows; i++) {
        ASSUME_NOT_EQUAL_I32(0.0, layer->bias->data[i][0]);
    }

    fossil_jellyfish_erase_matrix(input);
    fossil_jellyfish_erase_matrix(target);
    fossil_jellyfish_erase_matrix(d_output);
    fossil_jellyfish_neural_erase_layer(layer);
}

FOSSIL_TEST(test_fossil_jellyfish_neural_update_weights) {
    int input_size = 3;
    int output_size = 2;
    jellyfish_layer_t* layer = fossil_jellyfish_neural_create_layer(input_size, output_size, fossil_jellyfish_sigmoid);
    jellyfish_matrix_t* d_weights = fossil_jellyfish_create_matrix(output_size, input_size);
    jellyfish_matrix_t* d_bias = fossil_jellyfish_create_matrix(output_size, 1);

    // Initialize d_weights and d_bias with some dummy values
    d_weights->data[0][0] = 0.1; d_weights->data[0][1] = 0.1; d_weights->data[0][2] = 0.1;
    d_weights->data[1][0] = 0.1; d_weights->data[1][1] = 0.1; d_weights->data[1][2] = 0.1;
    d_bias->data[0][0] = 0.1; d_bias->data[1][0] = 0.1;

    double learning_rate = 0.01;

    fossil_jellyfish_neural_update_weights(layer, d_weights, d_bias, learning_rate);

    // Check if weights and biases are updated
    for (int i = 0; i < layer->weights->rows; i++) {
        for (int j = 0; j < layer->weights->cols; j++) {
            ASSUME_NOT_EQUAL_I32(0.0, layer->weights->data[i][j]);
        }
    }

    for (int i = 0; i < layer->bias->rows; i++) {
        ASSUME_NOT_EQUAL_I32(0.0, layer->bias->data[i][0]);
    }

    fossil_jellyfish_erase_matrix(d_weights);
    fossil_jellyfish_erase_matrix(d_bias);
    fossil_jellyfish_neural_erase_layer(layer);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(neural_group) {
    ADD_TEST(test_fossil_jellyfish_neural_create_layer);
    ADD_TEST(test_fossil_jellyfish_neural_forward);
    ADD_TEST(test_fossil_jellyfish_neural_backward);
    ADD_TEST(test_fossil_jellyfish_neural_update_weights);
} // end of fixture
