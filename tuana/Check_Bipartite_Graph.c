#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100005

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Adjacency list
    int *adj[MAX_N];
    int adj_count[MAX_N] = {0};

    // Allocate space for adjacency list
    for (int i = 1; i <= n; i++) {
        adj[i] = (int *)malloc((m + 1) * sizeof(int));
    }

    // Read edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][adj_count[u]++] = v;
        adj[v][adj_count[v]++] = u;
    }

    // Color array: -1 = unvisited, 0 and 1 = two colors
    int color[MAX_N];
    memset(color, -1, sizeof(color));

    int is_bipartite = 1;

    // BFS for each connected component
    for (int start = 1; start <= n && is_bipartite; start++) {
        if (color[start] == -1) {
            // BFS from start vertex
            int queue[MAX_N];
            int front = 0, rear = 0;

            queue[rear++] = start;
            color[start] = 0;

            while (front < rear && is_bipartite) {
                int u = queue[front++];

                // Check all neighbors
                for (int i = 0; i < adj_count[u]; i++) {
                    int v = adj[u][i];

                    if (color[v] == -1) {
                        // Color with opposite color
                        color[v] = 1 - color[u];
                        queue[rear++] = v;
                    } else if (color[v] == color[u]) {
                        // Same color as neighbor - not bipartite
                        is_bipartite = 0;
                        break;
                    }
                }
            }
        }
    }

    printf("%d\n", is_bipartite);

    // Free allocated memory
    for (int i = 1; i <= n; i++) {
        free(adj[i]);
    }

    return 0;
}
/*
input
6 6
1 2
1 3
2 5
2 6
4 5
4 6

output
1
*/