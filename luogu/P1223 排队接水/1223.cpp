#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn = 1005;
int n;
struct person{
    int id;
    ll takingTime;
    float waitingTime;
}lines[maxn];
bool cmp(person a, person b)
{
    return a.takingTime < b.takingTime;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &lines[i].takingTime);
        lines[i].id = i;
    }
    sort(lines + 1, lines + n + 1, cmp);
    ll sum = 0, beforeSum = 0;
    for (int i = 1; i <= n; i++)
    {
        if(i > 1)
            printf(" %d", lines[i].id);
        else
            printf("%d", lines[i].id);
        sum += beforeSum;   // 加上之前等待的人花费的时间
        beforeSum += lines[i].takingTime;   // 后面的人需要加上当前人的花费时间
    }
    printf("\n%.2f", sum * 1.0 / n);
    return 0;
}