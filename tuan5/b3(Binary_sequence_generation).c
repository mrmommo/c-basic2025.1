#include <stdio.h>

int n;
int a[25];

void print() {
    for (int i = 0; i < n; i++)
        printf("%d", a[i]);
    printf("\n");
}

void Try(int k) {
    for (int v = 0; v <= 1; v++) {
        a[k] = v;
        if (k == n - 1)
            print();
        else
            Try(k + 1);
    }
}

int main() {
    scanf("%d", &n);
    Try(0);
    return 0;
}
/*
Input
3
Output
000
001
010
011
100
101
110
111
*/