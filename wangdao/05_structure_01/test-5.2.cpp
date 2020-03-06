#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    double t;
    double a[1000];
    while (scanf("%lf", &t) != EOF)
    {
        double sum = 0;
        char ch;
        int i = 0;
        a[0] = t;
        while (scanf("%c", &ch) != EOF && ch != '\n')
        {
            double tem;
            scanf("%lf", &tem);
            if (ch == '+')
                a[++i] = tem;
            else if (ch == '-')
                a[++i] = -tem;
            else if (ch == '*')
                a[i] *= tem;
            else if (ch == '/')
                a[i] /= tem;
        }
        for (int j = 0; j <= i; j++)
            sum += a[j];
        cout << sum << endl;
    }
}