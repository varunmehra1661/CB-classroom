#include <bits/stdc++.h>
using namespace std;

int coins(int amt, int *deno, int n)
{
    if (amt == 0)
    {
        return 0;
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (amt >= deno[i])
        {
            int choti_amt = amt - deno[i];
            int smaller_ans = coins(choti_amt, deno, n);
            if (smaller_ans != INT_MAX)
            {
                ans = min(smaller_ans + 1, ans);
            }
        }
    }
    return ans;
}

// top-down
int coins_top_down(int amt, int *deno, int n, int *dp)
{
    if (amt == 0)
    {
        return dp[amt] = 0;
    }

    if (dp[amt] != -1)
    {
        return dp[amt];
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (amt >= deno[i])
        {
            int choti_amt = amt - deno[i];
            int smaller_ans = coins_top_down(choti_amt, deno, n, dp);
            if (smaller_ans != INT_MAX)
            {
                ans = min(smaller_ans + 1, ans);
            }
        }
    }
    return dp[amt] = ans;
}

// bottom-up
int coins_bottom_up(int amt, int *deno, int n)
{
    int *dp = new int[n + 1];
    dp[0] = 0;

    for (int rupay = 1; rupay <= amt; rupay++)
    {
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int kam_ru = rupay;
            int small_ans = dp[kam_ru];
            if (small_ans != INT_MAX)
            {
                ans = min(ans, small_ans + 1);
            }
        }
        dp[rupay] = ans;
    }
    for (int i = 0; i <= amt; i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl;
    return dp[amt];
}

int main()
{
    int amt;
    int deno[] = {1, 7, 10};
    int n = sizeof(deno) / sizeof(int);
    cin >> amt;
    int dp[10000];
    memset(dp, -1, sizeof dp);
    cout << coins_top_down(amt, deno, n, dp) << endl;
}