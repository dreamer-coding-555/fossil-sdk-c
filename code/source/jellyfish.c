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
#include "fossil/jellyfish/jellyfish.h"
#include "fossil/common/common.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Define stopwords and language-specific normalization rules for each language
char* stopwords_en[] = {"a", "an", "the", "is", "are", "was", "were", "in", "on", "at", "to", "for", "of", "and", "or", "not"};
char* stopwords_es[] = {"el", "la", "los", "las", "un", "una", "unos", "unas", "en", "de", "del", "a", "por", "para", "con", "entre"};
char* stopwords_fr[] = {"le", "la", "les", "un", "une", "des", "du", "de", "d'", "en", "à", "au", "aux", "pour", "avec", "sur", "sous"};
char* stopwords_de[] = {"der", "die", "das", "ein", "eine", "einer", "einem", "einen", "eines", "in", "auf", "an", "für", "mit", "von", "zu"};
char* stopwords_it[] = {"il", "la", "i", "gli", "le", "un", "una", "uno", "dei", "delle", "in", "su", "per", "con", "a", "da"};
char* stopwords_pt[] = {"o", "a", "os", "as", "um", "uma", "uns", "umas", "em", "no", "na", "nos", "nas", "para", "com", "por", "de"};
char* stopwords_nl[] = {"de", "het", "een", "en", "van", "voor", "op", "te", "naar", "bij", "over", "onder", "uit", "door", "met", "zijn"};
char* stopwords_ru[] = {"и", "в", "во", "не", "что", "он", "на", "я", "с", "со", "как", "а", "то", "все", "она", "так", "его"};
char* stopwords_ja[] = {"の", "で", "て", "た", "る", "に", "を", "は", "が", "も", "と", "し", "である", "これ", "その", "ある", "いる"};

// utilites for tokenization and normalization

// Check if a word is a stopword for a specific language
int is_stopword(char* word, char* stopwords[], int num_stopwords) {
    for (int i = 0; i < num_stopwords; i++) {
        if (strcmp(word, stopwords[i]) == 0) {
            return 1; // Word is a stopword
        }
    }
    return 0; // Word is not a stopword
}

// Normalize a word (convert to lowercase, remove punctuation)
void normalize_word(char* word) {
    // Convert word to lowercase
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
    // Remove punctuation (replace with space)
    for (int i = 0; word[i]; i++) {
        if (!isalpha(word[i])) {
            word[i] = ' ';
        }
    }
}

// Create a matrix with the specified number of rows and columns
jellyfish_matrix_t* fossil_jellyfish_create_matrix(int rows, int cols) {
    jellyfish_matrix_t* mat = (jellyfish_matrix_t*)malloc(sizeof(jellyfish_matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        mat->data[i] = (double*)malloc(cols * sizeof(double));
        for (int j = 0; j < cols; j++) {
            mat->data[i][j] = 0.0;  // Initialize all elements to zero
        }
    }
    return mat;
}

// Free memory allocated for a matrix
void fossil_jellyfish_erase_matrix(jellyfish_matrix_t* mat) {
    for (int i = 0; i < mat->rows; i++) {
        free(mat->data[i]);
    }
    free(mat->data);
    free(mat);
}

// Print the contents of a matrix
void fossil_jellyfish_print_matrix(jellyfish_matrix_t* mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%f ", mat->data[i][j]);
        }
        printf("\n");
    }
}

// Multiply two matrices and return the result
jellyfish_matrix_t* fossil_jellyfish_multiply(jellyfish_matrix_t* a, jellyfish_matrix_t* b) {
    if (a->cols != b->rows) {
        fprintf(stderr, "Matrix dimensions are incompatible for multiplication.\n");
        return cnullptr;
    }
    jellyfish_matrix_t* result = fossil_jellyfish_create_matrix(a->rows, b->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            double sum = 0.0;
            for (int k = 0; k < a->cols; k++) {
                sum += a->data[i][k] * b->data[k][j];
            }
            result->data[i][j] = sum;
        }
    }
    return result;
}

