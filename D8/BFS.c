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