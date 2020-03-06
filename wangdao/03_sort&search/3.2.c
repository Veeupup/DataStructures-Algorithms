#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 1000

struct Student
{
    int age;
    char name[100];
    int score;
}stu[1000];

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%s%d%d", stu[i].name, &stu[i].age, &stu[i].score);
        }
        // 三趟排序，分别对成绩，姓名，年龄
        for (int i = 0; i < n; i++)
        {
            printf("%s %d %d\n", stu[i].name, stu[i].age, stu[i].score);
        }

    }
    return 0;
}
