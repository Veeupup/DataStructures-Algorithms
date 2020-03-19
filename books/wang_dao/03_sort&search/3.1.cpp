/* 排序算法，对输入的n个数字进行排序输出 */
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int maxn = 101;
int arr[101];

void quickSort(int A[], int left, int right);
int partition(int A[], int left, int right);

void merge(int A[], int L1, int R1, int L2, int R2);
void mergeSort(int A[], int left, int right);

int main()
{
    int n;
    while(scanf("%d", &n) != EOF) 
    {
        for(int i=0;i<n;i++) {
            scanf("%d", &arr[i]);
        }
        // sort(arr, arr+n);
        // quickSort(arr, 0, n-1);
        mergeSort(arr, 0, n-1);
        for(int i=0;i<n;i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }


    return 0;
}

int Partition(int A[], int left, int right) {
    int temp = A[left];
    while (left < right)
    {
        while(left < right && A[right] > temp) right--;
        A[left] = A[right];
        while(left < right && A[left] < temp) left++;
        A[right] = A[left];
    }
    A[left] = temp;
    return left;
}

void quickSort(int A[], int left, int right) {
    if(left < right) {
        int pos = Partition(A, left, right);
        quickSort(A, left, pos - 1);
        quickSort(A, pos + 1, right);
    }
}

void merge(int A[], int L1, int R1, int L2, int R2)
{
    int i = L1, j = L2;
    int temp[maxn], index = 0;
    while (i <= R1 && j <= R2)
    {
        if (A[i] <= A[j])
        {
            temp[index++] = A[i++];
        }
        else
        {
            temp[index++] = A[j++];
        }
    }
    while (i <= R1)
        temp[index++] = A[i++];
    while (j <= R2)
        temp[index++] = A[j++];
    for (int i = 0; i < index; i++)
    {
        A[L1 + i] = temp[i];
    }
}

// 递归实现
void mergeSort(int A[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid + 1, right);
        merge(A, left, mid, mid + 1, right);
    }
}
