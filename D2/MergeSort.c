#include<stdio.h>

void merge(int a[], int low, int high, int mid){
    int i = low;
    int j = mid + 1;
    int k = 0;

    int temp[100];

    while(i <= mid && j <= high){
        if(a[i] <= a[j]){
            temp[k++] = a[i++];
        }else{
            temp[k++] = a[j++];
        }
    }

    while(i <= mid){
        temp[k++] = a[i++];
    }

    while(j <= high){
        temp[k++] = a[j++];
    }

    for(i=low, k=0; i<=high; i++, k++){
        a[i] = temp[k];
    }
}

void mergeSort(int a[], int low, int high){
    if(low < high){
        int mid = low + (high - low) / 2;

        //DIVIDE
        mergeSort(a, low, mid);
        mergeSort(a, mid+1, high);

        //MERGE
        merge(a, low, high, mid);
    }
}

int main(){
    int arr[] = {10, 50, 2, 300, 45};
    int n = sizeof(arr) / sizeof(int);
    mergeSort(arr, 0, n-1);

    for (int i = 0; i < n; i++){
        printf("%d, ", arr[i]);
    }
}