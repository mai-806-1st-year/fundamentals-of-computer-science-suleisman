# Отчет по лабораторной работе №2 по курсу "Фундументальня информатика" по курсу Фундументальная информатика
Cтудент группы М8О-108Б-22, Шелаев Серафим Ильич  
**Контакты:** serafimshelaev@mail.ru  
1.**Цель работы:** Изучение и освоение программногообеспеченя OC LINUX  и приобретение навыков по практическому применению утлит  Emacs, bc, навыков работе с файлами.  
2.**Оборудование:** ноутбук  Asus Vivobook 15(1920x1080, Intel Core i5 2.4 ГГц, RAM 16 ГБ, SSD 512 ГБ, Windows 11 Home)  
3.**Идея, метод, алгоритм**
1. Вывод информации о пользователе, системе, машине с помощью команд:who, pwd, date, 
2. Работа с каталогами с помощью команд: pwd, mkdir, rmdir, ls, cd
3. Работа с файлами с помощью команд: mw, rm, cp, cat
 
 
4.**Сценарий выполнения работы**  
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


5.**Вывод:**  
Было проведено знакомство с основными командами ОС UNIX, были изучены перемещение по директориям, создание, редактирование, чтение, удаление файлов. Были получены базовые навыки владения ОС UNIX.


