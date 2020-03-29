/*
    Author: Veeupup
    堆中的路径

    首先构建小顶堆，然后一路向前找到根结点

    小顶堆的特点，当前结点的值比它的左右子树的值大
    我们先读入一个数列，然后进行小顶堆的调整

 */
#include <iostream>
#include <cstdio>
#include <cstdint>
using namespace std;

const int maxn = 1010;

int n, m, H[maxn];  // 插入元素个数，需要打印路径条数，小顶堆

// 这是给定好所有的元素的时候调整的策略，如果需要插入生成最小对，应该使用向上调整的策略
// 建堆过程应该从上往下来
// 也就是从堆顶向下走，一定能保证每次走到正确的位置
void downAdjust(int low, int high) {
    int i = low, j = i * 2;
    while (j <= high)
    {   // 如果存在父亲节点，那么将两个父亲节点中较小的一个换上来
        if(j + 1 <= high && H[j+1] < H[j]) {
            j = j + 1;
        }
        if(H[j] < H[i]) {   // 如果父亲节点比当前结点小，那么交换
            swap(H[j], H[i]);
            i = j;
            j = j * 2;
        }else { // 如果两个父亲节点都比当前的结点大，那么就调整对来
            break;  
        }
    }   
}

// 向上调整堆结构的过程，我们首先确保之前 high 之前的结构已经是一个最小顶堆
void upAdjust(int low, int high) {
    int i = high, j = high / 2;
    while (j >= low)
    {
        if(H[i] < H[j]) {   // 如果当前结点比父亲节点更小，那么就交换
            swap(H[i], H[j]);
            i = j;  
            j = i / 2;  
        }else { // 如果它比父亲节点更大，那么就结束来
            break;  
        }
    } 
}

int main()
{
    freopen("data.txt","r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &H[i]);
        upAdjust(1, i);
    }
    // for (int i = n/2; i >= 1; i--)
    // {   // 成为叶子结点的最多有 n/2 个
    //     downAdjust(i, n);    // 向下调整下标为 i 的结点
    // }
    int index;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &index);
        int flag = 0;
        while (index != 0)
        {
            if(flag == 0) {
                printf("%d", H[index]);
                flag++;
            }else {
                printf(" %d", H[index]);
            }
            index = index % 2 == 0 ? index / 2 : (index - 1) / 2;
        }
        printf("\n");
    }
    return 0;
}