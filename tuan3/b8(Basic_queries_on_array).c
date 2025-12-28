#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[10005];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    char ch;
    while ((ch = getchar()) != '*' && ch != EOF);

    char cmd[50];
    while (1) {
        scanf("%s", cmd);
        if (strcmp(cmd, "***") == 0) break;

        if (strcmp(cmd, "find-max") == 0) {
            int max = a[0];
            for (int i = 1; i < n; i++)
                if (a[i] > max) max = a[i];
            printf("%d\n", max);
        } 
        
        else if (strcmp(cmd, "find-min") == 0) {
            int min = a[0];
            for (int i = 1; i < n; i++)
                if (a[i] < min) min = a[i];
            printf("%d\n", min);
        } 
        
        else if (strcmp(cmd, "sum") == 0) {
            int s = 0;
            for (int i = 0; i < n; i++)
                s += a[i];
            printf("%d\n", s);
        } 
        
        else if (strcmp(cmd, "find-max-segment") == 0) {
            int i, j;
            scanf("%d %d", &i, &j);
            i--; 
            j--; 
            int max = a[i];
            for (int k = i + 1; k <= j; k++)
                if (a[k] > max) max = a[k];
            printf("%d\n", max);
        }
    }

    return 0;
}
