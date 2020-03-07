/*
    Author: Veeupup
 */
#include <iostream>
#include <cstdint>
#include <cstdio>
#include <algorithm>
using namespace std;

#define N 101
int arr1[N];
int arr2[N];

int main()
{
    freopen("data.txt","r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    for (int i = 0; i < n; i++)
    {
        arr2[(i+m)%n] = arr1[i];
    }
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if(flag == 0) {
            printf("%d", arr2[i]);
            flag = 1;
        }else {
            printf(" %d", arr2[i]);
        }
    }
    return 0;

}