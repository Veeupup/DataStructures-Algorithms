#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1010;

struct Node
{
    int k1, k2, left, right;
    Node(){}; // 如果要要用 trees，需要定义无参的构造方法
    Node(int _k1, int _k2, int _left, int _right) : k1(_k1), k2(_k2), left(_left), right(_right){};
} trees[maxn];

int root;
bool isRoot[maxn];
vector<int> orders;

bool JudgeHeap(int root); // 判断是否是最小值堆

void InOrder(int root)
{
    if(root == -1)
        return;
    InOrder(trees[root].left);
    orders.push_back(trees[root].k1);
    InOrder(trees[root].right);
}

int main()
{
    freopen("data.txt", "r", stdin);
    fill(isRoot, isRoot + maxn, true);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    { // 结点从 0～n-1
        scanf("%d%d%d%d", &trees[i].k1, &trees[i].k2, &trees[i].left, &trees[i].right);
        if (trees[i].left >= 0)
            isRoot[trees[i].left] = false;
        if (trees[i].right >= 0)
            isRoot[trees[i].right] = false;
    }
    for (int i = 0; i < n; i++)
    { // 寻找根结点
        if (isRoot[i])
        {
            root = i;
            break;
        }
    }
    InOrder(root);

    bool isTree = true;
    for (int i = 0; i < n-1; i++)
    {
        if(orders[i+1] < orders[i]) {
            isTree = false;
            break;
        }
    }
    
    if (isTree && JudgeHeap(root))
        printf("YES");
    else
        printf("NO");
    return 0;
}

bool JudgeHeap(int root)
{
    int nowLeft = trees[root].left, nowRight = trees[root].right;
    int nowK2 = trees[root].k2; // 当前结点的 k2 值
    if (nowLeft == -1 && nowRight == -1)
        return true;
    if (nowLeft >= 0 && trees[nowLeft].k2 > nowK2 && nowRight == -1)
        return JudgeHeap(nowLeft);
    if (nowRight >= 0 && trees[nowRight].k2 > nowK2 && nowLeft == -1)
        return JudgeHeap(nowRight);
    if (nowLeft >= 0 && nowRight >= 0 && trees[nowLeft].k2 > nowK2 && trees[nowRight].k2 > nowK2)
        return JudgeHeap(nowLeft) && JudgeHeap(nowRight);
    return false;
}