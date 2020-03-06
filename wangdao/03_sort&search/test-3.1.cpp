#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[1001];

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        sort(arr, arr + n);
        printf("%d\n", arr[n - 1]);
        if (n == 1)
        {
            printf("-1\n");
        }
        else
        {
            for (int i = 0; i < n - 1; i++)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
    }

    return 0;
}