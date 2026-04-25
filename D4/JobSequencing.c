#include <stdio.h>

struct Job {
    int id;
    int deadline;
    int profit;
};

// Sort jobs by profit (descending)
void sort(struct Job a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(a[j].profit < a[j + 1].profit) {
                struct Job temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void sequenceJobs(struct Job a[], int n) {

    // Step 1: Find maximum deadline
    int maxD = 0;
    for(int i = 0; i < n; i++) {
        if(a[i].deadline > maxD)
            maxD = a[i].deadline;
    }

    // Step 2: Create slot array dynamically
    int slot[maxD];

    // Initialize slots as empty
    for(int i = 0; i < maxD; i++) {
        slot[i] = -1;
    }

    int totalProfit = 0;

    // Step 3: Assign jobs to slots
    for(int i = 0; i < n; i++) {

        // Try to place job in latest free slot
        for(int j = a[i].deadline - 1; j >= 0; j--) {

            if(slot[j] == -1) {
                slot[j] = a[i].id;
                totalProfit += a[i].profit;
                break;
            }
        }
    }

    // Step 4: Print result
    printf("Selected Jobs: ");
    for(int i = 0; i < maxD; i++) {
        if(slot[i] != -1)
            printf("J%d ", slot[i]);
    }

    printf("\nTotal Profit: %d\n", totalProfit);
}

int main() {

    struct Job jobs[] = {
        {1, 2, 100},
        {2, 1, 19},
        {3, 2, 27},
        {4, 1, 25},
        {5, 3, 15}
    };

    int n = sizeof(jobs) / sizeof(jobs[0]);

    sort(jobs, n);
    sequenceJobs(jobs, n);

    return 0;
}