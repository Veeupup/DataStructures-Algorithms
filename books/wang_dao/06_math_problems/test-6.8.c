/* 

    

 */

#include <stdio.h>
int main()
{
    int a, n;
    while (scanf("%d%d", &n, &a) != EOF)
    {
        int count1[1010] = {0};
        int count2[1010] = {0};
        for (int i = 2; i <= n; i++)
        {
            int t = n;
            while (t)
            {
                count1[i] += t / i;
                t = t / i;
            }
        }
        int ans = 233333333;
        for (int i = 2; i <= a; i++)
        {
            while (a % i == 0)
            {
                count2[i]++;
                a /= i;
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