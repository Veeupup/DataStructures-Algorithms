#include <stdio.h>
#define N 600

int gcd(int a, int b)
{
    if (b == 0)
        return a + b;
    else
        return gcd(b, a % b);
}

int main()
{
    
    int buf[N];
    int count, n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &buf[i]);
        }
        count = 0;                  //总计0个真分数
        for (int i = 0; i < n; i++) //分母
        {
            for (int j = 0; j < n; j++) //分子
            {
                if (i == j)
                    continue;
                else if (buf[i] > buf[j] && gcd(buf[i], buf[j]) == 1)
                {
                    count++;
                }
            }
        }
        printf("%d\n", count);
    }

    return 0;
}