#include <stdio.h>

int arr[101];

void merge(int A[], int L1, int R1, int L2, int R2);
void mergeSort(int A[], int left, int right);
void fastSort(int a[], int low, int high);

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        // mergeSort(arr, 0, n - 1);
        fastSort(arr, 0, n-1);
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}

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

void merge(int A[], int L1, int R1, int L2, int R2)
{
    int i = L1, j = L2;
    int temp[101], index = 0;
    while (i <= R1 && j <= R2)
    {
        if (A[i] < A[j])
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

//快速排序
void fastSort(int a[], int low, int high)
{
    if (low < high)
    {

        int i = low, j = high;
        int temp;
        temp = a[i];
        while (i < j)
        {
            while (i < j && a[j] >= temp)
                j--;
            if (i < j)
            {
                a[i] = a[j];
                i++;
            }
            while (i < j && a[i] <= temp)
                i++;
            if (i < j)
            {
                a[j] = a[i];
                j--;
            }
        }
        a[i] = temp;
        fastSort(a, low, i - 1);
        fastSort(a, i + 1, high);
    }
}