// Add two matrices and return the result
jellyfish_matrix_t* fossil_jellyfish_add(jellyfish_matrix_t* a, jellyfish_matrix_t* b) {
    if (a->rows != b->rows || a->cols != b->cols) {
        fprintf(stderr, "Matrix dimensions are incompatible for addition.\n");
        return cnullptr;
    }
    jellyfish_matrix_t* result = fossil_jellyfish_create_matrix(a->rows, a->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            result->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
    return result;
}

// Subtract one matrix from another and return the result
jellyfish_matrix_t* fossil_jellyfish_subtract(jellyfish_matrix_t* a, jellyfish_matrix_t* b) {
    if (a->rows != b->rows || a->cols != b->cols) {
        fprintf(stderr, "Matrix dimensions are incompatible for subtraction.\n");
        return cnullptr;
    }
    jellyfish_matrix_t* result = fossil_jellyfish_create_matrix(a->rows, a->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            result->data[i][j] = a->data[i][j] - b->data[i][j];
        }
    }
    return result;
}

// Transpose a matrix and return the result
jellyfish_matrix_t* fossil_jellyfish_transpose(jellyfish_matrix_t* mat) {
    jellyfish_matrix_t* result = fossil_jellyfish_create_matrix(mat->cols, mat->rows);
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            result->data[j][i] = mat->data[i][j];
        }
    }
    return result;
}

// Apply the sigmoid activation function element-wise to a matrix
void fossil_jellyfish_sigmoid(jellyfish_matrix_t* mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            mat->data[i][j] = 1.0 / (1.0 + exp(-mat->data[i][j]));
        }
    }
}

// Apply the ReLU activation function element-wise to a matrix
void fossil_jellyfish_relu(jellyfish_matrix_t* mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            mat->data[i][j] = fmax(0.0, mat->data[i][j]);
        }
    }
}

// Apply the hyperbolic tangent (tanh) activation function element-wise to a matrix
void fossil_jellyfish_tanh(jellyfish_matrix_t* mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            mat->data[i][j] = tanh(mat->data[i][j]);
        }
    }
}

// Perform forward propagation for a single layer of a neural network
jellyfish_matrix_t* fossil_jellyfish_forward(jellyfish_matrix_t* input, jellyfish_layer_t* layer) {
    jellyfish_matrix_t* z = fossil_jellyfish_multiply(input, layer->weights);
    for (int i = 0; i < z->rows; i++) {
        for (int j = 0; j < z->cols; j++) {
            z->data[i][j] += layer->bias->data[0][j];
        }
    }
    layer->activation(z);
    layer->output = z;
    return z;
}

// Create a neural network layer with the specified input and output sizes and activation function
jellyfish_layer_t* fossil_jellyfish_create_layer(int input_size, int output_size, void (*activation)(jellyfish_matrix_t*)) {
    jellyfish_layer_t* layer = (jellyfish_layer_t*)malloc(sizeof(jellyfish_layer_t));
    layer->weights = fossil_jellyfish_create_matrix(input_size, output_size);
    layer->bias = fossil_jellyfish_create_matrix(1, output_size);
    layer->output = cnullptr;
    layer->activation = activation;
    // Initialize weights and biases with small random values
    for (int i = 0; i < input_size; i++) {
        for (int j = 0; j < output_size; j++) {
            layer->weights->data[i][j] = ((double)rand() / RAND_MAX) * 0.01;
        }
    }
    for (int j = 0; j < output_size; j++) {
        layer->bias->data[0][j] = ((double)rand() / RAND_MAX) * 0.01;
    }
    return layer;
}

// Free memory allocated for a neural network layer
void fossil_jellyfish_erase_layer(jellyfish_layer_t* layer) {
    fossil_jellyfish_erase_matrix(layer->weights);
    fossil_jellyfish_erase_matrix(layer->bias);
    if (layer->output != cnullptr) {
        fossil_jellyfish_erase_matrix(layer->output);
    }
    free(layer);
}

