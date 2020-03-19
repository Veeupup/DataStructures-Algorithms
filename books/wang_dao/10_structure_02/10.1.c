#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<stdlib.h>

#define N 101
/* 
    使用 C 语言构建二叉树
    结构体的使用
 */

struct Node {
    struct Node *leftChild;
    struct Node *rightChild;
    char c;
};

struct Node *CreateNode() {
    struct Node *ret = (struct Node*) malloc (sizeof(struct Node));
    ret->leftChild = NULL;
    ret->rightChild = NULL;
    return ret;
}

void InOrder(struct Node *root) {
    if(root->leftChild != NULL) InOrder(root->leftChild);
    printf("%c ", root->c);
    if(root->rightChild != NULL) InOrder(root->rightChild);
}

// 删除树，怕内存泄漏问题
void Del(struct Node *root) {
    if(root->leftChild) {
        Del(root->leftChild);
        root->leftChild = NULL;
    }
    if(root->rightChild) {
        Del(root->rightChild);
        root->rightChild = NULL;
    }
    free(root);
}

unsigned pos;   // 标记处理到哪里了字符串
char str[N];

struct Node *BuildTree() {
    if(pos >= strlen(str)) return NULL;
    if(str[pos] == '#') {
        pos++;
        return NULL;
    }
    struct Node *p = CreateNode();
    p->c = str[pos++];  // 先序，先获取根结点信息
    p->leftChild = BuildTree();
    p->rightChild = BuildTree();
    return p;
}

int main()
{
    // freopen("data.txt","r", stdin);
    while (gets(str))
    {
        pos = 0;
        struct Node *root = BuildTree();
        InOrder(root);
        printf("\n");
        Del(root);  // 贴心的删除树，释放内存空间
    }
    



    return 0;
}