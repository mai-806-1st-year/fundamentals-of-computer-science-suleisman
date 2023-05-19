#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sort.h"
#include "stack.h"






void Sort(Stack* s){
    Stack s_garb1;
    Stack s_garb2;
    Stack s_min;
    Create(&s_garb1);
    Create(&s_garb2);
    Create(&s_min);
    int min_el = Top(s);
    Push(&s_min, min_el);
    Pop(s);
    while (s->size != 0){
        if(Top(&s_min) < Top(s)) {
            Push(&s_garb1, Top(s));
            Pop(s);
        }
        else {
            Push(&s_garb1, Top(&s_min));
            Push(&s_min, Top(s));
            Pop(s);
        }        
    }
    Push(s, Top(&s_min));
    Pop(&s_min);
    
    
    while((Size(&s_garb1) > 0) || (Size(&s_garb2) > 0)) {
        
        Push(&s_min, Top(&s_garb1));
        Pop(&s_garb1);
        while (Size(&s_garb1) != 0) {
            if(Top(&s_garb1) >= Top(&s_min)) {
                Push(&s_garb2, Top(&s_garb1));
                Pop(&s_garb1);
            }
            else {
                Push(&s_garb2, Top(&s_min)); 
                Pop(&s_min);
                Push(&s_min, Top(&s_garb1));
                Pop(&s_garb1);
            }         
        }
        Push(s, Top(&s_min));
        Pop(&s_min);
        
        if(Size(&s_garb2) > 0) {
        Push(&s_min, Top(&s_garb2));
        Pop(&s_garb2);
        while(Size(&s_garb2) != 0) {
            if(Top(&s_garb2) >= Top(&s_min)) {
                Push(&s_garb1, Top(&s_garb2));
                Pop(&s_garb2);
            }
            else {
                Push(&s_garb1, Top(&s_min));
                Pop(&s_min);
                Push(&s_min, Top(&s_garb2));
                Pop(&s_garb2);
            }
        }
        Push(s, Top(&s_min));
        Pop(&s_min);
        }
        
        
    }
   
    
}
