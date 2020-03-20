/*
    Author: Veeupup
 */
#include <iostream>
#include <cstdio>
#include <cstdint>
using namespace std;

const int maxn = 100;
// heap 为堆，n为元素个数
int heap[maxn], n = 10;

// 对 heap 数组在 [low, high] 范围进行向下调整
// 其中 low 为欲调整结点的数组下标， high 一般为堆的最后一个元素的数组下标
void downAdjust(int low, int high) {
    int i = low, j = i * 2; // i为调整目标， j 为左孩子
    while (j <= high)   // 存在孩子结点
    {   // 右孩子存在且值大于左孩子
        if(j + 1 <= high && heap[j+1] > heap[j]) {
            j = j + 1;
        }
        // 如果孩子中最大的权值比欲调整结点 i 大
        if(heap[j] > heap[i]) {
            swap(heap[i], heap[j]); // 交换最大权值的孩子与欲调整结点 i
            i = j;      // 保持 i 为欲调整结点，j 为 i 的孩子
            j = 2 * i;
        }else {
            break;  // 孩子都比欲调整结点 i 小，调整结束
        }
    } 
}

/* 
    如果有 n 个元素，那么非叶子结点从 1 开始一直到 n/2 
    从 n/2 倒着枚举结点。
 */
void createHeap() {
    for (int i = n/2; i >= 1; i--)
    {
        downAdjust(i, n);
    }
}

/* 
    删除堆顶元素，并让其仍然保持堆的结构，只需要让最后一个元素覆盖堆顶，然后对根结点进行调整
 */
int popTop() {
    heap[1] = heap[n--];
    downAdjust(1, n);
}

/* 
    往堆中添加一个元素，把想要添加的元素放在数组最后，然后进行向上调整操作
    向上调整总是与父节点比较，如果权值比父亲节点大
    那么交换其与父亲结点，直到到达堆顶或者父亲结点的权值更大
 */
void upAdjust(int low, int high) {
    int i = high, j = high / 2; // j 为父亲结点
    while (j >= low)
    {   // 如果父亲结点的权值比当前权值小，那么交换
        if(heap[j] < heap[i]) {
            swap(heap[i], heap[j]);
            i = j;
            j = i / 2;
        }else {
            break;
        }
    }
}

void heapSort(){
    createHeap();   // 建堆
    for (int i = n; i > 1; i--)
    {
        swap(heap[i], heap[1]);
        downAdjust(1, i-1); // 调整堆顶
    }
    
}

int main()
{
    for (int i = 1; i <= n; i++)
    {
        heap[i] = 100 - i;
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");
    heapSort();
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", heap[i]);
    }
    



    return 0;

}