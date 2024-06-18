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
#include "fossil/algorithm/greedy.h"
#include "fossil/common/common.h"
#include <limits.h>

// Coin Change Problem
int fossil_greedy_coin_change(fossil_tofu_t* coins, int amount) {
    fossil_tofu_sort(coins->data.array_type.elements);

    int result = 0;
    for (int i = coins->data.array_type.size - 1; i >= 0; i--) {
        fossil_tofu_t* coin = &coins->data.array_type.elements[i];
        while (amount >= coin->data.int_type) {
            amount -= coin->data.int_type;
            result++;
        }
    }
    return result;
}

// Fractional Knapsack Problem
double fossil_greedy_fractional_knapsack(fossil_tofu_t* weights, fossil_tofu_t* values, int capacity) {
    fossil_tofu_t* ratios = fossil_tofu_create_array(TOFU_DOUBLE_TYPE, weights->data.array_type.size);

    for (size_t i = 0; i < weights->data.array_type.size; i++) {
        double ratio = (double)values->data.array_type.elements[i].data.int_type /
                       weights->data.array_type.elements[i].data.int_type;
        ratios->data.array_type.elements[i].data.double_type = ratio;
    }

    fossil_tofu_sort(ratios->data.array_type.elements);

    double maxValue = 0.0;
    for (int i = ratios->data.array_type.size - 1; i >= 0; i--) {
        if (capacity <= 0)
            break;
        double itemRatio = ratios->data.array_type.elements[i].data.double_type;
        int selectedWeight = (capacity > weights->data.array_type.elements[i].data.int_type)
                                 ? weights->data.array_type.elements[i].data.int_type
                                 : capacity;
        maxValue += itemRatio * selectedWeight;
        capacity -= selectedWeight;
    }

    fossil_tofu_erase(ratios);
    return maxValue;
}

// Interval Scheduling
int fossil_greedy_interval_scheduling(fossil_tofu_t* startTimes, fossil_tofu_t* endTimes) {
    int numTasks = startTimes->data.array_type.size;
    fossil_tofu_t* tasks = fossil_tofu_create_array(TOFU_INT_TYPE, numTasks * 2);

    for (int i = 0; i < numTasks; i++) {
        tasks->data.array_type.elements[i * 2] = startTimes->data.array_type.elements[i];
        tasks->data.array_type.elements[i * 2 + 1] = endTimes->data.array_type.elements[i];
    }

    fossil_tofu_sort(tasks->data.array_type.elements);

    int maxTasks = 0;
    int currentEnd = INT_MIN;
    for (int i = 0; i < numTasks * 2; i += 2) {
        if (tasks->data.array_type.elements[i].data.int_type >= currentEnd) {
            maxTasks++;
            currentEnd = tasks->data.array_type.elements[i + 1].data.int_type;
        }
    }

    fossil_tofu_erase(tasks);
    return maxTasks;
}
