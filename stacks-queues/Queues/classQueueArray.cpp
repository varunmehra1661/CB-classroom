#include <bits/stdc++.h>
using namespace std;
class Queue
{
public:
    int *a;
    int n;
    int cs;
    int f;
    int e;
    Queue(int s = 5)
    {
        n = s;
        a = new int[s];
        cs = 0;
        f = 0;
        e = n - 1;
    }

    void push(int d)
    {
        if (cs == n)
        {
            cout << "Overflow" << endl;
            return;
        }
        e = (e + 1) % n;
        a[e] = d;
        cs++;
    }

    void pop()
    {
        if (cs > 0)
        {
            cs--;
        }
        else
        {
            cout << "Overflow" << endl;
        }
    }

    bool empty()
    {
        return cs == 0;
    }

    int front()
    {
        return a[f];
    }
};

int main()
{
    Queue v;
    v.push(1);
    v.push(2);
    v.push(3);
    v.push(4);
    v.push(5);
}