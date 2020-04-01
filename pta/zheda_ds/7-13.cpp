/*
    Author: Veeupup
 */
#include <iostream>
#include <cstdio>
#include <cstdint>
using namespace std;

const int maxn = 55;

int n, age[maxn];

int main()
{
    freopen("data.txt","r", stdin);
    fill(age, age + maxn, 0);
    scanf("%d", &n);
    int temp;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        age[temp]++;
    }
    for (int i = 0; i < maxn; i++)
    {
        if(age[i] != 0) {
            printf("%d:%d\n", i, age[i]);
        }
    }
    return 0;
}