#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

/* tạo node mới */
Node *newNode(int k) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = k;
    p->left = p->right = NULL;
    return p;
}

/* insert vào BST, không chèn nếu trùng */
Node *insert(Node *root, int k) {
    if (root == NULL)
        return newNode(k);

    if (k < root->key)
        root->left = insert(root->left, k);
    else if (k > root->key)
        root->right = insert(root->right, k);

    return root; // k == root->key thì bỏ qua
}

/* duyệt pre-order */
void preorder(Node *root) {
    if (root == NULL)
        return;
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    Node *root = NULL;
    char cmd[20];
    int k;

    while (1) {
        if (scanf("%s", cmd) != 1)
            break;
        if (cmd[0] == '#')
            break;

        if (strcmp(cmd, "insert") == 0) {
            scanf("%d", &k);
            root = insert(root, k);
        }
    }

    preorder(root);
    return 0;
}
