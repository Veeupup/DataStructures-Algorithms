#include<iostream>
#include<cstdio>
using namespace std;

const int month[13][2] = {
    {0, 0}, {31, 31}, {28, 29}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}};

bool IsLeapYear(int year)
{
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int main()
{
    int n;
    scanf("%d", &n);
    int yy, mm, dd;
    for(int i=0; i<n;i++) 
    {
        scanf("%d%d%d", &yy, &mm, &dd);
        dd++;
        if(dd == month[mm][IsLeapYear(yy)] + 1) {
            dd = 1;
            mm++;
        }
        if(mm == 13) {
            mm = 1;
            yy++;
        }
        printf("%4d-%02d-%02d\n", yy, mm, dd);
    }
    return 0;

}