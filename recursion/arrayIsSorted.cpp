#include <bits/stdc++.h>
using namespace std;

bool sortedCheck(int n, int arr[])
{
    if (n == 0 || n == 1)
    {
        return true;
    }
    if (arr[0] <= arr[1] && sortedCheck(n - 1, arr + 1))
    {
        return true;
    }

    return false;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << sortedCheck(n, arr);
    return 0;
}