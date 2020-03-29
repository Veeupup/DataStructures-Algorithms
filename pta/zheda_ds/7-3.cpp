/*
 *  Author: Veeupup
 *  树的同构
 *  
 *  思路
 *  1.  同构的树有一个特点，那就是每一层的结点都是一样的
 *      所以我们只需要使用层序遍历来进行比较就行了
 * 
 *  2.  我们需要读取树，而且需要确定树的根结点
 *      确定树的根结点的时候，我们可以使用一个布尔数组来记录
 *      没有成为过子结点的结点就是根结点
 * 
 *  3. 读取树的过程中，我们不能使用 scanf 直接读取，因为会读到空格和换行，我们可以使用 getchar() 来吃掉空格
 * 
 *  这个题学到了：
 *      getchar() 的用法，同构的树应该如何判断的算法
 *  但是我写的太麻烦了，应该找更简单的写法
 * 
 */
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <queue>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    char data;
    int left, right, layer;
} tree1[11], tree2[11]; // 两棵树分别保存左右两边的信息

bool cmp(Node a, Node b)
{
    return a.data < b.data;
}

int n1, n2;
int head1, head2;                      // 记录头结点
bool isRoot[11] = {true};              // 记录是否是头结点
vector<Node> layers1[15], layers2[15]; // 保存每层的结点
char tempData, tempLeft, tempRight;
string str;
queue<int> myQ;
int nowLayer;

int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d", &n1);
    getchar();
    if (n1 != 0)
    {
        for (int i = 0; i < n1; i++)
        { // 读取信息, 保存到当前的树中
            getline(cin, str);
            tempData = str[0];
            tempLeft = str[2];
            tempRight = str[4];
            tree1[i].data = tempData; // 记录当前的符号
            if (isdigit(tempLeft))
            {
                tree1[i].left = tempLeft - '0';
                isRoot[tempLeft - '0'] = false; // 成为过左子结点
            }
            else
            { // -1 代表该结点不存在
                tree1[i].left = -1;
            }
            if (isdigit(tempRight))
            {
                tree1[i].right = tempRight - '0';
                isRoot[tempRight - '0'] = false; // 成为过右子结点
            }
            else
            { // -1 代表不存在
                tree1[i].right = -1;
            }
        }
        for (int i = 0; i < n1; i++)
        {
            if (isRoot[i])
            {
                head1 = i;
                break;
            }
        }
        myQ.push(head1);
        nowLayer = 1;
        tree1[head1].layer = nowLayer;
        // 层序遍历
        int topId;
        while (!myQ.empty())
        {
            topId = myQ.front();
            nowLayer = tree1[topId].layer;
            layers1[nowLayer].push_back(tree1[topId]); // 记录每一层的数值
            myQ.pop();
            if (tree1[topId].left != -1)
            {
                int left = tree1[topId].left;
                tree1[left].layer = nowLayer + 1;
                myQ.push(left);
            }
            if (tree1[topId].right != -1)
            {
                int right = tree1[topId].right;
                tree1[right].layer = nowLayer + 1;
                myQ.push(right);
            }
        }
    }
    scanf("%d", &n2);
    getchar();
    if (n2 != 0)
    {

        fill(isRoot, isRoot + 11, true);
        for (int i = 0; i < n2; i++)
        {
            getline(cin, str);
            tempData = str[0];
            tempLeft = str[2];
            tempRight = str[4];
            tree2[i].data = tempData; // 记录当前的符号
            if (isdigit(tempLeft))
            {
                tree2[i].left = tempLeft - '0';
                isRoot[tempLeft - '0'] = false;
            }
            else
            { // -1 代表该结点不存在
                tree2[i].left = -1;
            }
            if (isdigit(tempRight))
            {
                tree2[i].right = tempRight - '0';
                isRoot[tempRight - '0'] = false;
            }
            else
            { // -1 代表不存在
                tree2[i].right = -1;
            }
        }
        for (int i = 0; i < n2; i++)
        {
            if (isRoot[i])
            {
                head2 = i;
                break;
            }
        }
        myQ.push(head2);
        nowLayer = 1;
        tree2[head2].layer = nowLayer;
        while (!myQ.empty())
        {
            int topId = myQ.front();
            nowLayer = tree2[topId].layer;
            myQ.pop();
            layers2[nowLayer].push_back(tree2[topId]); // 记录每一层的数值
            if (tree2[topId].left != -1)
            {
                int left = tree2[topId].left;
                tree2[left].layer = nowLayer + 1;
                myQ.push(left);
            }
            if (tree2[topId].right != -1)
            {
                int right = tree2[topId].right;
                tree2[right].layer = nowLayer + 1;
                myQ.push(right);
            }
        }
    }
    bool flag = true;
    for (int i = 0; i <= 11; i++)
    {
        if (layers1[i].size() != layers2[i].size())
        {
            flag = false;
            break;
        }
        else if (layers1[i].size() != 0)
        {
            // 当存在而且不为 0 时，比较两个集合中的数据是否都相同
            sort(layers1[i].begin(), layers1[i].end(), cmp);
            sort(layers2[i].begin(), layers2[i].end(), cmp);
            for (int j = 0; j < layers1[i].size(); j++)
            {
                if (layers1[i][j].data != layers2[i][j].data)
                {
                    flag = false;
                    break;
                }
            }
        }
    }
    if (!flag)
    {
        printf("No");
    }
    else 
    {
        printf("Yes");
    }
    return 0;
}