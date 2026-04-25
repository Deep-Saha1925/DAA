#include <stdio.h>
#define MAX 10
#define INF 999999

int main() {
    int n, i, j, k, L;
    int arr[MAX];
    int dp[MAX][MAX];  // DP table

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    printf("Enter %d dimensions: ", n + 1);
    for(i = 0; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 1: Initialize diagonal = 0
    for(i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }

    // Step 2: Chain length from 2 to n
    for(L = 2; L <= n; L++) {
        for(i = 1; i <= n - L + 1; i++) {
            j = i + L - 1;
            dp[i][j] = INF;

            for(k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] 
                         + arr[i-1] * arr[k] * arr[j];

                if(cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    // Output result
    printf("Minimum multiplication cost = %d\n", dp[1][n]);

    return 0;
}