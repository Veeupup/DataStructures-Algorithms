/* 
    竟然这道题也可以用打表是我没想到的，需要记住质数表就行
 */
#include <stdio.h>
#include <math.h>

int count[27];
char str[100];

int isPrime(int n)
{
    if(n <= 1)
        return 0;
    int bound = sqrt(n);
    for (int i = 2; i <= bound; i++)
    {
        if(n % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    for (int i = 0; i < 27; i++)
        count[i] = 0;
    scanf("%s", str);
    int minn = 1000, maxn = -1, num;
    for (int i = 0; str[i] != '\0' ; i++)
    {
        num = str[i] - 'a';
        count[num]++;
    }
    for (int i = 0; i < 26; i++)
    {
        if(count[i]==0)
            continue;
        if(count[i]>maxn)
            maxn = count[i];
        if(count[i]<minn)
            minn = count[i];
    }
    if(isPrime(maxn-minn))
        printf("Lucky Word\n%d", maxn-minn);
    else
        printf("No Answer\n0");
    return 0;
}