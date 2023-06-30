# Отчет по курсовой работе №9 по курсу "Фундументальня информатика" 
<b>Студент группы:</b> <ins>М80-108Б-22 Шелаев Серафим Ильич, номер по списку 23</ins>  
<b>Контакты e mail:</b> <ins>serafimshelaev@mail.ru</ins>  
<b>Работа выполнена:</b> «29» <ins>июня</ins> <ins>2023</ins> г.
<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins>3 (удовлетворительно)</ins>

<b>Отчет сдан</b> «29» <ins>июня</ins> <ins>2022</ins> г., <b>итоговая оценка</b>3 <ins> (удовлетворительно)</ins>                                                          

<b>Подпись преподавателя:</b> ________________
## 1. Тема
Сортировка и поиск
## 2. Цель работы
Составить программу на языке Си с использованием процедур и функций для сортировки таблицы заданным методом и двоичного поиска по ключу в таблице   
## 3. Задание (вариант № 23)
Программа должна вводить значения элементов неупорядоченной таблицы и проверять работу процедуры сортировки в трех случаях: (1) элементы таблицы с самого начала упорядочены; (2) элементы таблицы расставлены в обратном порядке; (3) элементы таблицы не упорядочены. В последнем случае можно использовать встроенные процедуры генерации псевдослучайных чисел

Для каждого вызова процедуры сортировки необходимо печатать исходное состояние таблицы и результаты сортировки. После выполнения сортировки программа должна вводить ключи и для каждого из них выполнять поиск в упорядоченной таблице с помощью процедуры двоичного поиска и печатать найденные элементы, если они присутствуют в таблице. В процессе отладки и тестирования рекомендуется использовать команды обработки текстовых файлов ОС UNIX и переадресацию ввода-вывода. Тестовые данные необходимо заранее поместить в текстовые файлы. В качестве текста для записей таблицы взять изображение ASCII-графики. Каждый элемент таблицы, содержащий ключ и текст записи, распечатывать в отдельной строке  
## 4. Оборудование:
ноутбук  Asus Vivobook 15(1920x1080, Intel Core i5 2.4 ГГц, RAM 16 ГБ, SSD 512 ГБ, Windows 11 Home)
## 5. Программное обеспечение:
<b>Операционная система семейства:</b> Microsoft Windows 11<br/> 
<b>Компилятор:</b> GNU Compiler Collection<br/>
<b>Текстовый редактор:</b> Visual Studio Code версия 1.73.0<br/>
## 6. Идея, метод, алгоритм решения задачи (в формах: словесной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)
## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию]. 
main.c
```c
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "table.h"

int main() {
    FILE *file;
    file = fopen("text.txt", "r");
    Table table;
    tableCreate(&table);
    size_t size;
    char key[KEY_LENGTH] = "b";
    char value[VALUE_LENGTH];
    fscanf(file, "%ld", &size);
    for (size_t i = 0; i < size; ++i) {
        fscanf(file, "%s %s\n", key, value);
        tablePushBack(&table, key, value);
    }
    fclose(file);
    tablePrintGood(&table);
    tableSort(&table);
    printf("\n");
    tablePrintGood(&table);
    scanf("%s", key);
    tableSearch(&table, key);
    tableDestroy(&table);

}
```
table.h
```c
#ifndef TABLE_H
#define TEBLE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LENGTH 5
#define VALUE_LENGTH 10

typedef struct Cell Cell;

struct Cell {
    char data[KEY_LENGTH + VALUE_LENGTH];
};

typedef struct {
    Cell *cell;
    size_t capacity, size;
} Table;

void tableCreate(Table *table);
size_t tableCopacity(Table *table);
void tablePushBack(Table *table, char *key, char *value);
void tableResize(Table *table, size_t newsize);
bool tabeIsEmpty(Table *teble);
char *tableGetBack(Table *table);
void tableDestroy(Table *table);
void tablePrintSimple(Table *table);
void tablePrintGood(Table *table);
void tableGetKey(Table *table, char key[KEY_LENGTH] ,size_t i);
void tableGetValue(Table *table, char value[VALUE_LENGTH] ,size_t i);
void tableSort(Table *table);
bool tableCheckSort(Table *table);
bool tableCheckSortInv(Table *table);
void tableReverse(Table *table);
void tableSwap(Table *table, size_t i, size_t j);
void tableSearch(Table *table, char key[KEY_LENGTH]);

#endif //TABLE_H
```
table.c
```c
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "table.h"

void tableCreate(Table *table) {
    table->cell = NULL;
    table->capacity = 0;
    table->size = 0;
}

size_t tableCopacity(Table *table) {
    return table->capacity;
}

void tableResize(Table *table, size_t newsize) {
    if (table->size == 0) {
        table->cell = malloc(newsize * sizeof(Cell));
        table->size = newsize;
    }
    else if (newsize > table->size) {
        table->cell = realloc(table->cell, newsize * sizeof(Cell));
        table->size = newsize;
    }
    else if (newsize < table->size) {
        table->size = newsize;
        if (table->size < table->capacity)
            table->capacity = table->size;
    }
}

void tablePushBack(Table *table, char *key, char *value) {
    char data[KEY_LENGTH + VALUE_LENGTH];
    strcpy(data, key);
    strcpy(data + KEY_LENGTH, value);

    Cell newcell;
     for (int i = 0; i <KEY_LENGTH + VALUE_LENGTH; ++ i)
         newcell.data[i] = data[i];

    if (table->capacity < table->size) {
        table->cell[table->capacity] = newcell;
        table->capacity++;
    } else {
        tableResize(table, table->size + 1);
        table->cell[table->capacity] = newcell;
        table->capacity++;
    }
}

void tablePrintSimple(Table *table) {
    for (size_t i = 0; i < table->capacity; ++i) {
        for (size_t j = 0; j < KEY_LENGTH + VALUE_LENGTH; ++j)
            printf("%c", table->cell[i].data[j]);
        printf("\n");
    }
}

void tableDestroy(Table *table) {
    free(table->cell);
    table->cell = NULL;
    table->size = 0;
    table->capacity = 0;
}

void tableGetValue(Table *table, char value[VALUE_LENGTH] ,size_t i) {
    for (int j = KEY_LENGTH; j < KEY_LENGTH + VALUE_LENGTH; ++j) {
        value[j - KEY_LENGTH] = table->cell[i].data[j];
    }
}

void tableGetKey(Table *table, char key[KEY_LENGTH] ,size_t i) {
    for (int j = 0; j < KEY_LENGTH; ++j) {
        key[j] = table->cell[i].data[j];
    }
}

// линейный выбор с обменом
void tableSort(Table *table) {
    bool sort = tableCheckSort(table);
    if (sort) {
        printf("the table is already sorted \n");
        return;
    }
    bool sortinv = tableCheckSortInv(table);
    if (sortinv) {
        printf("the table is already sorted in reverse order \n");
        tableReverse(table);
        return;
    }
    char key1[KEY_LENGTH];
    char key2[KEY_LENGTH];
    size_t a;
    for (size_t i = 0; i < table->size - 1; ++i) {
        a = i;
        tableGetKey(table, key1, i);
        for (size_t j = i + 1; j < table->capacity; ++j) {
            tableGetKey(table, key2, j);
            if (strcmp(key2, key1) < 0) {
                tableGetKey(table, key1, j);
                a = j;
            }
        }
        tableSwap(table, a, i);
    }

}

void tableSwap(Table *table, size_t i, size_t j) {
    Cell tmp = table->cell[i];
    for (int k = 0; k < KEY_LENGTH+VALUE_LENGTH; ++k) {
        table->cell[i].data[k] = table->cell[j].data[k];
    }
    for (int k = 0; k < KEY_LENGTH+VALUE_LENGTH; ++k) {
        table->cell[j].data[k] = tmp.data[k];
    }
}

bool tableCheckSort(Table *table) {
    bool check = 1;
    char first[KEY_LENGTH];
    char second[KEY_LENGTH];
    for (size_t i = 1; i < table->capacity; ++i) {
        tableGetKey(table, first, i - 1);
        tableGetKey(table, second, i);
        if (strcmp(first, second) > 0){
            check = 0;
            break;
        }
    }
    return check;
}

void tableReverse(Table *table) {
    for (size_t i = 0; i < table->capacity / 2; ++i) {
        tableSwap(table, i, table->capacity - 1 - i);
    }
}

bool tableCheckSortInv(Table *table) {
    bool check = 1;
    char first[KEY_LENGTH];
    char second[KEY_LENGTH];
    for (size_t i = 1; i < table->capacity; ++i) {
        tableGetKey(table, first, i - 1);
        tableGetKey(table, second, i);
        if (strcmp(first, second) < 0){
            check = 0;
            break;
        }
    }
    return check;
}

void tablePrintGood(Table *table) {
    char key[KEY_LENGTH];
    char value[VALUE_LENGTH];
    for (size_t i = 0; i < table->capacity; ++i) {
        tableGetKey(table, key, i);
        tableGetValue(table, value, i);
        printf("%s", key);  
        printf("  "); 
        printf("%s", value);
        printf("\n");
    }
}

void tableSearch(Table *table, char key[KEY_LENGTH]) {
    size_t len = table->capacity;
    size_t middle = len / 2;
    char V[VALUE_LENGTH];
    while(len != 0) {
        len = len / 2;
        char K[KEY_LENGTH];
        tableGetKey(table, K, middle);
        if (strcmp(K, key) > 0) {
            middle -= len / 2 + 1;
        } else if (strcmp(K, key) < 0) {
            middle += len / 2 + 1;
        } else {
            tableGetValue(table, V, middle);
            printf("%s\n", V);
            return;
        }
    }
    printf("key not in table\n");
}
  ```
