/*
    Author: Veeupup
    中位数
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("data.txt", "r", stdin);
    int n;
    int arr[100010];
    while (scanf("%d", &n) != EOF)
    {
        if(n == 0)
            break;
        int val;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        sort(arr, arr + n);
        if (n & 1 == 1)
        {
            printf("%d\n", arr[n / 2]);
        }
        else
        {
            int mean = (arr[n / 2] + arr[n / 2 - 1]) / 2;
            printf("%d\n", mean);
        }
    }

    return 0;
}