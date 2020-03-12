#include <cstdio>
#include <cstdint>
#include <cmath>
#include <vector>
using namespace std;

/*
 * 计算和，输出格式两个注意点：
 *  1 和为0时，需要输出
 *  2 每三位输出逗号，是从低位向高位开始计算的
 */

int main()
{
    freopen("data.txt", "r", stdin);
    int a, b, c;
    scanf("%d%d", &a, &b);
    c = a + b;
    if(c < 0) {
        printf("-");
        c *= -1;
    }
    if(c == 0) {
        printf("0");
        return 0;
    }
    vector<int> nums;
    while (c != 0) {
        nums.push_back(c % 10);
        c /= 10;
    }
    for (int i = nums.size() - 1; i >= 0; --i) {

        printf("%d", nums[i]);
        if(i % 3 == 0 && i != 0) {
            printf(",");
        }
    }


    return 0;
}