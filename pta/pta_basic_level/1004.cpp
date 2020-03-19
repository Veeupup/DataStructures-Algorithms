/* 
    读入 n（>0）名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。

    输入格式：
    每个测试输入包含 1 个测试用例，格式为

    第 1 行：正整数 n
    第 2 行：第 1 个学生的姓名 学号 成绩
    第 3 行：第 2 个学生的姓名 学号 成绩
    ... ... ...
    第 n+1 行：第 n 个学生的姓名 学号 成绩

      
    
    其中姓名和学号均为不超过 10 个字符的字符串，成绩为 0 到 100 之间的一个整数，这里保证在一组测试用例中没有两个学生的成绩是相同的。

    输出格式：
    对每个测试用例输出 2 行，第 1 行是成绩最高学生的姓名和学号，第 2 行是成绩最低学生的姓名和学号，字符串间有 1 空格。

    输入样例：
        3
        Joe Math990112 89
        Mike CS991301 100
        Mary EE990830 95
        
    输出样例：
        Mike CS991301
        Joe Math990112
 */

#include <iostream>
#include <cstdint>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

struct Stu {
    char name[12];
    char id[12];
    int score;
}stu[101];

bool cmp(Stu a, Stu b) {
    return a.score > b.score;
}

int main()
{
    freopen("data.txt","r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s %d", &stu[i].name, &stu[i].id, &stu[i].score);
    }
    sort(stu, stu+n, cmp);
    printf("%s %s\n", stu[0].name, stu[0].id);
    printf("%s %s\n", stu[n-1].name, stu[n-1].id);

    return 0;

}