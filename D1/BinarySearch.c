#include <stdio.h>

// Iterative Binary Search Function
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;   // Found

        else if (key < arr[mid])
            high = mid - 1;   // Go left

        else
            low = mid + 1;    // Go right
    }

    return -1;  // Not found
}



int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int n = 7;
    int key = 50;

    int result = binarySearch(arr, n, key);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}