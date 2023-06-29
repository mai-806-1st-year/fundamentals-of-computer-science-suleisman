# Отчет по курсовой работе №8 по курсу "Фундументальня информатика" 
<b>Студент группы:</b> <ins>М80-108Б-22 Шелаев Серафим Ильич, номер по списку 23</ins>  
<b>Контакты e mail:</b> <ins>serafimshelaev@mail.ru</ins>  
<b>Работа выполнена:</b> «29» <ins>июня</ins> <ins>2023</ins> г.
<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins>3 (удовлетворительно)</ins>

<b>Отчет сдан</b> «27» <ins>мая</ins> <ins>2022</ins> г., <b>итоговая оценка</b>3 <ins> (удовлетворительно)</ins>                                                          

<b>Подпись преподавателя:</b> ________________
## 1. Тема
Линейные списки  
## 2. Цель работы
Составить и отладить программу на языке Си для обработки линейного списка  
## 3. Задание (вариант № 23)
Составить и отладить программу на языке Си для обработки линейного списка заданной организации с отображением
списка на динамические структуры (группы 1, 2, 3, 8, 9, 11, 13) или на массив (только с индексным доступом, без
применения ссылок и указателей, для групп 4, 5, 6, 7, 10, 12). Навигацию по списку следует реализовать с применением
итераторов. Предусмотреть выполнение одного нестандартного и четырех стандартных действий:
1. Печать списка.
2. Вставка нового элемента в список.
3. Удаление элемента из списка.
4. Подсчет длины списка.
5. Исключить из списка последние k элементов   
## 4. Оборудование:
ноутбук  Asus Vivobook 15(1920x1080, Intel Core i5 2.4 ГГц, RAM 16 ГБ, SSD 512 ГБ, Windows 11 Home)
## 5. Программное обеспечение:
<b>Операционная система семейства:</b> Microsoft Windows 11<br/> 
<b>Компилятор:</b> GNU Compiler Collection<br/>
<b>Текстовый редактор:</b> Visual Studio Code версия 1.73.0<br/>
## 6. Идея, метод, алгоритм решения задачи (в формах: словесной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)
Был реализован линейный однонаправленный список с барьерным элементом;  
## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию]. 
main.c
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

#define COMMAND_LEN 40

int main() {
    List list;
    listCreate(&list);
    printf("pushback\n"
               "print\n"
               "length\n"
               "func\n"
               "delete\n"
               "exit\n");
    while (1) {
        char command[COMMAND_LEN];
        scanf("%s", command);
        if (strcmp(command, "pushback") == 0) {
            int val;
            printf("insert value:  ");
            scanf("%d", &val);
            listPushBack(&list, val);
        }
        if (strcmp(command, "print") == 0) {
            listPrint(&list);
        }
        if (strcmp(command, "length") == 0)
            printf("%ld\n", listLength(&list));
        if (strcmp(command, "func") == 0) {
            int val;
            printf("insert value:  ");
            scanf("%d", &val);
            listFunc(&list, val);
        }
        if (strcmp(command, "delete") == 0) {
            int val;
            printf("insert value:  ");
            scanf("%d", &val);
            listDelete(&list, val);
        }
        if (strcmp(command, "exit") == 0) {
            break;
        }

    }
    listDestroy(&list);
}

```
list.c
```c
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

typedef struct ListNode ListNode;

struct ListNode{
    int *data;
    ListNode *next;
} ;

void listCreate(List *list) {
    ListNode *node = malloc(sizeof(ListNode));
    node->next = NULL;
    node->data = NULL;
    list->first = node;
}

void listClear(List *list) {
    Iterator it = listIteratorBegin(list);
     while (!listIsEmpty(list)) {
        listErase(list, &it);
        it = listIteratorBegin(list);
    }
}

bool listIsEmpty(List *list) {
    Iterator begin = listIteratorBegin(list);
    return begin.node->data == NULL;
}

void listInsert(List *list, Iterator *iterator, int val) {
    ListNode *newnode = malloc(sizeof(ListNode));
    int *a = malloc(sizeof(int));
    *a = val;
    newnode->next = iterator->node;
    newnode->data = a;
    Iterator prev;
    prev = listIteratorPrev(list, iterator);
    if (prev.node != NULL) {
        prev.node->next = newnode;
    }
    else
        list->first = newnode;
}

void listErase(List *list, Iterator *iterator) {
    //compareValues(iterator->node->data, val)
    Iterator prev, next;
    prev = listIteratorPrev(list, iterator);
    next = listIteratorNext(list, iterator);

    if (prev.node != NULL)
        prev.node->next = next.node; 
    else
        list->first = next.node;

    free(iterator->node->data);
    free(iterator->node);

    iterator = &next;
}

void listPrint(List *list) {
    Iterator it = listIteratorBegin(list);
    while(it.node->data != NULL) {
        printf("%d ", *it.node->data);
        it = listIteratorNext(list, &it);
    }
    printf("\n");
}
void listPushBack(List *list, int val) {
    Iterator end = listIteratorEnd(list);
    listInsert(list, &end, val);
}

void listPushIndex(List *list, int val, int index) {
    Iterator it = listIteratorIndex(list, index);
    listInsert(list, &it, val);
}

