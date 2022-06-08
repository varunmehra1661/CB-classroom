#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "abc";
    s.push_back('y');
    s.push_back('a');
    s.pop_back();
    cout << s << endl;

    // concatenation
    string a = s;
    cout << a << endl;
    string x = "xyz";
    x += a;
    cout << x << endl;
}