# Отчет по лабораторной работе №2 по курсу "Фундументальня информатика" 
<b>Студент группы:</b> <ins>М80-108Б-22 Шелаев Серафим Ильич, номер по списку 25</ins>  
<b>Контакты e mail:</b> <ins>serafimshelaev@mail.ru</ins>  
<b>Работа выполнена:</b> «3» <ins>декабря</ins> <ins>2022</ins> г.
<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins>4 (хорошо)</ins>

<b>Отчет сдан</b> «3» <ins>декабря</ins> <ins>2022</ins> г., <b>итоговая оценка</b>4 <ins> (хорошо)</ins>                                                          

<b>Подпись преподавателя:</b> ________________
## 1. Тема
Отладчик системы программирования OC Unix.
## 2. Цель работы   
Научиться отлаживать простейшие программы, написанные на языке Си.
## 3. Задание (вариант № )

## 4. Оборудование:
ноутбук  Asus Vivobook 15(1920x1080, Intel Core i5 2.4 ГГц, RAM 16 ГБ, SSD 512 ГБ, Windows 11 Home)
## 5. Программное обеспечение:
<b>Операционная система семейства:</b> Microsoft Windows 11<br/> 
<b>Компилятор:</b> GNU Compiler Collection<br/>
<b>Текстовый редактор:</b> Visual Studio Code версия 1.73.0<br/>
## 6. Идея, метод, алгоритм решения задачи (в формах: словесной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)
1.Скомпиилируем исходную программу с помощью ключа компилятора -g
2.Проверим команды gdb.
## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию]. 
Скомпилируем при помощи команды gcc и ключа -g прогрмму lab9.c (gcc -g lab9.c)
Запустим отладку с помощью команды gdb (gdb a.out)
Проделаем все действия по отладке прогрммы.

Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя</b> ________________
## 8. Распечатка протокола 
```
serafim@serafim-VirtualBox:~$ gcc -g -std=c18 lab9.c
serafim@serafim-VirtualBox:~$ gdb ./a.out
GNU gdb (Ubuntu 12.0.90-0ubuntu1) 12.0.90
Copyright (C) 2022 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from ./a.out...
(gdb) help
List of classes of commands:

aliases -- User-defined aliases of other commands.
breakpoints -- Making program stop at certain points.
data -- Examining data.
files -- Specifying and examining files.
internals -- Maintenance commands.
obscure -- Obscure features.
running -- Running the program.
stack -- Examining the stack.
status -- Status inquiries.
support -- Support facilities.
text-user-interface -- TUI is the GDB text based interface.
tracepoints -- Tracing of program execution without stopping the program.
user-defined -- User-defined commands.

Type "help" followed by a class name for a list of commands in that class.
Type "help all" for the list of all commands.
Type "help" followed by command name for full documentation.
Type "apropos word" to search for commands related to "word".
Type "apropos -v word" for full documentation of commands related to "word".
Command name abbreviations are allowed if unambiguous.
(gdb) help data
Examining data.

List of commands:

agent-printf -- Target agent only formatted printing, like the C "printf" function.
append -- Append target code/data to a local file.
append binary -- Append target code/data to a raw binary file.
append binary memory -- Append contents of memory to a raw binary file.
append binary value -- Append the value of an expression to a raw binary file.
append memory -- Append contents of memory to a raw binary file.
append value -- Append the value of an expression to a raw binary file.
call -- Call a function in the program.
disassemble -- Disassemble a specified section of memory.
display -- Print value of expression EXP each time the program stops.
dump -- Dump target code/data to a local file.
dump binary -- Write target code/data to a raw binary file.
dump binary memory -- Write contents of memory to a raw binary file.
dump binary value -- Write the value of an expression to a raw binary file.
dump ihex -- Write target code/data to an intel hex file.
dump ihex memory -- Write contents of memory to an ihex file.
dump ihex value -- Write the value of an expression to an ihex file.
dump memory -- Write contents of memory to a raw binary file.
dump srec -- Write target code/data to an srec file.
dump srec memory -- Write contents of memory to an srec file.
dump srec value -- Write the value of an expression to an srec file.
dump tekhex -- Write target code/data to a tekhex file.
dump tekhex memory -- Write contents of memory to a tekhex file.
dump tekhex value -- Write the value of an expression to a tekhex file.
dump value -- Write the value of an expression to a raw binary file.
dump verilog -- Write target code/data to a verilog hex file.
dump verilog memory -- Write contents of memory to a verilog hex file.
dump verilog value -- Write the value of an expression to a verilog hex file.
explore -- Explore a value or a type valid in the current context.
explore type -- Explore a type or the type of an expression.
explore value -- Explore value of an expression valid in the current context.
find -- Search memory for a sequence of bytes.
init-if-undefined -- Initialize a convenience variable if necessary.
mem -- Define attributes for memory region or reset memory region handling to target-based.
memory-tag -- Generic command for printing and manipulating memory tag properties.
memory-tag check -- Validate a pointer's logical tag against the allocation tag.
memory-tag print-allocation-tag -- Print the allocation tag for ADDRESS.
memory-tag print-logical-tag -- Print the logical tag from POINTER.
memory-tag set-allocation-tag -- Set the allocation tag(s) for a memory range.
memory-tag with-logical-tag -- Print a POINTER with a specific logical TAG.
output -- Like "print" but don't put in value history and don't print newline.
print, inspect, p -- Print value of expression EXP.
print-object, po -- Ask an Objective-C object to print itself.
printf -- Formatted printing, like the C "printf" function.
ptype -- Print definition of type TYPE.
restore -- Restore the contents of FILE to target memory.
set -- Evaluate expression EXP and assign result to variable VAR.
set ada -- Prefix command for changing Ada-specific settings.
set ada print-signatures -- Enable or disable the output of formal and return types for functions in the overloads selection menu.
set ada source-charset -- Set the Ada source character set.
set ada trust-PAD-over-XVS -- Enable or disable an optimization trusting PAD types over XVS types.
set agent -- Set debugger's willingness to use agent as a helper.
set annotate -- Set annotation_level.
set architecture, set processor -- Set architecture of target.
set args -- Set argument list to give program being debugged when it is started.
set auto-connect-native-target -- Set whether GDB may automatically connect to the native target.
set auto-load -- Auto-loading specific settings.
set auto-load gdb-scripts -- Enable or disable auto-loading of canned sequences of commands scripts.
set auto-load libthread-db -- Enable or disable auto-loading of inferior specific libthread_db.
set auto-load local-gdbinit -- Enable or disable auto-loading of .gdbinit script in current directory.
set auto-load python-scripts -- Set the debugger's behaviour regarding auto-loaded Python scripts.
set auto-load safe-path -- Set the list of files and directories that are safe for auto-loading.
set auto-load scripts-directory -- Set the list of directories from which to load auto-loaded scripts.
set auto-solib-add -- Set autoloading of shared library symbols.
set backtrace -- Set backtrace specific variables.
set backtrace limit -- Set an upper bound on the number of backtrace levels.
set backtrace past-entry -- Set whether backtraces should continue past the entry point of a program.--Type <RET> for more, q to quit, c to continue without paging--q
Quit
(gdb) list
1	#include <stdio.h>
2	#include <stdlib.h>
3	
4	int max(int a, int b);
5	int min(int a, int b);
6	int sign(int a);
7	
8	int main(void){
9	    int i=1, j=-30, l=1, ik=i, jk=j, lk=l;
10	    for (int k=0;k<50;k++){
(gdb) list 1
1	#include <stdio.h>
2	#include <stdlib.h>
3	
4	int max(int a, int b);
5	int min(int a, int b);
6	int sign(int a);
7	
8	int main(void){
9	    int i=1, j=-30, l=1, ik=i, jk=j, lk=l;
10	    for (int k=0;k<50;k++){
(gdb) list 10
5	int min(int a, int b);
6	int sign(int a);
7	
8	int main(void){
9	    int i=1, j=-30, l=1, ik=i, jk=j, lk=l;
10	    for (int k=0;k<50;k++){
11	        ik=i;
12	        jk=j;
13	        lk=l;
14	        i=(max(min(ik+jk-lk-k,ik-jk+lk-k), min(k+ik-jk-lk, k-ik-jk+lk)));
(gdb) list 4
1	#include <stdio.h>
2	#include <stdlib.h>
3	
4	int max(int a, int b);
5	int min(int a, int b);
6	int sign(int a);
7	
8	int main(void){
9	    int i=1, j=-30, l=1, ik=i, jk=j, lk=l;
10	    for (int k=0;k<50;k++){
(gdb) breaak 5
Undefined command: "breaak".  Try "help".
(gdb) break 5
Breakpoint 1 at 0x1156: file lab9.c, line 9.
(gdb) run
Starting program: /home/alexey/a.out 
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

Breakpoint 1, main () at lab9.c:9
9	    int i=1, j=-30, l=1, ik=i, jk=j, lk=l;
(gdb) next
10	    for (int k=0;k<50;k++){
(gdb) step
11	        ik=i;
(gdb) continue
Continuing.
Попадание в заданную область 3 8 6 -8
[Inferior 1 (process 28248) exited normally]
(gdb) break
Breakpoint 2 at 0x555555555189: file lab9.c, line 11.
(gdb) quit



```
## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 03.12.22 | 13:00 | Выполнение лабораторной работы | - | - |
## 10. Замечания автора по существу работы — Написание команд для отработки навыков работы в ОС UNIX.
```
```
## 11. Выводы
Был изучен способ отладки программ, написанных на языке Си.  
Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> ____________________




