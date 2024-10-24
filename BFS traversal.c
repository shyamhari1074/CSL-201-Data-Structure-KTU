#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue structure for BFS
typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == -1;
}

// Function to enqueue an item
void enqueue(Queue* q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

// Function to dequeue an item
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = q->items[q->front];
    if (q->front >= q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

// Function to perform BFS on the graph
void bfs(int graph[MAX][MAX], int start, int visited[], int n) {
    Queue q;
    initQueue(&q);
   
    visited[start] = 1;
    enqueue(&q, start);
   
    while (!isEmpty(&q)) {
        int current = dequeue(&q);
        printf("%d ", current);
       
        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
}

int main() {
    int n; // Number of vertices
    int graph[MAX][MAX];
    int visited[MAX] = {0};

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0 and 1 only):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int startVertex;
    printf("Enter the starting vertex (0 to %d): ", n - 1);
    scanf("%d", &startVertex);

    printf("BFS traversal starting from vertex %d:\n", startVertex);
    bfs(graph, startVertex, visited, n);

    return 0;
}