// Calculate the mean squared error (MSE) loss between predicted and actual matrices
double fossil_jellyfish_mse(jellyfish_matrix_t* predicted, jellyfish_matrix_t* actual) {
    double sum_squared_error = 0.0;
    for (int i = 0; i < predicted->rows; i++) {
        for (int j = 0; j < predicted->cols; j++) {
            double error = predicted->data[i][j] - actual->data[i][j];
            sum_squared_error += error * error;
        }
    }
    return sum_squared_error / (predicted->rows * predicted->cols);
}

// Calculate the cross-entropy loss between predicted and actual matrices
double fossil_jellyfish_cross_entropy(jellyfish_matrix_t* predicted, jellyfish_matrix_t* actual) {
    double loss = 0.0;
    for (int i = 0; i < predicted->rows; i++) {
        for (int j = 0; j < predicted->cols; j++) {
            loss += actual->data[i][j] * log(predicted->data[i][j] + 1e-9); // Add small epsilon to prevent log(0)
        }
    }
    return -loss / (predicted->rows * predicted->cols);
}

// Sum the rows of a matrix
jellyfish_matrix_t* fossil_jellyfish_sum_rows(jellyfish_matrix_t* matrix) {
    int rows = matrix->rows;
    int cols = matrix->cols;
    jellyfish_matrix_t* result = fossil_jellyfish_create_matrix(1, cols);
    
    for (int j = 0; j < cols; j++) {
        double sum = 0.0;
        for (int i = 0; i < rows; i++) {
            sum += matrix->data[i][j];
        }
        result->data[0][j] = sum;
    }

    return result;
}

// Perform backpropagation for a single layer of a neural network and update weights and biases
void fossil_jellyfish_backward(jellyfish_layer_t* layer, jellyfish_matrix_t* input, jellyfish_matrix_t* target, jellyfish_matrix_t* d_output, double learning_rate) {
    // Compute error signal
    jellyfish_matrix_t* error = fossil_jellyfish_subtract(target, d_output);

    // Compute gradients
    jellyfish_matrix_t* d_weights = fossil_jellyfish_multiply(fossil_jellyfish_transpose(input), error);
    jellyfish_matrix_t* d_bias = fossil_jellyfish_sum_rows(error);

    // Update weights and biases
    fossil_jellyfish_update_weights(layer, d_weights, d_bias, learning_rate);

    // Clean up
    fossil_jellyfish_erase_matrix(error);
    fossil_jellyfish_erase_matrix(d_weights);
    fossil_jellyfish_erase_matrix(d_bias);
}

double fossil_jellyfish_find_in_vocab(char *word) {
    // Find the index of a word in the vocabulary
    // For simplicity, we'll use a fixed vocabulary with a predefined mapping of words to indices
    char* vocab[] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon"};
    int vocab_size = sizeof(vocab) / sizeof(vocab[0]);
    for (int i = 0; i < vocab_size; i++) {
        if (strcmp(word, vocab[i]) == 0) {
            return (double)i;
        }
    }
    return -1.0; // Return -1 if word is not found in the vocabulary
}

// Update weights and biases of a layer based on the calculated gradients
void fossil_jellyfish_update_weights(jellyfish_layer_t* layer, jellyfish_matrix_t* d_weights, jellyfish_matrix_t* d_bias, double learning_rate) {
    for (int i = 0; i < layer->weights->rows; i++) {
        for (int j = 0; j < layer->weights->cols; j++) {
            layer->weights->data[i][j] -= learning_rate * d_weights->data[i][j];
        }
    }
    for (int j = 0; j < layer->bias->cols; j++) {
        layer->bias->data[0][j] -= learning_rate * d_bias->data[0][j];
    }
}

