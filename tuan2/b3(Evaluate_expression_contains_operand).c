#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

char math[1000001];
long long num[1000001] = {0};
char op[100001];

int main() {
    fgets(math, 1000001, stdin);
    math[strcspn(math, "\n")] = '\0';
    int length = strlen(math);

    if (math[0] == '+' || math[0] == '*' || math[length - 1] == '+' ||
        math[length - 1] == '*') {
        printf("NOT_CORRECT");
        return 0;
    }

    for (int i = 0; i < length - 1; i++) {
        if ((math[i] == '*' || math[i] == '+') &&
            (math[i + 1] == '*' || math[i + 1] == '+')) {
            printf("NOT_CORRECT");
            return 0;
        }
    }

    char *ptr = math;
    int dem1 = 0, dem2 = 0;
    while (*ptr != '\0') {
        num[dem1++] = strtol(ptr, &ptr, 10);
        if (*ptr != '\0') {
            op[dem2++] = *ptr;
            ptr++;
        }
    }

    long long sum = 0;
    long long current = num[0];
    for (int i = 0; i < dem2; i++) {
        if (op[i] == '*') {
            current = (current * num[i + 1]) % MOD;
        } else {
            sum = (sum + current) % MOD;
            current = num[i + 1];
        }
    }
    sum = (sum + current) % MOD;

    printf("%lld", sum);
    return 0;
}
/*
Input
5+7*3*10*10
Output
2105
Input
5*+ 7*3*10*10
Output
NOT_CORRECT
*/