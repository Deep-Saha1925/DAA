#include<stdio.h>

struct Job{
    int id;
    int deadline;
    int profit;
};

//sort jobs by profit(desc)
void sort(struct Job a[], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(a[j].profit < a[j+1].profit){
                struct Job temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void sequenceJobs(struct Job a[], int n){
    int slot[100]; //track free slots

    // init all slots as free
    for(int i=0; i<100; i++){
        slot[i] = -1;
    }

    int totalProfit = 0;

    for(int i=0; i<n; i++){
        for(int j=a[i].deadline-1 ; j>=0; j--){  //for each job try to place it as close to its deadline
            if(slot[j] == -1){
                slot[j] = a[i].id;
                totalProfit += a[i].profit;
                break;
            }
        }
    }

    printf("Selected Jobs: ");
    for(int i=0; i<n; i++){
        if (slot[i] != -1){
            printf("J%d, ", slot[i]);
        }
    }

    printf("\nTotal Profit: %d", totalProfit);
}

int main(){
    struct Job jobs[] = {
        {1, 2, 100},
        {2, 1, 19},
        {3, 2, 27},
        {4, 1, 25},
        {5, 3, 15}
    };

    int n = sizeof(jobs)/sizeof(struct Job);
    
    sort(jobs, n);
    sequenceJobs(jobs, n);

    return 0;
}