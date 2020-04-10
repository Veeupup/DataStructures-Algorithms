#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct msg
{
    char content[12];
    int pri;
    // 写法需要记住
    bool operator<(msg x) const
    {
        return pri > x.pri;
    }
};

priority_queue<msg> Q1; // 默认输出是大顶堆，所以我们要

int main()
{
    freopen("data.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    char type[5], name[12];
    int pri;
    msg node;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", type);
        if (strcmp(type, "PUT") == 0)
        {
            scanf("%s", &node.content);
            scanf("%d", &node.pri);
            Q1.push(node);
        }
        else
        {
            if (Q1.size() > 0)
            {
                msg top = Q1.top();
                Q1.pop();
                printf("%s\n", top.content);
            }
            else
            {
                printf("EMPTY QUEUE!\n");
            }
        }
    }
    return 0;
}