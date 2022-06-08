#include <bits/stdc++.h>
using namespace std;

void push_bottom(stack<int> &s, int topElement)
{
    if (s.empty())
    {
        s.push(topElement);
        return;
    }

    int top = s.top();
    s.pop();
    push_bottom(s, topElement);
    s.push(top);
}

void revStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    int topElement = s.top();
    s.pop();
    revStack(s);
    push_bottom(s, topElement);
}
void printStack(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
