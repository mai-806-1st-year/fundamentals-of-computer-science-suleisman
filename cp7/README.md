# Отчет по курсовой работе №7 по курсу "Фундументальня информатика" 
<b>Студент группы:</b> <ins>М80-108Б-22 Шелаев Серафим Ильич, номер по списку 23</ins>  
<b>Контакты e mail:</b> <ins>serafimshelaev@mail.ru</ins>  
<b>Работа выполнена:</b> «11» <ins>июля</ins> <ins>2023</ins> г.
<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins>3 (удовлетворительно)</ins>

<b>Отчет сдан</b> «11» <ins>июля</ins> <ins>2022</ins> г., <b>итоговая оценка</b>3 <ins> (удовлетворительно)</ins>                                                          

<b>Подпись преподавателя:</b> ________________
## 1. Тема
Разреженные матрицы  
## 2. Цель работы
Составить программу на языке Си с процедурами и/или функциями для обработки прямоугольных разреженных матриц
## 3. Задание 
Составить программу на языке Си с процедурами и/или функциями для обработки прямоугольных разреженных матриц с
элементами целого (группы 6, 8), вещественного (группы 2-5), или комплексного (группы 1, 7) типов, которая:
1. вводит матрицы различного размера, представленные во входном текстовом файле в обычном формате (по строкам),
с одновременным размещением ненулевых элементов в разреженной матрице в соответствии с заданной схемой;
2. печатает введенные матрицы во внутреннем представлении согласно заданной схеме размещения и в обычном
(естественном) виде;
3. выполняет необходимые преобразования разреженных матриц (или вычисления над ними) путем обращения к
соответствующим процедурам и/или функциям;
4. печатает результат преобразования (вычисления) согласно заданной схеме размещения и в обычном виде
5. Умножить вектор-строку на разреженную матрицу и вычислить количество ненулевых элементов результата.

## 4. Оборудование:
ноутбук  Asus Vivobook 15(1920x1080, Intel Core i5 2.4 ГГц, RAM 16 ГБ, SSD 512 ГБ, Windows 11 Home)
## 5. Программное обеспечение:
<b>Операционная система семейства:</b> Microsoft Windows 11<br/> 
<b>Компилятор:</b> GNU Compiler Collection<br/>
<b>Текстовый редактор:</b> Visual Studio Code версия 1.73.0<br/>
## 6. Идея, метод, алгоритм решения задачи (в формах: словесной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)
Сначала сортируем стек с помощью двух дополнительных стеков в итоге на вершине получаем максимальный элемент и затем удаляем его.     
 
## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию]. 
main.c

```.c
#include <stdlib.h>
#include <stdio.h>

#include "matrix.h"

void printMenu() {
    printf(
           "1 - print simple matrix\n"
           "2 - print matrix\n"
           "3 - multiplication\n" 
           "4 - exit\n");
}



int main(int argc, char* argv[]) {
    FILE *file;
    
    if (argc == 2) {
        file = fopen(argv[1], "r");
    } else {
          file = fopen("t.txt", "r");
      }
    Matrix matrix;
    matrixCreate(&matrix);
    matrixScan(file, &matrix);
    printMenu();
    int a;
    while (1) {
        scanf("%d", &a);
       
        if (a == 1) {
            matrixPrint(&matrix);
        } else if (a == 2) {
              matrixPrintTable(&matrix); 
          } else if (a == 3) {

                size_t *arr[2];
                matrixGetSize(&matrix, arr);
                size_t n = *arr[0];
                int string[n];
                printf("enter vector (1x%ld)   ", n);
                for (int i = 0; i < n; ++i) 
                scanf("%d", &string[i]);
                func(&matrix, string);
            } else if (a == 4) {
                  matrixDestroy(&matrix);
                  fclose(file);
                  break;
              } else printf("incorrect parametr\n");
                             
    }
}

```
matrix.c

