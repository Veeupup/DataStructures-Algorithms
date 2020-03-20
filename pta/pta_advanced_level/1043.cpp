/*
    Author: Veeupup
    Is it a Binary Search Tree?
    判断给定的树是否为一颗二叉查找树

    先将给定的数据输入构建一颗查找二叉树，然后分别进行前序遍历
    对于镜像的遍历，只需要先访问右子树再访问左子树即可

 */
#include <cstdio>
#include <cstdint>
#include <vector>
using namespace std;

struct node
{
    int data;
    node *left, *right;
    node(int _data) : data(_data), left(NULL), right(NULL) {}
};

void insert(node* &root, int x)
{
    if (root == NULL)
    {
        root = new node(x);
        return;
    }
    else if (x < root->data)
    {
        insert(root->left, x);
    }
    else
    {
        insert(root->right, x);
    }
}

// 前序遍历
void preOrder(node *root, vector<int> &vi)
{
    if (root == NULL)
        return;
    vi.push_back(root->data);
    preOrder(root->left, vi);
    preOrder(root->right, vi);
}

// 镜像前序遍历
// 先访问右子树，后访问左子树
void preOrderMirror(node *root, vector<int> &vi) {
    if(root == NULL)
        return;
    vi.push_back(root->data);
    preOrderMirror(root->right, vi);
    preOrderMirror(root->left, vi);
}

// 后序遍历
void postOrder(node* root, vector<int> &vi) {
    if(root == NULL)
        return;
    postOrder(root->left, vi);
    postOrder(root->right, vi);
    vi.push_back(root->data);
}

// 镜像后序遍历
void postOrderMirror(node* root, vector<int> &vi) {
    if(root == NULL)
        return;
    postOrderMirror(root->right, vi);
    postOrderMirror(root->left, vi);
    vi.push_back(root->data);
}

vector<int> origin, pre, preM, post, postM;

int main()
{
    freopen("data.txt", "r", stdin);
    int n, data;
    node* root = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        origin.push_back(data);
        insert(root, data);
    }
    preOrder(root, pre);
    preOrderMirror(root, preM);
    postOrder(root, post);
    postOrderMirror(root, postM);
    if(origin == pre) {
        printf("YES\n");
        for (int i = 0; i < post.size(); i++)
        {
            printf("%d", post[i]);
            if(i < post.size() - 1) printf(" ");
        }
    }else if(origin == preM) {
        printf("YES\n");
        for (int i = 0; i < postM.size(); i++)
        {
            printf("%d", postM[i]);
            if(i < postM.size() - 1) printf(" ");
        }
    }else {
        printf("NO\n");
    }

    return 0;
}