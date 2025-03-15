#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846

double function(double x) {
    double y = (sqrt(sin(x)))/(sqrt(sin(x))+sqrt(cos(x)));
    return y;
}

double riemannSum(double a, double b, double n) {
    printf("i\t xi\t\t f(xi)\n");
    double dx = (b-a)/n;
    double sum = 0;
    for(int i = 0; i < n; i++) {
        sum += function(a + dx*i);
        printf("%d\t %lf\t %lf\n", i, a + dx*i, function(a + dx*i));
    }
    return sum*dx;
}

int main() {
    printf("\nHasil Riemann Sum: %lf", riemannSum(0, M_PI/2, 100)); 
    return 0;
}