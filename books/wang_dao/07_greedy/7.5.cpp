#include <iostream>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

/* 
    区间贪心, Case Of Fugitive

    input:
        4 4
        1 4
        7 8
        9 10
        12 14
        4 5 3 8
    output:
        Yes
        2 3 1
 */

const int MAXN = 1000;

struct Island
{
    long long left;
    long long right;
};

struct Bridge
{
    long long length;
    long long index;
};

struct Interval
{
    long long minimum;
    long long maxmum;
    long long index; // 区间编号
    // 重载运算符
    bool operator<(Interval x) const
    {
        return maxmum > x.maxmum;
    }
};

// 按照区间的最小值排序
bool IntervalCompare(Interval x, Interval y)
{
    if (x.minimum == y.minimum)
    {
        return x.maxmum < y.maxmum;
    }
    else
    {
        return x.minimum < y.minimum;
    }
}

bool BridgeCompare(Bridge x, Bridge y)
{
    return x.length < y.length;
}

Island island[MAXN];
Bridge bridge[MAXN];
Interval interval[MAXN];
long long answer[MAXN];

bool solve(int n, int m)
{
    priority_queue<Interval> myQueue;
    int position = 0; // 当前区间下标
    int number = 0;   // 搭建桥的数目
    for (int i = 0; i < m; i++)
    {
        while (myQueue.top().maxmum < bridge[i].length && !myQueue.empty())
        {
            myQueue.pop(); // 当前区间无法建造
        }
        while (position < n - 1 &&
               interval[position].minimum <= bridge[i].length &&
               interval[position].maxmum >= bridge[i].length)
        {
            myQueue.push(interval[position]);
            position++;
        }
        if (!myQueue.empty())
        {
            Interval current = myQueue.top();
            myQueue.pop();
            answer[current.index] = bridge[i].index;
            number++;
        }
    }
    return number == n - 1;
}

int main()
{
    freopen("data.txt", "r", stdin);
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        memset(island, 0, sizeof(island));
        memset(bridge, 0, sizeof(bridge));
        memset(interval, 0, sizeof(interval));
        memset(answer, 0, sizeof(answer));
        for (int i = 0; i < n; i++)
        {
            scanf("%lld%lld", &island[i].left, &island[i].right);
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%lld", &bridge[i].length);
            bridge[i].index = i + 1;
        }
        for (int i = 0; i < n - 1; i++)
        {
            interval[i].minimum = island[i + 1].left - island[i].right;
            interval[i].maxmum = island[i + 1].right - island[i].left;
            interval[i].index = i;
        }
        sort(interval, interval + n - 1, IntervalCompare);
        sort(bridge, bridge + m, BridgeCompare);
        if (solve(n, m))
        {
            printf("Yes\n");
            for (int i = 0; i < n - 1; i++)
            {
                printf("%lld\n", answer[i]);
            }
        }
        else
        {
            printf("No\n");
        }
    }

    return 0;
}