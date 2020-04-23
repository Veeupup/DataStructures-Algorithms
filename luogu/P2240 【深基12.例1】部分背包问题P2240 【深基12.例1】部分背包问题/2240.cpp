#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct money {
    int m, v;
    float pvm;  // 每千克的价值
} stores[110];

bool cmp(money a, money b)
{
    return a.pvm > b.pvm;
}

int main()
{
    int N, T;
    scanf("%d%d", &N, &T);
    int tempW, tempC;
    for (int i = 0; i < N; i++)
    {
        scanf("%d%d", &stores[i].m, &stores[i].v);
        stores[i].pvm = stores[i].v * 1.0 / stores[i].m;
    }
    sort(stores, stores + N, cmp);  // 按照单位价值排序
    float ans = 0.0;
    for (int i = 0; i < N && T > 0; i++)
    {
        if(T >= stores[i].m) 
        {
            ans += stores[i].v;
            T -= stores[i].m;
        }else {
            ans += T * stores[i].pvm;
            T = 0;
        }
    }
    printf("%.2f", ans);
    return 0;
}