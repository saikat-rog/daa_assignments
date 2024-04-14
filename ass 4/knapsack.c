#include <stdio.h>
#include <stdlib.h>

// Function to compare items based on their ratio
int compare(const void *a, const void *b) {
    double ratioA = *((double*)a);
    double ratioB = *((double*)b);
    if (ratioA < ratioB) return 1; // Sort in descending order
    if (ratioA > ratioB) return -1;
    return 0;
}

// Function to solve fractional knapsack problem
double fractionalKnapsack(int capacity, int values[], int weights[], int n) {
    double ratios[n];
    for (int i = 0; i < n; i++) {
        ratios[i] = (double)values[i] / weights[i]; // Calculate ratio
    }
    
    qsort(ratios, n, sizeof(double), compare); // Sort ratios

    int currentWeight = 0; // Current weight in knapsack
    double finalValue = 0.0; // Result (value in knapsack)

    // Loop through all items
    for (int i = 0; i < n; i++) {
        // Find index of the current ratio in the original arrays
        int index = 0;
        for (int j = 0; j < n; j++) {
            if ((double)values[j] / weights[j] == ratios[i]) {
                index = j;
                break;
            }
        }
        
        // If adding the next item won't overflow the knapsack
        if (currentWeight + weights[index] <= capacity) {
            currentWeight += weights[index];
            finalValue += values[index];
        } else {
            // Calculate the fraction of the item that fits into the knapsack
            int remainingWeight = capacity - currentWeight;
            finalValue += values[index] * ((double)remainingWeight / weights[index]);
            break; // Knapsack is full, so exit the loop
        }
    }

    return finalValue;
}

int main() {
    int capacity, n;
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &capacity);
    printf("Enter the number of items: ");
    scanf("%d", &n);

    // Allocate memory for arrays of values and weights
    int values[n], weights[n];

    // Input items' value and weight
    printf("Enter value and weight for each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &values[i], &weights[i]);
    }

    double maxValue = fractionalKnapsack(capacity, values, weights, n);
    printf("Maximum value in knapsack = %.2f\n", maxValue);

    return 0;
}
