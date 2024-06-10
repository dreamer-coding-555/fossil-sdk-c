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
#include "fossil/jellyfish/fishgpt.h"
#include "fossil/common/common.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Create a GPT model
Jellyfish_FishGPT* fossil_jellyfish_fishgpt_create(int vocab_size, int embedding_dim, int num_layers, int layer_size) {
    Jellyfish_FishGPT* model = (Jellyfish_FishGPT*)malloc(sizeof(Jellyfish_FishGPT));
    model->num_layers = num_layers;
    model->layers = (jellyfish_layer**)malloc(num_layers * sizeof(jellyfish_layer*));
    model->embedding_matrix = fossil_jellyfish_create_matrix(vocab_size, embedding_dim);
    
    for (int i = 0; i < vocab_size; i++) {
        for (int j = 0; j < embedding_dim; j++) {
            model->embedding_matrix->data[i][j] = (double)rand() / RAND_MAX; // Random initialization
        }
    }

    // Allocate memory for each layer and initialize
    for (int i = 0; i < num_layers; i++) {
        // Adjusted function call to match the prototype
        model->layers[i] = fossil_jellyfish_create_layer(embedding_dim, layer_size, NULL); // Assuming no activation function
    }

    return model;
}

// Add a layer to the GPT model
void fossil_jellyfish_fishgpt_add_layer(Jellyfish_FishGPT* model, jellyfish_layer* layer) {
    static int layer_index = 0;
    if (layer_index < model->num_layers) {
        model->layers[layer_index++] = layer;
    }
}

// Forward propagation through the GPT model
jellyfish_matrix* fossil_jellyfish_fishgpt_forward(Jellyfish_FishGPT* model, jellyfish_matrix* input) {
    jellyfish_matrix* output = fossil_jellyfish_embed(input, model->embedding_matrix);
    for (int i = 0; i < model->num_layers; i++) {
        output = fossil_jellyfish_forward(output, model->layers[i]);
    }
    return output;
}

// Backward propagation through the GPT model
void fossil_jellyfish_fishgpt_backward(Jellyfish_FishGPT* model, jellyfish_matrix* input, jellyfish_matrix* target, double learning_rate) {
    jellyfish_matrix* d_output = fossil_jellyfish_subtract(fossil_jellyfish_fishgpt_forward(model, input), target);
    for (int i = model->num_layers - 1; i >= 0; i--) {
        fossil_jellyfish_backward(model->layers[i], input, target, d_output, learning_rate);
    }
    fossil_jellyfish_erase_matrix(d_output);
}

// Train the GPT model
void fossil_jellyfish_fishgpt_train(Jellyfish_FishGPT* model, jellyfish_matrix* inputs, jellyfish_matrix* targets, int epochs, double learning_rate) {
    for (int epoch = 0; epoch < epochs; epoch++) {
        for (int i = 0; i < inputs->rows; i++) {
            jellyfish_matrix* input = &inputs[i];
            jellyfish_matrix* target = &targets[i];
            fossil_jellyfish_fishgpt_backward(model, input, target, learning_rate);
        }
    }
}

// Erase the GPT model
void fossil_jellyfish_fishgpt_erase(Jellyfish_FishGPT* model) {
    for (int i = 0; i < model->num_layers; i++) {
        fossil_jellyfish_erase_layer(model->layers[i]);
    }
    fossil_jellyfish_erase_matrix(model->embedding_matrix);
    free(model->layers);
    free(model);
}
