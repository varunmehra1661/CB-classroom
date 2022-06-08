#include <bits/stdc++.h>
using namespace std;

void reverse(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }

    int data = q.front();
    q.pop();
    reverse(q);
    q.push(data);
}

void print(queue<int> &q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    print(q);
    reverse(q);
    print(q);

    // while (!q.empty())
    // {
    //     cout << q.front() << " ";
    //     q.pop();
    // }
    cout << endl;
    return 0;
}