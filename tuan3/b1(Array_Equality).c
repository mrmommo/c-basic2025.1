#include <stdio.h>
int arr1[1002], arr2[1002];
int main() {
    int T;
    scanf("%d", &T);
    int arr3[1001] = {0};
    int i, j;
    int dem = 0;
    for (i = 0; i < T; i++) {
        int n, m;
        scanf("%d %d", &n, &m);
        for (j = 0; j < n; j++)
            scanf("%d", &arr1[j]);
        for (j = 0; j < m; j++)
            scanf("%d", &arr2[j]);
        if (n != m) {
            arr3[i] = 0;
            continue;
        }
        for (j = 0; j < n; j++) {
            if (arr1[j] == arr2[j])
                arr3[i] = 1;
            else {
                arr3[i] = 0;
                break;
            }
        }
    }
    for (i = 0; i < T; i++)
        printf("%d\n", arr3[i]);
    return 0;
}
/*
Input
3
3 3
1 2 3
1 2 3
4 2
1 2 3 4
1 2
3 3
2 4 1
2 3 1
Output
1
0
0
*/