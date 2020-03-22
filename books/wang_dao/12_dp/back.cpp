#include <cstdio>
#include <cstring>

const int maxn = 1010;
char S[maxn];
int dp[maxn][maxn];

int main()
{
  gets(S);
  int len = strlen(S), ans = 1;
  memset(dp, 0, sizeof(dp));
  // 边界
  for(int i = 0; i < len; i++) {
    dp[i][i] = 1;
    if(i < len - 1) {
      if(S[i] == S[i+1]) {
        dp[i][i+1] = 1;
        ans = 2;	// 初始化时注意当前最长回文子串长度
      }
    }
  }
  // 状态转移方程
  for(int L = 3; L <= len; L++) {	// 枚举长度
    for(int i = 0; i + L - 1 < len; i++) {	// 枚举起始端点
      int j = i + L -1;	// 右端点
      if(S[i] == S[j] && dp[i+1][j-1] == 1) {
        dp[i][j] = 1;
        ans = L;	// 更新
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}