#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {
    int id;
    struct Node *left, *right;
} Node;

#define MAXN 50005
Node *nodes[MAXN];
Node *root = NULL;

Node *getNode(int id) {
    if (nodes[id] == NULL) {
        nodes[id] = (Node *)malloc(sizeof(Node));
        nodes[id]->id = id;
        nodes[id]->left = nodes[id]->right = NULL;
    }
    return nodes[id];
}

int checkHeight(Node *node, bool *balanced) {
    if (!node)
        return 0;
    int lh = checkHeight(node->left, balanced);
    int rh = checkHeight(node->right, balanced);
    if (abs(lh - rh) > 1)
        *balanced = false;
    return (lh > rh ? lh : rh) + 1;
}

int main() {
    char cmd[20];
    int u, v;
    for (int i = 0; i < MAXN; i++)
        nodes[i] = NULL;

    while (scanf("%s", cmd)) {
        if (strcmp(cmd, "*") == 0)
            break;

        if (strcmp(cmd, "MakeRoot") == 0) {
            scanf("%d", &u);
            root = getNode(u);
        } else if (strcmp(cmd, "AddLeft") == 0) {
            scanf("%d %d", &u, &v);
            if (!nodes[u] && nodes[v] && nodes[v]->left == NULL) {
                nodes[u] = getNode(u);
                nodes[v]->left = nodes[u];
            }
        } else if (strcmp(cmd, "AddRight") == 0) {
            scanf("%d %d", &u, &v);
            if (!nodes[u] && nodes[v] && nodes[v]->right == NULL) {
                nodes[u] = getNode(u);
                nodes[v]->right = nodes[u];
            }
        }
    }

    bool balanced = true;
    int height = checkHeight(root, &balanced);

    printf("%d %d\n", balanced ? 1 : 0, height);

    return 0;
}
/*
Example
Input
MakeRoot 1
AddLeft 2 1
AddRight 3 1
AddLeft 9 2
AddRight 4 2
AddLeft 6 3
AddRight 5 3
AddLeft 7 4
AddRight 8 4
*
Output
1 4
*/