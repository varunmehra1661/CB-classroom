#include <bits/stdc++.h>
using namespace std;

int fibo(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return fibo(n - 1) + fibo(n - 2);
}

// top-down-approach

int fibol(int n, int *dp)
{
    if (n == 0 || n == 1)
    {
        return dp[n] = n;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = fibol(n - 1, dp) + fibol(n - 2, dp);
    return dp[n];
}

// bottom-up-approach
int fibob(int n, int *dp)
{
    // initialise using base case of top-down
    int *dp = new int[n + 1];
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 0; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    int *dp = new int[n + 1]; // here dp is used as the memo pad in which values are stored
    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }

    cout << fibol(n, dp);
}