/* 
    模拟 Excel 排序


 */
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 100010

int N, C;

struct Stu
{
    int id;
    char name[10];
    int grade;
} stus[MAXN];

bool cmp1(Stu a, Stu b)
{
    return a.id < b.id;
}

bool cmp2(Stu a, Stu b)
{
    if (strcmp(a.name, b.name) == 0)
        return a.id < b.id;
    else
        return strcmp(a.name, b.name) < 0;
}

bool cmp3(Stu a, Stu b)
{
    if (a.grade == b.grade)
        return a.id < b.id;
    else
        return a.grade < b.grade;
}

int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d%d", &N, &C);
    getchar();
    for (int i = 0; i < N; i++)
    {
        scanf("%d%s%d", &stus[i].id, &stus[i].name, &stus[i].grade);
    }
    if (C == 1)
    {
        sort(stus, stus + N, cmp1);
    }
    else if (C == 2)
    {
        sort(stus, stus + N, cmp2);
    }
    else if (C == 3)
    {
        sort(stus, stus + N, cmp3);
    }
    for (int i = 0; i < N; i++)
    {
        if(i != N - 1)
            printf("%06d %s %d\n", stus[i].id, stus[i].name, stus[i].grade);
        else 
            printf("%06d %s %d", stus[i].id, stus[i].name, stus[i].grade);
    }
    return 0;
}