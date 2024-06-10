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
#ifndef FOSSIL_ALGORITHM_GREEDY_H
#define FOSSIL_ALGORITHM_GREEDY_H

/**
 * @brief Greedy algorithms for various optimization problems
 *
 * This library provides functions to solve optimization problems using greedy algorithms.
 * Greedy algorithms make locally optimal choices at each step with the hope of finding a global optimum.
 * The functions in this library implement greedy solutions for the coin change problem,
 * the fractional knapsack problem, and the interval scheduling problem.
 *
 * @see fossil_tofu_t
 *
 * @brief Finds the minimum number of coins required to make up a given amount using a greedy algorithm.
 *
 * This function takes an array of coin denominations and an amount as input and
 * calculates the minimum number of coins required to make up the given amount.
 * It utilizes a greedy approach by selecting the largest coin denomination
 * possible at each step.
 *
 * @param coins An array containing the denominations of available coins.
 * @param amount The target amount for which coins need to be selected.
 * @return The minimum number of coins required to make up the given amount.
 * 
 * @brief Solves the Fractional Knapsack Problem using a greedy algorithm.
 *
 * This function takes arrays of weights and values for items, along with the
 * capacity of the knapsack, and calculates the maximum value that can be obtained
 * by selecting items fractionally. It uses a greedy approach by selecting items
 * with the highest value-to-weight ratio first.
 *
 * @param weights An array containing the weights of the items.
 * @param values An array containing the values of the items.
 * @param capacity The capacity of the knapsack.
 * @return The maximum value that can be obtained from the knapsack.
 * 
 * @brief Solves the Interval Scheduling Problem using a greedy algorithm.
 *
 * This function takes arrays of start times and end times for tasks and calculates
 * the maximum number of non-overlapping tasks that can be scheduled. It utilizes
 * a greedy approach by selecting tasks with the earliest end times first.
 *
 * @param startTimes An array containing the start times of tasks.
 * @param endTimes An array containing the end times of tasks.
 * @return The maximum number of non-overlapping tasks that can be scheduled.
 */

#include "fossil/tofu/tofu.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief Finds the minimum number of coins required to make up a given amount using a greedy algorithm.
 *
 * This function takes an array of coin denominations and an amount as input and
 * calculates the minimum number of coins required to make up the given amount.
 * It utilizes a greedy approach by selecting the largest coin denomination
 * possible at each step.
 *
 * @param coins An array containing the denominations of available coins.
 * @param amount The target amount for which coins need to be selected.
 * @return The minimum number of coins required to make up the given amount.
 */
int fossil_greedy_coin_change(fossil_tofu_t* coins, int amount);

/**
 * @brief Solves the Fractional Knapsack Problem using a greedy algorithm.
 *
 * This function takes arrays of weights and values for items, along with the
 * capacity of the knapsack, and calculates the maximum value that can be obtained
 * by selecting items fractionally. It uses a greedy approach by selecting items
 * with the highest value-to-weight ratio first.
 *
 * @param weights An array containing the weights of the items.
 * @param values An array containing the values of the items.
 * @param capacity The capacity of the knapsack.
 * @return The maximum value that can be obtained from the knapsack.
 */
double fossil_greedy_fractional_knapsack(fossil_tofu_t* weights, fossil_tofu_t* values, int capacity);

/**
 * @brief Solves the Interval Scheduling Problem using a greedy algorithm.
 *
 * This function takes arrays of start times and end times for tasks and calculates
 * the maximum number of non-overlapping tasks that can be scheduled. It utilizes
 * a greedy approach by selecting tasks with the earliest end times first.
 *
 * @param startTimes An array containing the start times of tasks.
 * @param endTimes An array containing the end times of tasks.
 * @return The maximum number of non-overlapping tasks that can be scheduled.
 */
int fossil_greedy_interval_scheduling(fossil_tofu_t* startTimes, fossil_tofu_t* endTimes);

#ifdef __cplusplus
}
#endif

#endif
