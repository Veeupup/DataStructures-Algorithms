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
    构造排序二叉树并且输出
    input:
        5
        1 6 5 9 8
    output:
        1 6 5 9 8 
        1 5 6 8 9 
        5 8 9 6 1 
 */

struct Node {
    int data;
    Node *leftChild;
    Node *rightChild;
    Node(int _data) : data(_data), leftChild(NULL), rightChild(NULL) {}
};

Node *Insert(Node *root, int data) {
    if(root == NULL) {
        root = new Node(data);
    }else if(data < root->data) {
        root->leftChild = Insert(root->leftChild, data);
    }else if(data > root->data){
        root->rightChild = Insert(root->rightChild, data);
    }
    return root;
}

bool visit[65535] = {false};

void PreOrder(Node *root) {
    if(root == NULL) {
        return;
    }
    printf("%d ", root->data);
    PreOrder(root->leftChild);
    PreOrder(root->rightChild);
}

void InOrder(Node *root) {
    if(root == NULL) {
        return;
    }
    
    InOrder(root->leftChild);
    printf("%d ", root->data);
    InOrder(root->rightChild);
}

void PostOrder(Node *root) {
    if(root == NULL) {
        return;
    }
    PostOrder(root->leftChild);
    PostOrder(root->rightChild);
    printf("%d ", root->data);
}


int main()
{
    freopen("data.txt","r", stdin);
    int n;
    while (scanf("%d", &n) != EOF)
    {
        Node *root = NULL;
        for (int i = 0; i < n; i++)
        {
            int temp;
            scanf("%d", &temp);
            root = Insert(root, temp);
        }
        PreOrder(root);
        printf("\n");
        InOrder(root);
        printf("\n");
        PostOrder(root);
        printf("\n");
    }
    



    return 0;

}