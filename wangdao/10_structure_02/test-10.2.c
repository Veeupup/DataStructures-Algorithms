#include <stdio.h>
#include <stdint.h>
#include <stdlib.h> // malloc

/* 
    一定要能手写快排，每天写一遍
 */

int Partition(int *arr, int left, int right)
{
    int temp = arr[left];
    while (left < right)
    {
        while (left < right && arr[right] > temp)
            right--;
        arr[left] = arr[right];
        while (left < right && arr[left] <= temp)
            left++;
        arr[right] = arr[left];
    }
    arr[left] = temp;
    return left;
}

void quickSort(int *arr, int left, int right)
{
    if (left < right)
    {
        int position = Partition(arr, left, right);
        quickSort(arr, left, position - 1);
        quickSort(arr, position + 1, right);
    }
}

// 其实也就是把
void quickSort2(int *arr, int left, int right)
{
    if (left < right)
    {
        int i = left;
        int j = right;
        int temp = arr[i];
        while (i < j)
        {
            while (i < j && arr[j] > temp)
                j--;
            arr[i] = arr[j];
            while (i < j && arr[i] <= temp)
                i++;
            arr[j] = arr[i];
        }
        arr[i] = temp;
        quickSort2(arr, left, i - 1);
        quickSort2(arr, i + 1, right);
    }
}

int main()
{
    freopen("data.txt", "r", stdin);
    int n;
    int *arr;
    while (scanf("%d", &n) != EOF)
    {
        arr = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        quickSort2(arr, 0, n - 1);
        int k;
        scanf("%d", &k);
        int pre = -1;
        int position = 0;
        while (k--)
        {
            while (arr[position] == pre)
                position++;
            pre = arr[position];
        }
        printf("%d\n", pre);
    }

    return 0;
}
