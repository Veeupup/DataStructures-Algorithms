#include <vector>
#include <cstdio>
using namespace std;

int main()
{
    vector<int> vi;
    vector<vector<int>> name;
    vector<int> stus[10]; // 定义一个 vector 数组
    vector<int>::iterator it = vi.begin() + 1;

    for (int i = 1; i <= 5; i++)
    {
        vi.push_back(i);
    }
    vi.insert(vi.begin() + 2, -1);
    for (int i = 0; i < vi.size(); i++)
    {
        printf("%d ", vi[i]);
    }
    printf("\n");
    // 删除一个元素
    vi.erase(vi.begin() + 1);
    for (int i = 0; i < vi.size(); i++)
    {
        printf("%d ", vi[i]);
    }
    printf("\n");
    // 删除一个区间内 [first, last) 左闭右开
    vi.erase(vi.begin() + 2, vi.begin() + 4);
    for (int i = 0; i < vi.size(); i++)
    {
        printf("%d ", vi[i]);
    }

    return 0;
}