// Tokenize a text input into a matrix of tokens based on a given vocabulary size and language
jellyfish_matrix_t* fossil_jellyfish_tokenize(char* text, int vocab_size, char* language) {
    // Initialize a matrix to store the tokens
    jellyfish_matrix_t* tokens = fossil_jellyfish_create_matrix(1, vocab_size);
    
    // Determine stopwords for the specified language
    char** stopwords;
    int num_stopwords;
    if (strcmp(language, "en") == 0) {
        stopwords = stopwords_en;
        num_stopwords = sizeof(stopwords_en) / sizeof(stopwords_en[0]);
    } else if (strcmp(language, "es") == 0) {
        stopwords = stopwords_es;
        num_stopwords = sizeof(stopwords_es) / sizeof(stopwords_es[0]);
    } else if (strcmp(language, "fr") == 0) {
        stopwords = stopwords_fr;
        num_stopwords = sizeof(stopwords_fr) / sizeof(stopwords_fr[0]);
    } else if (strcmp(language, "de") == 0) {
        stopwords = stopwords_de;
        num_stopwords = sizeof(stopwords_de) / sizeof(stopwords_de[0]);
    } else if (strcmp(language, "it") == 0) {
        stopwords = stopwords_it;
        num_stopwords = sizeof(stopwords_it) / sizeof(stopwords_it[0]);
    } else if (strcmp(language, "pt") == 0) {
        stopwords = stopwords_pt;
        num_stopwords = sizeof(stopwords_pt) / sizeof(stopwords_pt[0]);
    } else if (strcmp(language, "nl") == 0) {
        stopwords = stopwords_nl;
        num_stopwords = sizeof(stopwords_nl) / sizeof(stopwords_nl[0]);
    } else if (strcmp(language, "ru") == 0) {
        stopwords = stopwords_ru;
        num_stopwords = sizeof(stopwords_ru) / sizeof(stopwords_ru[0]);
    } else if (strcmp(language, "ja") == 0) {
        stopwords = stopwords_ja;
        num_stopwords = sizeof(stopwords_ja) / sizeof(stopwords_ja[0]);
    } else {
        // Default to English stopwords if language is not supported
        stopwords = stopwords_en;
        num_stopwords = sizeof(stopwords_en) / sizeof(stopwords_en[0]);
    }
    
    // Tokenization process (split text into words, normalize, remove stopwords, and filter tokens)
    char* word = strtok(text, " \t\n\r");
    int index = 0;
    while (word != cnullptr && index < vocab_size) {
        // Normalize word (convert to lowercase, remove punctuation)
        normalize_word(word);
        
        // Check if word is a stopword
        if (!is_stopword(word, stopwords, num_stopwords)) {
            // Store the token in the matrix
            tokens->data[0][index++] = fossil_jellyfish_find_in_vocab(word);
        }
        
        word = strtok(cnullptr, " \t\n\r");
    }
    
    return tokens;
}

// Embed tokens into a matrix of word embeddings using an embedding matrix
jellyfish_matrix_t* fossil_jellyfish_embed(jellyfish_matrix_t* tokens, jellyfish_matrix_t* embedding_matrix) {
    // Initialize a matrix to store the embeddings
    int max_token_length = tokens->cols;
    jellyfish_matrix_t* embeddings = fossil_jellyfish_create_matrix(max_token_length, embedding_matrix->cols);
    
    // Lookup embeddings for each token
    for (int i = 0; i < tokens->cols; i++) {
        int token_index = (int)tokens->data[0][i];
        if (token_index >= 0 && token_index < embedding_matrix->rows) {
            // Copy embedding from the embedding matrix
            for (int j = 0; j < embedding_matrix->cols; j++) {
                embeddings->data[i][j] = embedding_matrix->data[token_index][j];
            }
        } else {
            // Handle out-of-vocabulary tokens (use zero embeddings or a special token)
            // For simplicity, we'll use zero embeddings for out-of-vocabulary tokens
            for (int j = 0; j < embedding_matrix->cols; j++) {
                embeddings->data[i][j] = 0.0;
            }
        }
    }
    
    return embeddings;
}

