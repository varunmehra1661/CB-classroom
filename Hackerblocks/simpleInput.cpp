#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[4];
    for (int i = 0; i <= 4; i++)
    {
        cin >> arr[i];
    }
    int sum = 0;
    for (int i = 0; i <= 4; i++)
    {
        sum = sum + arr[i];
        cout << arr[i];
        if (sum < 0)
        {
            break;
        }
    }
}