#include<stdio.h>
#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value){
    if(rear == MAX-1)
        return;

    if(front == -1)
        front = 0;

    queue[++rear] = value;
}

void dfs(int graph[MAX][MAX], int vertices, int start){
    int visited[MAX] = {0};

    visited[start] = 1;
    enqueue(start);

    while (front <= rear){
        int node = dequeue();
        printf("Node: %d", node);

        for(int i=0; i<vertices; i++){
            if(graph[node][i] == 1 && visited[i] == 0){
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    
}

int dequeue(){
    if(front == -1 || front > rear)
        return -1;

    return queue[front++];
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

    printf("BFS Traversal: ");
    bfs(graph, vertices, 0);

    return 0;
}