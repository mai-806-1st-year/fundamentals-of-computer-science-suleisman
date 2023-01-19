#include <stdio.h>
#include <math.h>

#define max_itter 100

const long double k = 10e2;

long double factorial (int n) {
  return (n < 2) ? 1 : n * factorial (n - 1);
}

double epsilon() {
    long double eps = 1.0;
    while (1 + eps / 2.0 != 1) {
        eps /= 2.0;
    }    
    return eps;
}

long double function(long double x) {
    return (exp( pow(x,2)));
}

long double Taylor(double x, int n) {
    long double sum = 0;
    for (long double i = 0.0; i <= n; i++) {
      sum = sum + (pow(x,2*i)) / (factorial(i));
    }
    return sum;
}

int main() {
    double abs_eps = epsilon();
    double relative_eps = sqrt(abs_eps);
    long double a = 0.0, b = 1.0, x = 0.0, result;
    int n, t;
    printf("Enter the number of iterations: ");
    scanf("%d", &n);
    printf("Machine epsilon for long double = %.16e\n", abs_eps);
    long double step = (b - a) / n;
    printf("Taylor series value table for function f(x) =e^x^2 \n");
    printf(" ________________________________________________________________________ \n");
    printf("|    x    |       sum of row       |         function       |   iter    |\n");
    printf("|_________|________________________|________________________|___________|\n");
    for (long double x = a; x <= b; x += step) {
      for (n = 0; n < max_itter; n++) {
        result = Taylor(x, n);
        if (fabs(result) <= fmax(relative_eps * fabs(result), abs_eps)) {
          break;
        }
      }
      printf("| %.5Lf | %.20Lf | %.20Lf |   %d\t|\n", x, result, function(x), n);
      result = 0.0;
    }
    printf("|_________|________________________|________________________|___________|\n");
    return 0;
}
