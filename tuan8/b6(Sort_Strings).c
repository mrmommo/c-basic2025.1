#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comparator function for qsort
int cmp(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int n;
    scanf("%d", &n);

    // Allocate array of string pointers
    char **arr = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        arr[i] = (char *)malloc(105 * sizeof(char)); // assuming max length ~100
        scanf("%s", arr[i]);
    }

    // Sort using qsort
    qsort(arr, n, sizeof(char *), cmp);

    // Print sorted strings
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
        free(arr[i]); // free each string
    }
    free(arr); // free array of pointers

    return 0;
}
/*
Input
10
O0001
Z002
R003
R00004
P05
P00006
T0007
X08
N09
I010

Output
I010
N09
O0001
P00006
P05
R00004
R003
T0007
X08
Z002
*/