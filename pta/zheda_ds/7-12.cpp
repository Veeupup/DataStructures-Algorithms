/*
    Author: Veeupup
    排序

    我们可以直接用 algorithm 下的 sort
    还是推荐自己把快排可以再写一遍

 */
#include <cstdio>
#include <cstdint>
#include <algorithm>
using namespace std;

const int maxn = 1e5+5;

int n;
long arr[maxn];

void quickSort(long *arr, int left, int right) {
    if(left < right) {
        int i = left, j = right;
        long temp = arr[i];
        while (i < j)
        {
            while(i < j && arr[j] > temp)
                j--;
            arr[i] = arr[j];
            while(i < j && arr[i] <= temp)
                i++;
            arr[j] = arr[i];
        }
        arr[i] = temp;
        quickSort(arr, left, i - 1);
        quickSort(arr, i + 1, right);
    }
}

int main()
{
    freopen("data.txt","r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%ld", &arr[i]);
    }
    // sort(arr, arr+n);
    quickSort(arr, 0, n-1);
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if(flag) {
            printf(" %ld", arr[i]);
        }else {
            printf("%ld", arr[i]);
            flag = true;
        }
    }
    return 0;
}