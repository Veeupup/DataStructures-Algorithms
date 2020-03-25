/*
    Author: Veeupup
    分数的四则运算

 */
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <cmath>
using namespace std;

struct Fraction{
    int up, down;
};

int gcd(int a, int b) {
    if(b == 0) return a;
    else return gcd(b, a % b);
}

Fraction reduction(Fraction result) {
    if(result.down < 0) {   // 分母为负数，令分子分母都变味相反数
        result.up = -result.up;
        result.down = -result.down;
    }
    if(result.up == 0) {    // 如果分子为 0，令分母为 1
        result.down = 1;
    }else { 
        int d = gcd(abs(result.up), abs(result.down));  // 分子分母的最大公约数
        result.up /= d; 
        result.down /= d;   // 约去最大公约数
    }
    return result;
}

// 加法
Fraction add(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down + f2.up * f1.down;
    result.down = f1.down * f2.down;
    return reduction(result);
}

// 减法
Fraction minu(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down - f2.up * f1.down;
    result.down = f1.down * f2.down;
    return reduction(result);
}

// 乘法
Fraction mul(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.up;
    result.down = f2.down * f2.down;
    return reduction(result);
}

// 除法
Fraction divide(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down;
    result.down = f1.down * f2.up;
    return reduction(result);
}

void showResult(Fraction r) {
    r = reduction(r);
    if(r.down == 1) printf("%lld", r.up);
    else if(abs(r.up) > r.down) {
        printf("%d %d/%d", r.up / r.down, abs(r.up) % r.down, r.down);
    }else {
        printf("%d %d", r.up, r.down);
    }
}

int main()
{

    return 0;

}