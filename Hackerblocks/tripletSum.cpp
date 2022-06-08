#include <bits/stdc++.h>
using namespace std;
void findTriplets(int arr[], int n, int sum)
{
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == sum)
                {
                    cout << arr[i] << " "
                         << arr[j] << " "
                         << arr[k] << endl;
                }
            }
        }
    }
}
int main()
{
    int m;
    cin >> m;
    int arr[m];
    for (int i = 0; i < m; i++)
    {
        cin >> i;
    }
    int n = sizeof(arr) / sizeof(arr[0]);

    int val;
    cin >> val;

    findTriplets(arr, n, val);
    return 0;
}