#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1000005;
struct contest
{
    ll startTime, endTime;
} games[maxn];
bool cmp(contest a, contest b)
{
    return a.endTime < b.endTime;
}
int main()
{
    ll n;
    scanf("%lld", &n);
    for (ll i = 0; i < n; i++)
    {
        scanf("%lld%lld", &games[i].startTime, &games[i].endTime);
    }
    sort(games, games + n, cmp); // 按照结束时间排序
    ll count = 0, nowTime = -1;
    for (ll i = 0; i < n; i++)
    {
        if (games[i].startTime >= nowTime)
        {
            count++;
            nowTime = games[i].endTime;
        }
    }
    printf("%d", count);
    return 0;
}