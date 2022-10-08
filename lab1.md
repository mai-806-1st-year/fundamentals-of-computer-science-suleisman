# Отчет по лабораторной работе №2 по курсу "Фундументальня информатика" 
<b>Студент группы:</b> <ins>М80-108Б-22 Шелаев Серафим Ильич, номер по списку 25</ins>  
<b>Контакты e mail:</b> <ins>serafimshelaev@mail.ru</ins>  
<b>Работа выполнена:</b> «1» <ins>октября</ins> <ins>2022</ins> г.
<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins>5 (отлично)</ins>

<b>Отчет сдан</b> «1» <ins>октября</ins> <ins>2022</ins> г., <b>итоговая оценка</b> <ins>5 (отлично)</ins>                                                          

<b>Подпись преподавателя:</b> ________________
## 1. Тема
Операционная среда OC UNIX
## 2. Цель работы
Изучение и освоение программного обеспечения ОС UNIX и приобретение навыков, необходимых для выполнения курсовых и лабораторных работ в среде UNIX.
## 3. Задание (вариант № —)
Изучение команд и утилит bash.
## 4. Оборудование:
ноутбук  Asus Vivobook 15(1920x1080, Intel Core i5 2.4 ГГц, RAM 16 ГБ, SSD 512 ГБ, Windows 11 Home)
## 5. Программное обеспечение:
<b>Операционная система семейства:</b> VirtualBox 6.1.38 - Ubuntu 22.04.01 LTS<br/>
<b>Интерпретатор команд:</b> bash версия 4.4.19<br/>
<b>Система программирования:</b> не использовалась версия —<br/>
<b>Редактор текстов:</b> emacs версия 25.2.2<br/>
<b>Утилиты операционной системы:</b> cd, pwd, ls, cp, mv, mkdir, rmdir, cat, man, ps, rm<br/>
<b>Прикладные системы и программы:</b> gnuplot<br/>
<b>Местонахождение и имена файлов программ и данных на домашнем компьютере:</b> /home/kristina<br/>
## 6. Идея, метод, алгоритм решения задачи (в формах: словесной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)
*Команды выдающее информацию*
`who`- Показ количества пользователей
```
serafim@serafim-VirtualBox:~$ who
serafim  tty2         2022-09-22 21:24 (tty2)
serafim  pts/0        2022-09-22 21:24 (10.0.2.2)

```
`whoami`-Показ имени пользователя
```
serafim@serafim-VirtualBox:~$ whoami
serafim
```
`tty`-Показ номера группы пользователя
```
serafim@serafim-VirtualBox:~$ tty
/dev/pts/0
```
`hostname`-Показ терминала на котором ведется работа
```
serafim@serafim-VirtualBox:~$ hostname
serafim-VirtualBox
```
`uname -a`-Показ сетевого имени машины и версии OC UNIX
```
serafim@serafim-VirtualBox:~$ uname -a
Linux serafim-VirtualBox 5.15.0-47-generic #51-Ubuntu SMP Thu Aug 11 07:51:15 UTC 2022 x86_64 x86_64 x86_64 GNU/Linux
```
`date`-Показ текущей даты
```
serafim@serafim-VirtualBox:~$ date
Чт 22 сен 2022 21:56:13 MSK
```


*Команды для работы с катологами* 
`pwd`-Показ текущей директории
```
serafim@serafim-VirtualBox:~$ pwd
/home/serafim
```
`ls`-Показ оглавления каталога
```
serafim@serafim-VirtualBox:~$ ls
 snap   Видео   Документы   Загрузки   Изображения   Музыка   Общедоступные  'Рабочий стол'   Шаблоны
```  
`cd`-Перемещение по катологам  
Перемещение в каталог `Видео` и обратно:
```
serafim@serafim-VirtualBox:~$ cd Видео/
serafim@serafim-VirtualBox:~/Видео$ pwd
/home/serafim/Видео
serafim@serafim-VirtualBox:~/Видео$ cd ..
serafim@serafim-VirtualBox:~$ pwd
/home/serafim

```
`mkdir`-Создание нового католога
Cоздание нового католога `NEW`
```
serafim@serafim-VirtualBox:~$ mkdir NEW
serafim@serafim-VirtualBox:~$ ls
 NEW   snap   Видео   Документы   Загрузки   Изображения   Музыка   Общедоступные  'Рабочий стол'   Шаблоны
 ```
