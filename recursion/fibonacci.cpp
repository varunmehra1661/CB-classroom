#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    int sans1 = fib(n - 1);
    int sans2 = fib(n - 2);
    return sans1 + sans2;
}

int main()
{
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}