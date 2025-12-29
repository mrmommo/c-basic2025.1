#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id;
    struct Node *children[100];
    int childCount;
    struct Node *parent;
} Node;

#define MAXN 50005
Node *nodes[MAXN];
Node *root = NULL;

// Tạo hoặc lấy node theo id
Node *getNode(int id) {
    if (nodes[id] == NULL) {
        nodes[id] = (Node *)malloc(sizeof(Node));
        nodes[id]->id = id;
        nodes[id]->childCount = 0;
        nodes[id]->parent = NULL;
    }
    return nodes[id];
}

// Tính độ cao của nút (số tầng từ nút đến lá sâu nhất)
int getHeight(Node *node) {
    if (!node)
        return 0;
    int maxH = 0;
    for (int i = 0; i < node->childCount; i++) {
        int h = getHeight(node->children[i]);
        if (h > maxH)
            maxH = h;
    }
    return maxH + 1; // bao gồm chính nó
}

// Tính độ sâu của nút (số tầng từ gốc đến nút)
int getDepth(Node *node) {
    int depth = 1; // gốc có độ sâu là 1
    while (node && node->parent) {
        node = node->parent;
        depth++;
    }
    return depth;
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
                child->parent = parent;
            }
        } else if (strcmp(cmd, "Height") == 0) {
            scanf("%d", &u);
            printf("%d\n", getHeight(nodes[u]));
        } else if (strcmp(cmd, "Depth") == 0) {
            scanf("%d", &u);
            printf("%d\n", getDepth(nodes[u]));
        }
    }

    return 0;
}
