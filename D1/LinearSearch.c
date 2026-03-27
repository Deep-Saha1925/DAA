#include<stdio.h>

// Iterative Linear Search Function
int linearSearchIter(int a[], int n, int key){
    for(int i=0; i<n; i++){
        if(a[i] == key){
            return i;
        }
    }

    return -1;
}

//recursive Linear Search Function
int linearSearchRec(int a[], int i, int n, int key){
    if (i == n){
        return -1;
    }

    if (a[i] == key){
        return i;
    }

    return linearSearchRec(a, i+1, n, key);
}

int main(){
    int arr[] = {10, 25, 30, 45, 50};
    int n = 5;
    int key = 45;

    int pos = linearSearchIter(arr, n, key);
    int pos = linearSearchRec(arr, 0, n, key);

    if (pos != -1)
        printf("Element found at index %d\n", pos);
    else
        printf("Element not found\n");

    return 0;
}