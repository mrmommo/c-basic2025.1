#include <stdio.h>
int n;
void Binary(int n) {
    if (n == 0) {
        printf("0");
    } else if (n == 1) {
        printf("1");
    } else {
        Binary(n / 2);
        printf("%d", n % 2);
    }
}

int main() {
    scanf("%d", &n);
    Binary(n);
    return 0;
}
/*
Input
20

Output
10100
*/