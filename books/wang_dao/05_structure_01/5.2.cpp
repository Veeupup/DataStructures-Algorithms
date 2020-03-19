#include <iostream>
#include <cstdint>
#include <cstdio>
#include <queue>
using namespace std;

int main()
{
    int n, p, m;
    while (scanf("%d%d%d", &n, &p, &m) != EOF)
    {
        if (n == 0 && p == 0 && m == 0)
            break;
        queue<int> children;
        for (int i = 1; i <= n; i++)
        {
            children.push(i);
        }
        for (int i = 1; i < p; i++)
        { // 让小号编号为 p 的小孩在队首
            children.push(children.front());
            children.pop();
        }
        while (!children.empty())
        {
            for (int i = 1; i < m; i++)
            { // m-1 个小孩依次重新入队伍
                children.push(children.front());
                children.pop();
            }
            if (children.size() == 1)
            { // 只剩一个小孩时特殊处理
                printf("%d\n", children.front());
            }
            else
            {
                printf("%d,", children.front());
            }
            children.pop();
        }
    }
    return 0;
}