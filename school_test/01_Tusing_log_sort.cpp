/*
    Author: Veeupup
    sscanf() 函数可以用来从格式化字符串中取得对应的数据

 */
#include <bits/stdc++.h>
using namespace std;

struct Log
{
    char raw[100];
    string time;
    double cost;
    bool operator<(const Log &log)
    {
        if (cost == log.cost)
        {
            return time < log.time;
        }
        else
        {
            return cost < log.cost;
        }
    }
}logs[100];

int main()
{
    freopen("data.txt", "r", stdin);
    int size = 0;
    char name[20], date[20], time[20];
    while (gets(logs[size].raw) && strlen(logs[size].raw) != 0)
    {   // 使用 sscanf() 来从字符串中格式化出需要的字符
        sscanf(logs[size].raw, "%s %s %s %lf", name, date, time, &logs[size].cost);
        logs[size].time = string(date) + string(time);
        size++;
    }
    sort(logs, logs+size);
    for (int i = 0; i < size; i++)
    {
        printf("%s\n", logs[i].raw);
    }
    return 0;
}