jellyfish_matrix_t* fossil_jellyfish_inverse(jellyfish_matrix_t* covariance) {
    // Compute the inverse of a matrix using the Gauss-Jordan elimination method
    int n = covariance->rows;
    jellyfish_matrix_t* inverse = fossil_jellyfish_create_matrix(n, n);
    jellyfish_matrix_t* augmented = fossil_jellyfish_create_matrix(n, 2 * n);
    
    // Initialize the augmented matrix with the identity matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            augmented->data[i][j] = covariance->data[i][j];
            augmented->data[i][j + n] = (i == j) ? 1.0 : 0.0;
        }
    }
    
    // Perform row operations to transform the left side of the augmented matrix into the identity matrix
    for (int i = 0; i < n; i++) {
        // Divide the current row by the diagonal element
        double diagonal = augmented->data[i][i];
        for (int j = 0; j < 2 * n; j++) {
            augmented->data[i][j] /= diagonal;
        }
        // Subtract multiples of the current row from the other rows to zero out the other elements in the column
        for (int k = 0; k < n; k++) {
            if (k != i) {
                double factor = augmented->data[k][i];
                for (int j = 0; j < 2 * n; j++) {
                    augmented->data[k][j] -= factor * augmented->data[i][j];
                }
            }
        }
    }
    
    // Copy the right side of the augmented matrix (the inverse of the original matrix) to the result
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inverse->data[i][j] = augmented->data[i][j + n];
        }
    }
    
    fossil_jellyfish_erase_matrix(augmented);
    return inverse;
}

// Encode input data using the encoder layer of an autoencoder
jellyfish_matrix_t* fossil_jellyfish_autoencoder_encode(jellyfish_matrix_t* input, jellyfish_layer_t* encoder) {
    return fossil_jellyfish_forward(input, encoder);
}

// Decode encoded data using the decoder layer of an autoencoder
jellyfish_matrix_t* fossil_jellyfish_autoencoder_decode(jellyfish_matrix_t* encoded, jellyfish_layer_t* decoder) {
    return fossil_jellyfish_forward(encoded, decoder);
}

// Calculate the reconstruction error between the input and the reconstructed output
double fossil_jellyfish_reconstruction_error(jellyfish_matrix_t* input, jellyfish_matrix_t* reconstructed) {
    // Compute mean squared error between input and reconstructed output
    return fossil_jellyfish_mse(input, reconstructed);
}

// Save a matrix to a .fish file
int fossil_jellyfish_save_matrix(const char* filename, jellyfish_matrix_t* mat) {
    // Check if the filename has the .fish extension
    const char* extension = ".fish";
    if (strstr(filename, extension) == cnullptr) {
        // If the extension is not present, append it to the filename
        char filename_with_extension[strlen(filename) + strlen(extension) + 1];
        strcpy(filename_with_extension, filename);
        strcat(filename_with_extension, extension);
        return fossil_jellyfish_save_matrix(filename_with_extension, mat);
    }

    FILE* file = fopen(filename, "w");
    if (file == cnullptr) {
        perror("Error opening file for writing");
        return 0;
    }
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            fprintf(file, "%.6f ", mat->data[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
    return 1;
}

// Load a matrix from a .fish file
jellyfish_matrix_t* fossil_jellyfish_load_matrix(const char* filename) {
    // Check if the filename has the .fish extension
    const char* extension = ".fish";
    if (strstr(filename, extension) == cnullptr) {
        // If the extension is not present, append it to the filename
        char filename_with_extension[strlen(filename) + strlen(extension) + 1];
        strcpy(filename_with_extension, filename);
        strcat(filename_with_extension, extension);
        return fossil_jellyfish_load_matrix(filename_with_extension);
    }

    FILE* file = fopen(filename, "r");
    if (file == cnullptr) {
        perror("Error opening file for reading");
        return cnullptr;
    }
    // Read matrix dimensions
    int rows, cols;
    if (fscanf(file, "%d %d", &rows, &cols) != 2) {
        perror("Error reading matrix dimensions");
        fclose(file);
        return cnullptr;
    }
    // Allocate memory for the matrix
    jellyfish_matrix_t* mat = fossil_jellyfish_create_matrix(rows, cols);
    // Read matrix data
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (fscanf(file, "%lf", &mat->data[i][j]) != 1) {
                perror("Error reading matrix data");
                fclose(file);
                fossil_jellyfish_erase_matrix(mat);
                return cnullptr;
            }
        }
    }
    fclose(file);
    return mat;
}

