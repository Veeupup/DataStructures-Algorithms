/*
    Author: Veeupup
    World Cup Betting

 */
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <algorithm>
using namespace std;

struct Bet
{
    float num;
    char type;
} Bets[4][4];

bool cmp (Bet a,Bet b) {
    return a.num > b.num;
}

int main()
{
    freopen("data.txt", "r", stdin);
    for (int i = 0; i < 3; i++)
    { // 读取三个
        scanf("%f", &Bets[i][0].num);
        Bets[i][0].type = 'W';
        scanf("%f", &Bets[i][1].num);
        Bets[i][1].type = 'T';
        scanf("%f", &Bets[i][2].num);
        Bets[i][2].type = 'L';
    }
    sort(Bets[0], Bets[0] + 3, cmp);
    sort(Bets[1], Bets[1] + 3, cmp);
    sort(Bets[2], Bets[2] + 3, cmp);
    float total = (Bets[0][0].num * Bets[1][0].num * Bets[2][0].num * 0.65 - 1) * 2;
    printf("%c %c %c %.2f", Bets[0][0].type, Bets[1][0].type, Bets[2][0].type, total);
    return 0;
}