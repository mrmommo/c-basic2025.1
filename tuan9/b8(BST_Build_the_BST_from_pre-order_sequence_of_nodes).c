#include <limits.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} Node;

int *a;
int n;
int idx;

Node *create_node(int key) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

Node *build(int min, int max) {
    if (idx >= n)
        return NULL;
    int val = a[idx];
    if (val <= min || val >= max)
        return NULL;
    idx++;
    Node *node = create_node(val);
    node->left = build(min, val);
    node->right = build(val, max);
    return node;
}

int keys[50000];
int key_count;

void collect_postorder(Node *root) {
    if (root) {
        collect_postorder(root->left);
        collect_postorder(root->right);
        keys[key_count++] = root->key;
    }
}

int main() {
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    idx = 0;
    Node *root = build(INT_MIN, INT_MAX);
    if (root && idx == n) {
        key_count = 0;
        collect_postorder(root);
        for (int i = 0; i < key_count; i++) {
            printf("%d", keys[i]);
            if (i < key_count - 1)
                printf(" ");
        }
        printf("\n");
    } else {
        printf("NULL\n");
    }
    free(a);
    return 0;
}
