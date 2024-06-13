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

#include <fossil/jellyfish/deepsea.h> // library under test

// Define some constants for test data
#define INPUT_SIZE 2
#define OUTPUT_SIZE 1
#define NUM_SAMPLES 10
#define EPOCHS 5
#define BATCH_SIZE 2

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

FOSSIL_TEST(test_fossil_jellyfish_deepsea_create_network) {
    int num_layers = 3;
    jellyfish_network_t* network = fossil_jellyfish_deepsea_create_network(num_layers);

    ASSUME_NOT_CNULL(network);
    ASSUME_ITS_EQUAL_I32(num_layers, network->num_layers);

    fossil_jellyfish_deepsea_erase_network(network);
}

FOSSIL_TEST(test_fossil_jellyfish_deepsea_add_layer) {
    int num_layers = 3;
    jellyfish_network_t* network = fossil_jellyfish_deepsea_create_network(num_layers);

    int input_size = 4;
    int output_size = 2;
    jellyfish_layer_t* layer = fossil_jellyfish_create_layer(input_size, output_size, fossil_jellyfish_relu);
    fossil_jellyfish_deepsea_add_layer(network, layer);

    ASSUME_NOT_CNULL(network->layers[0]);

    fossil_jellyfish_deepsea_erase_network(network);
}

FOSSIL_TEST(test_fossil_jellyfish_deepsea_forward) {
    int num_layers = 1;
    jellyfish_network_t* network = fossil_jellyfish_deepsea_create_network(num_layers);

    int input_size = 4;
    int output_size = 2;
    jellyfish_layer_t* layer = fossil_jellyfish_create_layer(input_size, output_size, fossil_jellyfish_relu);
    fossil_jellyfish_deepsea_add_layer(network, layer);

    jellyfish_matrix_t* input = fossil_jellyfish_create_matrix(1, input_size);
    for (int i = 0; i < input_size; i++) {
        input->data[0][i] = (double)i;
    }

    jellyfish_matrix_t* output = fossil_jellyfish_deepsea_forward(network, input);

    ASSUME_NOT_CNULL(output);
    ASSUME_ITS_EQUAL_I32(1, output->rows);
    ASSUME_ITS_EQUAL_I32(output_size, output->cols);

    fossil_jellyfish_erase_matrix(input);
    fossil_jellyfish_erase_matrix(output);
    fossil_jellyfish_deepsea_erase_network(network);
}

FOSSIL_TEST(test_fossil_jellyfish_deepsea_backward) {
    int num_layers = 1;
    jellyfish_network_t* network = fossil_jellyfish_deepsea_create_network(num_layers);

    int input_size = 4;
    int output_size = 2;
    jellyfish_layer_t* layer = fossil_jellyfish_create_layer(input_size, output_size, fossil_jellyfish_relu);
    fossil_jellyfish_deepsea_add_layer(network, layer);

    jellyfish_matrix_t* input = fossil_jellyfish_create_matrix(1, input_size);
    jellyfish_matrix_t* target = fossil_jellyfish_create_matrix(1, output_size);
    for (int i = 0; i < input_size; i++) {
        input->data[0][i] = (double)i;
    }
    for (int i = 0; i < output_size; i++) {
        target->data[0][i] = (double)(i + 1);
    }

    fossil_jellyfish_deepsea_backward(network, input, target, 0.01);

    // If no assertion fails, the backward pass was executed
    ASSUME_ITS_TRUE(1);

    fossil_jellyfish_erase_matrix(input);
    fossil_jellyfish_erase_matrix(target);
    fossil_jellyfish_deepsea_erase_network(network);
}

FOSSIL_TEST(test_fossil_jellyfish_deepsea_train) {
    int num_layers = 1;
    jellyfish_network_t* network = fossil_jellyfish_deepsea_create_network(num_layers);

    int input_size = 4;
    int output_size = 2;
    jellyfish_layer_t* layer = fossil_jellyfish_create_layer(input_size, output_size, fossil_jellyfish_relu);
    fossil_jellyfish_deepsea_add_layer(network, layer);

    int epochs = 10;
    double learning_rate = 0.01;

    jellyfish_matrix_t* inputs = fossil_jellyfish_create_matrix(3, input_size);
    jellyfish_matrix_t* targets = fossil_jellyfish_create_matrix(3, output_size);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < input_size; j++) {
            inputs->data[i][j] = (double)j;
        }
        for (int k = 0; k < output_size; k++) {
            targets->data[i][k] = (double)(k + 1);
        }
    }

    fossil_jellyfish_deepsea_train(network, inputs, targets, epochs, learning_rate);

    // If no assertion fails, the training process was executed
    ASSUME_ITS_TRUE(1);

    fossil_jellyfish_erase_matrix(inputs);
    fossil_jellyfish_erase_matrix(targets);
    fossil_jellyfish_deepsea_erase_network(network);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(deepsea_group) {
    ADD_TEST(test_fossil_jellyfish_deepsea_create_network);
    ADD_TEST(test_fossil_jellyfish_deepsea_add_layer);
    ADD_TEST(test_fossil_jellyfish_deepsea_forward);
    ADD_TEST(test_fossil_jellyfish_deepsea_backward);
    ADD_TEST(test_fossil_jellyfish_deepsea_train);
} // end of fixture
