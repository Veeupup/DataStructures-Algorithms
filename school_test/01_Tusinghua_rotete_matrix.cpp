//
// Created by 谭巍 on 2020-03-11.
// 北航
//

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

// 顺时针旋转90度
void rotate(int (*a)[10], int len)
{
    // 先上下翻转
    int top = 0, down = len - 1;
    while (top < down) {
        for (int i = 0; i < len; ++i) {
            swap(a[top][i], a[down][i]);
        }
        top++, down--;
    }

    // 沿着对角线翻转
    for (int i = 0; i < len; ++i) {
        for (int j = i+1; j < len; ++j) {
            swap(a[i][j], a[j][i]);
        }
    }

}

// 判断是否相同
bool isSame(int a1[10][10], int a2[10][10], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(a1[i][j] != a2[i][j])
                return false;
        }
    }
    return true;
}

int arr1[10][10];
int arr2[10][10];

int main()
{
    freopen("data.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int i, j;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
           scanf("%d", &arr1[i][j]);
        }
    }
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            scanf("%d", &arr2[i][j]);
        }
    }
    int sec = 0;
    if(isSame(arr1, arr2, n)) {
        printf("%d", sec);
        return 0;
    }
    sec+=90;
    rotate(arr1, n);
    if(isSame(arr1, arr2, n)) {
        printf("%d", sec);
        return 0;
    }
    sec+=90;
    rotate(arr1, n);
    if(isSame(arr1, arr2, n)) {
        printf("%d", sec);
        return 0;
    }
    sec+=90;
    rotate(arr1, n);
    if(isSame(arr1, arr2, n)) {
        printf("%d", sec);
        return 0;
    }
    printf("-1");
    return 0;
}
