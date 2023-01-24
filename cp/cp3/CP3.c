#include <stdio.h>
#include <math.h>

#define max_itter 100

double epsilon() {
    long double eps = 1.0;
    while (1 + eps / 2.0 != 1) {
        eps /= 2.0;
    }    
    return eps;
}

long double function(long double x) {
    return exp(x * x);
}

long double taylor(double x, int n, double eps) {
    long double sum = 0;
    long double p = 1;
    for (int i = 1; i <= n; i++) {
        if (fabs(p) <= fmax(sqrt(eps) * fabs(sum), eps)) {
            break;
        }
        sum += p;
        p *= (x * x) / i;   
    }
    return sum;
}

int main() {
    double eps = epsilon();
    long double a = 0.0, b = 1.0, result;
    int n;
    printf("Machine epsilon for long double = %.16e\n", eps);
    printf("Enter the number of iterations: ");
    scanf("%d", &n);
    long double step = (b - a) / n;
    printf("Taylor series value table for function f(x) =e^x^2 \n");
    printf(" ________________________________________________________________________ \n");
    printf("|    x    |           sum          |         function       |   iter    |\n");
    printf("|_________|________________________|________________________|___________|\n");
    for (long double x = a; x <= b; x += step) {
        result = taylor(x, max_itter, eps);
        printf("| %.5Lf | %.20Lf | %.20Lf |   %d\t|\n", x, result, function(x), n);
        result = 0.0;
    }
    printf("|_________|________________________|________________________|___________|\n");
    return 0;
}
