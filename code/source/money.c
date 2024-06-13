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
#include "fossil/stdtool/money.h"
#include "fossil/common/common.h"
#include <stdio.h>
#include <math.h>

// Function to create a money object
fossil_money_t fossil_money_create(int32_t dollars, int32_t cents, fossil_currency_t currency) {
    fossil_money_t result;

    // Validate input parameters
    if (cents < 0 || cents >= 100) {
        // Invalid cents value
        printf("Invalid cents value\n");
        // On error set the currency to defualt values
        result.dollars = 0;
        result.cents = 0;
        result.currency = USD;
        return result;
    }

    // Initialize the fossil_money_t object
    result.dollars = dollars;
    result.cents = cents;
    result.currency = currency;

    return result;
}

// Function to add two money objects if they have the same currency
fossil_money_t fossil_money_add(fossil_money_t m1, fossil_money_t m2) {
    fossil_money_t result;

    // Check if the currencies match
    if (m1.currency == m2.currency) {
        // Perform addition for dollars and cents separately to avoid overflow
        int total_cents = m1.cents + m2.cents;
        int carry_over_dollars = total_cents / 100;
        
        result.dollars = m1.dollars + m2.dollars + carry_over_dollars;
        result.cents = total_cents % 100;
        result.currency = m1.currency; // Use the currency of the first money object
    } else {
        // Currencies do not match, return a result with an unknown currency
        result.dollars = 0;
        result.cents = 0;
        result.currency = -1; // Representing an unknown currency
    }

    return result;
}
 // end of func

// Function to convert money to a different currency
fossil_money_t fossil_money_convert(fossil_money_t source, fossil_currency_t target_currency) {
    // Assume a simple conversion rate of 1:1 for demonstration purposes
    fossil_money_t result;
    result.dollars = source.dollars;
    result.cents = source.cents;
    result.currency = target_currency;

    return result;
} // end of func

// Function to display a money object
void fossil_money_display(fossil_money_t m) {
    const char* currency_symbol;

    switch (m.currency) {
        case USD:
            currency_symbol = "$";
            break;
        case CAD:
            currency_symbol = "CA$";
            break;
        case GBP:
            currency_symbol = "£";
            break;
        case RUB:
            currency_symbol = "₽";
            break;
        case INR:
            currency_symbol = "₹";
            break;
        case JPY:
            currency_symbol = "¥";
            break;
        default:
            currency_symbol = "?";
    }

    printf("%s%d.%02d\n", currency_symbol, m.dollars, m.cents);
} // end of func

int32_t fossil_money_is_valid(fossil_money_t m) {
    return (m.cents >= 0 && m.cents <= 99);
} // end of func

int32_t fossil_money_compare(fossil_money_t m1, fossil_money_t m2) {
    if (m1.currency == m2.currency) {
        if (m1.dollars == m2.dollars && m1.cents == m2.cents) {
            return 0; // Equal
        } else if (m1.dollars > m2.dollars || (m1.dollars == m2.dollars && m1.cents > m2.cents)) {
            return 1; // m1 is greater
        } else {
            return -1; // m2 is greater
        }
    } else {
        // Currencies do not match
        return -2; // Indicate an error or undefined comparison
    }
} // end of func

fossil_money_t fossil_money_subtract(fossil_money_t m1, fossil_money_t m2) {
    fossil_money_t result;
    
    // Check if the currencies match
    if (m1.currency == m2.currency) {
        result.dollars = m1.dollars - m2.dollars;
        result.cents = m1.cents - m2.cents;

        // Adjust if cents are negative
        if (result.cents < 0) {
            result.dollars -= 1;
            result.cents += 100;
        }

        result.currency = m1.currency; // Use the currency of the first money object
    } else {
        // Currencies do not match, return a result with an unknown currency
        result.dollars = 0;
        result.cents = 0;
        result.currency = -1; // Representing an unknown currency
    }

    return result;
} // end of func

// Function to multiply a fossil_money_t object by a scalar value
fossil_money_t fossil_money_multiply_scalar(fossil_money_t m, int32_t scalar) {
    fossil_money_t result = m;
    result.dollars *= scalar;
    result.cents *= scalar;
    
    // Adjust cents to stay within the valid range (0 to 99)
    result.dollars += result.cents / 100;
    result.cents %= 100;

    return result;
} // end of func

// Function to divide a fossil_money_t object by a scalar value
fossil_money_t fossil_money_divide_scalar(fossil_money_t m, int32_t divisor) {
    if (divisor == 0) {
        // Division by zero, return original fossil_money_t object
        return m;
    }

    fossil_money_t result = m;
    result.dollars /= divisor;
    result.cents /= divisor;

    return result;
} // end of func

// Function to round the amount in a fossil_money_t object to the nearest integer
fossil_money_t fossil_money_round(fossil_money_t m) {
    fossil_money_t result = m;

    // Round the amount to the nearest integer
    result.cents = round((double)result.cents / 100.0 * 100.0);

    // Adjust dollars for any overflow from rounding cents
    result.dollars += result.cents / 100;
    result.cents %= 100;

    return result;
} // end of func

// Function to check if a fossil_money_t object represents a positive amount
int32_t fossil_money_is_positive(fossil_money_t m) {
    return (m.dollars > 0) || (m.dollars == 0 && m.cents > 0);
} // end of func

// Function to check if a fossil_money_t object represents a negative amount
int32_t fossil_money_is_negative(fossil_money_t m) {
    return (m.dollars < 0) || (m.dollars == 0 && m.cents < 0);
} // end of func

// Function to check if a fossil_money_t object represents zero amount
int32_t fossil_money_is_zero(fossil_money_t m) {
    return (m.dollars == 0) && (m.cents == 0);
} // end of func