```.c
#include <stdlib.h>
#include <stdio.h>

#include "matrix.h"

void matrixCreate(Matrix *matrix) {
    matrix->n = 0;
    matrix->m = 0;
    matrix->size = 0;
    matrix->ye = NULL;
    matrix->lb = NULL;
    
}

void matrixDestroy(Matrix *matrix) {
    free(matrix->lb);
    free(matrix->ye);
    matrix->n = 0;
    matrix->m = 0;
    matrixCreate(matrix);
    
}

void matrixResize(Matrix *matrix) {
    if (matrix->size == 0) {
        matrix->size =1;
        
        matrix->ye = malloc(sizeof(int));
        matrix->lb = malloc(sizeof(int)*2);
        matrix->lb[0] = -1;
        
    }
    else {
        matrix->size = matrix->size * 2;
        
        matrix->ye = realloc(matrix->ye, sizeof(int)*matrix->size);
        matrix->lb = realloc(matrix->lb, sizeof(int)*(matrix->size + 1));
    }
}

void matrixSet(Matrix *matrix, int val, int i, int j) {
    int k = 0;

    if (matrix->size == 0) matrixResize(matrix);

    for(k = 0; k < matrix->size; ++k)
        if (matrix->lb[k] == -1) {
            break;
        }

    if (k == matrix->size) {
        matrixResize(matrix);
    }

    matrix->lb[k] = i*matrix->m + j;
    matrix->lb[k + 1]= -1;
    
    matrix->ye[k] = val;
}


int matrixGet(Matrix *matrix, size_t i, size_t j) {
    for (int k = 0; matrix->lb[k] != -1; ++k) {
        if (matrix->lb[k] == i * matrix->m + j) {
            return matrix->ye[k];
            
        }
    }
    
    return 0;
}

void matrixScan(FILE *file, Matrix *matrix) {
    fscanf(file, "%ld %ld", &matrix->n, &matrix->m);
    int val;
    for (int k = 0; k < matrix->n*matrix->m; ++k) {
        fscanf(file, "%d", &val);
        
        if (val != 0) {
            matrixSet(matrix, val, k / matrix->m, k % matrix->m);
            
        }
    }
}

void matrixPrint(Matrix *matrix) {
    for(int i = 0; i < matrix->size; ++i) {
    
        if (matrix->lb[i] == -1) {
            break;
        }
        
        printf("(%d %d)\n", matrix->lb[i], matrix->ye[i]);
    }
}

void matrixGetSize(Matrix *matrix, size_t** arr) {

    arr[0] = &matrix->n;
    arr[1] = &matrix->m;
}

void func(Matrix *matrix, int* arr) {

    int result[matrix->m];
    int v;
    
    int count = 0;
    printf("res = (");
    for (int i = 0; i < matrix->m; ++i) {
        v = 0;
        
        for (int j = 0; j < matrix->n; ++j) {
            int val = matrixGet(matrix, j, i);
            v = v + (val * arr[j]);
        }
        result[i] = v;
        printf(" %d", result[i]);
        
        if (result[i] > 0){
            ++count;
        }
    }
    printf(" ) count = %d\n", count);
}

void matrixPrintTable(Matrix *matrix) {
    
    for(size_t i = 0; i < matrix->n; ++ i) {
    
        for(size_t j = 0; j < matrix->m; ++j) 
        
            printf("%d ", matrixGet(matrix, i, j));
            
            
        printf("\n");
    }
}#include <stdlib.h>
#include <stdio.h>

#include "matrix.h"

void matrixCreate(Matrix *matrix) {
    matrix->n = 0;
    matrix->m = 0;
    matrix->size = 0;
    matrix->ye = NULL;
    matrix->lb = NULL;
    
}

void matrixDestroy(Matrix *matrix) {
    free(matrix->lb);
    free(matrix->ye);
    matrix->n = 0;
    matrix->m = 0;
    matrixCreate(matrix);
    
}

void matrixResize(Matrix *matrix) {
    if (matrix->size == 0) {
        matrix->size =1;
        
        matrix->ye = malloc(sizeof(int));
        matrix->lb = malloc(sizeof(int)*2);
        matrix->lb[0] = -1;
        
    }
    else {
        matrix->size = matrix->size * 2;
        
        matrix->ye = realloc(matrix->ye, sizeof(int)*matrix->size);
        matrix->lb = realloc(matrix->lb, sizeof(int)*(matrix->size + 1));
    }
}

void matrixSet(Matrix *matrix, int val, int i, int j) {
    int k = 0;

    if (matrix->size == 0) matrixResize(matrix);

    for(k = 0; k < matrix->size; ++k)
        if (matrix->lb[k] == -1) {
            break;
        }

    if (k == matrix->size) {
        matrixResize(matrix);
    }

    matrix->lb[k] = i*matrix->m + j;
    matrix->lb[k + 1]= -1;
    
    matrix->ye[k] = val;
}


int matrixGet(Matrix *matrix, size_t i, size_t j) {
    for (int k = 0; matrix->lb[k] != -1; ++k) {
        if (matrix->lb[k] == i * matrix->m + j) {
            return matrix->ye[k];
            
        }
    }
    
    return 0;
}

void matrixScan(FILE *file, Matrix *matrix) {
    fscanf(file, "%ld %ld", &matrix->n, &matrix->m);
    int val;
    for (int k = 0; k < matrix->n*matrix->m; ++k) {
        fscanf(file, "%d", &val);
        
        if (val != 0) {
            matrixSet(matrix, val, k / matrix->m, k % matrix->m);
            
        }
    }
}

void matrixPrint(Matrix *matrix) {
    for(int i = 0; i < matrix->size; ++i) {
    
        if (matrix->lb[i] == -1) {
            break;
        }
        
        printf("(%d %d)\n", matrix->lb[i], matrix->ye[i]);
    }
}

void matrixGetSize(Matrix *matrix, size_t** arr) {

    arr[0] = &matrix->n;
    arr[1] = &matrix->m;
}

void func(Matrix *matrix, int* arr) {

    int result[matrix->m];
    int v;
    
    int count = 0;
    printf("res = (");
    for (int i = 0; i < matrix->m; ++i) {
        v = 0;
        
        for (int j = 0; j < matrix->n; ++j) {
            int val = matrixGet(matrix, j, i);
            v = v + (val * arr[j]);
        }
        result[i] = v;
        printf(" %d", result[i]);
        
        if (result[i] > 0){
            ++count;
        }
    }
    printf(" ) count = %d\n", count);
}

void matrixPrintTable(Matrix *matrix) {
    
    for(size_t i = 0; i < matrix->n; ++ i) {
    
        for(size_t j = 0; j < matrix->m; ++j) 
        
            printf("%d ", matrixGet(matrix, i, j));
            
            
        printf("\n");
    }
}
```
matrix.h

