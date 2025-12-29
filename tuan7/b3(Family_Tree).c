#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[50];
    struct Node *children[100];
    int childCount;
} Node;

#define MAXN 10005
Node *nodes[MAXN];
int nodeCount = 0;
Node *getNode(char *name) {
    for (int i = 0; i < nodeCount; i++) {
        if (strcmp(nodes[i]->name, name) == 0)
            return nodes[i];
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->childCount = 0;
    nodes[nodeCount++] = newNode;
    return newNode;
}
int countDescendants(Node *root) {
    if (!root)
        return 0;
    int total = root->childCount;
    for (int i = 0; i < root->childCount; i++) {
        total += countDescendants(root->children[i]);
    }
    return total;
}
int countGenerations(Node *root) {
    if (!root || root->childCount == 0)
        return 0;
    int maxGen = 0;
    for (int i = 0; i < root->childCount; i++) {
        int g = countGenerations(root->children[i]);
        if (g > maxGen)
            maxGen = g;
    }
    return 1 + maxGen;
}

int main() {
    char child[50], parent[50];
    char cmd[20], param[50];
    while (scanf("%s", child)) {
        if (strcmp(child, "***") == 0)
            break;
        scanf("%s", parent);
        Node *cNode = getNode(child);
        Node *pNode = getNode(parent);
        pNode->children[pNode->childCount++] = cNode;
    }
    while (scanf("%s", cmd)) {
        if (strcmp(cmd, "***") == 0)
            break;
        scanf("%s", param);
        Node *node = getNode(param);

        if (strcmp(cmd, "descendants") == 0) {
            printf("%d\n", countDescendants(node));
        } else if (strcmp(cmd, "generation") == 0) {
            printf("%d\n", countGenerations(node));
        }
    }

    return 0;
}
