#include <stdio.h>
#include <math.h>
#include <gmp.h>

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

long double function(long double x) {
    long double y = exp(-x);
    return y;
}

long double nth_derivative(long double (*func)(long double), long double x, int n, long double h) {
    if (n == 0) {
        return func(x);
    } else if (n == 1) {
        return (func(x + h) - func(x - h)) / (2 * h);
    } else {
        long double sum = 0;
        for (int k = 0; k <= n; k++) {
            sum += pow(-1, k) * factorial(n) / (factorial(k) * factorial(n - k)) * func(x + (n / 2.0 - k) * h);
        }
        return sum / pow(h, n);
    }
}

long double taylorApproximation(long double (*func)(long double), long double reference, long double target, int n, long double h) {
    long double sum = 0;
    for (int i = 0; i <= n; i++) {
        long double term = nth_derivative(func, reference, i, h) * pow(target - reference, i) / factorial(i);
        sum += term;
        printf("Term %d: %Lf\n", i, term);
    }
    return sum;
}

int main() {
    long double h = 1e-4;
    int n = 10;
    long double x = 2;
    long double a = 1;
    long double result = taylorApproximation(function, a, x, n, h);
    printf("The taylor approximation of the function at x = %Lf for f(%Lf) is %Lf\n", a, x, result);
    return 0;
}