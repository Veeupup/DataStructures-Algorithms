/* 
    日期问题，给出年份 n 和 第m天，计算出该天的年份月份日期
 */
#include <iostream>
#include <cstdio>
using namespace std;

const int monthDay[13][2] = {
    {0, 0}, {31, 31}, {28, 29}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}};

// 判断是否闰年
bool IsLeapYear(int year)
{
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int main()
{
    int year, day;
    while (scanf("%d%d", &year, &day) != EOF)
    {
        int mm = 0, dd = 0, flag = 0;
        if (IsLeapYear(year))
            flag = 1;
        while ( (day - monthDay[mm][flag]) > 0)
        {
            day -= monthDay[mm][flag];
            mm++;
        }
        printf("%4d-%02d-%02d\n", year, mm, day);
    }

    return 0;
}