#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node
{
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;

void Print( List L)
{
    if(L == NULL) 
    {
        printf("Empty\n");
        return;
    }
    List head = L;
    while (head != NULL)
    {
        printf("%d ", head->Data);
        head = head->Next;
    }
}

List NewNode()
{
    List node = malloc(sizeof(struct Node));
    return node;
}

// 逆转链表，不改变原来的链表
List ReversePro( List L )
{
    if(L == NULL)
        return NULL;
    List before = NULL, head = L, p;
    while (head != NULL)
    {
        p = NewNode();
        p->Data = head->Data;
        p->Next = before;
        before = p;
        head = head->Next;
    }
    return p;
}

// 逆转链表，修改原来的链表
List Reverse( List L )
{
    List before = NULL, head = L, next;
    while(head != NULL)
    {
        next = head->Next;      // 记录当前值的下一个值
        head->Next = before;    // 修改当前结点的下一个为上个结点
        before = head;          // 上一个结点修改为本结点
        head = next;            // 当前结点为下一个结点
    }
    return before;
};

//  根据输入生成单链表
List Read(int arr[], int n)
{
    if(n == 0)
        return NULL;
    List head, pre, p;
    head = NewNode();
    head->Data = arr[0];
    head->Next = NULL;
    pre = head;
    for (int i = 1; i < n; i++)
    {
        p = NewNode();
        p->Data = arr[i];
        p->Next = NULL;
        pre->Next = p;  // 该链表指向链表
        pre = p;    // 修改上一个结点的指针
    }
    return head;
}



int main()
{
    List L1, L2;
    int arr[] = {1, 3, 5, 4, 2};
    L1 = Read(arr, 5);
    Print(L1);
    printf("\n");
    L2 = Reverse(L1);
    Print(L2);
    return 0;
}