/*
    Author: Veeupup
    题目描述
        输入年、月、日，计算该天是本年的第几天。
    输入描述:
        包括三个整数年(1<=Y<=3000)、月(1<=M<=12)、日(1<=D<=31)。
    输出描述:
        输入可能有多组测试数据，对于每一组测试数据，
        输出一个整数，代表Input中的年、月、日对应本年的第几天。

    input:
        1990 9 20
        2000 5 1

    output:
        263
        122

    https://www.nowcoder.com/practice/ae7e58fe24b14d1386e13e7d70eaf04d?tpId=40&tqId=21350&tPage=1&rp=1&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking
 */
#include <iostream>
#include <cstdint>
#include <cstdio>
#include <algorithm>
using namespace std;

int monthDay[13][2] = {
    {0, 0}, {31, 31}, {28, 29}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}};

int isRun(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        return 1;
    return 0;
}

int main()
{
    freopen("data.txt", "r", stdin);
    int year, month, day;
    while (scanf("%d%d%d", &year, &month, &day) != EOF)
    {
        int run = isRun(year);
        int num = 0;
        for (int i = 0; i < month; i++)
        {
            num += monthDay[i][run];
        }
        num += day;
        printf("%d\n", num);
    }

    return 0;
}