/* 
    给出年月日，计算出该天为该年的第几天
    公元年分除以4不可整除，为平年。
    公元年分除以4可整除但除以100不可整除，为闰年。
    公元年分除以100可整除但除以400不可整除，为平年。
    公元年分除以400可整除，为闰年。
 */

#include <iostream>
#include <cstdio>
using namespace std;

const int monthDay[13][2] = {
    {0, 0}, {31, 31}, {28, 29}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}};

int main()
{
    int year, month, day;
    while (scanf("%d%d%d", &year, &month, &day) != EOF)
    { // 判断是否闰年
        int flag = 0, numDay = 0;
        if ( year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        {
            flag = 1;
        }
        for (int i = 1; i < month ; i++)
        {
            numDay += monthDay[i][flag];
        }
        numDay += day;
        printf("%d\n", numDay);
    };

    return 0;
}