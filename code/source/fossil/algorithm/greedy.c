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
#include "fossil/algorithm/dynamic.h"
#include "fossil/common/common.h"
#include <limits.h>

int greedy_compare_int(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}

int greedy_compare_ratio(const void* a, const void* b) {
    fossil_tofu_t ratio1 = *(fossil_tofu_t*)a;
    fossil_tofu_t ratio2 = *(fossil_tofu_t*)b;

    return ratio2.value.double_val - ratio1.value.double_val;
}

fossil_tofu_t greedy_calculate_ratio(fossil_tofu_t item) {
    fossil_tofu_t ratio = fossil_tofu_create("double", "0.0");
    return ratio;
}

// Coin Change Problem
int fossil_greedy_coin_change(fossil_tofu_arrayof_t coins, int amount) {
    if (coins.size == 0 || amount <= 0) return -1; // Error case

    fossil_dynamic_sort_array(coins, greedy_compare_int); // Sort coins in descending order

    int numCoins = 0;
    size_t i = 0;

    while (amount > 0 && i < coins.size) {
        while (amount >= coins.array[i].value.int_val) {
            amount -= coins.array[i].value.int_val;
            numCoins++;
        }
        i++;
    }

    if (amount > 0) return -1; // If amount cannot be formed with given coins

    return numCoins;
}

// Fractional Knapsack Problem
double fossil_greedy_fractional_knapsack(fossil_tofu_arrayof_t weights, fossil_tofu_arrayof_t values, int capacity) {
    if (weights.size == 0 || values.size == 0 || capacity <= 0) return 0.0; // Error case

    // Calculate value-to-weight ratios and sort items based on these ratios
    fossil_tofu_arrayof_t ratios = fossil_dynamic_map_array(weights, greedy_calculate_ratio);
    fossil_dynamic_sort_array(ratios, greedy_compare_ratio);

    double maxValue = 0.0;
    int remainingCapacity = capacity;

    for (size_t i = 0; i < ratios.size; ++i) {
        if (remainingCapacity <= 0) break;

        fossil_tofu_t currentRatio = ratios.array[i];
        double weight = weights.array[currentRatio.value.int_val].value.double_val;
        double value = values.array[currentRatio.value.int_val].value.double_val;

        if (weight <= remainingCapacity) {
            maxValue += value;
            remainingCapacity -= weight;
        } else {
            maxValue += value * ((double)remainingCapacity / weight);
            remainingCapacity = 0;
        }

        fossil_tofu_erase(&currentRatio);
    }

    // Clean up allocated memory
    free(ratios.array);

    return maxValue;
}

// Interval Scheduling
int fossil_greedy_interval_scheduling(fossil_tofu_arrayof_t startTimes, fossil_tofu_arrayof_t endTimes) {
    if (startTimes.size == 0 || endTimes.size == 0 || startTimes.size != endTimes.size) return 0; // Error case

    // Sort both arrays based on endTimes
    fossil_dynamic_sort_array(startTimes, greedy_compare_int);
    fossil_dynamic_sort_array(endTimes, greedy_compare_int);

    int maxTasks = 0;
    int lastEndTime = INT_MIN;
    size_t i = 0, j = 0;

    while (i < startTimes.size && j < endTimes.size) {
        int start = startTimes.array[i].value.int_val;
        int end = endTimes.array[j].value.int_val;

        if (start >= lastEndTime) {
            maxTasks++;
            lastEndTime = end;
            i++;
        }
        j++;
    }

    return maxTasks;
}
