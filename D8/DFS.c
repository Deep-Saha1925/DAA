#include<stdio.h>
#define MAX 10

void dfs(int graph[MAX][MAX], int visited[], int node, int vertices){
    printf("%d ", node);
    visited[node] = 1;

    for(int i=0; i<vertices; i++){
        if(graph[node][i] == 1 && visited[i] == 0){
            dfs(graph, visited, i, vertices);
        }
    }
}

int main(){
    int vertices = 5;

    int graph[MAX][MAX] = {
        {0,1,1,0,0},
        {1,0,0,1,1},
        {1,0,0,0,0},
        {0,1,0,0,0},
        {0,1,0,0,0}
    };

    int visited[MAX] = {0};

    printf("DFS Traversal: ");
    dfs(graph, visited, 0, vertices);

    return 0;
}