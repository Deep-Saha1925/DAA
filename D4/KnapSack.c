#include<stdio.h>

struct Item{
    int profit;
    int weight;
    float ratio;
};

// Sort items by raio(descending)
void sort(struct Item arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j].ratio < arr[j+1].ratio){
                struct Item temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Greedy Knapsack
float knapSack(struct Item a[], int n, int capacity){
    float totalProfit = 0.0;

    for(int i=0; i<n; i++){
        if(a[i].weight <= capacity){
            capacity -= a[i].weight;
            totalProfit += a[i].profit;
        }else{
            totalProfit += ((float)capacity / a[i].weight) * a[i].profit;
            break;
        }
    }

    return totalProfit;
}

int main(){
    struct Item a[] = {
        {60, 10, 0},
        {100, 20, 0},
        {120, 30, 0}
    };

    int n = sizeof(a)/sizeof(struct Item);
    int capacity = 50;

    //calculate ratio
    for(int i=0; i<n; i++){
        a[i].ratio = (float)a[i].profit / a[i].weight;
    }

    //sort items by ratio
    sort(a, n);

    float maxProfit = knapSack(a, n, capacity);

    printf("Maximum profit: %.2f\n", maxProfit);
    return 0;
}