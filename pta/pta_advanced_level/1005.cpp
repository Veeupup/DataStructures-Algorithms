/*
    Author: Veeupup
    spell it right

 */
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <cstring>
using namespace std;

const int maxn = 105;
// 每个数字
char nums[10][10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

int main()
{
    freopen("data.txt","r", stdin);
    char str[maxn];
    scanf("%s", str);
    int len = strlen(str);
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        int x = str[i] - '0';   // 获取当前位置的数字
        sum += x;
    }
    if(sum == 0) {  // 考虑和为 0 的情况
        printf("zero");
        return 0;
    }
    int arr[1010], num = 0;
    while (sum != 0)
    {
        arr[num++] = sum % 10;
        sum /= 10;
    }
    for (int i = num - 1; i >= 0; i--)
    {
        if(i == num - 1) {
            printf("%s", nums[arr[i]]);
        }else {
            printf(" %s", nums[arr[i]]);
        }
    }
    return 0;
}