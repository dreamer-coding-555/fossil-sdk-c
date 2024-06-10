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

#include <fossil/xjellyfish/dolphin.h> // library under test

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

XTEST(test_FOSSIL_jellyfish_dolphin_tokenize) {
    char* text = "This is a test sentence.";
    int vocab_size = 100;
    jellyfish_matrix* tokens = FOSSIL_jellyfish_dolphin_tokenize(text, vocab_size, "en");

    // Check if the tokens matrix is not NULL
    TEST_ASSUME_NOT_CNULLPTR(tokens);

    // Additional checks can be added to verify the correctness of tokenization
}

XTEST(test_FOSSIL_jellyfish_dolphin_embed) {
    // Create sample tokenized matrix and embedding matrix
    jellyfish_matrix* tokens = FOSSIL_jellyfish_create_matrix(5, 10);
    jellyfish_matrix* embedding_matrix = FOSSIL_jellyfish_create_matrix(10, 20);

    jellyfish_matrix* embeddings = FOSSIL_jellyfish_dolphin_embed(tokens, embedding_matrix);

    // Check if the embeddings matrix is not NULL
    TEST_ASSUME_NOT_CNULLPTR(embeddings);

    // Additional checks can be added to verify the correctness of embedding
}

XTEST(test_FOSSIL_jellyfish_dolphin_analyze_sentiment) {
    // Create sample tokenized matrix and sentiment labels matrix
    jellyfish_matrix* tokens = FOSSIL_jellyfish_create_matrix(5, 10);
    jellyfish_matrix* sentiment_labels = FOSSIL_jellyfish_create_matrix(5, 1);

    // Analyze sentiment
    FOSSIL_jellyfish_dolphin_analyze_sentiment(tokens, sentiment_labels);

    // Additional checks can be added to verify the sentiment analysis
}

XTEST(test_FOSSIL_jellyfish_dolphin_recognize_entities) {
    // Create sample tokenized matrix and NER labels matrix
    jellyfish_matrix* tokens = FOSSIL_jellyfish_create_matrix(5, 10);
    jellyfish_matrix* ner_labels = FOSSIL_jellyfish_create_matrix(5, 1);

    // Recognize entities
    FOSSIL_jellyfish_dolphin_recognize_entities(tokens, ner_labels);

    // Additional checks can be added to verify the named entity recognition
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
XTEST_DEFINE_POOL(dolphin_group) {
    XTEST_RUN_UNIT(test_FOSSIL_jellyfish_dolphin_tokenize);
    XTEST_RUN_UNIT(test_FOSSIL_jellyfish_dolphin_embed);
    XTEST_RUN_UNIT(test_FOSSIL_jellyfish_dolphin_analyze_sentiment);
    XTEST_RUN_UNIT(test_FOSSIL_jellyfish_dolphin_recognize_entities);
} // end of fixture
