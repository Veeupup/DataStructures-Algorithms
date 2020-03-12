/*
 * 清华上机
 *
 * 约数的个数
 *
 * https://www.nowcoder.com/practice/04c8a5ea209d41798d23b59f053fa4d6?tpId=40&tqId=21334&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 */
#include <cstdio>
#include <cmath>
#include <cstdint>

int getNum(int temp) {
    int count = 0, i;
    for (i = 1; i * i < temp; ++i) {
        if(temp % i == 0)
            count += 2;
    }
    if(i * i == temp)
        count++;
    return count;
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF) {
        int temp;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &temp);
            printf("%d\n", getNum(temp));
        }
    }
}

