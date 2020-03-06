/* 

    读入一个正整数 n，计算其各位数字之和，用汉语拼音写出和的每一位数字

    输入格式：
    每个测试输入包含 1 个测试用例，即给出自然数 n 的值 这里保证 n 小于 10^100

    输出格式：
    在一行内输出 n 的各位数字之和的每一位，拼音数字间有 1 空格，但一行中最后一个拼音数字后没有空格

    输入样例：
    1234567890987654321123456789

    输出样例：
    yi san wu
    
 */

#include<stdio.h>
#include<stdint.h>

/* 
    注意字符串数组的定义，这里使用的是 C 的二维字符数组
 */

char number[10][5] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };

int main()
{
    freopen("data.txt", "r", stdin);
    int n;
    int sum = 0;
    while(scanf("%1d", &n) != EOF) {
        sum += n;
    }
    int arr[100];
    int counter = 0;
    while (sum != 0)
    {
        arr[counter++] = sum % 10;
        sum /= 10;
    }
    for (int i = counter-1; i >= 0; i--)
    {
        if(i != 0) {
            printf("%s ", number[arr[i]]);
        }else {
            printf("%s\n", number[arr[i]]);
        }
    }
    return 0;
}
