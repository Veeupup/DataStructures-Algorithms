/*
 * 清华上机
 *
 * 成绩排序
 *
 * https://www.nowcoder.com/practice/0383714a1bb749499050d2e0610418b1?tpId=40&tqId=21333&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 *
 */
#include <cstdio>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>
using namespace std;

struct Stu {
    string name;
    int score;
    int id;
    Stu(string _name, int _score, int _id): name(_name), score(_score), id(_id)  {}
};

bool cmp1 (Stu a, Stu b) {
    if(a.score == b.score) {
        return a.id < b.id; // 分数相同则返回先录入的
    }else {
        return a.score > b.score;   // 降序排列
    }
}

bool cmp2 (Stu a, Stu b) {
    if(a.score == b.score) {
        return a.id < b.id; // 分数相同则返回先录入的
    }else {
        return a.score < b.score;   // 升序排列
    }
}

vector<Stu> stus;

int main()
{
    freopen("data.txt", "r", stdin);
    int n, type;
    while ( scanf("%d%d", &n, &type) != EOF) {
        string name;
        int score;
        for(int i = 0; i < n; i++) {
            cin >> name >> score;
            stus.push_back(Stu(name, score, i));
        }
        if(type == 0) {
            sort(stus.begin(), stus.end(), cmp1);
        }else {
            sort(stus.begin(), stus.end(), cmp2);
        }
        for (int i = 0; i < n; ++i) {
            cout << stus[i].name << " " << stus[i].score << endl;
        }
    }



    return 0;
}


