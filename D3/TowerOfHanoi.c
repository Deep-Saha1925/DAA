#include<stdio.h>

void TOH(int n, char src[], char aux[], char dest[]){
    if(n == 1){
        printf("Move disk 1 from %s to %s\n", src, dest);
        return;
    }

    // Step 1: Move n-1 disks from src to aux
    TOH(n-1, src, dest, aux);

    // Step 2: Move 1 disk from src to dest
    TOH(1, src, aux, dest);

    // Step 3: Move n-1 disks from aux to dest
    TOH(n-1, aux, src, dest); 
}

int main(){
    int n = 3;
    // TOH(n, 'A', 'B', 'C');
    TOH(n, "SRC", "HELPER", "DESTINATION");
}