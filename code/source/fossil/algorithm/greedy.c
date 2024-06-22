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

static int greed_compare(const void* a, const void* b) {
    double ratio1 = ((double*)a)[0] / ((double*)a)[1];
    double ratio2 = ((double*)b)[0] / ((double*)b)[1];
    return (ratio1 > ratio2) ? -1 : ((ratio1 < ratio2) ? 1 : 0);
}

double fossil_greedy_fractional_knapsack(const double* weights, const double* values, size_t n, double capacity) {
    double items[n][2];
    for (size_t i = 0; i < n; ++i) {
        items[i][0] = values[i];
        items[i][1] = weights[i];
    }

    qsort(items, n, sizeof(items[0]), greed_compare);

    double total_value = 0.0;
    for (size_t i = 0; i < n; ++i) {
        if (capacity == 0)
            break;
        if (items[i][1] <= capacity) {
            capacity -= items[i][1];
            total_value += items[i][0];
        } else {
            total_value += items[i][0] * (capacity / items[i][1]);
            capacity = 0;
        }
    }
    return total_value;
}

static int greed_compare_finish_times(const void* a, const void* b) {
    return (*(double*)a > *(double*)b) ? 1 : -1;
}

size_t fossil_greedy_activity_selection(const double* start_times, const double* finish_times, size_t n) {
    double activities[n][2];
    for (size_t i = 0; i < n; ++i) {
        activities[i][0] = start_times[i];
        activities[i][1] = finish_times[i];
    }

    qsort(activities, n, sizeof(activities[0]), greed_compare_finish_times);

    size_t count = 1;
    double last_finish = activities[0][1];
    for (size_t i = 1; i < n; ++i) {
        if (activities[i][0] >= last_finish) {
            last_finish = activities[i][1];
            count++;
        }
    }
    return count;
}

int fossil_greedy_coin_change(const int* coins, size_t n, int amount, int* result) {
    int count = 0;
    memset(result, 0, n * sizeof(int));
    
    for (size_t i = 0; i < n; ++i) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            result[i]++;
            count++;
        }
    }
    return (amount == 0) ? count : -1;
}
