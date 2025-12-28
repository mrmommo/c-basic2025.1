#include <stdio.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        char str[201];
        scanf("%s", str);
        long long hash = 0;
        for(int j = 0; str[j]; j++) {
            hash = (hash * 256LL + str[j]) % m;
        }
        printf("%lld\n", hash);
    }
    return 0;
}
