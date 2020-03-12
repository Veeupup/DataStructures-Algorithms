/*
 * 成绩排序
 *
 *
 */
#include <cstdio>
#include <cstdint>
#include <algorithm>
using namespace std;

struct Stu {
    int id;
    int score;
}stu[101];

bool cmp(Stu a, Stu b) {
    if(a.score == b.score) {
        return a.id < b.id;
    }else {
        return a.score < b.score;
    }
}

int main()
{
    freopen("data.txt", "r", stdin);
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &stu[i].id, &stu[i].score);
        }
        sort(stu, stu+n, cmp);
        for (int j = 0; j < n; ++j) {
            printf("%d %d\n", stu[j].id,stu[j].score);
        }
    }
    return 0;
}

