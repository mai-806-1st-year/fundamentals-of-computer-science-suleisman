# Отчет по лабораторной работе №24 по курсу "Фундументальня информатика" 
<b>Студент группы:</b> <ins>М80-108Б-22 Шелаев Серафим Ильич, номер по списку 23</ins>  
<b>Контакты e mail:</b> <ins>serafimshelaev@mail.ru</ins>  
<b>Работа выполнена:</b> «11» <ins>июля</ins> <ins>2023</ins> г.
<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins>3 (удовлетворительно)</ins>

<b>Отчет сдан</b> «11» <ins>июля</ins> <ins>2023</ins> г., <b>итоговая оценка</b>3 <ins> (удовлетворительно)</ins>                                                          

<b>Подпись преподавателя:</b> ________________
## 1. Тема
Деревья арифметических выражений  
## 2. Цель работы
Составить программу на Си выполнения заданных преобразований арифметическиз выражений с применением деревьев.
## 3. Задание (вариант № 23)
Упростить дробь, сократив в числителе и знаменателя общие переменные и константы:  
a/(a*b)->1/b  
## 4. Оборудование:
ноутбук  Asus Vivobook 15(1920x1080, Intel Core i5 2.4 ГГц, RAM 16 ГБ, SSD 512 ГБ, Windows 11 Home)
## 5. Программное обеспечение:
<b>Операционная система семейства:</b> Microsoft Windows 11<br/> 
<b>Компилятор:</b> GNU Compiler Collection<br/>
<b>Текстовый редактор:</b> Visual Studio Code версия 1.73.0<br/>
## 6. Идея, метод, алгоритм решения задачи (в формах: словесной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)

## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию]. 