void listDestroy(List *list) {
    Iterator it = listIteratorBegin(list);
    while (!listIsEmpty(list)) {
        listErase(list, &it);
        it = listIteratorBegin(list);
    }
    free(list->first);
    list->first = NULL;
}

size_t listLength(List *list) {
    Iterator it = listIteratorBegin(list);
    size_t length = 0;
    while (it.node != NULL && it.node->data != NULL) {
        length++;
        it = listIteratorNext(list, &it);
    }
    return length;
}


void listDelete(List *list, int val) {
    Iterator it = listIteratorSet(list, val);
    if (it.node != NULL) {
        listErase(list, &it);
    }
    else 
        printf("not value in list\n");
}

void listFunc(List *list, int k) {
    if(k < listLength(list)) {
        while(k != 0) { 
            Iterator it = listIteratorIndex(list, listLength(list) - k); 
            listErase(list, &it);
            --k;
        }
    } 
    
}

// iterator
Iterator listIteratorBegin(List *list) {
    return (Iterator){.node = list->first};
}
Iterator listIteratorEnd(List *list) {
    Iterator it = listIteratorBegin(list);
    // if (it.node->end != 1) {
    //     while (it.node->next->end != 1) {
    //         it = listIteratorNext(list, &it);
    //     }
    // }
    while ((it.node)->next != NULL)
        it = listIteratorNext(list, &it);
    return it;
}

Iterator listIteratorNext(List *list, const Iterator *iterator) {
    return (Iterator){.node = iterator->node->next};
}
Iterator listIteratorPrev(List *list, const Iterator *iterator) {
    if (list->first == iterator->node) {
        return (Iterator){.node = NULL};
    }
    Iterator it = listIteratorBegin(list);

    while (it.node->next != iterator->node)
        it = listIteratorNext(list, &it);
    return it;
}

void listIteratorGet(const Iterator *iterator, int val) {
    val = *iterator->node->data;
}

bool compareValues(int v1, int v2) {
    if (v1 == v2)
        return 1; 
    return 0;
}

Iterator listIteratorSet(List *list, int val) {
    Iterator it = listIteratorBegin(list);
    while (it.node->data != NULL) {
        if (!compareValues(*it.node->data, val))
            it = listIteratorNext(list, &it);
        else
            break;
    }
    if (it.node->data == NULL)
        return (Iterator){.node = NULL};
    return it;
}

Iterator listIteratorIndex(List *list, int index) {
    size_t id = 0;
    Iterator iter = listIteratorBegin(list);
    while (id != index && iter.node->data != NULL) {
        iter = listIteratorNext(list, &iter);
        ++id; 
    }
    return iter;

}
```
list.h
```c
#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stdlib.h>


typedef struct ListNode ListNode;

typedef struct {
    ListNode *first;
} List;

typedef struct {
    ListNode *node;
} Iterator;

void listCreate(List *list);
void listClear(List *list);
bool listIsEmpty(List *list);
void listInsert(List *list, Iterator *iterator, int val);
void listErase(List *list, Iterator *iterator);
void listDestroy(List *list);
void listPrint(List *list);
void listPushBack(List *list, int val);
void listDelete(List *list, int val);
size_t listLength(List *list);
void listFunc(List *list, int val);


Iterator listIteratorNext(List *list, const Iterator *iterator);
Iterator listIteratorPrev(List *list, const Iterator *iterator);
Iterator listIteratorBegin(List *list);
Iterator listIteratorEnd(List *list);
void listIteratorGet(const Iterator *iterator, int val);
Iterator listIteratorSet(List *list, int val);
Iterator listIteratorIndex(List *list, int index);



#endif // LIST_H
```
## 8. Протокол  
```
serafim@serafim-VirtualBox:~/programs/cp8$ valgrind ./cp6
==15873== Memcheck, a memory error detector
==15873== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==15873== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==15873== Command: ./cp6
==15873== 
pushback
print
length
func
delete
exit
pushback
insert value:  8
pushback
insert value:  6
pushback
insert value:  7
pushback
insert value:  4
print
8 6 7 4 
func
insert value:  2
print
8 6 
exit
==15873== 
==15873== HEAP SUMMARY:
==15873==     in use at exit: 0 bytes in 0 blocks
==15873==   total heap usage: 11 allocs, 11 frees, 2,144 bytes allocated
==15873== 
==15873== All heap blocks were freed -- no leaks are possible
==15873== 
==15873== For lists of detected and suppressed errors, rerun with: -s
==15873== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```

## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 29.06.22 | 13:00 | Выполнение лабораторной работы | - | - |
## 10. Замечания автора по существу работы — Написание команд для отработки навыков работы в ОС UNIX.
Защита с Coderforces:  
<b>[Контест (Div. 2)](https://codeforces.com/contest/1810/submission/199989384)</b> 

## 11. Выводы
Была составлена программа на языке Си для обработки линейного списка заданной организации с отображением на динамические структуры и написана процедура для выполнения нестандартного действия по номеру варианта. Были получены навыки написания итераторов для структур данных, изучен принцип их работы. 

Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> ____________________




