#include <queue>
#include <iostream>
using namespace std;

struct fruit {
    string name;
    int price;
    fruit(string _name, int _price): name(_name), price(_price) {}
    friend bool operator< (const fruit& f1, const fruit& f2) {
        return f1.price < f2.price;
    }
};

int main()
{
    priority_queue<fruit> q;
    q.push(fruit("桃子", 3));
    q.push(fruit("梨子", 4));
    q.push(fruit("苹果", 1));
    cout << q.top().name << " " << q.top().price << endl;

    return 0;
}