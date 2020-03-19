#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#define N 100

// 重命名后就可以直接用来定义
struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode()
{
    struct Node *ret = (struct Node*)malloc(sizeof(struct Node));
    ret->left = NULL;
    ret->right = NULL;
    return ret;
}

void PreOrder(struct Node *root)
{
    if(root == NULL)
        return;
    printf("%c ", root->val);
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(struct Node *root)
{
    if(root == NULL)
        return;
    InOrder(root->left);
    printf("%c ", root->val);
    InOrder(root->right);
}

// 释放内存
void Del(struct Node *root) 
{
    if(root->left != NULL)
    {
        Del(root->left);
        root->left = NULL;
    }
    if(root->right != NULL)
    {
        Del(root->right);
        root->right = NULL;
    }
    free(root); // 删除根结点
}

unsigned pos;   // 标记字符串处理到哪里了
char str[N];    // 读取的字符串

struct Node *BuildTree()
{
    if(pos >= strlen(str))  return NULL;
    if(str[pos] == '#')
    {
        pos++;
        return NULL;
    }
    struct Node *p = createNode();
    p->val = str[pos++];
    p->left = BuildTree();
    p->right = BuildTree();
    return p;
}

int main()
{
    while (gets(str))
    {
        pos = 0;
        struct Node *root = BuildTree();
        PreOrder(root);
        printf("\n");
        InOrder(root);
        printf("\n");
        Del(root);
    }
    
    return 0;
}