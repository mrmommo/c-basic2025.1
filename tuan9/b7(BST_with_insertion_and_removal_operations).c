#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

Node* root = NULL;
int keys[10000];
int key_count;

Node* create_node(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

void insert_iter(Node** root, int key) {
    Node* newnode = create_node(key);
    if(*root == NULL) {
        *root = newnode;
        return;
    }
    Node* curr = *root;
    Node* parent = NULL;
    while(curr) {
        parent = curr;
        if(key < curr->key) {
            curr = curr->left;
        } else if(key > curr->key) {
            curr = curr->right;
        } else {
            free(newnode);
            return;
        }
    }
    if(key < parent->key) {
        parent->left = newnode;
    } else {
        parent->right = newnode;
    }
}

Node* find_min(Node* node) {
    while(node->left) node = node->left;
    return node;
}

void remove_node(Node** root, int key) {
    if(*root == NULL) return;
    if(key < (*root)->key) {
        remove_node(&(*root)->left, key);
    } else if(key > (*root)->key) {
        remove_node(&(*root)->right, key);
    } else {
        if((*root)->left == NULL) {
            Node* temp = *root;
            *root = (*root)->right;
            free(temp);
        } else if((*root)->right == NULL) {
            Node* temp = *root;
            *root = (*root)->left;
            free(temp);
        } else {
            Node* temp = find_min((*root)->right);
            (*root)->key = temp->key;
            remove_node(&(*root)->right, temp->key);
        }
    }
}

void collect_preorder(Node* root) {
    if(root) {
        keys[key_count++] = root->key;
        collect_preorder(root->left);
        collect_preorder(root->right);
    }
}

void collect_postorder(Node* root) {
    if(root) {
        collect_postorder(root->left);
        collect_postorder(root->right);
        keys[key_count++] = root->key;
    }
}

int main() {
    char line[100];
    while(fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\n")] = 0;
        if(strcmp(line, "#") == 0) break;
        char cmd[20];
        int k;
        if(sscanf(line, "%s %d", cmd, &k) == 2) {
            if(strcmp(cmd, "insert") == 0) {
                insert_iter(&root, k);
            } else if(strcmp(cmd, "remove") == 0) {
                remove_node(&root, k);
            }
        } else {
            if(strcmp(line, "preorder") == 0) {
                key_count = 0;
                collect_preorder(root);
                for(int i = 0; i < key_count; i++) {
                    printf("%d", keys[i]);
                    if(i < key_count - 1) printf(" ");
                }
                printf("\n");
            } else if(strcmp(line, "postorder") == 0) {
                key_count = 0;
                collect_postorder(root);
                for(int i = 0; i < key_count; i++) {
                    printf("%d", keys[i]);
                    if(i < key_count - 1) printf(" ");
                }
                printf("\n");
            }
        }
    }
    return 0;
}
