#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX 1000000
int main() {
    char arr[MAX];
    while (fgets(arr, MAX, stdin)) {
        int i;
        int k = 'A' - 'a';
        for (i = 0; i < strlen(arr); i++) {
            if ('a' <= arr[i] && arr[i] <= 'z')
                arr[i] += k;
        }
        printf("%s", arr);
    }
    return 0;
}