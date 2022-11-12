# Отчет по лабораторной работе №2 по курсу "Фундументальня информатика" 
<b>Студент группы:</b> <ins>М80-108Б-22 Шелаев Серафим Ильич, номер по списку 25</ins>  
<b>Контакты e mail:</b> <ins>serafimshelaev@mail.ru</ins>  
<b>Работа выполнена:</b> «15 » <ins>октября</ins> <ins>2022</ins> г.
<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> 4 <ins>     </ins>

<b>Отчет сдан</b> «15» <ins>октября</ins> <ins>2022</ins> г., <b>итоговая оценка</b>4 <ins>   </ins>                                                          

<b>Подпись преподавателя:</b> ________________
## 1. Тема
Сети и теллекоммуникации в OC LINUX
## 2. Цель работы
Изучение работы сетевых команд консоли OC LINUX
## 3. Задание (вариант № —)

## 4. Оборудование:
ноутбук  Asus Vivobook 15(1920x1080, Intel Core i5 2.4 ГГц, RAM 16 ГБ, SSD 512 ГБ, Windows 11 Home)
## 5. Программное обеспечение:
<b>Операционная система семейства:</b> VirtualBox 6.1.38 - Ubuntu 22.04.01 LTS<br/>
<b>Интерпретатор команд:</b> bash версия 4.4.19<br/>
<b>Система программирования:</b> не использовалась версия —<br/>
<b>Редактор текстов:</b> emacs версия 25.2.2<br/>
<b>Утилиты операционной системы:</b> <br/>
<b>Прикладные системы и программы:</b> Команды hostname, ping, ssh, put, scp, tar, gzip, rlogin, pax  <br/>
<b>Местонахождение и имена файлов программ и данных на домашнем компьютере:</b> <br/>
## 6. Идея, метод, алгоритм решения задачи (в формах: словесной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)
    ssh
_криптографический сетевой протокол, используемый для зашифрованного соединения между клиентом и сервером_

    logout
_завершение сеанса подключения_

    scp
_копирование файлов или директорий_

    tar
_утилита для работы с архивами_ 





## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию]. 
- Изучить литературу по OC UNIX
- Просмотреть демонстрационный материал в лабораторной аудитории
- Приобрести основные навыки работы сетевыми средствами в OC UNIX

- Продемонстрировать владение приобретенными навыками
 
