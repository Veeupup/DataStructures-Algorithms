#include <iostream>
#include <string>
using namespace std;

struct node {
    char data;
    node *left, *right;
    node(char _data): data(_data), left(NULL), right(NULL) {}
};

int n;  // 总结点数目
string preOrder, inOrder;

node *createTree(int preL, int preR, int inL, int inR) {
    if(preL > preR)
        return NULL;
    char nowChar = preOrder[preL];
    node *root = new node(nowChar);
    int pos = inOrder.find(nowChar);
    int len = pos - inL;    // 左子树的长度
    root->left = createTree(preL + 1, preL + len, inL, pos - 1);
    root->right = createTree(preL + len + 1, preR, pos + 1, inR);
    return root;
}

int getHeight(node *root) {
    if(root == NULL)
        return 0;
    else
        return max(getHeight(root->left), getHeight(root->right)) + 1;
}

int main()
{
    cin >> n >> preOrder >> inOrder;
    node *root = createTree(0, preOrder.size()-1, 0, inOrder.size() - 1);
    printf("%d", getHeight(root));
    return 0;
}