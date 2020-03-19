#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 83;
int arr[maxn] = {0};
bool peak[maxn] = {false};

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
        }
        arr[0] = arr[2];
        arr[n+1] = arr[n-1];
        for (int i = 1; i <= n; i++)
        {
            if ((arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) || (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]))
            {
                peak[i-1] = true;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (peak[i])
                printf("%d ", i);
        }
        for(int i=0;i<80;i++) {
            peak[i] = false;
        }
        printf("\n");
    }

    return 0;
}