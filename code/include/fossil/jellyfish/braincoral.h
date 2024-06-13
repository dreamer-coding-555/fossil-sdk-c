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
#ifndef FOSSIL_JELLYFISH_AI_BRAINCORAL_H
#define FOSSIL_JELLYFISH_AI_BRAINCORAL_H

#include "jellyfish.h"

#ifdef __cplusplus
extern "C"
{
#endif

// Theory of Mind Inference

// ========================================================================
// create and erase functions
// ========================================================================

/**
 * Update the belief matrix based on the given observation.
 *
 * @param belief The belief matrix to update.
 * @param observation The observation matrix.
 */
void fossil_jellyfish_braincoral_tom_update_belief(jellyfish_matrix_t* belief, jellyfish_matrix_t* observation);

/**
 * Combine two belief matrices into a single belief matrix.
 *
 * @param belief1 The first belief matrix.
 * @param belief2 The second belief matrix.
 * @return The combined belief matrix.
 */
jellyfish_matrix_t* fossil_jellyfish_braincoral_tom_combine_beliefs(jellyfish_matrix_t* belief1, jellyfish_matrix_t* belief2);

/**
 * Infer the desire matrix based on the given behavior matrix.
 *
 * @param behavior The behavior matrix.
 * @return The inferred desire matrix.
 */
jellyfish_matrix_t* fossil_jellyfish_braincoral_tom_infer_desire(jellyfish_matrix_t* behavior);

/**
 * Infer the intention matrix based on the given behavior matrix and context matrix.
 *
 * @param behavior The behavior matrix.
 * @param context The context matrix.
 * @return The inferred intention matrix.
 */
jellyfish_matrix_t* fossil_jellyfish_braincoral_tom_infer_intention(jellyfish_matrix_t* behavior, jellyfish_matrix_t* context);

/**
 * Recognize the emotion matrix based on the given text data matrix.
 *
 * @param text_data The text data matrix.
 * @return The recognized emotion matrix.
 */
jellyfish_matrix_t* fossil_jellyfish_braincoral_tom_recognize_emotion(jellyfish_matrix_t* text_data);

/**
 * Simulate the perspective matrix based on the given own belief matrix and other belief matrix.
 *
 * @param own_belief The own belief matrix.
 * @param other_belief The other belief matrix.
 * @return The simulated perspective matrix.
 */
jellyfish_matrix_t* fossil_jellyfish_braincoral_tom_simulate_perspective(jellyfish_matrix_t* own_belief, jellyfish_matrix_t* other_belief);

/**
 * Model the joint attention matrix based on the given own belief matrix and other belief matrix.
 *
 * @param own_belief The own belief matrix.
 * @param other_belief The other belief matrix.
 * @return The modeled joint attention matrix.
 */
jellyfish_matrix_t* fossil_jellyfish_braincoral_tom_model_joint_attention(jellyfish_matrix_t* own_belief, jellyfish_matrix_t* other_belief);

/**
 * Infer the mind state matrix based on the given own belief matrix, other belief matrix, observed behavior matrix, and context matrix.
 *
 * @param own_belief The own belief matrix.
 * @param other_belief The other belief matrix.
 * @param observed_behavior The observed behavior matrix.
 * @param context The context matrix.
 * @return The inferred mind state matrix.
 */
jellyfish_matrix_t* fossil_jellyfish_braincoral_tom_infer_mind_state(jellyfish_matrix_t* own_belief, jellyfish_matrix_t* other_belief, jellyfish_matrix_t* observed_behavior, jellyfish_matrix_t* context);

#ifdef __cplusplus
}
#endif

#endif
