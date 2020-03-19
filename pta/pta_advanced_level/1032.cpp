/*
    Author: Veeupup
    使用静态链表，用 next 来指明下一个结点的位置，如果 next 为 -1 表示达到了结尾

    通用步骤：
    1. 定义静态链表
        struct Node
        {
            int addr;   // 结点地址
            char data; // 数据域
            int next;  // 指针域
            bool flag;  // 结点是否在链表中出现
        } nodes[N];     // 使用静态指针

    2. 初始化
    3. 遍历链表
    int p = begin, count = 0;
    while(p != -1) {
        xxx = 1;
        count++;
        p = nodes[p]->next;
    }

 */
#include <bits/stdc++.h>
using namespace std;

#define N 100000
#define DEBUG

struct Node
{
    char data; // 数据域
    int next;  // 指针域
    bool flag;  // 结点是否在链表中出现
} nodes[N];     // 使用静态指针

int main()
{
    freopen("data.txt", "r", stdin);
    for (int i = 0; i < N; i++)
    {
        nodes[i].flag = false;
    }
    int head_1, head_2, n; // 记录两个单词的头指针和字母总数
    scanf("%d %d %d", &head_1, &head_2, &n);
    char nowC;             // 记录临时字符
    int nowAddr, nextAddr; // 记录临时地址
    while (n--)
    {   // 扫描并且记录
        scanf("%d %c %d", &nowAddr, &nowC, &nextAddr);
        nodes[nowAddr].data = nowC;
        nodes[nowAddr].next = nextAddr;
    }
    int p1 = head_1;
    while (p1 != -1)
    {   // 枚举第一条链表的所有结点
        nodes[p1].flag = true;
        p1 = nodes[p1].next;
    }
    int p2 = head_2;
    for (p2 = head_2; p2 != -1; p2 = nodes[p2].next)
    {
        if(nodes[p2].flag == true) break;
    }
    if(p2 != -1)    // 如果第二条链表还没有到达结尾，说明找到了公共结点
        printf("%05d\n", p2);
    else 
        printf("-1\n", p2);
    
    return 0;
}