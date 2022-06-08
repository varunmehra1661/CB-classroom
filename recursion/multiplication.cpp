#include <bits/stdc++.h>
using namespace std;

int mul(int m, int n)
{
    if (m == 0)
    {
        return 0;
    }
    return n + mul(m - 1, n);
}

int main()
{
    int m, n;
    cin >> m >> n;
    cout << mul(m, n);
    return 0;
}