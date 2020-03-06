#include <iostream>
#include <cstdint>
#include <cstdio>
#include <queue>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode* leftChild;
    TreeNode* rightChild;
    TreeNode(int _data) : data(_data), leftChild(NULL), rightChild(NULL) {}
};

void visit(int data) {
    printf("%d ", data);
}

// 前序遍历
void PreOrder(TreeNode* root) {
    if(root == NULL) {
        return;
    }
    visit(root->data);
    PreOrder(root->leftChild);
    PreOrder(root->rightChild);
    return;
}

// 中序遍历
void InOrder(TreeNode* root) {
    if(root == NULL) {
        return;
    }
    InOrder(root->leftChild);
    visit(root->data);
    InOrder(root->rightChild);
    return;
}

// 后序遍历
void PostOrder(TreeNode* root) {
    if(root == NULL) {
        return;
    }
    PostOrder(root->leftChild);
    PostOrder(root->rightChild);
    visit(root->data);
    return;
}

// 层序遍历
void LayerOrder(TreeNode* root) {
    queue<TreeNode*> myQ;
    myQ.push(root);
    while (!myQ.empty())
    {
        TreeNode* curr = myQ.front();
        myQ.pop();
        visit(curr->data);
        if(curr->leftChild != NULL) {
            myQ.push(curr->leftChild);
        }
        if(curr->rightChild != NULL) {
            myQ.push(curr->rightChild);
        }
    }
    return;
}

/* 
    比如下面的二叉树结构，
            1
        2               3
     4      5         6
          7   8
 */

TreeNode* makeTree() {
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node8 = new TreeNode(8);

    node1->leftChild = node2;
    node1->rightChild = node3;
    
    node2->leftChild = node4;
    node2->rightChild = node5;

    node5->leftChild = node7;
    node5->rightChild = node8;

    node3->rightChild = node6;

    return node1;
}

int main()
{
    TreeNode *root = makeTree();
    PreOrder(root);
    printf("\n");
    InOrder(root);
    printf("\n");
    PostOrder(root);
    printf("\n");
    LayerOrder(root);
    printf("\n");
    return 0;

}