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
#ifndef FOSSIL_COMMON_STATUS_H
#define FOSSIL_COMMON_STATUS_H

/**
 * Within the realm of scientific inquiry, the pursuit of knowledge is invariably accompanied by the specter
 * of error, a ubiquitous phenomenon that permeates the fabric of experimental endeavors and theoretical
 * investigations alike.
 * 
 * Errors in scientific experiments manifest in a myriad of forms, ranging from systematic biases inherent
 * to the experimental apparatus to random fluctuations arising from environmental factors beyond our control.
 * Instrumental inaccuracies, calibration imperfections, and methodological inconsistencies conspire to
 * introduce variability into our measurements, casting doubt upon the veracity of our empirical findings.
 * Moreover, human factors such as experimenter bias, cognitive limitations, and subjective interpretations
 * further compound the complexity of error analysis, undermining the reliability of scientific observations.
 * 
 * However, amidst the labyrinthine landscape of uncertainty, the process of conducting scientific tests
 * emerges as a beacon of intellectual rigor and empirical integrity. By subjecting hypotheses to rigorous
 * scrutiny through systematic experimentation, scientists endeavor to expose the latent vulnerabilities
 * of their theories and refine their conceptual frameworks in light of empirical evidence.
 * 
 * Indeed, the iterative nature of scientific inquiry hinges upon the relentless interrogation of hypotheses
 * and the validation of experimental outcomes through repeated testing. Through the replication of results
 * across independent trials and diverse experimental conditions, researchers endeavor to discern genuine
 * patterns from spurious anomalies, fostering confidence in the robustness and generalizability of their
 * scientific conclusions.
 * 
 * Moreover, errors in scientific experiments serve as invaluable learning opportunities, offering insights
 * into the intricacies of natural phenomena and the limitations of human knowledge. Each deviation from
 * expected outcomes affords scientists the chance to refine their methodologies, recalibrate their instruments,
 * and reassess their theoretical assumptions, thereby advancing the frontiers of scientific understanding
 * with each successive iteration.
 * 
 * Thus, while errors may pose formidable challenges to the pursuit of scientific truth, they also serve as
 * catalysts for intellectual growth and discovery. Through the diligent application of empirical methods,
 * critical analysis, and peer review, scientists endeavor to navigate the treacherous terrain of uncertainty
 * and illuminate the path towards a deeper comprehension of the natural world.
 */

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum {
    // Existing error codes...
    FOSSIL_ERROR_OK = 0,
    FOSSIL_ERROR_NULL_POINTER,
    FOSSIL_ERROR_TYPE_MISMATCH,
    FOSSIL_ERROR_OVERFLOW_INT,
    FOSSIL_ERROR_UNDERFLOW_INT,
    FOSSIL_ERROR_OVERFLOW_FLOAT,
    FOSSIL_ERROR_UNDERFLOW_FLOAT,
    FOSSIL_ERROR_INVALID_CAST,
    FOSSIL_ERROR_DIVISION_BY_ZERO,
    FOSSIL_ERROR_INVALID_OPERATION,
    FOSSIL_ERROR_INDEX_OUT_OF_BOUNDS,
    FOSSIL_ERROR_MEMORY_CORRUPTION,
    FOSSIL_ERROR_FILE_CORRUPTION,
    FOSSIL_ERROR_BUFFER_OVERFLOW,
    FOSSIL_ERROR_BUFFER_UNDERFLOW,
    FOSSIL_ERROR_NETWORK_FAILURE,
    FOSSIL_ERROR_TIMEOUT,
    FOSSIL_ERROR_FORMAT,
    FOSSIL_ERROR_SQL_INJECTION,
    FOSSIL_ERROR_XSS_ATTACK,
    FOSSIL_ERROR_CSRF_ATTACK,
    FOSSIL_ERROR_BUFFER_OVERFLOW_STR,
    FOSSIL_ERROR_BUFFER_OVERFLOW_FMT,
    FOSSIL_ERROR_BUFFER_OVERFLOW_FILE,
    FOSSIL_ERROR_BUFFER_OVERFLOW_NET,
    FOSSIL_ERROR_BUFFER_OVERFLOW_CMD,
    FOSSIL_ERROR_BUFFER_OVERFLOW_ENV,
    FOSSIL_ERROR_FORMAT_STRING_ATTACK,
    FOSSIL_ERROR_CRYPTOGRAPHIC_WEAKNESS,
    FOSSIL_ERROR_INSECURE_RANDOMNESS,
    FOSSIL_ERROR_INSECURE_CONFIGURATION,
    FOSSIL_ERROR_INSECURE_DESERIALIZATION,
    FOSSIL_ERROR_INSECURE_FILE_HANDLING,
    FOSSIL_ERROR_INSECURE_TEMPORARY_FILES,
    FOSSIL_ERROR_INSECURE_COMMUNICATION,
    FOSSIL_ERROR_INSECURE_AUTHENTICATION,
    FOSSIL_ERROR_INSECURE_ACCESS_CONTROL,
    FOSSIL_ERROR_CUSTOM,
    FOSSIL_ERROR_UNKNOWN,
    FOSSIL_ERROR_HARDWARE_FAILURE,
    FOSSIL_ERROR_OUT_OF_MEMORY,
    FOSSIL_ERROR_INVALID_ARGUMENT,
    FOSSIL_ERROR_SYSTEM_CALL_FAILED,
    FOSSIL_ERROR_PERMISSION_DENIED,
    FOSSIL_ERROR_RESOURCE_UNAVAILABLE,
    FOSSIL_ERROR_INTERRUPTED,
    FOSSIL_ERROR_UNKNOWN_HOST,
    FOSSIL_ERROR_CONNECTION_REFUSED,
    FOSSIL_ERROR_NETWORK_UNREACHABLE,
    FOSSIL_ERROR_PROTOCOL,
    FOSSIL_ERROR_FILE_NOT_FOUND,
    FOSSIL_ERROR_DIRECTORY_NOT_FOUND,
    FOSSIL_ERROR_TOO_MANY_OPEN_FILES,
    FOSSIL_ERROR_IO,
    FOSSIL_ERROR_UNSUPPORTED_OPERATION,
    FOSSIL_ERROR_INCOMPATIBLE_VERSION,
    FOSSIL_ERROR_DEADLOCK,
    FOSSIL_ERROR_BUSY,
    FOSSIL_ERROR_SIGNAL,
    FOSSIL_ERROR_PIPE,
    FOSSIL_ERROR_PROCESS,
    FOSSIL_ERROR_USER_ABORT,
    FOSSIL_ERROR_INTERNAL,
    FOSSIL_ERROR_LIMIT_REACHED,
    FOSSIL_ERROR_UNKNOWN_ERROR_CODE,

    // Jellyfish AI specific error codes
    FOSSIL_ERROR_MODEL_LOAD_FAILED,
    FOSSIL_ERROR_MODEL_EXECUTION_FAILED,
    FOSSIL_ERROR_DATA_PREPROCESSING_FAILED,
    FOSSIL_ERROR_DATA_POSTPROCESSING_FAILED,
    FOSSIL_ERROR_TRAINING_FAILED,
    FOSSIL_ERROR_INFERENCE_FAILED,
    FOSSIL_ERROR_DATA_NOT_FOUND,
    FOSSIL_ERROR_INVALID_MODEL,
    FOSSIL_ERROR_UNSUPPORTED_DATA_FORMAT,
    FOSSIL_ERROR_UNSUPPORTED_MODEL_FORMAT,
    FOSSIL_ERROR_GPU_NOT_AVAILABLE,
    FOSSIL_ERROR_GPU_MEMORY_FULL,
    FOSSIL_ERROR_GPU_DRIVER_ISSUE,
    FOSSIL_ERROR_UNSUPPORTED_OPERATION_ON_DEVICE,
    FOSSIL_ERROR_INVALID_INPUT_SHAPE,
    FOSSIL_ERROR_INVALID_OUTPUT_SHAPE
} fscl_status_t;

