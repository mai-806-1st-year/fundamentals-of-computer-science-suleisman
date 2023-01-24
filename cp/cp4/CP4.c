#include <stdio.h>
#include <math.h>

double epsilon() {
    double eps = 1.0;
    while (1 + eps / 2.0 != 1)
        eps /= 2.0;
    return eps;
}

double f_1 (double x) {
    return cos(2 / x) - 2 * sin(1 / x) + 1 / x;
}

double f_2 (double x) {
    return  sqrt(1 - (0.4 * x * x)) - asin(x);
}

double f_2_derivative(double x) {
    return -((2 * x)/(5 * sqrt(1 - 0.4 * x * x))) - (1 / sqrt(2 - x * x));
}



double dichotomy(double (*f)(double), double a, double b, double relative_eps, double eps) {
    double x = (a + b) / 2;
    if (f(a) * f(b) < 0) {
        while (fabs(a - b) > fmax(relative_eps * fmax(fabs(a), fabs(b)), eps)) {
            x = (a + b) / 2;
            if (f(x) * f(a) < 0) {
                b = x;
            }
            else {
                a = x;
            }
        }
        return x;
    }
    else {
        return NAN;
    }
}

double iterations(double (*f)(double), double (*f_derivative)(double), double a, double b, double relative_eps, double eps) {
    double x = (a + b) / 2;
    if (fabs(f_derivative(x)) < 1) 
    {
        while (fabs(f(x) - x) >= fmax(relative_eps * fmax (fabs(f(x)), fabs(x)), eps)) {
            x = f(x);
        }
        return x;
    }
    else {
        return NAN;
    }
}

int main() {
    double eps = epsilon();
    double relative_eps = sqrt(eps);
    if (dichotomy(f_1, 1, 2, relative_eps, eps) != NAN) {
        printf("%10f\n", dichotomy(f_1, 1, 2, relative_eps, eps));
    }    
    if (iterations(f_2, f_2_derivative, 0, 1, relative_eps, eps) != NAN) {
        printf("%10f\n", iterations(f_2, f_2_derivative, 0, 1, relative_eps, eps));
    }    
    return 0;
}
