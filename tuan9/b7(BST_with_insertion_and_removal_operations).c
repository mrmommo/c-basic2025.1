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

/* tìm node nhỏ nhất */
Node *minNode(Node *root) {
    while (root && root->left)
        root = root->left;
    return root;
}

/* remove node có key = k */
Node *removeNode(Node *root, int k) {
    if (root == NULL)
        return NULL;

    if (k < root->key) {
        root->left = removeNode(root->left, k);
    } else if (k > root->key) {
        root->right = removeNode(root->right, k);
    } else {
        // tìm thấy node cần xóa
        if (root->left == NULL) {
            Node *tmp = root->right;
            free(root);
            return tmp;
        } else if (root->right == NULL) {
            Node *tmp = root->left;
            free(root);
            return tmp;
        } else {
            // có 2 con
            Node *tmp = minNode(root->right);
            root->key = tmp->key;
            root->right = removeNode(root->right, tmp->key);
        }
    }
    return root;
}

/* preorder */
void preorder(Node *root) {
    if (!root)
        return;
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
}

/* postorder */
void postorder(Node *root) {
    if (!root)
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
        } else if (strcmp(cmd, "remove") == 0) {
            scanf("%d", &k);
            root = removeNode(root, k);
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
insert 3
insert 4
remove 4
preorder
postorder
insert 5
insert 1
insert 8
remove 1
preorder
postorder
#

Output
3
3
3 5 8
8 5 3k

*/