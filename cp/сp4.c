#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*int main(void) {

    int t;
    scanf( "%d", &t);
    for( int j=0;j<t;j++) {
        int n;
        scanf("%d",&n);
        int v[n];
        int sum=0;
        int k=0;
        int ans = 100000000; 
        for(int i=0;i<n;i++) {
            scanf("%d", &v[i]);
            sum = sum + v[i];
        }
        if(sum %2==0) {
            printf("%d\n", k);
        } 


        if (sum % 2!=0) {
            for (int i =0;i < n;i++) {
                int tek = v[i]; k=0;
                if (v[i]%2 == 0) {
                    while (tek %2 == 0 ) {
                        k++;
                        tek = tek/2;
                    }
                    if (k < ans) {
                        ans = k;
                    }
                }
                if( v[i] %2 != 0) {
                    while (tek %2 != 0) {
                        k++;
                        tek = tek/2;
                    }
                    if(k < ans) {
                        ans = k;
                    }
                }
            }
            printf("%d\n",ans);    
        }
    
    }
}*/


double F ( double x) {
    return cos(2/x) - 2*sin(1/x) + 1/x;
}

double dichotomy( double f( double ), double a, double b, double eps) {
    double x;
    while (fabs(a - b) > eps) {
        x = (a + b) / 2;
        if (f(x) * f(a) < 0) {
            b = x;
        } else {
            a = x;
        }
    }
    return (a+b)/2;
}

double eps() {
    double eps = 1;
    while (1 + eps/2 > 1) {
        eps /= 2;
    }
    return eps;
}


int main () {
     printf(" %11.7f\n", dichotomy(F, 1, 2, eps()));
}
