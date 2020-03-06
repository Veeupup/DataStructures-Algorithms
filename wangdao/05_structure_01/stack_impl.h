#ifndef __STACK_H__
#define __STACK_H__

typedef int DataType;
typedef struct node {
    DataType data;
    struct node * next;
}Stack;

Stack* CreateStack();
void StackEmpty(Stack* );
void DestroyStack(Stack*);
int IsEmpty(Stack* );
int PushStack(Stack* );
int PopStack(Stack* );
DataType GetTopElement(Stack* );

#endif