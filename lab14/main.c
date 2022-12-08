#include <stdio.h>

#define N (7)

enum State {
    up,
    down,
    right,
    left
};

void matrix_print(size_t n, int (*mat)[n]) {



    enum State state=up;
        int v[4] = {0, 1, 0, -1};
        int k=n;
        int a = k;
        int p = 0;
        int i = n, j = 0;
        while(a != 0){
            for(int x = 0; x != a; x++ ) {
                j = j + v[p%4];
                i = i + v[(p+3)%4];
                printf("%d ", mat[i][j]);
            }
            p++;
            a = a - p%2;


   
     
        }
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
