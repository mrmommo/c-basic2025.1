#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX] = {0};
int first = 1;

// Comparison function for sorting
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// DFS recursive function
void dfsVisit(int graph[MAX][MAX], int n, int node) {
    visited[node] = 1;

    if (!first)
        printf(" ");
    printf("%d", node);
    first = 0;

    // Collect neighbors
    int neighbors[MAX];
    int count = 0;

    for (int i = 1; i <= n; i++) {
        if (graph[node][i] && !visited[i]) {
            neighbors[count++] = i;
        }
    }

    // Sort neighbors in lexicographic order
    qsort(neighbors, count, sizeof(int), compare);

    // Visit sorted neighbors recursively
    for (int i = 0; i < count; i++) {
        if (!visited[neighbors[i]]) {
            dfsVisit(graph, n, neighbors[i]);
        }
    }
}

// DFS function for complete traversal
void dfs(int graph[MAX][MAX], int n) {
    // Start from each unvisited node in lexicographic order
    for (int start = 1; start <= n; start++) {
        if (!visited[start]) {
            dfsVisit(graph, n, start);
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

    // Perform complete DFS traversal
    dfs(graph, n);

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