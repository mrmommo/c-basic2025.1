#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX 1000

int stack[MAX];
int top = -1;

void push(int v) {
    if (top < MAX - 1) {
        stack[++top] = v;
    }
}

void pop() {
    if (top >= 0) {
        printf("%d\n", stack[top--]);
    } else {
        printf("NULL\n");
    }
}

int main() {
    char line[100];
    while (fgets(line, sizeof(line), stdin)) {
        if (line[0] == '#')
            break;

        if (strncmp(line, "PUSH", 4) == 0) {
            int v;
            sscanf(line + 5, "%d", &v);
            push(v);
        } else if (strncmp(line, "POP", 3) == 0) {
            pop();
        }
    }
    return 0;
}
/*
Input
PUSH 1
PUSH 2
PUSH 3
POP
POP
PUSH 4
PUSH 5
POP
#
Output
3
2
5
*/