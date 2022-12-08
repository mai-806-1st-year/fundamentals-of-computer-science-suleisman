#include <stdio.h>
#include <stdlib.h>

enum State {
    INSIDE,
    OUTSIDE
};

int f_1();


int main(void) {
    f_1();

    return 0;
}

int f_1() {
    enum State state = INSIDE;
    char c;
   
    int i = 0;

    int sum = 0;
    int now=0;
    int now_1=0;
    int now_2=0;
   
    for(char c=getchar() ;c!='\n'; c=getchar()) {
      
        if(c!=' ') {
            switch (state) {
                case INSIDE:
                    now_1=c-'0';
                    sum=sum*10+now_1;
                    now=now + now_1;
                    state=OUTSIDE;
                    break;
                case OUTSIDE:
                    now_2=c-'0';
                    sum=sum*10+now_2;
                    now=now + now_2;
                    if(now<10) {
                        sum=sum*10+now;
                        printf("%d",sum);
                        now=0;
                        sum=0;
                    } else {
                        printf("%d",sum);
                        now=0;
                        sum=0;
                      }
                    state= INSIDE;
                    break;
                
                
            }
       } else { 
            if(sum>0) { 
                printf("%d",sum); state =INSIDE;
            }
            printf(" ");
            sum=0;
            now=0;
        
         }
       
       
   }
   if(sum>0) {
    printf("%d",sum);
   }
       
   
    
}
