#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<stdlib.h>

int solve(int m, int n) {
    if(m == 0 || n == 1)
        return 1;   // 没有剩余的苹果了,或者只有一个盘子
    if(m < n) 
        return solve(m ,m);
    else
        return solve(m, n-1) + solve(m-n, n);
}

int main()
{
    freopen("data.txt","r", stdin);
    int k, m, n;
    while (scanf("%d", &k) != EOF)
    {
        while (k--)
        {
            scanf("%d%d", &m, &n);
            printf("%d\n", solve(m, n));
        }
    }
    



    return 0;
}