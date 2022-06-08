#include <bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int n)
{
    if (n == 0 || n == 1)
    {
        return true;
    }

    bool sans = isSorted(arr + 1, n - 1);
    if (arr[0] <= arr[1] && sans)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int arr[] = {1, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << isSorted;
    return 0;
}