// Save a layer to a .fish file
int fossil_jellyfish_save_layer(const char* filename, jellyfish_layer_t* layer) {
    // Check if the filename has the .fish extension
    const char* extension = ".fish";
    if (strstr(filename, extension) == cnullptr) {
        // If the extension is not present, append it to the filename
        char filename_with_extension[strlen(filename) + strlen(extension) + 1];
        strcpy(filename_with_extension, filename);
        strcat(filename_with_extension, extension);
        return fossil_jellyfish_save_layer(filename_with_extension, layer);
    }

    FILE* file = fopen(filename, "w");
    if (file == cnullptr) {
        perror("Error opening file for writing");
        return 0;
    }
    // Save layer weights
    fprintf(file, "%d %d\n", layer->weights->rows, layer->weights->cols);
    for (int i = 0; i < layer->weights->rows; i++) {
        for (int j = 0; j < layer->weights->cols; j++) {
            fprintf(file, "%.6f ", layer->weights->data[i][j]);
        }
        fprintf(file, "\n");
    }
    // Save layer bias
    fprintf(file, "%d %d\n", layer->bias->rows, layer->bias->cols);
    for (int i = 0; i < layer->bias->rows; i++) {
        for (int j = 0; j < layer->bias->cols; j++) {
            fprintf(file, "%.6f ", layer->bias->data[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
    return 1;
}

// Load a layer from a .fish file
jellyfish_layer_t* fossil_jellyfish_load_layer(const char* filename) {
    // Check if the filename has the .fish extension
    const char* extension = ".fish";
    if (strstr(filename, extension) == cnullptr) {
        // If the extension is not present, append it to the filename
        char filename_with_extension[strlen(filename) + strlen(extension) + 1];
        strcpy(filename_with_extension, filename);
        strcat(filename_with_extension, extension);
        return fossil_jellyfish_load_layer(filename_with_extension);
    }

    FILE* file = fopen(filename, "r");
    if (file == cnullptr) {
        perror("Error opening file for reading");
        return cnullptr;
    }
    // Read weights dimensions
    int w_rows, w_cols;
    if (fscanf(file, "%d %d", &w_rows, &w_cols) != 2) {
        perror("Error reading weights dimensions");
        fclose(file);
        return cnullptr;
    }
    // Allocate memory for weights
    jellyfish_matrix_t* weights = fossil_jellyfish_create_matrix(w_rows, w_cols);
    // Read weights data
    for (int i = 0; i < w_rows; i++) {
        for (int j = 0; j < w_cols; j++) {
            if (fscanf(file, "%lf", &weights->data[i][j]) != 1) {
                perror("Error reading weights data");
                fclose(file);
                fossil_jellyfish_erase_matrix(weights);
                return cnullptr;
            }
        }
    }
    // Read bias dimensions
    int b_rows, b_cols;
    if (fscanf(file, "%d %d", &b_rows, &b_cols) != 2) {
        perror("Error reading bias dimensions");
        fclose(file);
        fossil_jellyfish_erase_matrix(weights);
        return cnullptr;
    }
    // Allocate memory for bias
    jellyfish_matrix_t* bias = fossil_jellyfish_create_matrix(b_rows, b_cols);
    // Read bias data
    for (int i = 0; i < b_rows; i++) {
        for (int j = 0; j < b_cols; j++) {
            if (fscanf(file, "%lf", &bias->data[i][j]) != 1) {
                perror("Error reading bias data");
                fclose(file);
                fossil_jellyfish_erase_matrix(weights);
                fossil_jellyfish_erase_matrix(bias);
                return cnullptr;
            }
        }
    }
    fclose(file);
    // Create layer and set weights and bias
    jellyfish_layer_t* layer = fossil_jellyfish_create_layer(w_rows, w_cols, cnullptr); // Assuming no activation function for simplicity
    layer->weights = weights;
    layer->bias = bias;
    return layer;
}
