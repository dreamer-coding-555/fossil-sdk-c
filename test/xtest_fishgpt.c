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

#include <fossil/xjellyfish/fishgpt.h> // library under test

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

FOSSIL_TEST(test_fossil_jellyfish_fishgpt_create) {
    int vocab_size = 1000;
    int embedding_dim = 64;
    int num_layers = 3;
    int layer_size = 128;

    Jellyfish_FishGPT* model = fossil_jellyfish_fishgpt_create(vocab_size, embedding_dim, num_layers, layer_size);

    ASSUME_NOT_CNULL(model);
    ASSUME_ITS_EQUAL_I32(num_layers, model->num_layers);
    ASSUME_ITS_EQUAL_I32(vocab_size, model->embedding_matrix->rows);
    ASSUME_ITS_EQUAL_I32(embedding_dim, model->embedding_matrix->cols);

    fossil_jellyfish_fishgpt_erase(model);
}

FOSSIL_TEST(test_fossil_jellyfish_fishgpt_add_layer) {
    int vocab_size = 1000;
    int embedding_dim = 64;
    int num_layers = 3;
    int layer_size = 128;

    Jellyfish_FishGPT* model = fossil_jellyfish_fishgpt_create(vocab_size, embedding_dim, num_layers, layer_size);
    jellyfish_layer* layer = fossil_jellyfish_create_layer(embedding_dim, layer_size, fossil_jellyfish_relu);

    fossil_jellyfish_fishgpt_add_layer(model, layer);

    ASSUME_NOT_CNULL(model->layers[0]);

    fossil_jellyfish_fishgpt_erase(model);
}

FOSSIL_TEST(test_fossil_jellyfish_fishgpt_forward) {
    int vocab_size = 1000;
    int embedding_dim = 64;
    int num_layers = 3;
    int layer_size = 128;

    Jellyfish_FishGPT* model = fossil_jellyfish_fishgpt_create(vocab_size, embedding_dim, num_layers, layer_size);

    jellyfish_matrix* input = fossil_jellyfish_create_matrix(1, embedding_dim);
    // Fill input with some data
    for (int i = 0; i < embedding_dim; i++) {
        input->data[0][i] = (double)i / embedding_dim;
    }

    jellyfish_matrix* output = fossil_jellyfish_fishgpt_forward(model, input);

    ASSUME_NOT_CNULL(output);

    fossil_jellyfish_erase_matrix(input);
    fossil_jellyfish_erase_matrix(output);
    fossil_jellyfish_fishgpt_erase(model);
}

FOSSIL_TEST(test_fossil_jellyfish_fishgpt_tokenize) {
    char text[] = "Hello world! This is a test.";
    int vocab_size = 10;

    jellyfish_matrix* tokens = fossil_jellyfish_tokenize(text, vocab_size, "en");

    ASSUME_NOT_CNULL(tokens);
    ASSUME_ITS_EQUAL_I32(1, tokens->rows);
    TEST_ASSUME_LESS_EQUAL_INT(vocab_size, tokens->cols);

    fossil_jellyfish_erase_matrix(tokens);
}

FOSSIL_TEST(test_fossil_jellyfish_fishgpt_embed) {
    int vocab_size = 10;
    int embedding_dim = 64;

    jellyfish_matrix* tokens = fossil_jellyfish_create_matrix(1, vocab_size);
    // Fill tokens with some data
    for (int i = 0; i < vocab_size; i++) {
        tokens->data[0][i] = i;
    }

    jellyfish_matrix* embedding_matrix = fossil_jellyfish_create_matrix(vocab_size, embedding_dim);
    // Fill embedding matrix with some data
    for (int i = 0; i < vocab_size; i++) {
        for (int j = 0; j < embedding_dim; j++) {
            embedding_matrix->data[i][j] = (double)j / embedding_dim;
        }
    }

    jellyfish_matrix* embeddings = fossil_jellyfish_embed(tokens, embedding_matrix);

    ASSUME_NOT_CNULL(embeddings);
    ASSUME_ITS_EQUAL_I32(1, embeddings->rows);
    ASSUME_ITS_EQUAL_I32(embedding_dim, embeddings->cols);

    fossil_jellyfish_erase_matrix(tokens);
    fossil_jellyfish_erase_matrix(embedding_matrix);
    fossil_jellyfish_erase_matrix(embeddings);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(fishgpt_group) {
    ADD_TEST(test_fossil_jellyfish_fishgpt_create);
    ADD_TEST(test_fossil_jellyfish_fishgpt_add_layer);
    ADD_TEST(test_fossil_jellyfish_fishgpt_forward);
    ADD_TEST(test_fossil_jellyfish_fishgpt_tokenize);
    ADD_TEST(test_fossil_jellyfish_fishgpt_embed);
} // end of fixture
