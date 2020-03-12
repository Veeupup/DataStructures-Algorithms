/*
 * 求球的半径和体积
 *
 * pi = arcos(-1)
 */
#include <cstdio>
#include <cmath>
#include <cstdint>

int main()
{
    freopen("data.txt", "r", stdin);
    int x0, y0, z0, x1, y1, z1;
    while (scanf("%d %d %d %d %d %d", &x0, &y0, &z0, &x1, &y1, &z1) != EOF) {
        int x = x0 - x1, y = y0 - y1, z = z0 - z1;
        double r = sqrt(x*x + y*y + z*z);
        double v = (4.0/3.0) * acos(-1) * r*r*r;
        printf("%.3f %.3f\n", r, v);
    }
}
