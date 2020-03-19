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

long long root(long long x, long long y, int k)
{
    long long ans = 1;
    while (y != 0)
    {
        if (y % 2 == 1)
        {
            ans *= x;
            ans %= k;
        }
        y /= 2;
        x *= x;
        x %= k;
    }
    return ans;
}

int main()
{
    // freopen("data.txt","r", stdin);
    int x, y, k;
    scanf("%d%d%d", &x, &y, &k);
    int ans = root(x, y, k - 1);
    if (ans == 0)
        ans = k - 1;
    printf("%d\n", ans);
    return 0;
}