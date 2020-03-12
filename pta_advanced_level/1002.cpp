#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cmath>
#include <climits>

const int MAX = 1e5+10;
double ans[MAX];

int max(int a, int b);
int min(int a, int b);

int main()
{
    int n;
    scanf("%d", &n);
    int maxE = INT_MIN, minE = INT_MAX;
    for (int i = 0; i < n; ++i) {
        int ea;
        double temp;
        scanf("%d", &ea);
        scanf("%lf", &temp);
        ans[ea] += temp;
        maxE = max(maxE, ea);
        minE = min(minE, ea);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int ea;
        double temp;
        scanf("%d", &ea);
        scanf("%lf", &temp);
        ans[ea] += temp;
        maxE = max(maxE, ea);
        minE = min(minE, ea);
    }
    int cnt = 0;   // 记录 A+B的项数
    for (int i = minE; i <= maxE; ++i) {
        if(ans[i] != 0)
                cnt++;
    }
    printf("%d", cnt);
    for (int i = maxE; i >= minE ; --i) {
        if(ans[i] != 0.0) {
            printf(" %d %.1f", i, ans[i]);
        }
    }

    return 0;
}

int max(int a, int b) {
    return a > b ? a : b;
};

int min(int a, int b) {
    return a > b ? b : a;
};
