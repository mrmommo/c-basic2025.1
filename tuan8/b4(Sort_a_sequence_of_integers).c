#include <stdio.h>

#define MAXA 100000

int cnt[MAXA + 1];

int main() {
    int n, x;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        cnt[x]++;
    }

    int printed = 0;
    for (int v = 0; v <= MAXA; v++) {
        while (cnt[v] > 0) {
            printf("%d", v);
            printed++;
            if (printed < n)
                printf(" ");
            cnt[v]--;
        }
    }
    return 0;
}
/*
Input
4
1 3 4 2
Output
1 2 3 4
*/