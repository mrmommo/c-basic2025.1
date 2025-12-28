#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 1000003

typedef struct Node {
    long long key;
    struct Node* next;
} Node;

Node* hash_table[HASH_SIZE];

long long hash_func(long long key) {
    return (key % HASH_SIZE + HASH_SIZE) % HASH_SIZE;
}

int has_key(long long key) {
    long long h = hash_func(key);
    Node* node = hash_table[h];
    while(node) {
        if(node->key == key) return 1;
        node = node->next;
    }
    return 0;
}

void insert(long long key) {
    long long h = hash_func(key);
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->next = hash_table[h];
    hash_table[h] = node;
}

int main() {
    int n;
    scanf("%d", &n);
    long long* a = (long long*)malloc(n * sizeof(long long));
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for(int i = 0; i < n; i++) {
        if(has_key(a[i])) {
            printf("1\n");
        } else {
            printf("0\n");
        }
        insert(a[i]);
    }
    free(a);
    return 0;
}
