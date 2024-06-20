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
#ifndef FOSSIL_JELLYFISH_AI_CORE_H
#define FOSSIL_JELLYFISH_AI_CORE_H

#include <stdlib.h>
#include <stdint.h>

// Define a structure for a matrix
typedef struct {
    int rows;
    int cols;
    double** data;
} jellyfish_matrix_t;

// Define a structure for a neural network layer
typedef struct {
    jellyfish_matrix_t* weights;
    jellyfish_matrix_t* bias;
    jellyfish_matrix_t* output;
    void (*activation)(jellyfish_matrix_t*);
} jellyfish_layer_t;

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * Creates a new jellyfish_matrix_t with the specified number of rows and columns.
 *
 * @param rows The number of rows in the matrix.
 * @param cols The number of columns in the matrix.
 * @return A pointer to the newly created jellyfish_matrix_t.
 */
jellyfish_matrix_t* fossil_jellyfish_create_matrix(int rows, int cols);

/**
 * Erases the contents of the given jellyfish_matrix_t.
 *
 * @param mat The jellyfish_matrix_t to be erased.
 */
void fossil_jellyfish_erase_matrix(jellyfish_matrix_t* mat);

/**
 * Calculates the inverse of a jellyfish matrix.
 *
 * This function takes a jellyfish matrix as input and calculates its inverse.
 * The resulting inverse matrix is returned.
 *
 * @param covariance The jellyfish matrix to be inverted.
 * @return The inverse of the input jellyfish matrix.
 */
jellyfish_matrix_t* fossil_jellyfish_inverse(jellyfish_matrix_t* covariance);

/**
 * Prints the contents of the given jellyfish_matrix_t.
 *
 * @param mat The jellyfish_matrix_t to be printed.
 */
void fossil_jellyfish_print_matrix(jellyfish_matrix_t* mat);

/**
 * Multiplies two jellyfish_matrices and returns the result.
 *
 * @param a The first jellyfish_matrix_t.
 * @param b The second jellyfish_matrix_t.
 * @return A pointer to the resulting jellyfish_matrix_t.
 */
jellyfish_matrix_t* fossil_jellyfish_multiply(jellyfish_matrix_t* a, jellyfish_matrix_t* b);

/**
 * Adds two jellyfish_matrices and returns the result.
 *
 * @param a The first jellyfish_matrix_t.
 * @param b The second jellyfish_matrix_t.
 * @return A pointer to the resulting jellyfish_matrix_t.
 */
jellyfish_matrix_t* fossil_jellyfish_add(jellyfish_matrix_t* a, jellyfish_matrix_t* b);

/**
 * Subtracts one jellyfish_matrix_t from another and returns the result.
 *
 * @param a The jellyfish_matrix_t to subtract from.
 * @param b The jellyfish_matrix_t to subtract.
 * @return A pointer to the resulting jellyfish_matrix_t.
 */
jellyfish_matrix_t* fossil_jellyfish_subtract(jellyfish_matrix_t* a, jellyfish_matrix_t* b);

/**
 * Transposes the given jellyfish_matrix_t and returns the result.
 *
 * @param mat The jellyfish_matrix_t to be transposed.
 * @return A pointer to the resulting jellyfish_matrix_t.
 */
jellyfish_matrix_t* fossil_jellyfish_transpose(jellyfish_matrix_t* mat);

/**
 * Applies the sigmoid activation function to the given jellyfish_matrix_t.
 *
 * @param mat The jellyfish_matrix_t to apply the sigmoid function to.
 */
void fossil_jellyfish_sigmoid(jellyfish_matrix_t* mat);

/**
 * Applies the ReLU activation function to the given jellyfish_matrix_t.
 *
 * @param mat The jellyfish_matrix_t to apply the ReLU function to.
 */
void fossil_jellyfish_relu(jellyfish_matrix_t* mat);

/**
 * Applies the hyperbolic tangent activation function to the given jellyfish_matrix_t.
 *
 * @param mat The jellyfish_matrix_t to apply the hyperbolic tangent function to.
 */
void fossil_jellyfish_tanh(jellyfish_matrix_t* mat);

/**
 * Performs forward propagation on the neural network with the given input and layer.
 *
 * @param input The input jellyfish_matrix_t.
 * @param layer The jellyfish_layer_t to perform forward propagation on.
 * @return A pointer to the resulting jellyfish_matrix_t.
 */
jellyfish_matrix_t* fossil_jellyfish_forward(jellyfish_matrix_t* input, jellyfish_layer_t* layer);

/**
 * Creates a new jellyfish_layer_t with the specified input size, output size, and activation function.
 *
 * @param input_size The size of the input to the layer.
 * @param output_size The size of the output from the layer.
 * @param activation The activation function to be used by the layer.
 * @return A pointer to the newly created jellyfish_layer_t.
 */
jellyfish_layer_t* fossil_jellyfish_create_layer(int input_size, int output_size, void (*activation)(jellyfish_matrix_t*));

/**
 * Erases the contents of the given jellyfish_layer_t.
 *
 * @param layer The jellyfish_layer_t to be erased.
 */
void fossil_jellyfish_erase_layer(jellyfish_layer_t* layer);

