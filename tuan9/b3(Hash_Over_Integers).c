#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 1000003

typedef struct Node {
    long long key;
    struct Node *next;
} Node;

Node *hash_table[HASH_SIZE];

long long hash_func(long long key) {
    return (key % HASH_SIZE + HASH_SIZE) % HASH_SIZE;
}

int has_key(long long key) {
    long long h = hash_func(key);
    Node *node = hash_table[h];
    while (node) {
        if (node->key == key)
            return 1;
        node = node->next;
    }
    return 0;
}

void insert_key(long long key) {
    long long h = hash_func(key);
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->next = hash_table[h];
    hash_table[h] = node;
}

int main() {
    char line[100];
    // Read initial keys
    while (fgets(line, sizeof(line), stdin)) {
        if (line[0] == '*' && line[1] == '\n')
            break;
        long long k = atoll(line);
        insert_key(k);
    }
    // Read actions
    while (fgets(line, sizeof(line), stdin)) {
        if (strncmp(line, "***", 3) == 0)
            break;
        char cmd[10];
        long long k;
        sscanf(line, "%s %lld", cmd, &k);
        if (strcmp(cmd, "find") == 0) {
            printf("%d\n", has_key(k));
        } else if (strcmp(cmd, "insert") == 0) {
            if (!has_key(k)) {
                insert_key(k);
                printf("1\n");
            } else {
                printf("0\n");
            }
        }
    }
    return 0;
}
