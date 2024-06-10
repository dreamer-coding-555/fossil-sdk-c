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

#include <fossil/xjellyfish/deepsea.h> // library under test

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

XTEST(test_FOSSIL_jellyfish_deepsea_create_network) {
    int num_layers = 3;
    Jellyfish_Network* network = FOSSIL_jellyfish_deepsea_create_network(num_layers);

    TEST_ASSUME_NOT_CNULLPTR(network);
    TEST_ASSUME_EQUAL_INT(num_layers, network->num_layers);

    FOSSIL_jellyfish_deepsea_erase_network(network);
}

XTEST(test_FOSSIL_jellyfish_deepsea_add_layer) {
    int num_layers = 3;
    Jellyfish_Network* network = FOSSIL_jellyfish_deepsea_create_network(num_layers);

    int input_size = 4;
    int output_size = 2;
    jellyfish_layer* layer = FOSSIL_jellyfish_create_layer(input_size, output_size, FOSSIL_jellyfish_relu);
    FOSSIL_jellyfish_deepsea_add_layer(network, layer);

    TEST_ASSUME_NOT_CNULLPTR(network->layers[0]);

    FOSSIL_jellyfish_deepsea_erase_network(network);
}

XTEST(test_FOSSIL_jellyfish_deepsea_forward) {
    int num_layers = 1;
    Jellyfish_Network* network = FOSSIL_jellyfish_deepsea_create_network(num_layers);

    int input_size = 4;
    int output_size = 2;
    jellyfish_layer* layer = FOSSIL_jellyfish_create_layer(input_size, output_size, FOSSIL_jellyfish_relu);
    FOSSIL_jellyfish_deepsea_add_layer(network, layer);

    jellyfish_matrix* input = FOSSIL_jellyfish_create_matrix(1, input_size);
    for (int i = 0; i < input_size; i++) {
        input->data[0][i] = (double)i;
    }

    jellyfish_matrix* output = FOSSIL_jellyfish_deepsea_forward(network, input);

    TEST_ASSUME_NOT_CNULLPTR(output);
    TEST_ASSUME_EQUAL_INT(1, output->rows);
    TEST_ASSUME_EQUAL_INT(output_size, output->cols);

    FOSSIL_jellyfish_erase_matrix(input);
    FOSSIL_jellyfish_erase_matrix(output);
    FOSSIL_jellyfish_deepsea_erase_network(network);
}

XTEST(test_FOSSIL_jellyfish_deepsea_backward) {
    int num_layers = 1;
    Jellyfish_Network* network = FOSSIL_jellyfish_deepsea_create_network(num_layers);

    int input_size = 4;
    int output_size = 2;
    jellyfish_layer* layer = FOSSIL_jellyfish_create_layer(input_size, output_size, FOSSIL_jellyfish_relu);
    FOSSIL_jellyfish_deepsea_add_layer(network, layer);

    jellyfish_matrix* input = FOSSIL_jellyfish_create_matrix(1, input_size);
    jellyfish_matrix* target = FOSSIL_jellyfish_create_matrix(1, output_size);
    for (int i = 0; i < input_size; i++) {
        input->data[0][i] = (double)i;
    }
    for (int i = 0; i < output_size; i++) {
        target->data[0][i] = (double)(i + 1);
    }

    FOSSIL_jellyfish_deepsea_backward(network, input, target, 0.01);

    // If no assertion fails, the backward pass was executed
    TEST_ASSUME_TRUE(1);

    FOSSIL_jellyfish_erase_matrix(input);
    FOSSIL_jellyfish_erase_matrix(target);
    FOSSIL_jellyfish_deepsea_erase_network(network);
}

XTEST(test_FOSSIL_jellyfish_deepsea_train) {
    int num_layers = 1;
    Jellyfish_Network* network = FOSSIL_jellyfish_deepsea_create_network(num_layers);

    int input_size = 4;
    int output_size = 2;
    jellyfish_layer* layer = FOSSIL_jellyfish_create_layer(input_size, output_size, FOSSIL_jellyfish_relu);
    FOSSIL_jellyfish_deepsea_add_layer(network, layer);

    int epochs = 10;
    double learning_rate = 0.01;

    jellyfish_matrix* inputs = FOSSIL_jellyfish_create_matrix(3, input_size);
    jellyfish_matrix* targets = FOSSIL_jellyfish_create_matrix(3, output_size);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < input_size; j++) {
            inputs->data[i][j] = (double)j;
        }
        for (int k = 0; k < output_size; k++) {
            targets->data[i][k] = (double)(k + 1);
        }
    }

    FOSSIL_jellyfish_deepsea_train(network, inputs, targets, epochs, learning_rate);

    // If no assertion fails, the training process was executed
    TEST_ASSUME_TRUE(1);

    FOSSIL_jellyfish_erase_matrix(inputs);
    FOSSIL_jellyfish_erase_matrix(targets);
    FOSSIL_jellyfish_deepsea_erase_network(network);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
XTEST_DEFINE_POOL(deepsea_group) {
    XTEST_RUN_UNIT(test_FOSSIL_jellyfish_deepsea_create_network);
    XTEST_RUN_UNIT(test_FOSSIL_jellyfish_deepsea_add_layer);
    XTEST_RUN_UNIT(test_FOSSIL_jellyfish_deepsea_forward);
    XTEST_RUN_UNIT(test_FOSSIL_jellyfish_deepsea_backward);
    XTEST_RUN_UNIT(test_FOSSIL_jellyfish_deepsea_train);
} // end of fixture
