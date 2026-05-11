#include<stdio.h>
#define N 4

int board[N][N];

int isSafe(int row, int col){
    //left
    for (int i = 0; i < col; i++){
        if(board[row][i])
            return 0;
    }

    //upper digonal
    for (int i=row, j=col; i>=0 && j >= 0; i--, j--){
        if(board[i][j])
            return 0;
    }
    
    //lower diagonal
    for (int i=row, j=col; i<N && j >= 0; i++, j--){
        if(board[i][j])
            return 0;
    }

    return 1;
}