- Запротоколировать сеанс
Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя</b> ________________
## 8. Распечатка протокола 
```
stud@it-10:~$ ssh stud@192.168.2.224
stud@192.168.2.224's password: 
Welcome to Ubuntu 22.04.1 LTS (GNU/Linux 5.15.0-48-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage

81 updates can be applied immediately.
To see these additional updates run: apt list --upgradable

Last login: Sat Oct  1 10:30:42 2022 from 192.168.2.140
stud@it-20:~$ ls
106B_11        767        Downloads      hello.txt  Pictures  Templates  Videos
192.168.2.140  Desktop    _file.txt      lll.gz     Public    test
4444.txt       Documents  file.txt.save  Music      snap      test1
stud@it-20:~$ cat > testssh.txt
hello
123456
stud@it-20:~$ ls
106B_11        Desktop    file.txt.save  Pictures   test
192.168.2.140  Documents  hello.txt      Public     test1
4444.txt       Downloads  lll.gz         snap       testssh.txt
767            _file.txt  Music          Templates  Videos
stud@it-20:~$ logout
Connection to 192.168.2.224 closed.
stud@it-10:~$ ls
1          Downloads     file.txt   homestud  Public     test1
4444.txt   f5            fl.gz      Kochev    snap       Untitled.ipynb
and        file2345.txt  gnuplot    misha     spasibo    Videos
Desktop    filesh_zh     hello      Music     Templates  zh_hz.gz
Documents  _file.txt     hello.txt  Pictures  test
stud@it-10:~$ ssh stud@192.168.2.224
stud@192.168.2.224's password: 
Welcome to Ubuntu 22.04.1 LTS (GNU/Linux 5.15.0-48-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage

81 updates can be applied immediately.
To see these additional updates run: apt list --upgradable

Last login: Sat Oct  1 10:42:33 2022 from 192.168.2.140
stud@it-20:~$ scp testssh.txt stud@192.168.2.140:./
stud@192.168.2.140's password: 
testssh.txt                                   100%   12    13.2KB/s   00:00    
stud@it-20:~$ logout
Connection to 192.168.2.224 closed.
stud@it-10:~$ ls
1          Downloads     file.txt   homestud  Public     test1
4444.txt   f5            fl.gz      Kochev    snap       testssh.txt
and        file2345.txt  gnuplot    misha     spasibo    Untitled.ipynb
Desktop    filesh_zh     hello      Music     Templates  Videos
Documents  _file.txt     hello.txt  Pictures  test       zh_hz.gz
stud@it-10:~$ ssh stud@192.168.2.224
stud@192.168.2.224's password: 
Welcome to Ubuntu 22.04.1 LTS (GNU/Linux 5.15.0-48-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:
 81 updates can be applied immediately.
To see these additional updates run: apt list --upgradable

Last login: Sat Oct  1 10:43:04 2022 from 192.168.2.140
stud@it-20:~$ ls
106B_11        Desktop    file.txt.save  Pictures   test
192.168.2.140  Documents  hello.txt      Public     test1
4444.txt       Downloads  lll.gz         snap       testssh.txt
767            _file.txt  Music          Templates  Videos
stud@it-20:~$ ls ./Desktop/
f1.txt  ppy.py
stud@it-20:~$ logout
Connection to 192.168.2.224 closed.
stud@it-10:~$ scp -r stud@192.168.2.224:./Desktop ./
stud@192.168.2.224's password: 
f1.txt                                        100%    4     7.4KB/s   00:00    
ppy.py                                        100%   54   219.8KB/s   00:00    
stud@it-10:~$ ls
1          Downloads     file.txt   homestud  Public     test1
4444.txt   f5            fl.gz      Kochev    snap       testssh.txt
and        file2345.txt  gnuplot    misha     spasibo    Untitled.ipynb
Desktop    filesh_zh     hello      Music     Templates  Videos
Documents  _file.txt     hello.txt  Pictures  test       zh_hz.gz
stud@it-10:~$ ls ./Desktop/
f1.txt  ppy.py
stud@it-10:~$ ssh stud@192.168.2.224
stud@192.168.2.224's password: 
Welcome to Ubuntu 22.04.1 LTS (GNU/Linux 5.15.0-48-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage

81 updates can be applied immediately.
To see these additional updates run: apt list --upgradable

Last login: Sat Oct  1 10:47:06 2022 from 192.168.2.140
stud@it-20:~$ ls
106B_11        Desktop    file.txt.save  Pictures   test
192.168.2.140  Documents  hello.txt      Public     test1
4444.txt       Downloads  lll.gz         snap       testssh.txt
767            _file.txt  Music          Templates  Videos
stud@it-20:~$ mkdir midir
stud@it-20:~$ ls
106B_11        Desktop    file.txt.save  Music     Templates    Videos
192.168.2.140  Documents  hello.txt      Pictures  test
4444.txt       Downloads  lll.gz         Public    test1
767            _file.txt  midir          snap      testssh.txt
stud@it-20:~$ cd midir/
stud@it-20:~/midir$ cat > file1.txt
1233456
stud@it-20:~/midir$ cat > file2.txt
7891011
stud@it-20:~/midir$ cd ..
stud@it-20:~$ ls
106B_11        Desktop    file.txt.save  Music     Templates    Videos
192.168.2.140  Documents  hello.txt      Pictures  test
4444.txt       Downloads  lll.gz         Public    test1
767            _file.txt  midir          snap      testssh.txt
stud@it-20:~$ tar -cf miarh.tar midir/
stud@it-20:~$ ls
106B_11        Desktop    file.txt.save  midir     snap       testssh.txt
192.168.2.140  Documents  hello.txt      Music     Templates  Videos
4444.txt       Downloads  lll.gz         Pictures  test
767            _file.txt  miarh.tar      Public    test1
stud@it-20:~$ logout
Connection to 192.168.2.224 closed.
stud@it-10:~$ scp -r stud@192.168.2.224:./miarh.tar ./
stud@192.168.2.224's password: 
miarh.tar                                     100%   10KB 267.1KB/s   00:00    
stud@it-10:~$ ls
1          Downloads     fl.gz      miarh.tar  spasibo         Videos
4444.txt   f5            gnuplot    misha      Templates       zh_hz.gz
and        file2345.txt  hello      Music      test
arh.tar    filesh_zh     hello.txt  Pictures   test1
Desktop    _file.txt     homestud   Public     testssh.txt
Documents  file.txt      Kochev     snap       Untitled.ipynb
stud@it-10:~$ tar -xf miarh.tar 
stud@it-10:~$ ls
1          Downloads     fl.gz      miarh.tar  snap         Untitled.ipynb
4444.txt   f5            gnuplot    midir      spasibo      Videos
and        file2345.txt  hello      misha      Templates    zh_hz.gz
arh.tar    filesh_zh     hello.txt  Music      test
Desktop    _file.txt     homestud   Pictures   test1
Documents  file.txt      Kochev     Public     testssh.txt
stud@it-10:~$ cd midir/
stud@it-10:~/midir$ ls
file1.txt  file2.txt
stud@it-10:~/midir$ cat file1.txt 
1233456
stud@it-10:~/midir$ cat file2.txt 
7891011
stud@it-10:~/midir$ 
stud@it-10:~/midir$ cd ..
stud@it-10:~$ 
```
## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | .10.22 | 13:00 | Выполнение лабораторной работы | - | - |
## 10. Замечания автора по существу работы — Написание команд для отработки навыков работы в ОС UNIX.
```
```
## 11. Выводы
Были изучены сетевые команды OC LINUX и приобретены навыки применения их на практике.


Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> ____________________




