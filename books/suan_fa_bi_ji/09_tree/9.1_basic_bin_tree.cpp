/*
    Author: Veeupup

    完全二叉树的叶子结点判定方法：
        该结点的左子结点的编号 root*2 大于结点的总个数
    判断某个节点是否为空结点：
        该结点下标 root 大于总结点个数 n

 */
#include <iostream>
#include <cstdint>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

node* newNode(int v) {
    node* Node = new node;  // 申请一个 node 型变量的地址空间
    Node->data = v;
    Node->left = Node->right = NULL;
    return Node;
}

/* 
    查找值为 x 的结点，并且把值替换为 newData
 */
void search(node* root, int x, int newData) {
    if(root == NULL)
        return;
    if(root->data == x)
        root->data = newData;
    search(root->left, x, newData);
    search(root->right, x, newData);
}

/* 
    insert 将在二叉树中插入一个数据域为 x 的新结点
    根结点要使用引用，不然不能插入成功
    因为这样在函数中修改 root 会直接修改原变量
    一般来说，如果需要新建结点，或者对二叉树的结构作出修改，那么就需要加引用 &
    如果仅仅是遍历树，就不用加引用
 */
void insert(node* &root, int x) {
    if(root == NULL) {
        root = newNode(x);
        return;
    }
    if(x < root->data) {
        // x 比当前结点小，则插入到左结点
        insert(root->left, x);
    }else {
        insert(root->right, x);
    }
}

node* create(int data[], int n) {
    node* root = NULL;
    for (int i = 0; i < n; i++)
    {
        insert(root, data[i]);
    }
    return root;
}

int main()
{
    freopen("data.txt","r", stdin);
    



    return 0;

}