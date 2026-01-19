#include <stdio.h>

int main() {
    char ch;
    int i = 0, inword = 0;
    while ((ch = getchar()) != EOF) {
        if (ch == ' ' || ch == '\n' || ch == '\t')
            inword = 0;
        else {
            if (inword == 0) {
                i++;
                inword = 1;
            }
        }
    }
    printf("%d", i);
    return 0;
}
/*
Input
Hanoi University Of Science and Technology
School of Information and Communication Technology


Output
12
*/