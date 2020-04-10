/* 
    求最大连通图的大小
 */
#include <iostream>
using namespace std;

const int maxn = 30010;

int n, m; // 学生总数，俱乐部个数
int father[maxn], height[maxn];   // 保留父亲节点,每个节点深度
int group[maxn];

int findFather(int x)
{
    while (x != father[x])
        x = father[x];
    return x;
}

void Union(int x, int y) 
{
    x = findFather(x);
    y = findFather(y);
    if (x != y)
    {
        if(height[x] < height[y]) {
            father[x] = y;
        }else if(height[y] < height[x]) {
            father[y] = x;
        }else {
            father[x] = y;
            height[y]++;
        }
    }
}

int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        father[i] = i; // 初始化
        height[i] = 1;
    }
    int nums, tempId;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &nums);
        int firstId;
        for (int j = 0; j < nums; j++)
        {
            if(j == 0) {
                scanf("%d", &firstId);  // 读取第一个
            }
            else
            {      
                scanf("%d", &tempId);
                Union(firstId, tempId); // 合并到一起
            }
        }
    }
    int maxVal = -1;
    fill(group, group + maxn, 0);
    int stu;
    for (int i = 1; i <= n; i++)
    {
        stu = findFather(i);
        group[stu]++;
        if(group[stu] > maxVal)
            maxVal = group[stu];
    }
    cout << maxVal;
    return 0;
}