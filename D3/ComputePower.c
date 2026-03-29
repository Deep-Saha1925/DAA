#include<stdio.h>

// Linear Recursion
int linearPower(int x, int n){
    if(n == 0){
        return 1;
    }

    return x * linearPower(x, n-1);
}

int main(){
    int x = 2, n = 5;
    printf("Linear Power: %d", linearPower(x, n));
}