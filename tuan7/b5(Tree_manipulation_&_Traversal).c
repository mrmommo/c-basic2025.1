#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id;
    struct Node *children[100];
    int childCount;
} Node;

#define MAXN 10005
Node *nodes[MAXN];
Node *root = NULL;
Node *getNode(int id) {
    if (nodes[id] == NULL) {
        nodes[id] = (Node *)malloc(sizeof(Node));
        nodes[id]->id = id;
        nodes[id]->childCount = 0;
    }
    return nodes[id];
}

// Duyệt PreOrder
void preorder(Node *node) {
    if (!node)
        return;
    printf("%d ", node->id);
    for (int i = 0; i < node->childCount; i++) {
        preorder(node->children[i]);
    }
}

void inorder(Node *node) {
    if (!node)
        return;
    int mid = node->childCount / 2;
    for (int i = 0; i < mid; i++) {
        inorder(node->children[i]);
    }
    printf("%d ", node->id);
    for (int i = mid; i < node->childCount; i++) {
        inorder(node->children[i]);
    }
}

void postorder(Node *node) {
    if (!node)
        return;
    for (int i = 0; i < node->childCount; i++) {
        postorder(node->children[i]);
    }
    printf("%d ", node->id);
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
        } else if (strcmp(cmd, "Insert") == 0) {
            scanf("%d %d", &u, &v);
            if (!nodes[u] && nodes[v]) {
                Node *child = getNode(u);
                Node *parent = nodes[v];
                parent->children[parent->childCount++] = child;
            }
        } else if (strcmp(cmd, "PreOrder") == 0) {
            preorder(root);
            printf("\n");
        } else if (strcmp(cmd, "InOrder") == 0) {
            inorder(root);
            printf("\n");
        } else if (strcmp(cmd, "PostOrder") == 0) {
            postorder(root);
            printf("\n");
        }
    }

    return 0;
}
