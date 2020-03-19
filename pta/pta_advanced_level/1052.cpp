/*
    Author: Veeupup
 */
#include <iostream>
#include <cstdint>
#include <climits>
#include <algorithm>
using namespace std;

#define N 100005
struct node
{
    int addr;
    int data;
    int next;
    bool flag;
} nodes[N];

bool cmp(node a, node b)
{
    if(a.flag == false || b.flag == false)
        return a.flag > b.flag; // a,b 中只要有一个是无效结点，就放到后面去 true=1 > false=0
    else return a.data < b.data;
}

int main()
{
    freopen("data.txt", "r", stdin);
    for (int i = 0; i < N; i++)
    { // 将所有结点初始化为最大值，之后排序可以放到最右边
        nodes[i].flag = false;
    }
    int n, head;
    scanf("%d %d", &n, &head);
    int tempAddr, tempData, tempNext;
    int total = n;
    while (total--)
    { // 读取完成链表内容
        scanf("%d %d %d", &tempAddr, &tempData, &tempNext);
        nodes[tempAddr].addr = tempAddr;
        nodes[tempAddr].data = tempData;
        nodes[tempAddr].next = tempNext;
    }
    int p = head, count = 0;
    while (p != -1)
    {
        nodes[p].flag = true;
        count++;
        p = nodes[p].next;
    }
    if (count == 0)
        printf("0 -1");
    else
    {
        sort(nodes, nodes + N, cmp);
        printf("%d %05d\n", n, nodes[0].addr);
        for (int i = 0; i < count; i++)
        {
            if (i != count - 1)
                printf("%05d %d %05d\n", nodes[i].addr, nodes[i].data, nodes[i+1].addr);
            else
                printf("%05d %d -1\n", nodes[i].addr, nodes[i].data);
        }
    }
    return 0;
}