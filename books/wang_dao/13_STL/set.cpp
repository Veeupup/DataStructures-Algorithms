/*
    Author: Veeupup
 */
#include <iostream>
#include <set>
using namespace std;

bool hasSame(string s)
{
    set<char> words;
    int len = s.size();
    for (int i = 0; i < len; i++)
    {
        char c = s[i];
        if (words.find(c) == end(words))
        {
            words.insert(c); // 如果不存在就加入 set
        }
        else
        {
            return false; // 只要发现相同，就没了
        }
    }
    return true;
}

int main()
{
    // 初始化，默认比较函数是 less<int>(可以理解为小的放在前面) 容默认会升序排列
    set<int> numbers{8, 7, 3, 4, 5, 1};
    // 提供不同的比较函数 greater<string>
    set<string, greater<string>> words{"one", "two"};

    // 添加元素
    auto pr1 = words.insert("four");
    auto pr2 = words.insert("two");
    // 删除元素
    auto pr3 = numbers.erase(7);
    auto pr4 = numbers.erase(1);
    // 清空所有元素
    numbers.clear();

    /* 
        访问元素
        如果存在，则返回一个指针
        不存在 则返回 std:: end (words)
     */
    numbers.insert(1);
    if (auto it = numbers.find(1) != end(numbers))
    {
        cout << "exist!" << endl;
    }
    else
    {
        cout << "not exist!" << endl;
    }
    string s = "12345678";
    string s1 = string(s, 1, 5);
    cout << s1 << endl;

    string s2 = "abcdefg";
    string s3 = "abb";
    if(hasSame(s2)) {
        cout << "s2无相同" << endl;
    }else {
        cout << "s2有相同" << endl;
    }

    if(hasSame(s3)) {
        cout << "s3无相同" << endl;
    }else {
        cout << "s3有相同" << endl;
    }

    set<int> st;
    st.insert(30);
    st.insert(91);
    st.insert(12);
    set<int>::iterator it = st.begin();
    for (it = st.begin(); it != st.end(); it++)
    {
        printf("%d ", *it);
    }
    

    return 0;
}