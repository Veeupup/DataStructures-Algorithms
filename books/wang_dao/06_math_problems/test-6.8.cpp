/* 
    考察：
        1.素数筛
        2.对n!质因子分解算法
        3.对a质因子分解算法
    int nFac[MAXN]={0};//记录n!的质因数分解后的结果，n!存在质因数i，则aFac[i]=指数
    int aFac[MAXN]={0};//记录a的质因数分解的结果，a存在质因数i，则aFac[i]=指数
    比较n！和a的相同质因数的指数相除的最小值为所求。
    例如:
        6!=2^4+3^2+5^1
        10=2^1*5^1
    有公共质因数：
        2 指数相除为4/1=4
        5 指数相除为1/1=1
    所以答案为1

    这里为什么要求相同质因数相除的最小值呢？
    因为相同质因数相除，每除一次，相当于所有位置上都除了一次
    所有相同质因数的指数都要减1，所以我们求 同质因数相除的最小值 
    就相当于求了 n！ 能够除我们的 a 几次，所以能够做出来

 */
#include <cstdio>
#define N 1010
int prime[N];
int primesize;
bool mark[N];
void init()
{
    for (int i = 0; i < N; i++)
        mark[i] = false;
    for (int i = 2; i < N; i++)
    {
        if (mark[i] == true)
            continue;
        else
        {
            prime[primesize++] = i;
            for (int j = i * i; j < N; j += i)
                mark[j] = true;
        }
    }
}
int main()
{
    init();
    int a, n;
    while (scanf("%d%d", &n, &a) != EOF)
    {
        int count1[N] = {0};
        int count2[N] = {0};
        for (int i = 0; i < primesize; i++)
        {
            int t = n;
            while (t)
            {
                count1[i] += t / prime[i];
                t /= prime[i];
            }
        }
        int ans = 233333333;
        for (int i = 0; i < primesize; i++)
        {
            while (a % prime[i] == 0)
            {
                count2[i]++;
                a /= prime[i];
            }
            if (count2[i] == 0)
                continue;
            if (count1[i] / count2[i] < ans)
                ans = count1[i] / count2[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}