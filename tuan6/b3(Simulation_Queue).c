// Perform a sequence of operations over a queue, each element is an integer:
// PUSH v: push a value v into the queue
// POP: remove an element out of the queue and print this element to stdout
// (print NULL if the queue is empty) Input Each line contains a command
// (operration) of type PUSH  v POP Output Write the results of POP operations
// (each result is written in a line)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int queue[MAX];
int front = 0, rear = 0;

void push(int v) {
    if (rear < MAX) {
        queue[rear++] = v;
    }
}

void pop() {
    if (front < rear) {
        printf("%d\n", queue[front++]);
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
1
2
3

Input
PUSH 1
POP
POP
PUSH 4
POP
#
Output
1
NULL
4
*/