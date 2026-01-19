#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000005

char stack[MAX];
int top = -1;

int isMatching(char open, char close) {
    return (open == '(' && close == ')') || (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

int isBalanced(const char *str) {
    for (int i = 0; str[i]; i++) {
        char ch = str[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            stack[++top] = ch;
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (top == -1 || !isMatching(stack[top], ch)) {
                return 0;
            }
            top--;
        }
    }
    return top == -1;
}

int main() {
    char str[MAX];
    if (scanf("%s", str) == 1) {
        printf("%d\n", isBalanced(str));
    }
    return 0;
}
/*
input
(()[][]{}){}{}[][]({[]()})
output
1
*/