`rmdir`- Удаление католога
Удаление нового католога `NEW`
```
serafim@serafim-VirtualBox:~$ ls
 NEW   snap   Видео   Документы   Загрузки   Изображения   Музыка   Общедоступные  'Рабочий стол'   Шаблоны
serafim@serafim-VirtualBox:~$ rmdir NEW
serafim@serafim-VirtualBox:~$ ls
 snap   Видео   Документы   Загрузки   Изображения   Музыка   Общедоступные  'Рабочий стол'   Шаблоны
```

*Команды для работы с файлами*  
Создание файла `new.txt` в катологе `NEW`
```
serafim@serafim-VirtualBox:~$ ls
 NEW   snap   Видео   Документы   Загрузки   Изображения   Музыка   Общедоступные  'Рабочий стол'   Шаблоны
serafim@serafim-VirtualBox:~$ cd NEW/
serafim@serafim-VirtualBox:~/NEW$ >new.txt
serafim@serafim-VirtualBox:~/NEW$ ls
new.txt
```

```
serafim@serafim-VirtualBox:~/NEW$ touch new.txt
serafim@serafim-VirtualBox:~/NEW$ ls
new.txt
```
`echo`-Вывод на экран терминала текстового сообщения вводимого с клавиатуры
```
serafim@serafim-VirtualBox:~/NEW$ echo NEW
NEW
```

Занесение текста `NEW` в файл `new.txt`
```
serafim@serafim-VirtualBox:~/NEW$ echo NEW >new.txt
```
`cat`-вывод содержимого файла на экран терминала
вывод на экран содержимого файла `new.txt`
```
serafim@serafim-VirtualBox:~/NEW$ cat new.txt
NEW
```
`cp`- копирование файла
копирование файла `new.txt` в файл `newcopy.txt`
```
serafim@serafim-VirtualBox:~/NEW$ cp new.txt newcopy.txt
serafim@serafim-VirtualBox:~/NEW$ ls
newcopy.txt  new.txt
```
`mv`-Переименование файла
переименование файла `newcopy.txt` в `copy.txt`
```
serafim@serafim-VirtualBox:~/NEW$ mv newcopy.txt copy.txt
serafim@serafim-VirtualBox:~/NEW$ ls
copy.txt  new.txt
```
`rm`-удаление файла
удаление файла `copy.txt`
```
serafim@serafim-VirtualBox:~/NEW$ rm copy.txt
serafim@serafim-VirtualBox:~/NEW$ ls
new.txt
```
*Работа с Gnuhplod*  
```
serafim@serafim-VirtualBox:~$ gnuplot

 G N U P L O T
 Version 5.4 patchlevel 2    last modified 2021-06-01 

 Copyright (C) 1986-1993, 1998, 2004, 2007-2021
 Thomas Williams, Colin Kelley and many others

 gnuplot home:     http://www.gnuplot.info
 faq, bugs, etc:   type "help FAQ"
 immediate help:   type "help"  (plot window: hit 'h')

Terminal type is now 'qt'
gnuplot> plot sin(x)
Warning: Ignoring XDG_SESSION_TYPE=wayland on Gnome. Use QT_QPA_PLATFORM=wayland to run on Wayland anyway.
gnuplot>
```

![image](https://user-images.githubusercontent.com/113765497/193401649-29c59644-3646-4085-9b29-1e58c8efd429.png)
## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию]. 
- Изучить литературу по OC UNIX
- Просмотреть демонстрационный материал в лабораторной аудитории
- Приобрести основные навыки работы в OC UNIX
- Освоить навигацию в иерархической файловой системе OC UNIX
- Научиться манипулировать с файлами 
- Ознакомиться с утилитой графики 
- Научиться писать и запускать скрипты
- Запротоколировать сеанс
Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя</b> ________________
## 8. Распечатка протокола 
```
```
## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 01.10.22 | 13:00 | Выполнение лабораторной работы | - | - |
## 10. Замечания автора по существу работы — Написание команд для отработки навыков работы в ОС UNIX.
```
```
## 11. Выводы
Было выяснено, что в OC UNIX есть множество полезных утилит, которые облегчают работу в этой системе. Были изучены некоторые из них. Освоены навигация в файловой системе, создание, удаление файлов и директорий. В результате выполнения работы, были приобретены навыки, которые будут полезны для выполнения других лабораторных работ.

Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> ____________________




