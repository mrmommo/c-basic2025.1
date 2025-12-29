#include <math.h>
#include <stdio.h>

int main() {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    double delta = b * b - 4 * a * c;
    if (a == 0) {
        if (b == c | c == 0) {
            printf("NO SOLUTION");
            return 0;
        }
        printf("%.2lf", -c / b);
        return 0;
    }
    if (delta < 0) {
        printf("NO SOLUTION");
        return 0;
    }
    if (delta == 0) {
        printf("%.2lf", (-b) / (2 * a));
        return 0;

    } else
        printf("%.2lf %.2lf", (-b - sqrt(delta)) / (2 * a),
               (-b + sqrt(delta)) / (2 * a));
    return 0;
}