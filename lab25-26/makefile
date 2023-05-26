CC = gcc
PROJECT = lab25

$(PROJECT) : main.o stack.o sort.o
	$(CC) main.o stack.o sort.o -o $(PROJECT) 

main.o : main.c 
	$(CC) -c main.c -o main.o 

stack.o : stack.c 
	$(CC) -c stack.c -o stack.o
sort.o : sort.c
	$(CC) -c sort.c -o sort.o
	
clear :
	rm $(PROJECT) *.oeq
