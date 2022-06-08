#include <bits/stdc++.h>
using namespace std;
int main()
{
    char str;
    cin >> str;
    // int a = str;

    if (str >= 'a' && str <= 'z')
    {
        cout << "lowercase";
    }
    else if (str >= 'A' && str <= 'Z')
    {
        cout << "UPPERCASE";
    }
    else
    {
        cout << "Invalid";
    }
}