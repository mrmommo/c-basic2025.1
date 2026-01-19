#include <stdio.h>
#include <string.h>

int main(void) {
    char arr[20];
    char a, b;
    int i;
    if (scanf("%19s", arr) != 1) {
        return 1;
    }
    if (scanf(" %c %c", &a, &b) != 2) {
        return 1;
    }
    for (i = 0; i < (int)strlen(arr); i++) {
        if (arr[i] == a) {
            arr[i] = b;
        }
    }
    printf("%s\n", arr);
    return 0;
}
/*
- input: “papa”, ‘p’, ‘m’
- output: “mama”
*/