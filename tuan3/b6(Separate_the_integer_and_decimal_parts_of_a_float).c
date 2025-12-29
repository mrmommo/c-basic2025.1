#include <stdio.h>
int main() {
    double a;
    scanf("%lf", &a);
    int b = (int)a;
    if (b > a)
        b -= 1;
    double c = a - b;
    printf("%d %.2f", b, c);
    return 0;
}