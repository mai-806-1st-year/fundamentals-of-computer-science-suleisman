#ifndef _Stack_H_
#define _Stack_H_


typedef struct {
    int size;
    int data[100];
} Stack;

void Create(Stack* s);
bool Empty(Stack* s);
int Size(Stack* s);
bool Push(Stack* s, int t);
bool Pop(Stack* s);
int Top(Stack* s);
void Destroy(Stack* s);
void Input(Stack* s);
void Output(Stack* s);

#endif
