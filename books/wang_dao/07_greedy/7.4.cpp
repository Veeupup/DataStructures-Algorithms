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
    区间贪心，选择最多不相交的区间
    input:
        12
        1 3
        3 4
        0 7
        3 8
        15 19
        15 20
        10 15
        8 18
        6 12
        5 10
        4 14
        2 9
        0
    output:
        5

 */

const int MAXN = 1000;

struct Show
{
    int start;
    int end;
};

Show shows[MAXN];

bool Compare(Show x, Show y)
{
    return x.end < y.end;
}

int main()
{
    freopen("data.txt", "r", stdin);
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &shows[i].start, &shows[i].end);
        }
        sort(shows, shows + n, Compare);
        int count = 0, endtime = 0;
        for (int i = 0; i < n; i++)
        {   // 遍历所有的区间，如果当前节目的开始时间大于上一个节目的结束时间
            // 那么选择这个节目开始看
            if(shows[i].start >= endtime) { 
                count++;
                endtime = shows[i].end;
            }
        }
        printf("%d\n", count);
    }

    return 0;
}