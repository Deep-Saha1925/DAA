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

int solveQueens(int col){
    if(col >= N)
        return 1;

    for (int i = 0; i < N; i++){
        if(isSafe(i, col)){
            board[i][col] = 1;

            if(solveQueens(col+1))
                return 1;

            //backtrack
            board[i][col] = 0;
        }
    }

    return 0;   
}

void printBoard(){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main(){
    if(solveQueens(0)){
        printf("Solution Found:\n");
        printBoard();
    } else {
        printf("No Solution\n");
    }

    return 0;
}