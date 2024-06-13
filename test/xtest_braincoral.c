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

#include <fossil/xjellyfish/braincoral.h> // library under test

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilites
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

// Define network architecture parameters
enum {
    NLG_TEST_INPUT_SIZE = 10,
    NLG_TEST_OUTPUT_SIZE = 20
};

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(test_fossil_jellyfish_braincoral_tom_update_belief) {
    jellyfish_matrix* belief = fossil_jellyfish_create_matrix(1, 3);
    jellyfish_matrix* observation = fossil_jellyfish_create_matrix(1, 3);
    
    // Initialize belief and observation with some dummy values
    for (int i = 0; i < 3; i++) {
        belief->data[0][i] = i + 1;
        observation->data[0][i] = (i + 1) * 2;
    }

    fossil_jellyfish_braincoral_tom_update_belief(belief, observation);

    // Check if the belief is updated correctly (dummy test, real test would check for correct values)
    ASSUME_NOT_CNULL(belief);

    fossil_jellyfish_erase_matrix(belief);
    fossil_jellyfish_erase_matrix(observation);
}

FOSSIL_TEST(test_fossil_jellyfish_braincoral_tom_combine_beliefs) {
    jellyfish_matrix* belief1 = fossil_jellyfish_create_matrix(1, 3);
    jellyfish_matrix* belief2 = fossil_jellyfish_create_matrix(1, 3);

    // Initialize beliefs with some dummy values
    for (int i = 0; i < 3; i++) {
        belief1->data[0][i] = i + 1;
        belief2->data[0][i] = (i + 1) * 3;
    }

    jellyfish_matrix* combined_belief = fossil_jellyfish_braincoral_tom_combine_beliefs(belief1, belief2);

    ASSUME_NOT_CNULL(combined_belief);
    ASSUME_ITS_EQUAL_I32(1, combined_belief->rows);
    ASSUME_ITS_EQUAL_I32(3, combined_belief->cols);

    fossil_jellyfish_erase_matrix(belief1);
    fossil_jellyfish_erase_matrix(belief2);
    fossil_jellyfish_erase_matrix(combined_belief);
}

FOSSIL_TEST(test_fossil_jellyfish_braincoral_tom_infer_desire) {
    jellyfish_matrix* behavior = fossil_jellyfish_create_matrix(1, 3);
    
    // Initialize behavior with some dummy values
    for (int i = 0; i < 3; i++) {
        behavior->data[0][i] = (i + 1) * 2;
    }

    jellyfish_matrix* desire = fossil_jellyfish_braincoral_tom_infer_desire(behavior);

    ASSUME_NOT_CNULL(desire);
    ASSUME_ITS_EQUAL_I32(1, desire->rows);
    ASSUME_ITS_EQUAL_I32(3, desire->cols);

    fossil_jellyfish_erase_matrix(behavior);
    fossil_jellyfish_erase_matrix(desire);
}

FOSSIL_TEST(test_fossil_jellyfish_braincoral_tom_infer_intention) {
    jellyfish_matrix* behavior = fossil_jellyfish_create_matrix(1, 3);
    jellyfish_matrix* context = fossil_jellyfish_create_matrix(1, 3);

    // Initialize behavior and context with some dummy values
    for (int i = 0; i < 3; i++) {
        behavior->data[0][i] = (i + 1) * 2;
        context->data[0][i] = (i + 1) * 3;
    }

    jellyfish_matrix* intention = fossil_jellyfish_braincoral_tom_infer_intention(behavior, context);

    ASSUME_NOT_CNULL(intention);
    ASSUME_ITS_EQUAL_I32(1, intention->rows);
    ASSUME_ITS_EQUAL_I32(3, intention->cols);

    fossil_jellyfish_erase_matrix(behavior);
    fossil_jellyfish_erase_matrix(context);
    fossil_jellyfish_erase_matrix(intention);
}

FOSSIL_TEST(test_fossil_jellyfish_braincoral_tom_recognize_emotion) {
    jellyfish_matrix* text_data = fossil_jellyfish_create_matrix(1, 5);
    
    // Initialize text_data with some dummy values
    for (int i = 0; i < 5; i++) {
        text_data->data[0][i] = (i + 1) * 2;
    }

    jellyfish_matrix* emotion = fossil_jellyfish_braincoral_tom_recognize_emotion(text_data);

    ASSUME_NOT_CNULL(emotion);
    ASSUME_ITS_EQUAL_I32(1, emotion->rows);
    ASSUME_ITS_EQUAL_I32(5, emotion->cols);

    fossil_jellyfish_erase_matrix(text_data);
    fossil_jellyfish_erase_matrix(emotion);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(braincoral_group) {
    ADD_TEST(test_fossil_jellyfish_braincoral_tom_update_belief);
    ADD_TEST(test_fossil_jellyfish_braincoral_tom_combine_beliefs);
    ADD_TEST(test_fossil_jellyfish_braincoral_tom_infer_desire);
    ADD_TEST(test_fossil_jellyfish_braincoral_tom_infer_intention);
    ADD_TEST(test_fossil_jellyfish_braincoral_tom_recognize_emotion);
} // end of fixture
