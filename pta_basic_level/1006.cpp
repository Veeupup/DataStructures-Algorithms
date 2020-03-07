/* 
    让我们用字母 B 来表示“百”、字母 S 表示“十”，用 12...n 来表示不为零的个位数字 n（<10），换个格式来输出任一个不超过 3 位的正整数。例如 234 应该被输出为 BBSSS1234，因为它有 2 个“百”、3 个“十”、以及个位的 4。

    输入格式：
    每个测试输入包含 1 个测试用例，给出正整数 n（<1000）。

    输出格式：
    每个测试用例的输出占一行，用规定的格式输出 n。

    输入样例 1：
    234
   
    输出样例 1：
    BBSSS1234
       
    输入样例 2：
    23
      
    输出样例 2：
    SS123

 */
#include <iostream>
#include <cstdint>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    freopen("data.txt","r", stdin);
    int n;
    int arr[5], pos;
    while (scanf("%d", &n) != EOF)
    {
        pos = 0;
        while (n != 0)
        {
            arr[pos++] = n % 10;
            n /= 10;
        }
        for (int i = pos-1; i >= 0; i--)
        {
            if(i == 2) {
                for (int j = 0; j < arr[i]; j++)
                {
                    printf("B");
                }
            }else if(i == 1) {
                for (int j = 0; j < arr[i]; j++)
                {
                    printf("S");
                }
            }else {
                for (int j = 1; j <= arr[i]; j++)
                {
                    printf("%d", j);
                }
            }
        }
        printf("\n");
    }
    return 0;
}