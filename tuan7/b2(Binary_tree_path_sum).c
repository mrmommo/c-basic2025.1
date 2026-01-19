#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {
    int id;
    struct Node *left, *right;
} Node;

#define MAXN 10005
Node *nodes[MAXN];

Node *createNode(int id) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->id = id;
    node->left = node->right = NULL;
    return node;
}

bool hasPathSum(Node *root, int targetSum, int currentSum) {
    if (!root)
        return false;
    currentSum += root->id;

    if (!root->left && !root->right) {
        return currentSum == targetSum;
    }

    return hasPathSum(root->left, targetSum, currentSum) ||
           hasPathSum(root->right, targetSum, currentSum);
}

int main() {
    char cmd[20];
    int u, v;
    Node *root = NULL;

    for (int i = 0; i < MAXN; i++)
        nodes[i] = NULL;

    while (scanf("%s", cmd)) {
        if (strcmp(cmd, "*") == 0)
            break;

        if (strcmp(cmd, "MakeRoot") == 0) {
            scanf("%d", &u);
            if (!nodes[u]) {
                nodes[u] = createNode(u);
            }
            root = nodes[u];
        } else if (strcmp(cmd, "AddLeft") == 0) {
            scanf("%d %d", &u, &v);
            if (!nodes[u] && nodes[v] && nodes[v]->left == NULL) {
                nodes[u] = createNode(u);
                nodes[v]->left = nodes[u];
            }
        } else if (strcmp(cmd, "AddRight") == 0) {
            scanf("%d %d", &u, &v);
            if (!nodes[u] && nodes[v] && nodes[v]->right == NULL) {
                nodes[u] = createNode(u);
                nodes[v]->right = nodes[u];
            }
        } else if (strcmp(cmd, "PathSum") == 0) {
            scanf("%d", &u);
            if (root && hasPathSum(root, u, 0)) {
                printf("True\n");
            } else {
                printf("False\n");
            }
        }
    }

    return 0;
}
/*
Example:
MakeRoot 1
AddLeft 2 1
AddRight 3 1
AddLeft 4 3
AddRight 5 2
AddLeft 6 5
AddRight 7 5
PathSum 4
PathSum 5
PathSum 8
PathSum 14
PathSum 15
PathSum 20
*
Output:
False
False
True
True
True
False
*/