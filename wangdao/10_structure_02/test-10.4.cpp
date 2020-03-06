#include <iostream>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

/* 
    统计同成绩学生人数
    input:
        3
        80 60 90
        60
        2
        85 66
        0
        5
        60 75 90 55 75
        75
        0
    output:
        1
        0
        2
 */

int main()
{
    freopen("data.txt","r", stdin);
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if(n == 0)
            break;
        map<int, int> grades;
        for (int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            grades[x]++;
        }
        int key;
        scanf("%d", &key);
        printf("%d\n", grades[key]);
    }
    return 0;

}