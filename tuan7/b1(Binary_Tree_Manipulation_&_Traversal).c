#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id;
    struct Node *left, *right;
} Node;

Node *root = NULL;
Node *find(Node *r, int id) {
    if (r == NULL)
        return NULL;
    if (r->id == id)
        return r;
    Node *left = find(r->left, id);
    if (left)
        return left;
    return find(r->right, id);
}
Node *newNode(int id) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->id = id;
    p->left = p->right = NULL;
    return p;
}
void preOrder(Node *r) {
    if (r == NULL)
        return;
    printf("%d ", r->id);
    preOrder(r->left);
    preOrder(r->right);
}
void inOrder(Node *r) {
    if (r == NULL)
        return;
    inOrder(r->left);
    printf("%d ", r->id);
    inOrder(r->right);
}
void postOrder(Node *r) {
    if (r == NULL)
        return;
    postOrder(r->left);
    postOrder(r->right);
    printf("%d ", r->id);
}

int main() {
    char cmd[20];
    int u, v;

    while (1) {
        scanf("%s", cmd);
        if (cmd[0] == '*')
            break;

        if (strcmp(cmd, "MakeRoot") == 0) {
            scanf("%d", &u);
            root = newNode(u);
        } else if (strcmp(cmd, "AddLeft") == 0) {
            scanf("%d %d", &u, &v);
            if (find(root, u) != NULL)
                continue;
            Node *parent = find(root, v);
            if (parent == NULL)
                continue;
            if (parent->left != NULL)
                continue;
            parent->left = newNode(u);
        } else if (strcmp(cmd, "AddRight") == 0) {
            scanf("%d %d", &u, &v);
            if (find(root, u) != NULL)
                continue;
            Node *parent = find(root, v);
            if (parent == NULL)
                continue;
            if (parent->right != NULL)
                continue;
            parent->right = newNode(u);
        } else if (strcmp(cmd, "PreOrder") == 0) {
            preOrder(root);
            printf("\n");
        } else if (strcmp(cmd, "InOrder") == 0) {
            inOrder(root);
            printf("\n");
        } else if (strcmp(cmd, "PostOrder") == 0) {
            postOrder(root);
            printf("\n");
        }
    }

    return 0;
}
/*
Input
MakeRoot 1
AddLeft 2 1
AddRight 3 1
AddLeft 4 3
AddRight 5 2
PreOrder
AddLeft 6 5
AddRight 7 5
InOrder
*

Output
1 2 5 3 4
2 6 5 7 1 4 3
*/