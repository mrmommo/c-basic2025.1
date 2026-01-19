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

/* insert vào BST, bỏ qua nếu trùng */
Node *insert(Node *root, int k) {
    if (root == NULL)
        return newNode(k);

    if (k < root->key)
        root->left = insert(root->left, k);
    else if (k > root->key)
        root->right = insert(root->right, k);

    return root;
}

/* preorder traversal */
void preorder(Node *root) {
    if (root == NULL)
        return;
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
}

/* postorder traversal */
void postorder(Node *root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->key);
}

int main() {
    Node *root = NULL;
    char cmd[30];
    int k;

    while (1) {
        if (scanf("%s", cmd) != 1)
            break;
        if (cmd[0] == '#')
            break;

        if (strcmp(cmd, "insert") == 0) {
            scanf("%d", &k);
            root = insert(root, k);
        } else if (strcmp(cmd, "preorder") == 0) {
            preorder(root);
            printf("\n");
        } else if (strcmp(cmd, "postorder") == 0) {
            postorder(root);
            printf("\n");
        }
    }

    return 0;
}
/*
Input
insert 5
insert 9
insert 2
insert 1
preorder
insert 8
insert 5
insert 3
postorder
#

Output
5 2 1 9
1 3 2 8 9 5
*/