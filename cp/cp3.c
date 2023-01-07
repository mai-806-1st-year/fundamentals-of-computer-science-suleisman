#include <stdio.h>
#include <math.h>

const long double k = 10e2;
const int max_iters = 100;



long double machine_eps() {
    long double eps = 1.0;
    while ((1.0 + eps) > 1.0) {
        eps/=2;
    }
    return eps;
}

long double func(long double x) {
    return exp( pow(x,2));
}

long double factorial(int n) {
    long double ans = 1;
    for (long double i = 2; i <= n; i ++) {
        ans = ans * i;
    }
    return ans;
}

int main () {
    long double ans, f;
    int n, cnt;
    printf("Машинное эпсилон для типа long double  = %.20Lf\n", machine_eps());
    printf("Введите число n\n");
    scanf("%d", &n);
    printf("n = %d, \n", n);
    long double a = 0.0;
    long double b = 1.0;
    
    printf("Таблица значений ряда Тейлора и стандартной функции для f(x) = e^(x^2)\n");
    printf("___________________________________________________________________\n");
    printf("|   x  |         sum         |      f(x)          |число итераций|\n");
    printf("___________________________________________________________________\n");
    long double x = 0;
    for (int i = 1; i <= n+1; i++) {
        long double d = 1;
        x = x+((a - b)/n);
        ans = 0;
        cnt = 1;
        f = func (x);
        while (fabs(d) >  machine_eps() * k && cnt < max_iters ) {
            d = (pow(x,2*cnt)) / (factorial(cnt));
            ans = ans + d;
            cnt++;
        }
        printf("| %.3Lf | %.20Lf | %.20Lf |      %d       |\n", x, ans, f, cnt);
        printf("___________________________________________________________________\n");
    }
    return 0;
    
}
