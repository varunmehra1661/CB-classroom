#include <bits/stdc++.h>
using namespace std;

int solve(int n)
{
    if (n == 1)
    {
        return 0;
    }

    int op1, op2, op3;
    op1 = op2 = op3 = INT_MAX;

    if (n % 3 == 0)
    {
        op1 = solve(n / 3);
    }

    if (n % 2 == 0)
    {
        op2 = solve(n / 2);
    }

    op3 = solve(n - 1);
    return min(op1, min(op2, op3)) + 1;
}

// top-down
int solve_top_down(int n, int *dp)
{
    if (n == 1)
    {
        return dp[n] = 0;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int op1, op2, op3;
    op1 = op2 = op3 = INT_MAX;

    if (n % 3 == 0)
    {
        op1 = solve_top_down(n / 3, dp);
    }

    if (n % 2 == 0)
    {
        op2 = solve_top_down(n / 2, dp);
    }

    op3 = solve_top_down(n - 1, dp);
    return dp[n] = min(op1, min(op2, op3)) + 1;
}

// bottom-up

int solve_bottom_up(int n)
{

    int *dp = new int[n + 1];
    dp[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        int op1, op2, op3;
        op1 = op2 = op3 = INT_MAX;

        if (i % 3 == 0)
        {
            op1 = dp[i / 3];
        }
        if (i % 2 == 0)
        {
            op2 = dp[i / 2];
        }
        op3 = dp[i - 1];
        dp[i] = min(op1, min(op2, op3)) + 1;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dp[n] << " ";
    }
    cout << endl;
    return dp[n];
}

int main()
{

    int n;
    cin >> n;
    // cout << solve(10);
    int *dp = new int[n + 1]; // here dp is used as the memo pad in which values are stored
    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }
    cout << solve_top_down(n, dp);
}