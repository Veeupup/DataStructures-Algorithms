#include<stdio.h>
#include<stdlib.h>
#include "stack_impl.h"

int main()
{
    



    return 0;
}

// 新建栈
Stack* CreateStack()
{
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    if(NULL != stack) 
    {
        stack->next = NULL;
        return stack;
    }
    printf("out of place.\n");
    return NULL;
}

// 清空栈
void StackEmpty(Stack* stack) 
{
    while (!IsEmpty(stack))
    {
        PopStack(stack);
    }
    printf("now stack is empty\n");
}
//撤销栈
void DestoryStack(Stack* stack)
{
    free(stack);
    printf("now stack is destoryed. \n");
    exit(0);
}
 
int IsEmpty(Stack* stack)
{
    return (stack->next == NULL);
}

// 撤销栈
int PushStack(Stack* stack, DataType data)
{
    Stack* newst = (Stack*) malloc(sizeof(Stack));
    if(NULL != newst) 
    {
        newst->data = data;
        newst->next = stack->next;
        stack->next = newst;
        return 1;
    }
    printf("Out of place. \n");
}


