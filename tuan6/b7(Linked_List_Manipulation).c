#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int key;
    struct Node *next;
} Node;

Node *head = NULL;

// Kiểm tra xem một giá trị đã tồn tại trong danh sách chưa
int exists(int key) {
    Node *p = head;
    while (p) {
        if (p->key == key)
            return 1;
        p = p->next;
    }
    return 0;
}

// Thêm vào đầu danh sách
void addFirst(int key) {
    if (exists(key))
        return;
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = head;
    head = newNode;
}

// Thêm vào cuối danh sách
void addLast(int key) {
    if (exists(key))
        return;
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;
    if (!head) {
        head = newNode;
        return;
    }
    Node *p = head;
    while (p->next)
        p = p->next;
    p->next = newNode;
}

// Thêm sau phần tử có key = afterKey
void addAfter(int key, int afterKey) {
    if (exists(key))
        return;
    Node *p = head;
    while (p && p->key != afterKey)
        p = p->next;
    if (!p)
        return;
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = p->next;
    p->next = newNode;
}

// Thêm trước phần tử có key = beforeKey
void addBefore(int key, int beforeKey) {
    if (exists(key))
        return;
    if (!head)
        return;
    if (head->key == beforeKey) {
        addFirst(key);
        return;
    }
    Node *prev = NULL;
    Node *curr = head;
    while (curr && curr->key != beforeKey) {
        prev = curr;
        curr = curr->next;
    }
    if (!curr)
        return;
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = curr;
    prev->next = newNode;
}

// Xóa phần tử có key = key
void removeKey(int key) {
    if (!head)
        return;
    if (head->key == key) {
        Node *tmp = head;
        head = head->next;
        free(tmp);
        return;
    }
    Node *prev = NULL;
    Node *curr = head;
    while (curr && curr->key != key) {
        prev = curr;
        curr = curr->next;
    }
    if (!curr)
        return;
    prev->next = curr->next;
    free(curr);
}

// Đảo ngược danh sách
void reverse() {
    Node *prev = NULL;
    Node *curr = head;
    while (curr) {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

// In danh sách
void printList() {
    Node *p = head;
    while (p) {
        printf("%d", p->key);
        if (p->next)
            printf(" ");
        p = p->next;
    }
    printf("\n");
}

int main() {
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        addLast(x);
    }

    char cmd[50];
    while (scanf("%s", cmd) && strcmp(cmd, "#") != 0) {
        if (strcmp(cmd, "addlast") == 0) {
            int k;
            scanf("%d", &k);
            addLast(k);
        } else if (strcmp(cmd, "addfirst") == 0) {
            int k;
            scanf("%d", &k);
            addFirst(k);
        } else if (strcmp(cmd, "addafter") == 0) {
            int u, v;
            scanf("%d %d", &u, &v);
            addAfter(u, v);
        } else if (strcmp(cmd, "addbefore") == 0) {
            int u, v;
            scanf("%d %d", &u, &v);
            addBefore(u, v);
        } else if (strcmp(cmd, "remove") == 0) {
            int k;
            scanf("%d", &k);
            removeKey(k);
        } else if (strcmp(cmd, "reverse") == 0) {
            reverse();
        }
    }

    printList();
    return 0;
}
/*
Input
5
5 4 3 2 1
addlast 3
addlast 10
addfirst 1
addafter 10 4
remove 1
#

Output
5 4 3 2 10
*/