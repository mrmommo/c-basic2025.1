#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 100
#define MAX_NAME 100
#define MAX_EMAIL 100

// BST Node for chaining
typedef struct BSTNode {
    char name[MAX_NAME];
    char email[MAX_EMAIL];
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

// Hash table
BSTNode *hashTable[HASH_SIZE];

// Hash function
int hashFunction(char *str) {
    int hash = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash = (hash * 256 + str[i]);
    }
    return hash % HASH_SIZE;
}

// Create new BST node
BSTNode *createNode(char *name, char *email) {
    BSTNode *node = (BSTNode *)malloc(sizeof(BSTNode));
    strcpy(node->name, name);
    strcpy(node->email, email);
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert into BST
BSTNode *insertBST(BSTNode *root, char *name, char *email) {
    if (root == NULL) {
        return createNode(name, email);
    }

    int cmp = strcmp(name, root->name);
    if (cmp < 0) {
        root->left = insertBST(root->left, name, email);
    } else if (cmp > 0) {
        root->right = insertBST(root->right, name, email);
    } else {
        // Update email if name exists
        strcpy(root->email, email);
    }

    return root;
}

// Search in BST
BSTNode *searchBST(BSTNode *root, char *name) {
    if (root == NULL) {
        return NULL;
    }

    int cmp = strcmp(name, root->name);
    if (cmp == 0) {
        return root;
    } else if (cmp < 0) {
        return searchBST(root->left, name);
    } else {
        return searchBST(root->right, name);
    }
}

// Find minimum node in BST
BSTNode *findMin(BSTNode *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Remove from BST
BSTNode *removeBST(BSTNode *root, char *name) {
    if (root == NULL) {
        return NULL;
    }

    int cmp = strcmp(name, root->name);
    if (cmp < 0) {
        root->left = removeBST(root->left, name);
    } else if (cmp > 0) {
        root->right = removeBST(root->right, name);
    } else {
        // Node found
        if (root->left == NULL) {
            BSTNode *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            BSTNode *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        BSTNode *temp = findMin(root->right);
        strcpy(root->name, temp->name);
        strcpy(root->email, temp->email);
        root->right = removeBST(root->right, temp->name);
    }

    return root;
}

// Write BST to file (in-order traversal)
void writeBSTToFile(BSTNode *root, FILE *file) {
    if (root == NULL)
        return;

    writeBSTToFile(root->left, file);
    fprintf(file, "%s %s\n", root->name, root->email);
    writeBSTToFile(root->right, file);
}

// Insert student into hash table
void insertStudent(char *name, char *email) {
    int hash = hashFunction(name);
    hashTable[hash] = insertBST(hashTable[hash], name, email);
}

// Find student
void findStudent(char *name) {
    int hash = hashFunction(name);
    BSTNode *node = searchBST(hashTable[hash], name);

    if (node != NULL) {
        printf("%d %s\n", hash, node->email);
    } else {
        printf("Not found\n");
    }
}

// Remove student
void removeStudent(char *name) {
    int hash = hashFunction(name);
    hashTable[hash] = removeBST(hashTable[hash], name);
}

// Load from file or stdin
void loadFromFile() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char name[MAX_NAME], email[MAX_EMAIL];
        scanf("%s %s", name, email);
        insertStudent(name, email);
    }
}

// Store to file
void storeToFile(char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    for (int i = 0; i < HASH_SIZE; i++) {
        if (hashTable[i] != NULL) {
            writeBSTToFile(hashTable[i], file);
        }
    }

    fclose(file);
}

int main() {
    // Initialize hash table
    for (int i = 0; i < HASH_SIZE; i++) {
        hashTable[i] = NULL;
    }

    char command[20];

    while (1) {
        scanf("%s", command);

        if (strcmp(command, "Load") == 0) {
            loadFromFile();
        } else if (strcmp(command, "Find") == 0) {
            char name[MAX_NAME];
            scanf("%s", name);
            findStudent(name);
        } else if (strcmp(command, "Insert") == 0) {
            char name[MAX_NAME], email[MAX_EMAIL];
            scanf("%s %s", name, email);
            insertStudent(name, email);
        } else if (strcmp(command, "Remove") == 0) {
            char name[MAX_NAME];
            scanf("%s", name);
            removeStudent(name);
        } else if (strcmp(command, "Store") == 0) {
            char filename[100];
            scanf("%s", filename);
            storeToFile(filename);
        } else if (strcmp(command, "Quit") == 0) {
            printf("Bye\n");
            break;
        }
    }

    return 0;
}