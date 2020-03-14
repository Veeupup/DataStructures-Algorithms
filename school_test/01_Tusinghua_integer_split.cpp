/*
 *  清华上机
 *
 *  整数拆分
 *
 * https://www.nowcoder.com/practice/376537f4609a49d296901db5139639ec?tpId=40&tqId=21339&tPage=1&rp=1&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking
 *
 * 这个题可以看作是 完全背包问题，每个物品的重量为 2^(i-1)
 *
 */
#include <cstdio>
#include <cstdint>
#include <algorithm>
using namespace std;

int n, dp[1000002], a[21];

int main()
{
    int i, j, k;
    for (i = 1; i <= 20; ++i) {
        a[i] = 1 << (i-1);
    }
    dp[0] = 1;
    freopen("data.txt", "r", stdin);
    while (scanf("%d", &n) != EOF)
    {
        fill(dp+1, dp+100000, 0);
        // 完全背包解法，从前往后
        for (i = 1; i <= 20; ++i) {
            for (j = a[i]; j <= n; ++j) {
                dp[j] += dp[j - a[i]];
                dp[j] %= 1000000000;
            }
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}
