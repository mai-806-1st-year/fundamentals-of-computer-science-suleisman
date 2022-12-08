#include <stdio.h>

#define N (7)


void matrix_print(size_t n, int (*mat)[n]) {


    int elem_min = mat[0][0];
    int max_j = 0;
    for(int i = 0;i < n; i++) {
        for(int j = 0 ;j < n; j++) {
            if(elem_min > mat[i][j]) {
                elem_min = mat[i][j];
                max_j = j;
            } else 
                if(elem_min == mat[i][j]) {
                    if(j > max_j) {
                        max_j = j;
                    }   

                }


        }
    
    }
    int proizv = 1;
    for(int i = 0;i < n; i++) {
        proizv = proizv*mat[i][max_j]; 
    }
    printf("%d ",proizv);



}

 






void matrix_input(size_t n, int (*mat)[n]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &mat[i][j]);
        }
    }
}


int main(void) {
    size_t n;
    scanf("%zu", &n);
    int mat[N * N];
    matrix_input(n, (int (*)[n]) mat);
    matrix_print(n, (int (*)[n]) mat);
    return 0;
}
