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
#include "fossil/string/number.h"
#include "fossil/string/manip.h"
#include "fossil/common/common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    cstring word;
    long long int value;
} NumberMapping;

typedef struct {
    cstring operator;
    int priority;
} OperatorMapping;

OperatorMapping operators[] = {
    {"+", 1}, {"-", 1}, {"*", 2}, {"/", 2}
};

// Define mappings for units, tens, and powers of ten
NumberMapping units[] = {
    {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
    {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}
};

NumberMapping teens[] = {
    {"ten", 10}, {"eleven", 11}, {"twelve", 12}, {"thirteen", 13}, {"fourteen", 14},
    {"fifteen", 15}, {"sixteen", 16}, {"seventeen", 17}, {"eighteen", 18}, {"nineteen", 19}
};

NumberMapping tens[] = {
    {"twenty", 20}, {"thirty", 30}, {"forty", 40}, {"fifty", 50},
    {"sixty", 60}, {"seventy", 70}, {"eighty", 80}, {"ninety", 90}
};

NumberMapping powersOfTen[] = {
    {"thousand", 1000}, {"million", 1000000}, {"billion", 1000000000}, {"trillion", 1000000000000}
};

int fossil_cstr_to_numeric(cstring number) {
    if (!number) {
        return 0;
    }
    
    int result = 0;
    int tempResult = 0;
    
    for (size_t i = 0; number[i];) {
        if (fossil_cletter_is_digit(number[i])) {
            tempResult = tempResult * 10 + (number[i] - '0');
            i++;
        } else {
            for (size_t j = 0; j < sizeof(units) / sizeof(units[0]); j++) {
                if (fossil_cstr_compare(units[j].word, &number[i]) == 0) {
                    tempResult += units[j].value;
                    i += fossil_cstr_length(units[j].word);
                    break;
                }
            }
            
            for (size_t j = 0; j < sizeof(teens) / sizeof(teens[0]); j++) {
                if (fossil_cstr_compare(teens[j].word, &number[i]) == 0) {
                    tempResult += teens[j].value;
                    i += fossil_cstr_length(teens[j].word);
                    break;
                }
            }
            
            for (size_t j = 0; j < sizeof(tens) / sizeof(tens[0]); j++) {
                if (fossil_cstr_compare(tens[j].word, &number[i]) == 0) {
                    tempResult += tens[j].value;
                    i += fossil_cstr_length(tens[j].word);
                    break;
                }
            }
            
            for (size_t j = 0; j < sizeof(powersOfTen) / sizeof(powersOfTen[0]); j++) {
                if (fossil_cstr_compare(powersOfTen[j].word, &number[i]) == 0) {
                    result += tempResult * powersOfTen[j].value;
                    tempResult = 0;
                    i += fossil_cstr_length(powersOfTen[j].word);
                    break;
                }
            }
        }
    }
    
    result += tempResult;
    
    return result;
}

int fossil_bstr_to_numeric(const_bstring number) {
    if (!number) {
        return 0;
    }
    
    int result = 0;
    int tempResult = 0;
    
    for (size_t i = 0; number[i];) {
        if (fossil_cletter_is_digit(number[i])) {
            tempResult = tempResult * 10 + (number[i] - '0');
            i++;
        } else {
            for (size_t j = 0; j < sizeof(units) / sizeof(units[0]); j++) {
                if (fossil_bstr_compare((const_bstring)units[j].word, &number[i]) == 0) {
                    tempResult += units[j].value;
                    i += fossil_bstr_length((const_bstring)units[j].word);
                    break;
                }
            }
            
            for (size_t j = 0; j < sizeof(teens) / sizeof(teens[0]); j++) {
                if (fossil_bstr_compare((const_bstring)teens[j].word, &number[i]) == 0) {
                    tempResult += teens[j].value;
                    i += fossil_bstr_length((const_bstring)teens[j].word);
                    break;
                }
            }
            
            for (size_t j = 0; j < sizeof(tens) / sizeof(tens[0]); j++) {
                if (fossil_bstr_compare((const_bstring)tens[j].word, &number[i]) == 0) {
                    tempResult += tens[j].value;
                    i += fossil_bstr_length((const_bstring)tens[j].word);
                    break;
                }
            }
            
            for (size_t j = 0; j < sizeof(powersOfTen) / sizeof(powersOfTen[0]); j++) {
                if (fossil_bstr_compare((const_bstring)powersOfTen[j].word, &number[i]) == 0) {
                    result += tempResult * powersOfTen[j].value;
                    tempResult = 0;
                    i += fossil_bstr_length((const_bstring)powersOfTen[j].word);
                    break;
                }
            }
        }
    }
    
    result += tempResult;
    
    return result;
}

int fossil_cstr_expression_to_numeric(cstring expression) {
    if (!expression) {
        return 0;
    }
    
    cstrings tokens = fossil_cstr_split(expression, ' ');
    if (!tokens) {
        return 0;
    }
    
    int result = 0;
    int tempResult = 0;
    int lastValue = 0;
    cstring lastOperator = cnullptr;
    
    for (size_t i = 0; tokens[i]; i++) {
        int value = fossil_cstr_to_numeric(tokens[i]);
        
        if (value == 0 && strcmp(tokens[i], "zero") != 0) {
            // If the token is not a recognized number, it might be an operator
            for (size_t j = 0; j < sizeof(operators) / sizeof(operators[0]); j++) {
                if (fossil_cstr_compare(operators[j].operator, tokens[i]) == 0) {
                    if (lastOperator && operators[j].priority == 1) {
                        tempResult = lastValue + tempResult;
                    } else if (lastOperator && operators[j].priority == 2) {
                        tempResult = lastValue - tempResult;
                    }
                    
                    lastValue = tempResult;
                    lastOperator = operators[j].operator;
                    tempResult = 0;
                    break;
                }
            }
        } else {
            tempResult += value;
        }
    }
    
    if (lastOperator && strcmp(lastOperator, "+") == 0) {
        result = lastValue + tempResult;
    } else if (lastOperator && strcmp(lastOperator, "-") == 0) {
        result = lastValue - tempResult;
    } else {
        result = tempResult;
    }
    
    fossil_cstr_erase_splits(tokens);
    
    return result;
}

int fossil_bstr_expression_to_numeric(const_bstring expression) {
    if (!expression) {
        return 0;
    }
    
    bstrings tokens = fossil_bstr_split(expression, cterminator);
    if (!tokens) {
        return 0;
    }
    
    int result = 0;
    int tempResult = 0;
    int lastValue = 0;
    const_bstring lastOperator = cnullptr;
    
    for (size_t i = 0; tokens[i]; i++) {
        int value = fossil_bstr_to_numeric(tokens[i]);
        
        if (value == 0 && fossil_bstr_compare(tokens[i], (const_bstring)"zero") != 0) {
            // If the token is not a recognized number, it might be an operator
            for (size_t j = 0; j < sizeof(operators) / sizeof(operators[0]); j++) {
                if (fossil_bstr_compare((bstring)operators[j].operator, tokens[i]) == 0) {
                    if (lastOperator && operators[j].priority == 1) {
                        tempResult = lastValue + tempResult;
                    } else if (lastOperator && operators[j].priority == 2) {
                        tempResult = lastValue - tempResult;
                    }
                    
                    lastValue = tempResult;
                    lastOperator = (bstring)operators[j].operator;
                    tempResult = 0;
                    break;
                }
            }
        } else {
            tempResult += value;
        }
    }
    
    if (lastOperator && fossil_bstr_compare(lastOperator, (const_bstring)"+") == 0) {
        result = lastValue + tempResult;
    } else if (lastOperator && fossil_bstr_compare(lastOperator, (const_bstring)"-") == 0) {
        result = lastValue - tempResult;
    } else {
        result = tempResult;
    }
    
    fossil_bstr_erase_splits(tokens);
    
    return result;
}

cstring fossil_cstr_from_numeric(long long number) {
    cstring str = malloc(50); // More than enough for any reasonable number
    if (!str) {
        return cnullptr;
    }
    snprintf(str, 50, "%ld", (long int)number);
    return str;
}

bstring fossil_bstr_from_numeric(long long number) {
    bstring str = malloc(50); // More than enough for any reasonable number
    if (!str) {
        return cnullptr;
    }
    snprintf((char*)str, 50, "%ld", (long int)number);
    return str;
}

int fossil_wstr_to_numeric(const_wstring number) {
    if (!number) {
        return 0;
    }
    
    int result = 0;
    int tempResult = 0;
    
    for (size_t i = 0; number[i];) {
        // Check if the current character is a digit
        if (fossil_wletter_is_digit(number[i])) {
            tempResult = tempResult * 10 + (number[i] - L'0');
            i++;
        } else {
            // Check for matches with the defined mappings
            for (size_t j = 0; j < sizeof(units) / sizeof(units[0]); j++) {
                if (fossil_wstr_compare((const_wstring)units[j].word, &number[i]) == 0) {
                    tempResult += units[j].value;
                    i += fossil_wstr_length((const_wstring)units[j].word);
                    break;
                }
            }
            
            for (size_t j = 0; j < sizeof(teens) / sizeof(teens[0]); j++) {
                if (fossil_wstr_compare((const_wstring)teens[j].word, &number[i]) == 0) {
                    tempResult += teens[j].value;
                    i += fossil_wstr_length((const_wstring)teens[j].word);
                    break;
                }
            }
            
            for (size_t j = 0; j < sizeof(tens) / sizeof(tens[0]); j++) {
                if (fossil_wstr_compare((const_wstring)tens[j].word, &number[i]) == 0) {
                    tempResult += tens[j].value;
                    i += fossil_wstr_length((const_wstring)tens[j].word);
                    break;
                }
            }
            
            for (size_t j = 0; j < sizeof(powersOfTen) / sizeof(powersOfTen[0]); j++) {
                if (fossil_wstr_compare((const_wstring)powersOfTen[j].word, &number[i]) == 0) {
                    result += tempResult * powersOfTen[j].value;
                    tempResult = 0;
                    i += fossil_wstr_length((const_wstring)powersOfTen[j].word);
                    break;
                }
            }
        }
    }
    
    result += tempResult;
    
    return result;
}

int fossil_wstr_expression_to_numeric(const_wstring expression) {
    if (!expression) {
        return 0;
    }
    
    wstrings tokens = fossil_wstr_split(expression, L' ');
    if (!tokens) {
        return 0;
    }
    
    int result = 0;
    int tempResult = 0;
    int lastValue = 0;
    const_wstring lastOperator = cnullptr;
    
    for (size_t i = 0; tokens[i]; i++) {
        int value = fossil_wstr_to_numeric(tokens[i]);
        
        if (value == 0 && fossil_wstr_compare(tokens[i], L"zero") != 0) {
            // If the token is not a recognized number, it might be an operator
            for (size_t j = 0; j < sizeof(operators) / sizeof(operators[0]); j++) {
                if (fossil_wstr_compare((const_wstring)operators[j].operator, tokens[i]) == 0) {
                    if (lastOperator && operators[j].priority == 1) {
                        tempResult = lastValue + tempResult;
                    } else if (lastOperator && operators[j].priority == 2) {
                        tempResult = lastValue - tempResult;
                    }
                    
                    lastValue = tempResult;
                    lastOperator = (wstring)operators[j].operator;
                    tempResult = 0;
                    break;
                }
            }
        } else {
            tempResult += value;
        }
    }
    
    if (lastOperator && fossil_wstr_compare(lastOperator, L"+") == 0) {
        result = lastValue + tempResult;
    } else if (lastOperator && fossil_wstr_compare(lastOperator, L"-") == 0) {
        result = lastValue - tempResult;
    } else {
        result = tempResult;
    }
    
    fossil_wstr_erase_splits(tokens);
    
    return result;
}

wstring fossil_wstr_from_numeric(long long number) {
    wstring str = malloc(50 * sizeof(wchar_t)); // More than enough for any reasonable number
    if (!str) {
        return cnullptr;
    }
    swprintf(str, 50, L"%ld", (long int)number);
    return str;
}