/**
 * @brief Retrieves the error message associated with the given error code.
 *
 * @param error The error code.
 * @return The error message.
 */
static inline const char* fscl_common_error_message(fscl_status_t error) {
    static const char* error_messages[] = {
        "No error occurred.",
        "Error: Null pointer.",
        "Error: Type mismatch.",
        "Error: Integer overflow.",
        "Error: Integer underflow.",
        "Error: Float overflow.",
        "Error: Float underflow.",
        "Error: Invalid cast.",
        "Error: Division by zero.",
        "Error: Invalid operation.",
        "Error: Index out of bounds.",
        "Error: Memory corruption.",
        "Error: File corruption.",
        "Error: Buffer overflow.",
        "Error: Buffer underflow.",
        "Error: Network failure.",
        "Error: Timeout.",
        "Error: Format error.",
        "Error: SQL injection.",
        "Error: Cross-site scripting (XSS) attack.",
        "Error: Cross-site request forgery (CSRF) attack.",
        "Error: Buffer overflow (string manipulation).",
        "Error: Buffer overflow (format string vulnerability).",
        "Error: Buffer overflow (file operation).",
        "Error: Buffer overflow (network operation).",
        "Error: Buffer overflow (command execution).",
        "Error: Buffer overflow (environment variable manipulation).",
        "Error: Format string attack.",
        "Error: Cryptographic weakness.",
        "Error: Insecure randomness generation.",
        "Error: Insecure configuration.",
        "Error: Insecure deserialization.",
        "Error: Insecure file handling.",
        "Error: Insecure temporary file creation.",
        "Error: Insecure communication.",
        "Error: Insecure authentication.",
        "Error: Insecure access control.",
        "Error: Custom error.",
        "Error: Unknown error.",
        "Error: Hardware failure.",
        "Error: Out of memory.",
        "Error: Invalid argument.",
        "Error: System call failed.",
        "Error: Permission denied.",
        "Error: Resource unavailable.",
        "Error: Interrupted.",
        "Error: Unknown host.",
        "Error: Connection refused.",
        "Error: Network unreachable.",
        "Error: Protocol error.",
        "Error: File not found.",
        "Error: Directory not found.",
        "Error: Too many open files.",
        "Error: I/O error.",
        "Error: Unsupported operation.",
        "Error: Incompatible version.",
        "Error: Deadlock.",
        "Error: Busy signal.",
        "Error: Signal error.",
        "Error: Pipe error.",
        "Error: Process error.",
        "Error: User abort error.",
        "Error: Internal error code.",
        "Error: Limit reached error.",
        "Error: Unknown error code error.",
        "Error: Model load failed.",
        "Error: Model execution failed.",
        "Error: Data preprocessing failed.",
        "Error: Data postprocessing failed.",
        "Error: Training failed.",
        "Error: Inference failed.",
        "Error: Data not found.",
        "Error: Invalid model.",
        "Error: Unsupported data format.",
        "Error: Unsupported model format.",
        "Error: GPU not available.",
        "Error: GPU memory full.",
        "Error: GPU driver issue.",
        "Error: Unsupported operation on device.",
        "Error: Invalid input shape.",
        "Error: Invalid output shape."
    };
    
    if (error >= FOSSIL_ERROR_OK && error <= FOSSIL_ERROR_INVALID_OUTPUT_SHAPE) {
        return error_messages[error];
    } else {
        return "Invalid error code.";
    }
}

#endif
