#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"
#include "sort.h"


int main(void){
    Stack stack1;
    Create(&stack1);
    Input(&stack1);
    Sort(&stack1);
    Output(&stack1);
    Destroy(&stack1);
    return 0;
}
