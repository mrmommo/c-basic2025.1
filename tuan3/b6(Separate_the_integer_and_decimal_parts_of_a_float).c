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
/*
Input
2.57902
Output
2 0.58

Input
-4.3456
Output
-5 0.65
*/