/*
    Author: Veeupup
    判断是否是同一棵二叉搜索树

    

 */
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int _data) : data(_data), left(NULL), right(NULL) {}
};

int n, l; // 二叉树结点数目，需要检查的序列数

Node *insert(Node *&root, int key)
{
    if (root == NULL)
    {
        root = new Node(key);
        return root;
    }
    else if (key < root->data)
    {
        insert(root->left, key);
    }
    else
    {
        insert(root->right, key);
    }
}

// 构建树
Node *createTree(int n)
{
    Node *root = NULL;
    int key;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &key);
        insert(root, key);
    }
    return root;
}

// 先序遍历判断两棵树树否相同
bool Judge(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true; // 空树相同
    if ((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL))
        return false; // 只要有一个存在，一个不存在就不同
    if (root1->data == root2->data)
    { // 数据相同时，比较左右子树
        bool leftSame = Judge(root1->left, root2->left);
        bool rightSame = Judge(root1->right, root2->right);
        return leftSame && rightSame;
    }else { // 数据不同直接`    1
        return false;
    }
}

// 层序遍历
void levelOrder(Node *root)
{
    queue<Node *> myQ;
    myQ.push(root);
    Node *nowNode = NULL;
    while (!myQ.empty())
    {
        nowNode = myQ.front();
        myQ.pop();
        printf("%d ", nowNode->data);
        if (nowNode->left != NULL)
        {
            myQ.push(nowNode->left);
        }
        if (nowNode->right != NULL)
        {
            myQ.push(nowNode->right);
        }
    }
    printf("\n");
}

int main()
{
    freopen("data.txt", "r", stdin);
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
            break;
        scanf("%d", &l);
        Node *originTree = createTree(n); // 生成默认的树
        // levelOrder(originTree);
        for (int i = 0; i < l; i++)
        {
            Node* nowRoot = createTree(n);
            // levelOrder(nowRoot);
            if (Judge(originTree, nowRoot))
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
    }
    return 0;
}