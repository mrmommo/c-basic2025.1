#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HASH_SIZE 1000003

typedef struct Node {
    char word[21];
    int count;
    struct Node* next;
} Node;

Node* hash_table[HASH_SIZE];

long long hash_func(char* s) {
    long long h = 0;
    for(int i = 0; s[i]; i++) {
        h = (h * 256LL + s[i]) % HASH_SIZE;
    }
    return h;
}

Node* has_key(char* k) {
    long long h = hash_func(k);
    Node* node = hash_table[h];
    while(node) {
        if(strcmp(node->word, k) == 0) return node;
        node = node->next;
    }
    return NULL;
}

void insert_key(char* k) {
    long long h = hash_func(k);
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->word, k);
    node->count = 1;
    node->next = hash_table[h];
    hash_table[h] = node;
}

int cmp(const void* a, const void* b) {
    Node* na = *(Node**)a;
    Node* nb = *(Node**)b;
    return strcmp(na->word, nb->word);
}

int main() {
    char buffer[1000000];
    int len = 0;
    char line[1000];
    while(fgets(line, sizeof(line), stdin)) {
        strcpy(buffer + len, line);
        len += strlen(line);
    }
    buffer[len] = 0;
    char* p = buffer;
    char word[21];
    int i = 0;
    while(*p) {
        if(isalnum(*p)) {
            if(i < 20) {
                word[i++] = *p;
            }
        } else {
            if(i > 0) {
                word[i] = 0;
                Node* node = has_key(word);
                if(node) {
                    node->count++;
                } else {
                    insert_key(word);
                }
                i = 0;
            }
        }
        p++;
    }
    if(i > 0) {
        word[i] = 0;
        Node* node = has_key(word);
        if(node) {
            node->count++;
        } else {
            insert_key(word);
        }
    }
    Node* all_words[10000];
    int num_words = 0;
    for(int j = 0; j < HASH_SIZE; j++) {
        Node* node = hash_table[j];
        while(node) {
            all_words[num_words++] = node;
            node = node->next;
        }
    }
    qsort(all_words, num_words, sizeof(Node*), cmp);
    for(int j = 0; j < num_words; j++) {
        printf("%s %d\n", all_words[j]->word, all_words[j]->count);
    }
    return 0;
}
