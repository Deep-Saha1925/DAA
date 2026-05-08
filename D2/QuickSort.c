#include <stdio.h>

int partition(int a[], int p, int q) {
        int pivot = a[p];   // first element as pivot
        int i = p + 1;
        int j = q;
        int temp;

        while (1) {
            while (i <= q && a[i] <= pivot)
                i++;

            while (a[j] > pivot)
                j--;

            if (i < j) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            } else {
                break;
            }
        }

        // place pivot at correct position
        temp = a[p];
        a[p] = a[j];
        a[j] = temp;

    return j;
}

// Quick Sort function
void quickSort(int a[], int p, int q) {
    if (p < q) {
        int j = partition(a, p, q);

        quickSort(a, p, j - 1);  // left
        quickSort(a, j + 1, q);  // right
    }
}

// Main
int main() {
    int a[] = {7, 2, 9, 4, 3};
    int n = 5;

    quickSort(a, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}