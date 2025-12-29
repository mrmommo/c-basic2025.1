// push
// pop
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max 100
//
int stack[Max];
int top = 0;
void push(int v) {
    if (top < Max) {
        stack[top++] = v;
    }
}
void pop() {
    if (top > 0) {
        printf("%d\n", stack[--top]);
    } else
        printf("NULL\n");
}
int main() {
    char line[100];
    while (fgets(line, sizeof(line), stdin)) {
        if (line[0] == '#')
            break;
        if (!strncmp(line, "PUSH", 4)) {
            int v;
            sscanf(line + 5, "%d", &v);
            push(v);
        } else if (!strncmp(line, "POP", 3)) {
            pop();
        }
    }
    return 0;
}