#include<stdio.h>
#include<stdint.h>

/* 
    鸡兔同笼，输出 最少的动物数 最多的动物数
    input: 
        0
        3
        20
    output:
        0 0
        0 0
        5 10
 */

int main()
{
    freopen("data.txt","r", stdin);
    int a;
    while (scanf("%d", &a) != EOF)
    {
        if(a % 2 != 0) {
            printf("0 0\n");
        }else {
            int temp = a % 4;
            if(temp == 2) { // 所有4只脚的鸡，剩下一只为🐰
                printf("%d %d\n", a / 4 + 1, a / 2);
            }else { // 能够全部为4只脚的🐔
                printf("%d %d\n", a / 4, a / 2);
            }
        }
    }
    return 0;
}