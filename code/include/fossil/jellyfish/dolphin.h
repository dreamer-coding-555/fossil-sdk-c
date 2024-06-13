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
#ifndef FOSSIL_JELLYFISH_AI_DOLPHIN_H
#define FOSSIL_JELLYFISH_AI_DOLPHIN_H

#include "jellyfish.h"

#ifdef __cplusplus
extern "C"
{
#endif

// ========================================================================
// create and erase functions
// ========================================================================

/**
 * Tokenizes the given text using the Dolphin algorithm.
 *
 * @param text The text to tokenize.
 * @param vocab_size The size of the vocabulary.
 * @return A pointer to the tokenized matrix.
 */
jellyfish_matrix_t* fossil_jellyfish_dolphin_tokenize(char* text, int vocab_size, char* language);

/**
 * Embeds the given tokens using the Dolphin algorithm.
 *
 * @param tokens The tokenized matrix.
 * @param embedding_matrix The embedding matrix.
 * @return A pointer to the embedded matrix.
 */
jellyfish_matrix_t* fossil_jellyfish_dolphin_embed(jellyfish_matrix_t* tokens, jellyfish_matrix_t* embedding_matrix);

/**
 * Analyzes the sentiment of the given tokens using the Dolphin algorithm.
 *
 * @param tokens The tokenized matrix.
 * @param sentiment_labels The sentiment labels matrix.
 */
void fossil_jellyfish_dolphin_analyze_sentiment(jellyfish_matrix_t* tokens, jellyfish_matrix_t* sentiment_labels);

/**
 * Recognizes entities in the given tokens using the Dolphin algorithm.
 *
 * @param tokens The tokenized matrix.
 * @param ner_labels The named entity recognition labels matrix.
 */
void fossil_jellyfish_dolphin_recognize_entities(jellyfish_matrix_t* tokens, jellyfish_matrix_t* ner_labels);

#ifdef __cplusplus
}
#endif

#endif
