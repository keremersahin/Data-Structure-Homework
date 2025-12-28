#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

void enqueue(Queue *q, int value) {
    if (q->rear == MAX - 1) return;
    if (q->front == -1) q->front = 0;
    q->items[++q->rear] = value;
}

int dequeue(Queue *q) {
    if (q->front == -1 || q->front > q->rear) return -1;
    return q->items[q->front++];
}

int isQueueEmpty(Queue *q) {
    return q->front == -1 || q->front > q->rear;
}

int adjMatrix[MAX][MAX];
int visited[MAX];
int numVertices;

void initGraph(int n) {
    numVertices = n;
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(int src, int dest) {
    adjMatrix[src][dest] = 1;
    adjMatrix[dest][src] = 1; 
}

void DFS(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < numVertices; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

void BFS(int startVertex) {
    Queue q;
    initQueue(&q);
    
    for(int i=0; i<numVertices; i++) visited[i] = 0;

    visited[startVertex] = 1;
    enqueue(&q, startVertex);

    while (!isQueueEmpty(&q)) {
        int current = dequeue(&q);
        printf("%d ", current);

        for (int i = 0; i < numVertices; i++) {
            if (adjMatrix[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

void findClusters() {
    for(int i=0; i<numVertices; i++) visited[i] = 0;
    
    int clusterCount = 0;

    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            clusterCount++;
            printf("Kume %d: { ", clusterCount);
            DFS(i); 
            printf("}\n");
        }
    }
    printf("Toplam kume: %d\n", clusterCount);
}

int main() {
    initGraph(7);

    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(2, 0);

    addEdge(3, 4);

    addEdge(5, 6);
    
    printf("BFS (0 baslangic): ");
    BFS(0); 

    printf("Cluster Analizi:\n");
    findClusters();

    return 0;
}