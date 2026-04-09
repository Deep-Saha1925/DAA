#include<stdio.h>

// Linear Recursion O(n)
int linearPower(int x, int n){
    if(n == 0){
        return 1;
    }

    return x * linearPower(x, n-1);
}

// Optimzed recursive Power function O(log n)
int powerFunction(int x, int n){
    if(n == 0){
        return 1;
    }

    int half = powerFunction(x, n/2);

    if(n % 2 == 0){
        return half * half;
    }else{
        return x * half * half;
    }
}

int main(){
    int x = 2, n = 5;
    // printf("Linear Power: %d", linearPower(x, n));
    printf("Recursive Power: %d", powerFunction(x, n));
}