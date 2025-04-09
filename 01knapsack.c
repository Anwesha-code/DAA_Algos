#include <stdio.h>

//Max function to get the larger of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

//0/1 Knapsack Function
int knapsack(int weights[], int values[], int n, int capacity) {
    // Create a 2D array: dp[i][w] = max value using first i items and capacity w
    int dp[n + 1][capacity + 1];

    // Build the table in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            // Base case: No items or capacity is 0
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }
            // If item can fit in the current capacity
            else if (weights[i - 1] <= w) {
                int includeItem = values[i - 1] + dp[i - 1][w - weights[i - 1]];
                int excludeItem = dp[i - 1][w];
                dp[i][w] = max(includeItem, excludeItem);
            }
            // If item can't fit, skip it
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The answer is in the bottom-right cell
    return dp[n][capacity];
}

//Main Function
int main() {
    int values[] = {60, 100, 120};   // Profit/Value of each item
    int weights[] = {10, 20, 30};    // Weight of each item
    int capacity = 50;               // Knapsack capacity
    int n = sizeof(values) / sizeof(values[0]);  // Number of items

    int maxValue = knapsack(weights, values, n, capacity);

    printf("Maximum value that can be carried: %d\n", maxValue);

    return 0;
}
