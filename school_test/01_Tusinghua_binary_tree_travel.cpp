/*
 * 二叉树遍历
 *
 * 建立二叉树，遍历
 *
 *
 */
#include <cstdio>
#include <cstdint>
#include <string>
#include <queue>
#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* leftChild;
    Node* rightChild;
    Node(char c): data(c), leftChild(NULL), rightChild(NULL) {}
};

/*
 * 可以使用 &取地址来进行某个参数的传递
 */
Node *createTree(int &pos, string str) {
    char c = str[pos++];
    if(c == '#')
        return NULL;
    // 按照先序遍历的顺序来进行
    Node *root = new Node(c);
    root->leftChild = createTree(pos, str);
    root->rightChild = createTree(pos, str);
    return root;
}

// 层序遍历
void layerOrder(Node *root) {
    queue<Node*> myQ;
    myQ.push(root);
    while (!myQ.empty()) {
        Node *top = myQ.front();
        myQ.pop();
        printf("%c ", top->data);
        if(top->leftChild != NULL) {
            myQ.push(top->leftChild);
        }
        if(top->rightChild != NULL) {
            myQ.push(top->rightChild);
        }
    }
}

void preOrder(Node *root) {
    if(root == NULL)
        return;
    printf("%c ", root->data);
    preOrder(root->leftChild);
    preOrder(root->rightChild);
}

void midOrder(Node *root) {
    if(root == NULL)
        return;
    midOrder(root->leftChild);
    printf("%c ", root->data);
    midOrder(root->rightChild);
}

void afterOrder(Node *root) {
    if(root == NULL)
        return;
    afterOrder(root->leftChild);
    afterOrder(root->rightChild);
    printf("%c ", root->data);
}

int main()
{
    freopen("data.txt", "r", stdin);
    string str;
    while (cin >> str) {
        int position = 0;
        Node *root = createTree(position, str);
        midOrder(root);
        printf("\n");
        layerOrder(root);
        printf("\n");
    }
    return 0;
}
