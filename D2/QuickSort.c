#include<stdio.h>

// Partition function
int partition(int arr[], int low, int high){
    int pivot = arr[high]; //last element
    int i = low - 1;  // index of smaller element

    for (int j = low; j < high; j++){   
        if(arr[j] < pivot){
            i++;
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }

    // place pivot in correct position 
    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;

    return i+1;
}

// Quick sort function
void quickSort(int a[], int low, int high){
    if(low < high){
        int p = partition(a, low, high);

        // sort left part
        quickSort(a, low, p-1);

        // sort right part
        quickSort(a, p+1, high);
    }
}

int main(){
    int arr[] = {10, 50, 2, 300, 45};
    int n = sizeof(arr) / sizeof(int);
    quickSort(arr, 0, n-1);

    for (int i = 0; i < n; i++){
        printf("%d, ", arr[i]);
    }
}