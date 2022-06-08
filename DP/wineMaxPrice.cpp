#include <bits/stdc++.h>
using namespace std;

int wineProb(int l, int r, int *wine, int day)
{
    if (l > r)
    {
        return 0;
    }

    int op1 = wine[l] * day + wineProb(l + 1, r, wine, day + 1);
    int op2 = wine[r] * day + wineProb(l, r - 1, wine, day + 1);
    return max(op1, op2);
}

// top-down
int wineProb_top_down(int l, int r, int *wine, int day, int dp[][100])
{
    if (l > r)
    {
        return dp[l][r] = 0;
    }

    int op1 = wine[l] * day + wineProb_top_down(l + 1, r, wine, day + 1, dp);
    int op2 = wine[r] * day + wineProb_top_down(l, r - 1, wine, day + 1, dp);
    return dp[l][r] = max(op1, op2);
}

// bottom_up
int wineProb_bottom_up(int wine[], int n)
{
    int dp[100][100] = {0};
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = n * wine[i];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            int day = n - (j - i);
            int op1 = wine[i] * day + dp[i + 1][j];
            int op2 = wine[j] * day + dp[i][j - 1];
            dp[i][j] = max(op1, op2);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[0][n - 1];
}

int main()
{
    int wine[] = {2, 3, 5, 1, 4};
    int n = sizeof(wine) / sizeof(int);
    int dp[100][100];
    memset(dp, -1, sizeof dp);
    cout << wineProb_top_down(0, n - 1, wine, 1, dp);
}