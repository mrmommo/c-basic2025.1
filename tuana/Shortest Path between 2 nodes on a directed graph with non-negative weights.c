#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100005

typedef struct {
    int v;
    long long weight;
} Edge;

typedef struct {
    Edge *edges;
    int count;
} AdjacencyList;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    AdjacencyList *graph =
        (AdjacencyList *)malloc((n + 1) * sizeof(AdjacencyList));
    for (int i = 0; i <= n; i++) {
        graph[i].edges = (Edge *)malloc((m + 1) * sizeof(Edge));
        graph[i].count = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        scanf("%d %d %lld", &u, &v, &w);

        graph[u].edges[graph[u].count].v = v;
        graph[u].edges[graph[u].count].weight = w;
        graph[u].count++;
    }

    int s, t;
    scanf("%d %d", &s, &t);

    // Dijkstra's algorithm using simple priority approach
    long long distance[MAX_NODES];
    int visited[MAX_NODES];

    for (int i = 1; i <= n; i++) {
        distance[i] = LLONG_MAX;
        visited[i] = 0;
    }

    distance[s] = 0;

    for (int i = 0; i < n; i++) {
        // Find unvisited node with minimum distance
        long long minDist = LLONG_MAX;
        int u = -1;

        for (int j = 1; j <= n; j++) {
            if (!visited[j] && distance[j] < minDist) {
                minDist = distance[j];
                u = j;
            }
        }

        if (u == -1 || distance[u] == LLONG_MAX)
            break;

        visited[u] = 1;

        for (int j = 0; j < graph[u].count; j++) {
            int v = graph[u].edges[j].v;
            long long w = graph[u].edges[j].weight;

            if (!visited[v] && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }

    if (distance[t] == LLONG_MAX) {
        printf("-1\n");
    } else {
        printf("%lld\n", distance[t]);
    }

    // Free memory
    for (int i = 0; i <= n; i++) {
        free(graph[i].edges);
    }
    free(graph);

    return 0;
}
/*
Input
5 7
2 5 87
1 2 97
4 5 78
3 1 72
1 4 19
2 3 63
5 1 18
1 5

Output
97
*/