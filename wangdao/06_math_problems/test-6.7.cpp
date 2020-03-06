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

int num[1010];
int ans[1010];

int GetNum(int x)
{
    int count = 0;
    int i;
    for (i = 1; i * i < x; i++)
    {
        if (x % i == 0)
        {
            count += 2;
        }
    }
    if (i * i == x)
        count++;
    return count;
}

int main()
{
    freopen("data.txt", "r", stdin);
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &num[i]);
            printf("%d\n" ,GetNum(num[i]));
        }
    }

    return 0;
}