## 8. Распечатка протокола
```
serafim@serafim-VirtualBox:~/programs/kp_nine$ valgrind ./main
==6619== Memcheck, a memory error detector
==6619== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==6619== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==6619== Command: ./main
==6619== 
aaaa  bbb
dddd  ccc
xxxx  ahaha
fofo  daaaa
qqqq  ccccpp
cvcv  xsa
vbtd  val0000
zzzz  ru
daae  ffsdf

aaaa  bbb
cvcv  xsa
daae  ffsdf
dddd  ccc
fofo  daaaa
qqqq  ccccpp
vbtd  val0000
xxxx  ahaha
zzzz  ru
fofo
daaaa
==6619== 
==6619== HEAP SUMMARY:
==6619==     in use at exit: 0 bytes in 0 blocks
==6619==   total heap usage: 13 allocs, 13 frees, 7,291 bytes allocated
==6619== 
==6619== All heap blocks were freed -- no leaks are possible
==6619== 
==6619== For lists of detected and suppressed errors, rerun with: -s
==6619== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```

## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 29.06.22 | 13:00 | Выполнение лабораторной работы | - | - |
## 10. Замечания автора по существу работы — Написание команд для отработки навыков работы в ОС UNIX.
Защита с Coderforces:  
<b>[Контест (Div. 2)](https://codeforces.com/contest/1810/submission/199989384)</b> 

## 11. Выводы
Были получены базовые представления о внутренней работе баз данных и таблиц с информацией. Были изучены новый метод сортировки, алгоритм бинарного поиска. 

Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> ____________________




