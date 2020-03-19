#include <iostream>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;


/* 
    二叉树
 */

// 定义节点
struct TreeNode {
    char data;
    TreeNode* leftChild;
    TreeNode* rightChild;
    TreeNode(char c): data(c), leftChild(NULL), rightChild(NULL) {}
};

// 建造二叉树
TreeNode* Build(int& position, string str) {
    char c = str[position++];
    if(c == '#') {
        return NULL;
    }
    TreeNode* root = new TreeNode(c);
    root->leftChild = Build(position, str);
    root->rightChild = Build(position, str);
    return root;
}

void InOrder(TreeNode* root) {
    if(root == NULL) {
        return;
    }
    InOrder(root->leftChild);
    printf("%c ", root->data);
    InOrder(root->rightChild);
    return;
}


int main()
{
    // freopen("data.txt","r", stdin);
    string str;
    while (cin >> str)
    {
        int position = 0;
        TreeNode* root = Build(position, str);
        InOrder(root);
        printf("\n");
    }
    



    return 0;

}