/**
 * Calculates the mean squared error between the predicted and actual jellyfish_matrices.
 *
 * @param predicted The predicted jellyfish_matrix_t.
 * @param actual The actual jellyfish_matrix_t.
 * @return The mean squared error.
 */
double fossil_jellyfish_mse(jellyfish_matrix_t* predicted, jellyfish_matrix_t* actual);

/**
 * Calculates the cross-entropy loss between the predicted and actual jellyfish_matrices.
 *
 * @param predicted The predicted jellyfish_matrix_t.
 * @param actual The actual jellyfish_matrix_t.
 * @return The cross-entropy loss.
 */
double fossil_jellyfish_cross_entropy(jellyfish_matrix_t* predicted, jellyfish_matrix_t* actual);

/**
 * Performs backpropagation on the given layer with the specified input, target, output gradient, and learning rate.
 *
 * @param layer The jellyfish_layer_t to perform backpropagation on.
 * @param input The input jellyfish_matrix_t.
 * @param d_output The output gradient jellyfish_matrix_t.
 * @param learning_rate The learning rate.
 */
void fossil_jellyfish_backward(jellyfish_layer_t* layer, jellyfish_matrix_t* input, jellyfish_matrix_t* target, jellyfish_matrix_t* d_output, double learning_rate);

/**
 * Updates the weights and biases of the given layer using the specified weight and bias gradients and learning rate.
 *
 * @param layer The jellyfish_layer_t to update.
 * @param d_weights The weight gradients jellyfish_matrix_t.
 * @param d_bias The bias gradients jellyfish_matrix_t.
 * @param learning_rate The learning rate.
 */
void fossil_jellyfish_update_weights(jellyfish_layer_t* layer, jellyfish_matrix_t* d_weights, jellyfish_matrix_t* d_bias, double learning_rate);

/**
 * Tokenizes the given text into a jellyfish_matrix_t of tokens using the specified vocabulary size.
 *
 * @param text The text to be tokenized.
 * @param vocab_size The size of the vocabulary.
 * @return A pointer to the resulting jellyfish_matrix_t of tokens.
 */
jellyfish_matrix_t* fossil_jellyfish_tokenize(char* text, int vocab_size, char* language);

/**
 * Embeds the given tokens into a jellyfish_matrix_t using the specified embedding matrix.
 *
 * @param tokens The jellyfish_matrix_t of tokens.
 * @param embedding_matrix The embedding matrix.
 * @return A pointer to the resulting jellyfish_matrix_t of embeddings.
 */
jellyfish_matrix_t* fossil_jellyfish_embed(jellyfish_matrix_t* tokens, jellyfish_matrix_t* embedding_matrix);

/**
 * Encodes the given input using the specified encoder layer and returns the encoded jellyfish_matrix_t.
 *
 * @param input The input jellyfish_matrix_t.
 * @param encoder The encoder jellyfish_layer_t.
 * @return A pointer to the encoded jellyfish_matrix_t.
 */
jellyfish_matrix_t* fossil_jellyfish_autoencoder_encode(jellyfish_matrix_t* input, jellyfish_layer_t* encoder);

/**
 * Decodes the given encoded jellyfish_matrix_t using the specified decoder layer and returns the reconstructed jellyfish_matrix_t.
 *
 * @param encoded The encoded jellyfish_matrix_t.
 * @param decoder The decoder jellyfish_layer_t.
 * @return A pointer to the reconstructed jellyfish_matrix_t.
 */
jellyfish_matrix_t* fossil_jellyfish_autoencoder_decode(jellyfish_matrix_t* encoded, jellyfish_layer_t* decoder);

/**
 * Calculates the reconstruction error between the input and reconstructed jellyfish_matrices.
 *
 * @param input The input jellyfish_matrix_t.
 * @param reconstructed The reconstructed jellyfish_matrix_t.
 * @return The reconstruction error.
 */
double fossil_jellyfish_reconstruction_error(jellyfish_matrix_t* input, jellyfish_matrix_t* reconstructed);

/**
 * Saves the contents of the given jellyfish_matrix_t to a .fish file with the specified filename.
 *
 * @param filename The name of the .fish file.
 * @param mat The jellyfish_matrix_t to be saved.
 * @return 0 if successful, -1 otherwise.
 */
int fossil_jellyfish_save_matrix(const char* filename, jellyfish_matrix_t* mat);

/**
 * Loads the contents of a .fish file with the specified filename into a jellyfish_matrix_t.
 *
 * @param filename The name of the .fish file.
 * @return A pointer to the loaded jellyfish_matrix_t, or NULL if unsuccessful.
 */
jellyfish_matrix_t* fossil_jellyfish_load_matrix(const char* filename);

/**
 * Saves the contents of the given jellyfish_layer_t to a .fish file with the specified filename.
 *
 * @param filename The name of the .fish file.
 * @param layer The jellyfish_layer_t to be saved.
 * @return 0 if successful, -1 otherwise.
 */
int fossil_jellyfish_save_layer(const char* filename, jellyfish_layer_t* layer);

/**
 * Loads the contents of a .fish file with the specified filename into a jellyfish_layer_t.
 *
 * @param filename The name of the .fish file.
 * @return A pointer to the loaded jellyfish_layer_t, or NULL if unsuccessful.
 */
jellyfish_layer_t* fossil_jellyfish_load_layer(const char* filename);

#ifdef __cplusplus
}
#endif

#endif
