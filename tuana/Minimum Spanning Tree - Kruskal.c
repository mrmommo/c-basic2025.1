#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, weight;
} Edge;

typedef struct {
    int parent;
    int rank;
} Node;

int find(Node *parent, int x) {
    if (parent[x].parent != x) {
        parent[x].parent = find(parent, parent[x].parent);
    }
    return parent[x].parent;
}

void unite(Node *parent, int x, int y) {
    int px = find(parent, x);
    int py = find(parent, y);

    if (px == py)
        return;

    if (parent[px].rank < parent[py].rank) {
        parent[px].parent = py;
    } else if (parent[px].rank > parent[py].rank) {
        parent[py].parent = px;
    } else {
        parent[py].parent = px;
        parent[px].rank++;
    }
}

int compare(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Edge *edges = (Edge *)malloc(m * sizeof(Edge));
    Node *parent = (Node *)malloc(n * sizeof(Node));

    for (int i = 0; i < n; i++) {
        parent[i].parent = i;
        parent[i].rank = 0;
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
        edges[i].u--; // Convert to 0-indexed
        edges[i].v--;
    }

    // Sort edges by weight
    qsort(edges, m, sizeof(Edge), compare);

    int totalWeight = 0;
    int edgeCount = 0;

    for (int i = 0; i < m && edgeCount < n - 1; i++) {
        int pu = find(parent, edges[i].u);
        int pv = find(parent, edges[i].v);

        if (pu != pv) {
            unite(parent, pu, pv);
            totalWeight += edges[i].weight;
            edgeCount++;
        }
    }

    printf("%d\n", totalWeight);

    free(edges);
    free(parent);

    return 0;
}
/*
Input
5 8
1 2 1
1 3 4
1 5 1
2 4 2
2 5 1
3 4 3
3 5 3
4 5 2
Output
7
*/