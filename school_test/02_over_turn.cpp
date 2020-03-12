//
// Created by 谭巍 on 2020-03-11.
// 北航
//

/*
 将矩阵旋转的通用方法：

    1.顺时针旋转：先将矩阵上下翻转，再将矩阵元素沿对角线对称交换

    2.逆时针旋转：先将矩阵左右翻转，再将矩阵元素沿对角线对称交换
 */

#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>
using namespace std;

// 打印数组
void print_array(int arr[5][5])
{
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}


// 上下翻转
void flipTop2Down(int(&mat)[5][5], int x, int y, int len) {
    int down = x + len - 1;
    while (down > x) {
        for (int i = y; i < y + len; ++i)
            swap(mat[x][i], mat[down][i]);
        ++x, --down;
    }
}

// 左右翻转
void flipLeft2Right(int(&mat)[5][5], int x, int y, int len) {
    int right = y + len - 1;
    while (y < right) {
        for (int i = x; i < x + len; ++i)
            swap(mat[i][y], mat[i][right]);
        ++y, --right;
    }
}

// 对称
void sym(int(&mat)[5][5], int x, int y, int len) {
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            swap(mat[x+i][y+j], mat[x+j][y+i]);
        }
    }
}

void Baoli();

int arr[5][5];
int a, b, x, y;

int main()
{
    freopen("data.txt", "r", stdin);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }
    scanf("%d%d%d%d", &a, &b, &x, &y);
    x--;y--;
    // Baoli();
    if(a == 1) {
        // 上下翻转
        flipTop2Down(arr, x, y, b);
        // 对称交换
        sym(arr, x, y, b);
    }else {
        flipLeft2Right(arr, x, y, b);
        sym(arr, x, y, b);
    }
    print_array(arr);

    return 0;
}

void Baoli()
{
    int tempArr[5][5];
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            tempArr[i][j] = arr[i][j];
        }
    }
    if(a == 1 && b == 2) {
        // 以 (x,y) 为左上角,顺时针翻转 4 个数
        tempArr[x][y] = arr[x+1][y];
        tempArr[x][y+1] = arr[x][y];
        tempArr[x+1][y] = arr[x+1][y+1];
        tempArr[x+1][y+1] = arr[x][y+1];


    }else if(a == 1 && b == 3) {

        tempArr[x][y] = arr[x+2][y];
        tempArr[x][y+1] = arr[x+1][y];
        tempArr[x][y+2] = arr[x][y];
        tempArr[x+1][y] = arr[x+2][y+1];
        tempArr[x+1][y+1] = arr[x+1][y+1];
        tempArr[x+1][y+2] = arr[x][y+1];
        tempArr[x+2][y] = arr[x+2][y+2];
        tempArr[x+2][y+1] = arr[x+1][y+2];
        tempArr[x+2][y+2] = arr[x][y+2];

    }else if(a == 2 && b == 2) {

        // 以 (x,y) 为左上角,顺时针翻转 4 个数
        tempArr[x][y] = arr[x][y+1];
        tempArr[x][y+1] = arr[x+1][y+1];
        tempArr[x+1][y] = arr[x][y];
        tempArr[x+1][y+1] = arr[x+1][y];



    }else if(a == 2 && b == 3) {

        tempArr[x][y] = arr[x][y+2];
        tempArr[x][y+1] = arr[x+1][y+2];
        tempArr[x][y+2] = arr[x+2][y+2];
        tempArr[x+1][y] = arr[x][y+1];
        tempArr[x+1][y+1] = arr[x+1][y+1];
        tempArr[x+1][y+2] = arr[x+2][y+1];
        tempArr[x+2][y] = arr[x][y];
        tempArr[x+2][y+1] = arr[x+1][y];
        tempArr[x+2][y+2] = arr[x+2][y];

    }

    print_array(tempArr);
}

//
// Created by 谭巍 on 2020-03-11.
//
//#include <cstdio>
//#include <cstdint>
//#include <iostream>
//using namespace std;
//
//void print_array(int arr[5][5])
//{
//    for (int i = 0; i < 5; ++i) {
//        for (int j = 0; j < 5; ++j) {
//            printf("%d ", arr[i][j]);
//        }
//        printf("\n");
//    }
//}
//
//int main()
//{
//    // freopen("data.txt", "r", stdin);
//    int arr[5][5];
//    for (int i = 0; i < 5; ++i) {
//        for (int j = 0; j < 5; ++j) {
//            scanf("%d", &arr[i][j]);
//        }
//    }
//    int a, b, x, y;
//    scanf("%d%d%d%d", &a, &b, &x, &y);
//    x--;y--;
//    int tempArr[3][3];
//    if(a == 1 && b == 2) {
//        // 以 (x,y) 为左上角,顺时针翻转 4 个数
//        tempArr[0][0] = arr[x+1][y];
//        tempArr[0][1] = arr[x][y];
//        tempArr[1][0] = arr[x+1][y+1];
//        tempArr[1][1] = arr[x][y+1];
//
//        for (int i = 0; i < 2; ++i) {
//            for (int j = 0; j < 2; ++j) {
//                arr[x+i][y+j] = tempArr[i][j];
//            }
//        }
//    }else if(a == 1 && b == 3) {
//
//        tempArr[0][0] = arr[x+2][y];
//        tempArr[0][1] = arr[x+1][y];
//        tempArr[0][2] = arr[x][y];
//        tempArr[1][0] = arr[x+2][y+1];
//        tempArr[1][1] = arr[x+1][y+1];
//        tempArr[1][2] = arr[x][y+1];
//        tempArr[2][0] = arr[x+2][y+2];
//        tempArr[2][1] = arr[x+1][y+2];
//        tempArr[2][2] = arr[x][y+2];
//
//        for (int i = 0; i < 3; ++i) {
//            for (int j = 0; j < 3; ++j) {
//                arr[x+i][y+j] = tempArr[i][j];
//            }
//        }
//
//
//    }else if(a == 2 && b == 2) {
//
//        // 以 (x,y) 为左上角,顺时针翻转 4 个数
//        tempArr[0][0] = arr[x][y+1];
//        tempArr[0][1] = arr[x+1][y+1];
//        tempArr[1][0] = arr[x][y];
//        tempArr[1][1] = arr[x+1][y];
//
//        for (int i = 0; i < 2; ++i) {
//            for (int j = 0; j < 2; ++j) {
//                arr[x+i][y+j] = tempArr[i][j];
//            }
//        }
//
//    }else if(a == 2 && b == 3) {
//
//        tempArr[0][0] = arr[x][y+2];
//        tempArr[0][1] = arr[x+1][y+2];
//        tempArr[0][2] = arr[x+2][y+2];
//        tempArr[1][0] = arr[x][y+1];
//        tempArr[1][1] = arr[x+1][y+1];
//        tempArr[1][2] = arr[x+2][y+1];
//        tempArr[2][0] = arr[x][y];
//        tempArr[2][1] = arr[x+1][y];
//        tempArr[2][2] = arr[x+2][y];
//
//        for (int i = 0; i < 3; ++i) {
//            for (int j = 0; j < 3; ++j) {
//                arr[x+i][y+j] = tempArr[i][j];
//            }
//        }
//
//    }
//
//    print_array(arr);
//
//
//    return 0;
//}
