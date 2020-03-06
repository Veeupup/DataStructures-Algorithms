#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct point
{
    int x;
    int y;
} arr[1001];

bool cmp(point a, point b)
{
    if (a.x != b.x)
    {
        return a.x < b.x;
    }
    else
    {
        return a.y < b.y;
    }
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &arr[i].x, &arr[i].y);
        }
        sort(arr, arr + n, cmp);
        printf("%d %d\n", arr[0].x, arr[0].y);
    }
    return 0;
}