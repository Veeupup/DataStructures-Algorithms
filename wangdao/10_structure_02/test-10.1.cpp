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
    判断两个二叉搜索树是不是相同

    input:
        2
        567432
        543267
        576342
        0
    output:
        YES
        NO
 */

struct Node
{
    int data;
    Node *leftChild;
    Node *rightChild;
    Node(int _data) : data(_data), leftChild(NULL), rightChild(NULL) {}
};

Node *Insert(Node *root, int x)
{
    if (root == NULL)
    {
        root = new Node(x);
    }
    else if (x < root->data)
    {
        root->leftChild = Insert(root->leftChild, x);
    }
    else
    {
        root->rightChild = Insert(root->rightChild, x);
    }
    return root;
}

int posi;

void PreOrder(Node *root, int seq[])
{
    if (root == NULL)
    {
        return;
    }
    seq[posi++] = root->data;
    PreOrder(root->leftChild, seq);
    PreOrder(root->rightChild, seq);
    return;
}

int main()
{
    freopen("data.txt", "r", stdin);
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
            break;
        // 构造第一棵二叉树
        Node *root = NULL;
        char str[10];
        scanf("%s", str);
        int len = strlen(str);
        for (int i = 0; i < len; i++)
        {
            int x = str[i] - '0';
            root = Insert(root, x);
        }
        posi = 0;
        int seq1[10] = {-1};
        PreOrder(root, seq1);
        for (int i = 0; i < n; i++)
        {
            Node *root1 = NULL;
            char str1[10];
            scanf("%s", str1);
            int len = strlen(str1);
            for (int i = 0; i < len; i++)
            {
                int x = str1[i] - '0';
                root1 = Insert(root1, x);
            }      
            bool flag = true;
            int seq2[10] = {-1};
            posi = 0;
            PreOrder(root1, seq2);
            for (int  i = 0; i < posi; i++)
            {
                if(seq1[i] != seq2[i]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                printf("YES\n");
            }else {
                printf("NO\n");
            }
        }
    }
    return 0;
}