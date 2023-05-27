#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

const int Pool_Size = 100;

void Create(Stack* s){
    s->size = 0;
}

bool Empty(Stack* s){
    return s->size == 0 ;
} 

int Size(Stack* s){
    return s->size;
}

bool Push(Stack* s, int t){
    if(s->size >= Pool_Size)
        return false;
    s->data[s->size++] = t;
    return true;
}

bool Pop(Stack* s){
    if (!s->size)
        return false;
    s->size--;
    return true;
}

int Top(Stack* s){
    if(s->size)
        return (s->data[s->size - 1]);
    else
        return 0;
}

void Destroy(Stack* s){
    s->size = 0;
}

void Input(Stack* s){
    int size1 = 0, a = 0;
    if (scanf("%d", &size1) != 1)
        return;
    for (int i = 0; i != size1; ++i){
        if (scanf("%d", &a)){}
        Push(s, a);
    }
}

void Output(Stack* s){
    int size1 = Size(s);
    for (int i = 0; i != size1;++i){
        printf("%d ", Top(s));
        Pop(s);
    }
    printf("\n");
}
