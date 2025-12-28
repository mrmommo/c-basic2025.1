#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id;
    struct Node* children[100]; // danh sách con
    int childCount;
} Node;

#define MAXN 50005
Node* nodes[MAXN];
Node* root = NULL;

// Tạo hoặc lấy node theo id
Node* getNode(int id) {
    if (nodes[id] == NULL) {
        nodes[id] = (Node*)malloc(sizeof(Node));
        nodes[id]->id = id;
        nodes[id]->childCount = 0;
    }
    return nodes[id];
}

// Duyệt PreOrder: thăm node trước, rồi duyệt các con
void preorder(Node* node) {
    if (!node) return;
    printf("%d ", node->id);
    for (int i = 0; i < node->childCount; i++) {
        preorder(node->children[i]);
    }
}

// Duyệt InOrder: nếu có 1 con → duyệt con rồi node; nếu nhiều con → nửa đầu, node, nửa sau
void inorder(Node* node) {
    if (!node) return;

    if (node->childCount == 1) {
        inorder(node->children[0]);
        printf("%d ", node->id);
    } else {
        int mid = node->childCount / 2;
        for (int i = 0; i < mid; i++) {
            inorder(node->children[i]);
        }
        printf("%d ", node->id);
        for (int i = mid; i < node->childCount; i++) {
            inorder(node->children[i]);
        }
    }
}

// Duyệt PostOrder: duyệt các con trước, rồi thăm node
void postorder(Node* node) {
    if (!node) return;
    for (int i = 0; i < node->childCount; i++) {
        postorder(node->children[i]);
    }
    printf("%d ", node->id);
}

int main() {
    char cmd[20];
    int u, v;

    for (int i = 0; i < MAXN; i++) nodes[i] = NULL;

    while (scanf("%s", cmd)) {
        if (strcmp(cmd, "*") == 0) break;

        if (strcmp(cmd, "MakeRoot") == 0) {
            scanf("%d", &u);
            root = getNode(u);
        }
        else if (strcmp(cmd, "Insert") == 0) {
            scanf("%d %d", &u, &v);
            if (!nodes[u] && nodes[v]) {
                Node* child = getNode(u);
                Node* parent = nodes[v];
                parent->children[parent->childCount++] = child;
            }
        }
        else if (strcmp(cmd, "PreOrder") == 0) {
            preorder(root);
            printf("\n");
        }
        else if (strcmp(cmd, "InOrder") == 0) {
            inorder(root);
            printf("\n");
        }
        else if (strcmp(cmd, "PostOrder") == 0) {
            postorder(root);
            printf("\n");
        }
    }

    return 0;
}
