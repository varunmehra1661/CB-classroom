#include <bits/stdc++.h>
using namespace std;
int ways(int n, int k)
{
    int sum = 0;
    if (n < 0)
    {
        return 0;
    }

    if (n == 0 || n == 1)
    {
        return 1;
    }
    for (int i = 1; i <= k; i++)
    {
        sum = sum + ways(n - i, k);
    }

    return sum;
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << ways(n, k);
}