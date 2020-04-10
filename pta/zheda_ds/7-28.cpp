/* 
    Author: Veeupup
 */
#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1010;

vector<int> inputOrder, preStr, preMirrorStr,postStr, postMirrorStr; // 保存输入的前序遍历的值，保存生成二叉搜索树的序列

struct node
{
    int data;
    node *left, *right;
    node(int _data): data(_data), left(NULL), right(NULL) {}
};

void insert(node* &root, int val) 
{
    if(root == NULL)
    {
        root = new node(val);
        return;
    }else if(val < root->data) {
        insert(root->left, val);
    }else {
        insert(root->right, val);
    }
}

// 后续遍历的值
void postOrder(node *root) {
    if(root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    postStr.push_back(root->data);
}

void postMirrorOrder(node *root) {
    if(root == NULL)
        return;
    postMirrorOrder(root->right);
    postMirrorOrder(root->left);
    postMirrorStr.push_back(root->data);
}

void preOrder(node *root) {
    if(root == NULL)
        return;
    preStr.push_back(root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void preMirrorOrder(node *root) {
    if(root == NULL)
        return;
    preMirrorStr.push_back(root->data);
    preMirrorOrder(root->right);
    preMirrorOrder(root->left);
}

int main()
{
    freopen("data.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int num;
    node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        insert(root, num);
        inputOrder.push_back(num);  //保存
    }
    preOrder(root);
    preMirrorOrder(root);
    if (inputOrder == preStr)
    {
        printf("YES\n");
        postOrder(root);
        for (int i = 0; i < postStr.size(); i++)
        {
            if(i > 0) {
                printf(" ");
            }
            printf("%d", postStr[i]);
        }
    }
    else if (inputOrder == preMirrorStr)
    {
        printf("YES\n");
        postMirrorOrder(root);
        for (int i = 0; i < postMirrorStr.size(); i++)
        {
            if(i > 0) {
                printf(" ");
            }
            printf("%d", postMirrorStr[i]);
        }
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}