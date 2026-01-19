#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 1000003

typedef struct Node {
    char key[51];
    struct Node *next;
} Node;

Node *hash_table[HASH_SIZE];

long long hash_func(char *s) {
    long long h = 0;
    for (int i = 0; s[i]; i++) {
        h = (h * 256LL + s[i]) % HASH_SIZE;
    }
    return h;
}

int has_key(char *k) {
    long long h = hash_func(k);
    Node *node = hash_table[h];
    while (node) {
        if (strcmp(node->key, k) == 0)
            return 1;
        node = node->next;
    }
    return 0;
}

void insert_key(char *k) {
    long long h = hash_func(k);
    Node *node = (Node *)malloc(sizeof(Node));
    strcpy(node->key, k);
    node->next = hash_table[h];
    hash_table[h] = node;
}

int main() {
    char line[100];
    while (fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\n")] = 0;
        if (strcmp(line, "*") == 0)
            break;
        insert_key(line);
    }
    while (fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\n")] = 0;
        if (strcmp(line, "***") == 0)
            break;
        char cmd[10];
        char k[51];
        sscanf(line, "%s %s", cmd, k);
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
/*
Input
computer
university
school
technology
phone
*
find school
find book
insert book
find algorithm
find book
insert book
***
Output
1
0
1
0
1
0
*/