
/*
6
11 12 13 14 15 16
21 22 23 24 25 26
31 32 33 34 35 36
41 42 43 44 45 46
51 52 53 54 55 56
61 62 63 64 65 66

8
11 12 13 14 15 16 17 18
21 22 23 24 25 26 27 28 
31 32 33 34 35 36 37 38
41 42 43 44 45 46 47 48
51 52 53 54 55 56 57 58
61 62 63 64 65 66 67 68
71 72 73 74 75 76 77 78
81 82 83 84 85 86 87 88

4
11 12 13 14 
21 22 23 24 
31 32 33 34 
41 42 43 44 


14 11 41 44

13 23 24   21 22 12    42 32 31    34 33 43
*/


#include <stdio.h>

#define N (8)

enum State {
    right_up,
    right_down,
    left_down,
    left_up,
};

void matrix_print(size_t n, int (*mat)[n]) {

    enum State state = right_up;
    int k = 1;
    int i=0, j = n-1;
    while (k != (n/2)+1 ) {
        switch ( state ) {
            case right_up:
                while(i != k - 1 ) {
                    printf("%d ", mat[i][j]);
                    i++;
                }
                while(j != n ) {
                    printf("%d ", mat[i][j]);
                    j++;
                }
                state = left_up;
                j = 0;
                break;
            case left_up:
                while(j != k - 1 ) {
                        printf("%d ", mat[i][j]);
                        j++;
                    }
                
                 while(i != -1 ) {
                        printf("%d ", mat[i][j]);
                        i--;
                    }
                state = left_down;
                i = n - 1;
                break;
            case left_down:
                while(i != n - k ) {
                        printf("%d ", mat[i][j]);
                        i--;
                    }
                while(j != -1 ) {
                        printf("%d ", mat[i][j]);
                        j--;
                    }
                j = n - 1;
                state = right_down;
                break;
            case right_down:
                while(j != n - k ) {
                        printf("%d ", mat[i][j]);
                        j--;
                    }
                while(i != n ) {
                        printf("%d ", mat[i][j]);
                        i++;
                    }
                k = k + 1;
                i = 0;
                j = j - 1; 
                state = right_up;
                break;                    
        }
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
