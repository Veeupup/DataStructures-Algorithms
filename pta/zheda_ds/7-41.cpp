#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 105
#define MAXK 305

int N, K;
int persons[MAXN];  // 记录每个考点的人数

struct Person {
    char id[15];    // 十三位的考号
    int score, testCenter;      // 分数，考点
    int rankCenter, rankAll;    // 考点的排名，总排名
}stu[MAXN * MAXK];  // 记录每个人的信息

// 根据分数排名
bool cmp(Person a, Person b)
{
    if(a.score == b.score)
        return strcmp(a.id, b.id) < 0;
    else
        return a.score > b.score;
}

int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d", &N);    // 总考点数目
    int sum = 0, lastPos = 0;   // 上一个排名的最后一个位置
    int level = 1;  // 排名
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &K);    // 该考点的总人数
        for (int j = 1; j <= K; j++)
        {   // 读取学号和分数
            scanf("%s%d", &stu[sum + j].id, &stu[sum + j].score);
            stu[sum + j].testCenter = i;    // 当前学生的考场号
        }
        sum += K;  // 当前总人数
        sort(stu + lastPos + 1, stu + sum + 1, cmp);    // 当前考场排序
        level = 1;
        for (int i = lastPos + 1; i <= sum; i++)
        {
            if(i == lastPos + 1)
            {
                stu[i].rankCenter = level;
            }else 
            {
                if(stu[i].score == stu[i-1].score)
                    stu[i].rankCenter = stu[i - 1].rankCenter;
                else
                    stu[i].rankCenter = level;
            }
            level++;
        }
        lastPos = sum;  // 记录上一个排序的位置的最后一个
    }
    sort(stu + 1, stu + sum + 1, cmp);
    level = 1;
    for (int i = 1; i <= sum; i++)
    {
        if(i == 1)
        {
            stu[i].rankAll = level;
        }else
        {
            if(stu[i].score == stu[i-1].score)
                stu[i].rankAll = stu[i - 1].rankAll;
            else
                stu[i].rankAll = level;
        }
        level++;
    }
    printf("%d\n", sum);
    for (int i = 1; i <= sum; i++)
    {
        printf("%s %d %d %d\n", stu[i].id, stu[i].rankAll, stu[i].testCenter, stu[i].rankCenter);
    }

    return 0;
}