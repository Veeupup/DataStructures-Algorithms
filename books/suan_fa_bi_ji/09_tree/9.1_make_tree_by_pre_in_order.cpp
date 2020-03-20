/*
    Author: Veeupup
    1. 由前序遍历和中序遍历构建二叉树
    2. 由中序遍历和后序遍历构建二叉树

 */
#include <iostream>
#include <cstdint>
using namespace std;

struct node
{
    char data;
    node *left;
    node *right;
    node(char _data) : data(_data), left(NULL), right(NULL) {}
};

string preStr;
string inStr;

/* 
    分别代表前序和中序序列的起始和终止位置
 */
node *createTreeByPreIn(int preL, int preR, int inL, int inR)
{
    if (preL > preR)
        return NULL;
    char x = preStr[preL];
    node *root = new node(x);    
    int pos = inStr.find(x);    // 寻找在中序序列中的下标
    int numLeft = pos - inL;    // 计算该结点的左子树的数量，应该为 pos - inL
    root->left = createTreeByPreIn(preL + 1, preL + numLeft, inL, pos - 1);    // 左子树的先序序列的起止，中序序列的起止
    root->right = createTreeByPreIn(preL + numLeft + 1, preR, pos + 1, inR);
    return root;
}

void postOrder(node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%c", root->data);
}

int main()
{
    freopen("data.txt", "r", stdin);
    while (cin >> preStr >> inStr)
    {
        node *root = NULL;
        // 通过先序和中序遍历来构建二叉树
        root = createTreeByPreIn(0, preStr.size() - 1, 0, inStr.size() - 1);
        postOrder(root);
        printf("\n");
    }

    return 0;
}