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
    贪心算法，猎人打猎获取最大奖金
    input:
        1
        2 2
        2 3
        2 2
    output:
        1
 */

const int MAXN = 1001;

long long gun[MAXN];
long long monsters[MAXN];

bool Compare(long long x, long long y)
{
    return x > y;
}

int main()
{
    freopen("data.txt", "r", stdin);
    int caseNumber;
    scanf("%d", &caseNumber);
    while (caseNumber--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &gun[i]);
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%lld", &monsters[i]);
        }
        sort(gun, gun + n, Compare);
        sort(monsters, monsters + m);
        long long answer = 0;
        for (int i = 0; i < n; i++)
        {
            if (i >= m || gun[i] < monsters[i])
            {
                break;
            }
            answer += (gun[i] - monsters[i]);
        }
        printf("%lld\n", answer);
    }

    return 0;
}