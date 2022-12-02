#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    int i, j, l;
} triangle;

int max(int a,int b){
    return a<b ? b:a;
}
int min(int a,int b ){
    return a>b ? b:a;
}
int sign(int a){
    return a>0?1 :a <0 ?-1:0;
}



int main(void)
{
    triangle s={20,0,11};
    for(int k=0;k<50;k++){
        triangle b={s.i,s.j,s.l};
        s.i=((b.i-k)*max(b.j,b.l)+(b.j-k)*min(b.i,b.l)+(b.l-k)*max(b.i,b.j))%23;
        s.j=-((b.i-k)*min(b.j,b.l)+(b.j-k)*max(b.i,b.l)+(b.l-k)*min(b.i,b.j))%27;
        s.l=abs(b.i+b.j-b.l-k)*sign(b.i-b.j+b.l-k);
        if(s.j<10 && s.j>=0 && s.i>=-10 && s.i<=0) {
            if(s.j>=s.i+10){
             printf("yes  %d i=%d, j=%d, l=%d\n", k, s.i, s.j,s.l);
            }
        }
        if(s.j>10 && s.j<=20 && s.i>=-10 && s.i<=0) {
            if(s.j<=-s.i+10) {
                printf("yes  %d i=%d, j=%d, l=%d\n", k, s.i, s.j,s.l);
            }
        }
        if(s.j==10 && s.i>=-10 && s.i<=0) {
             printf("yes  %f i=%d, j=%d, l=%d\n", k, s.i, s.j, s.l);
        }
    
    }
    
    
    
  return 0;
}
