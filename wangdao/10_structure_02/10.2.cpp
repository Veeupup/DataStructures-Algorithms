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
    前序遍历和后序遍历确定二叉树并且后序遍历输出
    input:
        ABC
        BAC
        FDXEAG
        XDEFAG
    output:
        BCA
        XEDGAF

 */

// 二叉树节点
struct Node {
    char data;
    Node *leftChild;
    Node *rightChild;
    Node(char c) : data(c), leftChild(NULL), rightChild(NULL) {}
};

Node *Build(string str1, string str2) {
    if(str1.size() == 0) {
        return NULL;
    }
    char c = str1[0];
    Node *root = new Node(c);
    int position = str2.find(c);    // 返回出现的位置，从 0 开始，刚好代表这个字符前方的长度
    root->leftChild = Build(str1.substr(1, position), str2.substr(0, position));
    root->rightChild = Build(str1.substr(position+1), str2.substr(position+1));
    return root;
}

// 后序遍历
void PostOrder(Node *root) {
    if(root == NULL) {
        return;
    }
    PostOrder(root->leftChild);
    PostOrder(root->rightChild);
    printf("%c", root->data);
    return;
}

int main()
{
    freopen("data.txt","r", stdin);
    string str1, str2;
    while (cin >> str1 >> str2)
    {
        Node *root = Build( str1, str2);
        PostOrder(root);
        printf("\n");
    }
    return 0;

}