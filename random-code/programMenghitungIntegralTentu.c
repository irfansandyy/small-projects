#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

/* Definitions of useful mathematical constants (_USE_MATH_DEFINES)
 * M_E        - e
 * M_LOG2E    - log2(e)
 * M_LOG10E   - log10(e)
 * M_LN2      - ln(2)
 * M_LN10     - ln(10)
 * M_PI       - pi
 * M_PI_2     - pi/2
 * M_PI_4     - pi/4
 * M_1_PI     - 1/pi
 * M_2_PI     - 2/pi
 * M_2_SQRTPI - 2/sqrt(pi)
 * M_SQRT2    - sqrt(2)
 * M_SQRT1_2  - 1/sqrt(2)
*/

/* CARA PAKAI FUNGSI DIBAWAH
 - Masukkan fungsi matematis pada y = ... di dalam function(double x)
 - Masukkan batas bawah, batas atas, dan besar dx atau jumlah iterasi pada
   riemannSum(batas bawah, batas atas, ukuran dx (iterasi))
*/

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