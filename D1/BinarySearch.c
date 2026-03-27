#include <stdio.h>

// Iterative Binary Search Function
int binarySearchIter(int arr[], int n, int key) {
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

int binarySearchRecursive(int arr[], int low, int high, int key) {

    // Base Case
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == key)
        return mid;

    else if (key < arr[mid])
        return binarySearchRecursive(arr, low, mid - 1, key);

    else
        return binarySearchRecursive(arr, mid + 1, high, key);
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int n = 7;
    int key = 50;

    int result = binarySearchIter(arr, n, key);
    int result = binarySearchRecursive(arr, 0, n, key);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}