#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue structure
typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Initialize queue
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if queue is empty
int isEmpty(Queue *q) {
    return q->front == -1;
}

// Enqueue operation
void enqueue(Queue *q, int value) {
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

// Dequeue operation
int dequeue(Queue *q) {
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

// Comparison function for sorting
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// BFS function for complete traversal
void bfs(int graph[MAX][MAX], int n) {
    int visited[MAX] = {0};
    Queue q;
    initQueue(&q);

    int first = 1;

    // Start from each unvisited node in lexicographic order
    for (int start = 1; start <= n; start++) {
        if (!visited[start]) {
            visited[start] = 1;
            enqueue(&q, start);

            while (!isEmpty(&q)) {
                int current = dequeue(&q);

                if (!first)
                    printf(" ");
                printf("%d", current);
                first = 0;

                // Collect neighbors
                int neighbors[MAX];
                int count = 0;

                for (int i = 1; i <= n; i++) {
                    if (graph[current][i] && !visited[i]) {
                        neighbors[count++] = i;
                    }
                }

                // Sort neighbors in lexicographic order
                qsort(neighbors, count, sizeof(int), compare);

                // Add sorted neighbors to queue
                for (int i = 0; i < count; i++) {
                    visited[neighbors[i]] = 1;
                    enqueue(&q, neighbors[i]);
                }
            }
        }
    }
    printf("\n");
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX] = {0};

    // Read edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    // Perform complete BFS traversal
    bfs(graph, n);

    return 0;
}
/*
Input
6 7
2 4
1 3
3 4
5 6
1 2
3 5
2 3

Output
1 2 3 4 5 6
*/