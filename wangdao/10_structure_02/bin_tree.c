#include <stdio.h>
#include <stdint.h>
#include <string.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 或者重新定义名字
// typedef struct TreeNode {
// 	int val;
// 	struct TreeNode *left;
// 	struct TreeNode *right;
// } BiNode, *BiTree;

struct TreeNode *CreateNode(int val)
{
    // 申请空间
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode *));

    root->val = val;
    root->left = NULL;
    root->right = NULL;

    return root;
}

void PreOrder(struct TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->val);
    PreOrder(root->left);
    PreOrder(root->right);
}

struct TreeNode *maketree(){
    struct TreeNode *node1 = CreateNode(1);
    struct TreeNode *node2 = CreateNode(2);
    struct TreeNode *node3 = CreateNode(3);
    struct TreeNode *node4 = CreateNode(4);
    struct TreeNode *node5 = CreateNode(5);
    struct TreeNode *node6 = CreateNode(6);
    struct TreeNode *node7 = CreateNode(7);
    struct TreeNode *node8 = CreateNode(8);

    node1->left = node2;
    node1->right = node3;

    node2->left = node4;
    node2->right = node5;

    node5->left = node7;
    node5->right = node8;

    node3->right = node6;

    return node1;
};

int main()
{
    // freopen("data.txt","r", stdin);
    struct TreeNode *root = makeTree();
    // PreOrder(root);
    printf("\n");
    return 0;
}