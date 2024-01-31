// Q2. Find the second Maximum and the second Minimum element from a given array of integers using Divide and Conquer approach
#include <stdio.h>

void findSecondMinimumMaximum(int arr[], int low, int high, int *secondMin, int *secondMax) {
    if (low == high) {
        return;
    }

    if (high - low == 1) {
        // If two elements are there, compare and set secondMin and secondMax
        if (arr[low] < arr[high]) {
            *secondMin = arr[low];
            *secondMax = arr[high];
        } else {
            *secondMin = arr[high];
            *secondMax = arr[low];
        }
        return;
    }

    int mid = (low + high) / 2;
    int leftSecondMin, leftSecondMax, rightSecondMin, rightSecondMax;

    findSecondMinimumMaximum(arr, low, mid, &leftSecondMin, &leftSecondMax);
    findSecondMinimumMaximum(arr, mid + 1, high, &rightSecondMin, &rightSecondMax);

    if (leftSecondMin < rightSecondMin) {
        *secondMin = leftSecondMin;
    } else {
        *secondMin = rightSecondMin;
    }

    if (leftSecondMax > rightSecondMax) {
        *secondMax = leftSecondMax;
    } else {
        *secondMax = rightSecondMax;
    }
}

int main() {
    int arr[] = {3, 1, 9, 7, 5, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int secondMin, secondMax;

    findSecondMinimumMaximum(arr, 0, size - 1, &secondMin, &secondMax);

    printf("Second Minimum element: %d\n", secondMin);
    printf("Second Maximum element: %d", secondMax);

    return 0;
}
