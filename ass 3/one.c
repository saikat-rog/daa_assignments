// Q1. Find the Maximum and the Minimum element from a given array of integers using Divide and Conquer approach

#include <stdio.h>
void findMinimumMaximum(int arr[], int low, int high, int *min, int *max) {
    int mid;
    if (low == high) {  //When only one element present
        *min = arr[low];
        *max = arr[low];
        return;
    }
    //When more than one element present.
    //Recursion
    mid = (low + high) / 2;
    int leftMin, leftMax, rightMin, rightMax;
    findMinimumMaximum(arr, low, mid, &leftMin, &leftMax);
    findMinimumMaximum(arr, mid + 1, high, &rightMin, &rightMax);
    *min = (leftMin < rightMin) ? leftMin : rightMin;
    *max = (leftMax > rightMax) ? leftMax : rightMax;
}

int main() {
    int arr[] = {3, 1, 9, 7, 5, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int min, max;
    findMinimumMaximum(arr, 0, size - 1, &min, &max);

    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);

    return 0;
}