stack.h
```c
#ifndef STACK_H
#define STACK_H

#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *data;
    int top, size;
} Stack;

void stackCreate(Stack *stack);
void stackDestroy(Stack *stack);
char stackTop(Stack *stack);
void stackPush(Stack *stack, char v);
char stackPop(Stack *stack);
void stackResize(Stack *stack, int newsize);
bool stackIsEmpty(Stack *stack);
void stackPrint(Stack *stack);
void toPostfix(Stack *stack, char *expression);
int precedence(char ch);
int checkIfOperand(char ch);


#endif //TREE_H
```
stack.c
```c
#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

void stackCreate(Stack *stack) {
    stack->data = NULL;
    stack->top = -1;
    stack->size = 0;
}
void stackDestroy(Stack *stack) {
    free(stack->data);
    stack->top = -1;
    stack->size = 0;
    stack->data = NULL;
}
char stackTop(Stack *stack) {
    return stack->data[stack->top];
}
void stackPush(Stack *stack, char v) {
    if (stack->top + 1 == stack->size)
        stackResize(stack, stack->size + 1);
    stack->data[stack->top + 1] = v;
    stack->top++;
}
char stackPop(Stack *stack) {
    stack->top--;
    return stack->data[stack->top + 1];

}
void stackResize(Stack *stack, int newsize) {
    if (stack->data == NULL) {
        stack->data = malloc(sizeof(char) * newsize);
        stack->size = newsize;
    } else {
        stack->data = realloc(stack->data, sizeof(char) * newsize);
        stack->size = newsize;
    }
}
bool stackIsEmpty(Stack *stack) {
    return stack->top == -1;
}

void stackPrint(Stack *stack) {
    while (!stackIsEmpty(stack))
        printf("%c ", stackPop(stack));
}

int checkIfOperand (char ch) {
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

int precedence (char ch) {
  switch (ch)
    {
    case '+':
    case '-':
      return 1;

    case '*':
    case '/':
      return 2;

    case '^':
      return 3;
    }
  return -1;
}

void toPostfix(Stack *stack, char *expression) {
      int i, j;

  for (i = 0, j = -1; expression[i]; ++i)
    {
      if (checkIfOperand (expression[i]))
	expression[++j] = expression[i];

      else if (expression[i] == '(')
		stackPush(stack, expression[i]);

      else if (expression[i] == ')')
	{
	  while (!stackIsEmpty(stack) && stackTop(stack) != '(')
	    expression[++j] = stackPop(stack);
	  if (!stackIsEmpty(stack) && stackTop(stack) != '(')
	    return ;	              
	  else
	    stackPop(stack);
	}
      else	
	{
	  while (!stackIsEmpty(stack)
		 && precedence(expression[i]) <= precedence(stackTop(stack)))
	    expression[++j] = stackPop(stack);
	  stackPush(stack, expression[i]);
	}
    }
  while (!stackIsEmpty(stack))
    expression[++j] = stackPop(stack);

  expression[++j] = '\0';
}
```
stackbin.h
```c
#ifndef STACKBIN_H
#define STACKBIN_H

#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct TreeNode TreeNode;
typedef struct Pair Pair;

struct Pair{    
    TreeNode *node;
    bool v;
};

typedef struct {
    Pair *data;
    int top, size;
} StackBin;

void stackBinCreate(StackBin *stack);
void stackBinDestroy(StackBin *stack);
Pair stackBinTop(StackBin *stack);
void stackBinPush(StackBin *stack, TreeNode *node, bool v);
Pair stackBinPop(StackBin *stack);
void stackBinResize(StackBin *stack, int newsize);
bool stackBinIsEmpty(StackBin *stack);
void stackBinPrint(StackBin *stack);


#endif //TREE_H
```
stackbin.c
```c
#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stackbin.h"

typedef struct Pair Pair;

void stackBinCreate(StackBin *stack) {
    stack->data = NULL;
    stack->top = -1;
    stack->size = 0;
}
void stackBinDestroy(StackBin *stack) {
    free(stack->data);
    stack->top = -1;
    stack->size = 0;
    stack->data = NULL;
}
struct Pair stackBinTop(StackBin *stack) {
    return stack->data[stack->top];
}
void stackBinPush(StackBin *stack, TreeNode *node, bool v) {
    Pair pair;
    pair.node = node;
    pair.v = v;

    if (stack->top + 1 == stack->size)
        stackBinResize(stack, stack->size + 1);
    stack->data[stack->top + 1] = pair;
    stack->top++;
}
struct Pair stackBinPop(StackBin *stack) {
    stack->top--;
    return stack->data[stack->top + 1];

}
void stackBinResize(StackBin *stack, int newsize) {
    if (stack->data == NULL) {
        stack->data = malloc(sizeof(Pair) * newsize);
        stack->size = newsize;
    } else {
        stack->data = realloc(stack->data, sizeof(Pair) * newsize);
        stack->size = newsize;
    }
}
bool stackBinIsEmpty(StackBin *stack) {
    return stack->top == -1;
}

void stackBinPrint(StackBin *stack) {
    while (!stackBinIsEmpty(stack))
        printf("%d ", stackBinPop(stack).v);
}
```
## 8. Протокол  
```
serafim@serafim-VirtualBox:~/programs/laba24$ valgrind ./lab24
==2181== Memcheck, a memory error detector
==2181== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==2181== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==2181== Command: ./lab24
==2181== 
enter expression
(2*3)/(8*2)
/
 *
  2
  3
 *
  8
  2

/
 3
 8

3 / 8 

count = 0
==2181== 
==2181== HEAP SUMMARY:
==2181==     in use at exit: 0 bytes in 0 blocks
==2181==   total heap usage: 22 allocs, 22 frees, 2,402 bytes allocated
==2181== 
==2181== All heap blocks were freed -- no leaks are possible
==2181== 
==2181== For lists of detected and suppressed errors, rerun with: -s
==2181== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
serafim@serafim-VirtualBox:~/programs/laba24$ valgrind ./lab24
==3173== Memcheck, a memory error detector
==3173== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==3173== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==3173== Command: ./lab24
==3173== 
enter expression
(3*3)/(3*3)
/
 *
  3
  3
 *
  3
  3

/
 1
 1

1 / 1 

count = 1
==3173== 
==3173== HEAP SUMMARY:
==3173==     in use at exit: 0 bytes in 0 blocks
==3173==   total heap usage: 22 allocs, 22 frees, 2,402 bytes allocated
==3173== 
==3173== All heap blocks were freed -- no leaks are possible
==3173== 
==3173== For lists of detected and suppressed errors, rerun with: -s
==3173== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
serafim@serafim-VirtualBox:~/programs/laba24$ valgrind ./lab24
==3994== Memcheck, a memory error detector
==3994== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==3994== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==3994== Command: ./lab24
==3994== 
enter expression
(2*3*8*7)/(3*6*a*9)
/
 *
  *
   *
    2
    3
   8
  7
 *
  *
   *
    3
    6
   a
  9

/
 *
  *
   2
   8
  7
 *
  *
   6
   a
  9

2 * 8 * 7 / 6 * a * 9 

count = 0
==3994== 
==3994== HEAP SUMMARY:
==3994==     in use at exit: 0 bytes in 0 blocks
==3994==   total heap usage: 38 allocs, 38 frees, 2,750 bytes allocated
==3994== 
==3994== All heap blocks were freed -- no leaks are possible
==3994== 
==3994== For lists of detected and suppressed errors, rerun with: -s
==3994== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
serafim@serafim-VirtualBox:~/programs/laba24$ valgrind ./lab24
==4017== Memcheck, a memory error detector
==4017== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==4017== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==4017== Command: ./lab24
==4017== 
enter expression
(0*8)/(7*2)
/
 *
  0
  8
 *
  7
  2

0
0
 ==4017== 
==4017== HEAP SUMMARY:
==4017==     in use at exit: 0 bytes in 0 blocks
==4017==   total heap usage: 22 allocs, 22 frees, 2,402 bytes allocated
==4017== 
==4017== All heap blocks were freed -- no leaks are possible
==4017== 
==4017== For lists of detected and suppressed errors, rerun with: -s
==4017== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)


```

## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 11.07.23 | 13:00 | Выполнение лабораторной работы | - | - |
## 10. Замечания автора по существу работы — Написание команд для отработки навыков работы в ОС UNIX.
Защита с Coderforces:  
<b>[Контест (Div. 2)](https://codeforces.com/contest/1810/submission/199989384)</b> 

## 11. Выводы
После выполнения работы, были получены неплохие навыки обработки строк и бинарных деревьев в языке Си.  
Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> ____________________



