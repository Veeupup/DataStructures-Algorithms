#include<stdio.h>
#include<stdint.h>
#define N 101



int main()
{
    freopen("data.txt","r", stdin);
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if(n == 0)
            break;
        int grades[N] = {0};
        for (int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            grades[x]++;
        }
        int key;
        scanf("%d", &key);
        printf("%d\n", grades[key]);
    }
    



    return 0;
}