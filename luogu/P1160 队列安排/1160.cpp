#include <iostream>
#include <cstdio>
using namespace std;
struct Node
{
    int L, R;
} nodes[100003];
int n, m;
void insertRight(int x, int pos)
{
    nodes[x].L = pos;
    nodes[nodes[pos].R].L = x;
    nodes[x].R = nodes[pos].R;
    nodes[pos].R = x;
}
void insertLeft(int x, int pos)
{
    nodes[x].R = pos;
    nodes[nodes[pos].L].R = x;
    nodes[x].L = nodes[pos].L;
    nodes[pos].L = x;
}
void del(int x)
{
    if(nodes[x].L == -1)
        return;
    nodes[nodes[x].L].R = nodes[x].R;
    nodes[nodes[x].R].L = nodes[x].L;
    nodes[x].L = -1;
    nodes[x].R = -1;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        nodes[i].L = nodes[i].R = -1;
        nodes[1].R = -1;
        nodes[1].L = 0;
        nodes[0].R = 1;
    }
    int k, p;
    for (int i = 2; i <= n; i++)
    {
        scanf("%d%d", &k, &p);
        if(p == 0)
            insertLeft(i, k);
        else
            insertRight(i, k);
    }
    int m, tempId;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &tempId);
        del(tempId);
    }
    int x = nodes[0].R;
    bool flag = false;
    while (1)
    {
        if(!flag) {
            printf("%d", x);
            flag = true;
        }else
            printf(" %d", x);
        if (nodes[x].R == -1)
            break;
        x = nodes[x].R;
    }
    printf("\n");
    return 0;
}