#include <bits/stdc++.h>
using namespace std;

int len_lcs(char *a, char *b, int i, int j, int dp[][100])
{
    if (a[i] == '\0')
    {
        return 0;
    }
    if (a[i] == b[j])
    {
        return 1 + len_lcs(a, b, i + 1, j + 1, dp);
    }
    else
    {
        return dp[i][j] = max(len_lcs(a, b, i, j + 1, dp), len_lcs(a, b, i + 1, j, dp));
    }
}

// BOTTOM
int bottom_up(char a[], char b[])
{
    int dp[100][100] = {0};
    for (int i = 1; i <= strlen(a); i++)
    {
        for (int j = 1; j <= strlen(b); j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    for (int i = 0; i <= strlen(a); i++)
    {
        for (int j = 0; j <= strlen(b); j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[strlen(a)][strlen(b)];
}

int main()
{
    char a[] = "";
    char b[] = "";
    int dp[100][100];
    memset(dp, -1, sizeof dp);
}