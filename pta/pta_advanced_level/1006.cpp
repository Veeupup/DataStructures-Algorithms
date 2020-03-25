/*
    Author: Veeupup
    Signed in and signed out

 */
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Person
{
    string id, inTime, outTime;
    Person(string _id, string _inTime, string _outTime) : id(_id), inTime(_inTime), outTime(_outTime) {}
};

bool inCmp (Person a, Person b) {
    return a.inTime < b.inTime;
}

bool outCmp (Person a, Person b) {
    return a.outTime > b.outTime;
}

int main()
{
    freopen("data.txt", "r", stdin);
    int n;
    vector<Person> lists;
    scanf("%d", &n);
    string tempId, tempIn, tempOut;
    for (int i = 0; i < n; i++)
    {
        cin >> tempId >> tempIn >> tempOut;
        lists.push_back(Person(tempId, tempIn, tempOut));
    }
    sort(lists.begin(), lists.end(), inCmp);
    cout << lists[0].id << " "; 
    sort(lists.begin(), lists.end(), outCmp);
    cout << lists[0].id;
    return 0;
}