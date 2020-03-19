#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct Student
{
    int age;
    char name[100];
    int score;
} stu[1000];

bool Compare(Student x, Student y)
{
    if (x.score != y.score)
    {
        return x.score < y.score;
    }
    else if (strcmp(x.name, y.name) != 0)
    {
        return strcmp(x.name, y.name) < 0;
    }
    else
    {
        return x.age < y.age;
    }
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%s%d%d", stu[i].name, &stu[i].age, &stu[i].score);
        }
        sort(stu, stu + n, Compare);
        for (int i = 0; i < n; i++)
        {
            printf("%s %d %d\n", stu[i].name, stu[i].age, stu[i].score);
        }
    }

    return 0;
}