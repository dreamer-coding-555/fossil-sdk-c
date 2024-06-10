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
#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassume.h> // extra asserts

#include <fossil/xjellyfish/neural.h> // library under test

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

XTEST(test_FOSSIL_jellyfish_neural_create_layer) {
    int input_size = 3;
    int output_size = 2;
    jellyfish_layer* layer = FOSSIL_jellyfish_neural_create_layer(input_size, output_size, FOSSIL_jellyfish_sigmoid);

    // Check if layer is not NULL and has correct dimensions
    TEST_ASSUME_NOT_CNULLPTR(layer);
    TEST_ASSUME_NOT_CNULLPTR(layer->weights);
    TEST_ASSUME_EQUAL_INT(output_size, layer->weights->rows);
    TEST_ASSUME_EQUAL_INT(input_size, layer->weights->cols);
    TEST_ASSUME_NOT_CNULLPTR(layer->bias);
    TEST_ASSUME_EQUAL_INT(output_size, layer->bias->rows);
    TEST_ASSUME_EQUAL_INT(1, layer->bias->cols);
    TEST_ASSUME_NOT_CNULLPTR(layer->activation);

    FOSSIL_jellyfish_neural_erase_layer(layer);
}

XTEST(test_FOSSIL_jellyfish_neural_forward) {
    int input_size = 3;
    int output_size = 2;
    jellyfish_layer* layer = FOSSIL_jellyfish_neural_create_layer(input_size, output_size, FOSSIL_jellyfish_sigmoid);
    jellyfish_matrix* input = FOSSIL_jellyfish_create_matrix(1, input_size);

    // Initialize input with some dummy values
    input->data[0][0] = 1.0;
    input->data[0][1] = 2.0;
    input->data[0][2] = 3.0;

    jellyfish_matrix* output = FOSSIL_jellyfish_neural_forward(input, layer);

    // Check if output is not NULL and has correct dimensions
    TEST_ASSUME_NOT_CNULLPTR(output);
    TEST_ASSUME_EQUAL_INT(1, output->rows);
    TEST_ASSUME_EQUAL_INT(output_size, output->cols);

    FOSSIL_jellyfish_erase_matrix(input);
    FOSSIL_jellyfish_erase_matrix(output);
    FOSSIL_jellyfish_neural_erase_layer(layer);
}

XTEST(test_FOSSIL_jellyfish_neural_backward) {
    int input_size = 3;
    int output_size = 2;
    jellyfish_layer* layer = FOSSIL_jellyfish_neural_create_layer(input_size, output_size, FOSSIL_jellyfish_sigmoid);
    jellyfish_matrix* input = FOSSIL_jellyfish_create_matrix(1, input_size);
    jellyfish_matrix* target = FOSSIL_jellyfish_create_matrix(1, output_size);
    jellyfish_matrix* d_output = FOSSIL_jellyfish_create_matrix(1, output_size);

    // Initialize input, target, and d_output with some dummy values
    input->data[0][0] = 1.0;
    input->data[0][1] = 2.0;
    input->data[0][2] = 3.0;
    target->data[0][0] = 0.5;
    target->data[0][1] = 0.8;
    d_output->data[0][0] = 0.1;
    d_output->data[0][1] = 0.2;

    double learning_rate = 0.01;

    FOSSIL_jellyfish_neural_backward(layer, input, target, d_output, learning_rate);

    // Check if weights and biases are updated (this is a basic check for non-zero values)
    for (int i = 0; i < layer->weights->rows; i++) {
        for (int j = 0; j < layer->weights->cols; j++) {
            TEST_ASSUME_NOT_EQUAL(0.0, layer->weights->data[i][j]);
        }
    }

    for (int i = 0; i < layer->bias->rows; i++) {
        TEST_ASSUME_NOT_EQUAL(0.0, layer->bias->data[i][0]);
    }

    FOSSIL_jellyfish_erase_matrix(input);
    FOSSIL_jellyfish_erase_matrix(target);
    FOSSIL_jellyfish_erase_matrix(d_output);
    FOSSIL_jellyfish_neural_erase_layer(layer);
}

XTEST(test_FOSSIL_jellyfish_neural_update_weights) {
    int input_size = 3;
    int output_size = 2;
    jellyfish_layer* layer = FOSSIL_jellyfish_neural_create_layer(input_size, output_size, FOSSIL_jellyfish_sigmoid);
    jellyfish_matrix* d_weights = FOSSIL_jellyfish_create_matrix(output_size, input_size);
    jellyfish_matrix* d_bias = FOSSIL_jellyfish_create_matrix(output_size, 1);

    // Initialize d_weights and d_bias with some dummy values
    d_weights->data[0][0] = 0.1; d_weights->data[0][1] = 0.1; d_weights->data[0][2] = 0.1;
    d_weights->data[1][0] = 0.1; d_weights->data[1][1] = 0.1; d_weights->data[1][2] = 0.1;
    d_bias->data[0][0] = 0.1; d_bias->data[1][0] = 0.1;

    double learning_rate = 0.01;

    FOSSIL_jellyfish_neural_update_weights(layer, d_weights, d_bias, learning_rate);

    // Check if weights and biases are updated
    for (int i = 0; i < layer->weights->rows; i++) {
        for (int j = 0; j < layer->weights->cols; j++) {
            TEST_ASSUME_NOT_EQUAL(0.0, layer->weights->data[i][j]);
        }
    }

    for (int i = 0; i < layer->bias->rows; i++) {
        TEST_ASSUME_NOT_EQUAL(0.0, layer->bias->data[i][0]);
    }

    FOSSIL_jellyfish_erase_matrix(d_weights);
    FOSSIL_jellyfish_erase_matrix(d_bias);
    FOSSIL_jellyfish_neural_erase_layer(layer);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
XTEST_DEFINE_POOL(neural_group) {
    XTEST_RUN_UNIT(test_FOSSIL_jellyfish_neural_create_layer);
    XTEST_RUN_UNIT(test_FOSSIL_jellyfish_neural_forward);
    XTEST_RUN_UNIT(test_FOSSIL_jellyfish_neural_backward);
    XTEST_RUN_UNIT(test_FOSSIL_jellyfish_neural_update_weights);
} // end of fixture
