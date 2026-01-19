#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100005

int *adj[MAX_N];
int adj_count[MAX_N];
int visited[MAX_N];

void dfs(int u) {
    visited[u] = 1;

    for (int i = 0; i < adj_count[u]; i++) {
        int v = adj[u][i];
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize adjacency list
    for (int i = 1; i <= n; i++) {
        adj[i] = (int *)malloc((m + 1) * sizeof(int));
        adj_count[i] = 0;
    }

    // Read edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][adj_count[u]++] = v;
        adj[v][adj_count[v]++] = u;
    }

    // Count connected components
    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            components++;
        }
    }

    printf("%d\n", components);

    // Free allocated memory
    for (int i = 1; i <= n; i++) {
        free(adj[i]);
    }

    return 0;
}
/*
Input
8 8
1 2
1 7
1 8
2 7
4 5
4 6
5 6
7 8

Output
3
*/