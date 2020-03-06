#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[201];

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int i;
        for (i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        // sort(arr, arr + n);
        int key;
        bool flag = true;
        scanf("%d", &key);
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == key)
            {
                printf("%d\n", i);
                flag = false;
                break;
            }
        }
        if (flag)
            printf("-1\n");
        // 二分查找
        // int pos = -1;
        // int left = 0, right = n - 1;
        // while (left <= right)
        // {
        //     int mid = left + (right - left) / 2;
        //     if (arr[mid] == key)
        //     {
        //         pos = mid;
        //         break;
        //     }
        //     else if (arr[mid] > key)
        //     {
        //         right = mid - 1;
        //     }
        //     else
        //         left = mid + 1;
        // }
        // printf("%d\n", pos);
    }

    return 0;
}