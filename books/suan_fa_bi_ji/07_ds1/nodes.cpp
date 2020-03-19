/*
    Author: Veeupup
    链表
 */
#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* next;
};

node* create(int arr[], int n) {
    node *p, *pre, *head;   // pre保存当前结点的前驱结点，head为头结点
    head = new node;
    head->next = NULL;  // 初始化为 NULL
    pre = head;
    for (int i = 0; i < n; i++)
    {
        p = new node;
        p->data = arr[i];
        p->next = NULL;
        pre->next = p;
        pre = p;    // 下一个结点的前驱设为 p
    }
    return head;
}

int searchX(node* head, int x) {
    int count = 0;
    node* p = head->next;
    while (p != NULL)
    {
        if(p->data == x) {
            count++;
        }
        p = p->next;
    }
    return count;
}

void insert(node* head, int pos, int x) {
    node* p = head;
    for (int i = 0; i < pos - 1; i++)
    {
        p = p->next;
    }
    node* q = new node;
    q->data = x;
    q->next = p->next;
    p->next = q;
}

void deleteX(node* head, int x) {
    node* p = head->next;
    node* pre = head;
    while (p != NULL)
    {
        if(p->data == x) {
            pre->next = p->next;    // 前驱结点指向该结点下一个结点
            p = p->next;    // 当前结点指向下一个结点
        }else {
            pre = pre->next;    // 前驱结点前进
            p = p->next;    // 当前结点前进
        }
    }
}

int main()
{
    int arr[5] = {3, 5, 1, 3, 7};
    node* head = create(arr, 5);
    node* L = head->next;
    while (L != NULL)
    {
        printf("%d ",L->data);
        L = L->next;
    }
    printf("\n");
    int count = searchX(head, 3);
    printf("counter:3 : %d\n", count);
    insert(head, 2, 10);
    L = head->next;
    while (L != NULL)
    {
        printf("%d ",L->data);
        L = L->next;
    }
    printf("\n");
    deleteX(head, 3);
    L = head->next;
    while (L != NULL)
    {
        printf("%d ",L->data);
        L = L->next;
    }
    return 0;

}