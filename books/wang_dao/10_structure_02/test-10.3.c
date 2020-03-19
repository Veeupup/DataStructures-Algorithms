#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

void quickSort(int *arr, int left, int right) {
    if(left < right) {
        int i = left;
        int j = right;
        int key = arr[left];
        while (i < j)
        {
            while (i < j && arr[j] > key) j--;
            arr[i] = arr[j];
            while (i < j && arr[i] < key) i++;
            arr[j] = arr[i];  
        }
        arr[i] = key;
        quickSort(arr, left, i-1);
        quickSort(arr, i+1, right);
    }
}

int main()
{
    freopen("data.txt","r", stdin);
    int n;
    int *arr;
    while (scanf("%d", &n) != EOF)
    {
        if(n == 0)
            break;
        arr = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        quickSort(arr, 0, n-1);
        int ans = 0, i = 1;
        for (int i = 0; i < n-1; i++)
        {
            arr[i+1] = arr[i] + arr[i+1];   // 取最小的两个值
            ans += arr[i+1];
            quickSort(arr, 0, n-1);
        }
        printf("%d\n", ans);
    }
    return 0;
}


