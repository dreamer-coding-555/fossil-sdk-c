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
#include "fossil/jellyfish/dolphin.h"
#include "fossil/common/common.h"
#include <stdio.h>
#include <stdlib.h>

jellyfish_matrix* fossil_jellyfish_dolphin_tokenize(char* text, int vocab_size, char* language) {
    return fossil_jellyfish_tokenize(text, vocab_size, language);
}

jellyfish_matrix* fossil_jellyfish_dolphin_embed(jellyfish_matrix* tokens, jellyfish_matrix* embedding_matrix) {
    return fossil_jellyfish_embed(tokens, embedding_matrix);
}

// NLU wrapper functions
void fossil_jellyfish_dolphin_analyze_sentiment(jellyfish_matrix* tokens, jellyfish_matrix* sentiment_labels) {
    if (tokens->cols != sentiment_labels->cols) {
        printf("Error: Number of tokens does not match number of labels.\n");
        return;
    }

    int correct_predictions = 0;
    // Iterate over each token and compare sentiment prediction with label
    for (int i = 0; i < tokens->cols; ++i) {
        // Placeholder implementation: Compare sentiment prediction with label
        if (tokens->data[0][i] == sentiment_labels->data[0][i]) {
            correct_predictions++;
        }
    }

    // Calculate accuracy
    double accuracy = (double)correct_predictions / tokens->cols * 100.0;
    printf("Sentiment Analysis Accuracy: %.2f%%\n", accuracy);
}

// NER wrapper functions
void fossil_jellyfish_dolphin_recognize_entities(jellyfish_matrix* tokens, jellyfish_matrix* ner_labels) {
    if (tokens->cols != ner_labels->cols) {
        printf("Error: Number of tokens does not match number of labels.\n");
        return;
    }

    int correct_predictions = 0;
    // Iterate over each token and compare NER prediction with label
    for (int i = 0; i < tokens->cols; ++i) {
        // Placeholder implementation: Compare NER prediction with label
        if (tokens->data[0][i] == ner_labels->data[0][i]) {
            correct_predictions++;
        }
    }

    // Calculate accuracy
    double accuracy = (double)correct_predictions / tokens->cols * 100.0;
    printf("NER Accuracy: %.2f%%\n", accuracy);
}