```.h
#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>
#include <stdio.h>

typedef struct {
    size_t n, m, size;
    int *lb;
    int *ye;
} Matrix;

void matrixCreate(Matrix *matrix);

void matrixDestroy(Matrix *matrix);

void matrixScan(FILE *file, Matrix *matrix);

void matrixPrint(Matrix *matrix);

void matrixPrintTable(Matrix *matrix);

void matrixResize(Matrix *matrix);

void matrixSet(Matrix *matrix, int val, int i, int j);

int matrixGet(Matrix *matrix, size_t i, size_t j);

void matrixGetSize(Matrix *matrix, size_t **arr);

void func(Matrix *matrix, int* arr);

#endif // MATRIX_H
```
## 8. Протокол 
```
serafim@serafim-VirtualBox:~/programs/kp7$ valgrind ./kp7 t.txt
==4233== Memcheck, a memory error detector
==4233== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==4233== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==4233== Command: ./kp7 t.txt
==4233== 
1 - print simple matrix
2 - print matrix
3 - multiplication
4 - exit
1
(9 8)
(12 2)
(17 6)
(31 7)
(34 8)
2
0 0 0 0 0 0 0 
0 0 8 0 0 2 0 
0 0 0 6 0 0 0 
0 0 0 0 0 0 0 
0 0 0 7 0 0 8 
0 0 0 0 0 0 0 
3
enter vector (1x6)   1 3 5 6 9 4
res = ( 0 0 24 93 0 6 72 ) count = 4
4
==4233== 
==4233== HEAP SUMMARY:
==4233==     in use at exit: 0 bytes in 0 blocks
==4233==   total heap usage: 12 allocs, 12 frees, 6,752 bytes allocated
==4233== 
==4233== All heap blocks were freed -- no leaks are possible
==4233== 
==4233== For lists of detected and suppressed errors, rerun with: -s
==4233== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
serafim@serafim-VirtualBox:~/programs/kp7$ valgrind ./kp7 t2.txt
==4257== Memcheck, a memory error detector
==4257== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==4257== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==4257== Command: ./kp7 t2.txt
==4257== 
1 - print simple matrix
2 - print matrix
3 - multiplication
4 - exit
1
(2 9)
2
0 0 
9 0 
3
enter vector (1x2)   3 4
res = ( 36 0 ) count = 1
4
==4257== 
==4257== HEAP SUMMARY:
==4257==     in use at exit: 0 bytes in 0 blocks
==4257==   total heap usage: 6 allocs, 6 frees, 6,628 bytes allocated
==4257== 
==4257== All heap blocks were freed -- no leaks are possible
==4257== 
==4257== For lists of detected and suppressed errors, rerun with: -s
==4257== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
serafim@serafim-VirtualBox:~/programs/kp7$ valgrind ./kp7 t3.txt
==4260== Memcheck, a memory error detector
==4260== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==4260== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==4260== Command: ./kp7 t3.txt
==4260== 
1 - print simple matrix
2 - print matrix
3 - multiplication
4 - exit
1
(2 1)
(4 8)
2
0 0 1 
0 8 0 
0 0 0 
3
enter vector (1x3)   5 4 1
res = ( 0 32 5 ) count = 2
4    
==4260== 
==4260== HEAP SUMMARY:
==4260==     in use at exit: 0 bytes in 0 blocks
==4260==   total heap usage: 8 allocs, 8 frees, 6,648 bytes allocated
==4260== 
==4260== All heap blocks were freed -- no leaks are possible
==4260== 
==4260== For lists of detected and suppressed errors, rerun with: -s
==4260== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
serafim@serafim-VirtualBox:~/programs/kp7$ valgrind ./kp7 t4.txt
==4262== Memcheck, a memory error detector
==4262== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==4262== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==4262== Command: ./kp7 t4.txt
==4262== 
1 - print simple matrix
2 - print matrix
3 - multiplication
4 - exit
1
(0 1)
(9 1)
(14 8)
(35 7)
(48 3)
(70 2)
(74 5)
2
1 0 0 0 0 0 0 0 0 
1 0 0 0 0 8 0 0 0 
0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 7 
0 0 0 0 0 0 0 0 0 
0 0 0 3 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 2 0 
0 0 5 0 0 0 0 0 0 
3
enter vector (1x9)   9 5 3 4 1 2  8 8 0
res = ( 14 0 0 6 0 40 0 16 28 ) count = 5
4
==4262== 
==4262== HEAP SUMMARY:
==4262==     in use at exit: 0 bytes in 0 blocks
==4262==   total heap usage: 12 allocs, 12 frees, 6,752 bytes allocated
==4262== 
==4262== All heap blocks were freed -- no leaks are possible
==4262== 
==4262== For lists of detected and suppressed errors, rerun with: -s
==4262== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)


```

## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 11.07.23 | 13:00 | Выполнение лабораторной работы | - | - |
## 10. Замечания автора по существу работы — Написание команд для отработки навыков работы в ОС UNIX.
Защита с Coderforces:  
<b>[Контест (Div. 2)](https://codeforces.com/contest/1810/submission/199989384)</b> 


## 11. Выводы
Были получены навыки написания эффективных программ для обработки разреженных матриц. Были отработаны навыки работы с файлами, динамическими структурами и указателями в Си.
Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> ____________________



