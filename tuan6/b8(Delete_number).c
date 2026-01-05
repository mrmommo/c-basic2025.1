#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 120000
char stack[120002];
int top = 0;
// stack
void push(char num) {
    if (top < max) {
        stack[top++] = num;
    }
    return;
}
void pop() {
    if (top > 0) {
        top--;
    }
    return;
}
//
int main() {
    char line[120002];
    fgets(line, sizeof(line), stdin);
    int len = strlen(line);
    if (line[len - 1] == '\n')
        len--;
    int k;
    scanf("%d", &k);
    for (int j = 0; j < len; j++) {
        while (k > 0 && top > 0 && stack[top - 1] > line[j]) {
            pop();
            k--;
        }
        push(line[j]);
    }
    while (k > 0 && top > 0) {
        pop();
        k--;
    }
    for (int i = 0; i < top; i++) {
        printf("%c", stack[i]);
    }
    return 0;
}