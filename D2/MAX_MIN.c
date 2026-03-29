#include<stdio.h>

typedef struct Pair{
    int min;
    int max;
} s;

s getMinMax(int a[], int low, int high){
    s result, left, right;
    int mid;

    // Case 1: One element
    if(low == high){
        result.min = result.max = a[low];
        return result;
    }

    // Case 2: Two elements
    if(high == low+1){
        if(a[low] < a[high]){
            result.min = a[low];
            result.max = a[high];
        }else{
            result.min = a[high];
            result.max = a[low];
        }
        return result;
    }

    // DIVIDE
    mid = (low + high) / 2;

    // CONQUER
    left = getMinMax(a, low, mid);
    right = getMinMax(a, mid+1, high);

    // Combine
    result.min = (left.min < right.min) ? left.min : right.min;
    result.max = (left.max > right.max) ? left.max : right.max;

    return result;
}

int main(){
    int arr[] = {10, 50, 2, 300, 45};
    int n = sizeof(arr) / sizeof(int);
    s result = getMinMax(arr, 0, n-1);

    printf("Minimum: %d\n", result.min);
    printf("Maximum: %d", result.max);
}