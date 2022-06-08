#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {2, 4, 6, -15, 12, 4, -11, 4, 6, -10, 12};
    // int arr[] = {-15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int mx_sum = INT_MIN;
    int sum = 0;
    int start = 0;
    int end = 0;
    int maxs = 0;
    int maxe = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        end++;

        if (sum > mx_sum)
        {
            mx_sum = sum;
            maxs = start;
            maxe = end;
        }

        if (sum < 0)
        {
            sum = 0;
            start = i; //
        }
    }

    for (int i = start; i <= end; i++)
    {
        cout << arr[i] << " ";
    }

    // for (int i = 0; i < n; ++i)
    // {
    //     sum += arr[i];
    //     mx_sum = max(sum, mx_sum);
    //     // if (sum < 0)
    //     // {
    //     //     sum = 0;
    //     // }
    //     if (sum > mx_sum)
    //     {
    //         mx_sum = sum;
    //         start = 0;
    //         end = i;
    //     }
    // }
    cout << "maximum sum = " << mx_sum << endl;
    // for (int i = start; i <= end; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    return 0;
}