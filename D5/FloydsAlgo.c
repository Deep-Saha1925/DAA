#include <stdio.h>

#define INF 999

int main() {
    int n = 4;

    int cost[4][4] = {
        {0, 7, 5, INF},
        {INF, 0, 7, 6},
        {INF, INF, 0, INF},
        {4, 1, 11, 0}
    };

    int i, j, k;

    // Floyd's Algorithm
    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {

                if(cost[i][k] + cost[k][j] < cost[i][j]) {
                    cost[i][j] = cost[i][k] + cost[k][j];
                }

            }
        }
    }

    // Print shortest path matrix
    printf("Shortest Path Matrix:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {

            if(cost[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", cost[i][j]);
        }
        printf("\n");
    }

    return 0;
}