/*
    Author: Veeupup
    二叉查找树
    增删查改

 */
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <queue>
using namespace std;

struct node {
    int data;
    node *left, *right;
    node(int _data): data(_data), left(NULL), right(NULL) {}
};

void search(node* root, int key) {
    if(root == NULL) {
        printf("查找失败\n");
        return;
    }
    if(root->data == key) {
        printf("find: %d\n", root->data);
    }else if(key < root->data) {
        // 比该结点小，则去左子树寻找
        search(root->left, key);
    }else {
        // 大于等于该结点，去右子树寻找
        search(root->right, key);
    }
}

// 插入结点，记得带上取地址符
void insert(node* &root, int v) {
    if(root == NULL) {
        root = new node(v);
        return;
    }else if(v == root->data) {
        return; // 已经存在则不必继续
    }
    else if(v < root->data) {
        insert(root->left, v);
    }else {
        insert(root->right, v);
    }
}

// 创建树
node* create(int data[], int n) {
    node* root = NULL;
    for (int i = 0; i < n; i++)
    {
        insert(root, data[i]);
    }
    return root;
}

/* 
    删除结点：
    两种方法：
    1. 寻找比删除结点 大 的 最小结点（后驱）
    2. 寻找比删除结点 小 的 最大结点

    然后将原结点删除，新找到的结点替换原来的位置
 */

// 寻找最大的结点
node* findMax(node* root) {
    while(root->right != NULL) {
        root = root->right;
    }
    return root;
}

node* findMin(node* root) {
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

// 使用 节点N 的前驱 P 来代替 N，==》 在 N 的左子树中删除结点 P
/* 
    思路：
    1. 如果当前结点为空，说明不存在该结点
    2. 如果当前结点 root 的权值恰好为给定的权值 x，那么说明找到来想要删除的结点
        a)  如果当前结点 root 不存在左右孩子，说明是叶子结点，直接删除
        b)  如果存在左孩子，则在左子树中寻找结点前驱 pre，然后让 pre 的数据覆盖root，接着在左子树中删除结点 pre
        c)  如果存在右孩子，则在右子树中寻找结点前驱 next，然后让 next 的数据覆盖root，接着在右子树中删除结点 next
    3.  如果当前结点 root 的权值大于给定的权值，则在左子树中递归删除 x
    4.  如果当前结点 root 的权值小于给定的权值，则在右子树中递归删除 x
 */
void deleteNode(node* &root, int x) {
    if(root == NULL) return;
    if(root->data == x) {
        if(root->left == NULL && root->right == NULL) {
            root = NULL;    // 叶子结点直接删除
        }// 左子树和右子树只需要选择一种
        else if(root->left != NULL) {
            // 左子树不为空，则去左子树中寻找最大的值
            node* pre = findMax(root->left);
            root->data = pre->data;
            deleteNode(root->left, pre->data);  // 直接调用本身来进行删除
        }else if(root->right != NULL) {
            // 右子树不为空
            node* next = findMin(root->right);
            root->data = next->data;
            deleteNode(root->right, next->data);
        }
    }else if(x < root->data) {
        deleteNode(root->left, x);
    }else {
        deleteNode(root->right, x);
    }
}

void levelOrder(node* root) {
    queue<node*> q;
    q.push(root);
    while (!q.empty())
    {
        node* top = q.front();
        q.pop();
        printf("%d ", top->data);
        if(top->left != NULL)
            q.push(top->left);
        if(top->right != NULL)
            q.push(top->right);
    }
    printf("\n");
}


int main()
{
    int arr[8] = {5, 8, 1, 4, 9, 2, 3, 0};
    node* root = create(arr, 8);
    levelOrder(root);
    insert(root, 6);
    levelOrder(root);
    deleteNode(root ,5);
    levelOrder(root);
    return 0;

}