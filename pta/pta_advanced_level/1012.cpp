/*
    Author: Veeupup
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdint>
#define LOCAL
using namespace std;

struct Stu
{
    int id, best;
    int sco[4], rnk[4];
};

int exited[1000000];    // hash 看是否存在
int flag = 0;

bool compare(Stu stu1, Stu stu2) {
    return stu1.sco[flag] < stu2.sco[flag];
}

int main()
{
#ifdef LOCAL
    freopen("data.txt","r", stdin);
#endif
    int n, m;
    scanf("%d %d", &n, &m);
    vector<Stu> stu(n); // 默认大小为 n 的数组
    fill(exited, exited + 1000000, -1);   // 用 -1 填充，之后看是否存在
    // 1. input
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d %d", &stu[i].id, &stu[i].sco[1], &stu[i].sco[2], &stu[i].sco[3]);
        stu[i].sco[0] = (stu[i].sco[1] + stu[i].sco[2] + stu[i].sco[3]) / 3;
        exited[stu[i].id] = i;  // 表示存在
    }
    // 2.find the rank
    for (int j = 0; j < 4; j++)
    {
        int last = 0;
        for (int i = 1; i <= n; i++)
        {   // 选出最大的元素
            vector<Stu>::iterator it = max_element(stu.begin(), stu.end(), compare);
            int r = i;  // rank
            if(it->sco[j] == last) {
                r--;
            }
            last = it->sco[j];
            it->rnk[j] = r;
             // let it less than others, and then find next max_element
            it->sco[j] = -1;
        }
        flag++;   
    }
    // 3. find the best rank of position
    // ** while i's rank equals to i+p's rank, min_element returns i
    for(int i = 0; i < n; i++) {
        int *p = min_element(stu[i].rnk, stu[i].rnk+4);
        stu[i].best = p - stu[i].rnk;  // position
    }
    // 4. output
    char c[5] = "ACME";
    for(int k = 1; k <= m; k++) {
        int id;
        scanf("%d", &id);
        if(exited[id] != -1) {
            int i = exited[id];
            int j = stu[i].best;
            printf("%d %c", stu[i].rnk[j], c[j]);
        } else {
            printf("N/A");
        }
        if(k != m) printf("\n");
    }
    return 0;

}