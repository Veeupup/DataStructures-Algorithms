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
    二叉排序树的构造
        添加节点
    todo:删除节点

    input:
        5
        2 5 1 3 4
    output:
        -1
        2
        2
        5
        3
 */

struct Node {
    int data;
    Node* leftChild;
    Node* rightChild;
    Node(int _data) : data(_data), leftChild(NULL), rightChild(NULL) {}
};

Node *Insert(Node *root, int data, int father) {
    if(root == NULL) {
        root = new Node(data);
        printf("%d\n", father);
    }else if(data < root->data) {
        root->leftChild = Insert(root->leftChild, data, root->data);
    }else {
        root->rightChild = Insert(root->rightChild, data, root->data);
    }
    return root;
}

int main()
{
    //freopen("data.txt","r", stdin);
    int n;
    while (scanf("%d", &n) != EOF)
    {
        Node *root = NULL;
        for (int i = 0; i < n; i++)
        {
            int temp;
            scanf("%d", &temp);
            root = Insert(root, temp, -1);
        }
    }
    



    return 0;

}