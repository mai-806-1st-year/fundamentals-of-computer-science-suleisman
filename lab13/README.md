# Отчет по лабораторной работе №2 по курсу "Фундументальня информатика" 
<b>Студент группы:</b> <ins>М80-108Б-22 Шелаев Серафим Ильич, номер по списку 25</ins>  
<b>Контакты e mail:</b> <ins>serafimshelaev@mail.ru</ins>  
<b>Работа выполнена:</b> «17» <ins>декабря</ins> <ins>2022</ins> г.
<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins>4 (хорошо)</ins>

<b>Отчет сдан</b> «17» <ins>декабря</ins> <ins>2022</ins> г., <b>итоговая оценка</b> <ins>4 (хорошо)</ins>                                                          

<b>Подпись преподавателя:</b> ________________
## 1. Тема
Множества
## 2. Цель работы
Составить программу на языке Си, выполняющую анализ и обработку вводимого текста в соответствии с выданным вариантом задания  
## 3. Задание (вариант № 24)
Есть ли слово, все согласные которого - глухие  
## 4. Оборудование:
ноутбук  Asus Vivobook 15(1920x1080, Intel Core i5 2.4 ГГц, RAM 16 ГБ, SSD 512 ГБ, Windows 11 Home)
## 5. Программное обеспечение:
<b>Операционная система семейства:</b> Microsoft Windows 11<br/> 
<b>Компилятор:</b> GNU Compiler Collection<br/>
<b>Текстовый редактор:</b> Visual Studio Code версия 1.73.0<br/>
## 6. Идея, метод, алгоритм решения задачи (в формах: словесной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)
Обрабатываем слова, учитывая то, что состоит ли оно из нужных букв, учитывая пробелы и преводы строк.  
 
## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию]. 
```
aaaa rrrr
```
```
aaff 
```

```
aaaaarrr aaaaaa sssss
```
```
aaaaa vgvgv asas
```





```
/*#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <wchar.h>
#include <locale.h>


typedef unsigned set_data_elem;
enum {
    bits_per_char = 16u,
    bits_per_elem = sizeof(set_data_elem) * bits_per_char,
    datalen = (1u << bits_per_char) / bits_per_elem
};

typedef struct {
    set_data_elem data[datalen];
} set;

void set_clear(set *s) {
    memset(s->data, 0, sizeof(s->data));
}

void set_insert(set *s, int c) {
    s->data[c / bits_per_elem] |= 1u << (c % bits_per_elem);
}


bool set_in(const set *s, int c) {
    return (s->data[c / bits_per_elem] & (1u << (c % bits_per_elem))) != 0;
}


bool set_includes(const set *s1, const set *s2) {
    for (int i = 0; i != datalen; i++) {
        if ((s1->data[i] | s2->data[i]) != s1->data[i]) return false;
    }
    return true;
}



bool is_alpha(int c) { return isalpha(c); }

bool is_digit(int c) { return isdigit(c); }


int main() {
    setlocale(LC_ALL, "");
    freopen("in.txt", "r", stdin);

    set empty_set, uSet, consonants;
    set_clear(&empty_set);
    set_clear(&uSet);
    set_clear(&consonants);

    set_insert(&consonants, L'п');
    set_insert(&consonants, L'ф');
    set_insert(&consonants, L'к');
    set_insert(&consonants, L'т');
    set_insert(&consonants, L'ш');
    set_insert(&consonants, L'с');

    wchar_t buf;
    while (wscanf(L"%lc", &buf) > 0) {
        if(buf >= L'а' && buf <= L'я'){
            if(set_in(&consonants, buf)){
                set_insert(&uSet, buf);
            }
        }else {
            for (wchar_t ch = L'а'; ch != L'я'; ch++) {
                if (set_in(&uSet, ch)) {
                    wprintf(L"Yes, this consonant is '%lc'\n", ch);
                    return 0;
                }
            }
        }
    }

} */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define VOWELS ( \
    1U << ('b' - 'a') | \
    1U << ('v' - 'a') | \
    1U << ('g' - 'a') | \
    1U << ('d' - 'a') | \
    1U << ('z' - 'a') | \
    1U << ('l' - 'a') | \
    1U << ('m' - 'a') | \
    1U << ('n' - 'a') | \
    1U << ('r' - 'a') \
)

enum State {
    CHAR_IN_WORLD,
    NO_CHAR_IN_WORLD,
};
enum Gap {
    BE,
    NOT_BE,
};

unsigned int char_to_set(int c);
bool process();

int main() {

    if (process() == 1) {
        printf("Yes");
    } else printf("No");

    return 0;
}

unsigned int char_to_set(int c) {//преобразование буквы в цифру
    c= tolower(c);
    if (c < 'a' || c > 'z') {
        return 0;
    } else {
        return 1u << (c - 'a');
    }
}

bool process () {
    enum State state = CHAR_IN_WORLD;
    enum Gap gap = NOT_BE;
    unsigned int set = 0;
    
    int k = 0;

    for (char c = getchar(); c != '\n'; c = getchar())
    {

        switch (state)
        {
        case CHAR_IN_WORLD:
            if (isalpha(c) != 0) {
                c=tolower(c);
                if ((char_to_set(c) & VOWELS)!=0) {
                    set=char_to_set(c);
                    gap = NOT_BE;
                } 
                else {
                    state = NO_CHAR_IN_WORLD;
                }
            }
            else {
                gap = BE;
                k ++;
            }   
            break;        
        case NO_CHAR_IN_WORLD:
            if (isalpha(c) != 0) {
                gap = NOT_BE;    
            }
            else {
                state = CHAR_IN_WORLD;
                gap = BE;
            }
            break;
        }
       
    }  
     
        if (gap == NOT_BE && state == CHAR_IN_WORLD) {
            k++;
        }
        if ( k > 0 ) {
            return 1;
        } else {
            return 0;
        }
    return 0;
}
```



Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя</b> ________________
## 8. Распечатка протокола 
```
serafim@serafim-VirtualBox:~$ cat test.txt
aaa rrrr
serafim@serafim-VirtualBox:~$ gcc -std=c18 lab13.c
serafim@serafim-VirtualBox:~$ ./a.out < test.txt
YES
serafim@serafim-VirtualBox:~$ cat test.txt
AAaaaA
serafim@serafim-VirtualBox:~$ gcc -std=c18 lab13.c
serafim@serafim-VirtualBox:~$ ./a.out < test.txt
NO

```
## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 17.12.22 | 13:00 | Выполнение лабораторной работы | - | - |
## 10. Замечания автора по существу работы — Написание команд для отработки навыков работы в ОС UNIX.
```
```
## 11. Выводы
Была изучена работа со множествами на языке Си. 
Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> ____________________




