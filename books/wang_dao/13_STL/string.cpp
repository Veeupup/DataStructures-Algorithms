#include <iostream>
#include <string>
#include <memory>
using namespace std;

int main()
{
    //  定义，输入输出
    string stuff;
//    cin >> stuff;
//    getline(cin, stuff);
//    cout << stuff << endl;

    // 常见构造函数
    string strs = "hello I am ok"; //
    string s1 (strs);     // 复制strs的内容
    string s2 (strs, 5); // 从下标位置为 5 开始作为构造函数的初值
    string s3 (strs, 6, 4);  // 从下标为 6 开始，复制长度为 4
    string s4 (10, 'a'); // 生成一个长度为10全部为a的字符串
    cout << s1 << " | " << s2 << " | " << s3 << " | " << s4 << endl;

    // 获取字符串长度
    cout << "size of strs : " << strs.length() << endl;
    strs.resize(5);
    cout << strs << " : size of strs : " << strs.length() << endl;

    // 比较字符串
    string A ("aBcdef");
    string B ("AbcdEf");
    string C ("123456");
    string D ("123dfg");
    int m = A.compare(B);   // 完整比较
    int n = A.compare(1, 5, B, 4, 2);
    int p = C.compare(0, 3, D, 0, 3);
    cout << "m = " << m << ", n = " << n <<", p = " << p << endl;

    // 字符串内容的修改
    string str1 = "123456";
    strs.assign(str1);
    cout << "after assign : " << strs << endl;
    strs.assign(str1, 3, 2);
    cout << "after assign : " << strs << endl;
    strs.assign(str1, 2);
    cout << "after assign : " << strs << endl;

    A.assign("ello");
    B.assign("");
    B.insert(0, A);
    cout << B << endl;
    B = "H|aa";
    B.insert(1, "yanchy", 3);
    cout << B << endl;
    B = "H|aa";
    B.insert(1, "yanchy", 3, 2);
    cout << B << endl;

    // 字符串的替换
    string var ("abcdefghijklmn");
    const string dest ("1234");
    string dest2 ("567891234");
    var.replace(3, 3, dest);
    cout << var << endl;

    // 字符串查找
    string str_ch (" for");
    string str (" Hi, Peter, I'm sick. Please bought some drugs for me.");
    string::size_type m1 = str.find('P', 10);
    string::size_type rm1 = str.rfind('P', 5);
    cout << "Example - find() : The position (forward) of 'P' is: " << (int) m1 << endl;
    cout << "Example - rfind(): The position (reverse) of 'P' is: " << (int) rm1 << endl;
    string::size_type n1 = str.find (" some", 0);
    string::size_type rn1 = str.rfind (" some", 0);
    cout << "Example - find () : The position (forward) of 'some' is: " << (int) n1 << endl;
    cout << "Example - rfind () : The position (reverse) of 'some' is: " << (int) rn1 << endl;

    str = "Thank you for you smile";
    str1 = "you";
    if(str.find(str1) != string::npos) {
        cout << str.find(str1) <<endl;
    }

    return 0;
}

