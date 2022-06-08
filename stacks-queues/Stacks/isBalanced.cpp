#include <bits/stdc++.h>

using namespace std;

bool isBalanced(char *a, int n)
{
    stack<char> v;
    for (int i = 0; i < n; i++)
    {
        // opening brackets
        if (a[i] == '{' || a[i] == '[' || a[i] == '(')
        {
            v.push(a[i]);
        }

        // closing brackets && compare
        if (a[i] == ')' && v.top() == '(')
        {
            v.pop();
        }
        if (a[i] == ']' && v.top() == '[')
        {
            v.pop();
        }
        if (a[i] == '}' && v.top() == '{')
        {
            v.pop();
        }
    }
    if (v.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    char a[] = "[a+b*(c+d)+e*{f+(g+d)]";
    int n = strlen(a);
    cout << isBalanced(a, n);
}