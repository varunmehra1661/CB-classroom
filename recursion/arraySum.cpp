#include <bits/stdc++.h>
using namespace std;

int arraySum(int n, int arr[])
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return arr[0];
    }
    int sans = arraySum(n - 1, arr + 1);
    return arr[0] + sans;
}

int main()
{
    int arr[] = {1, 2, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << arraySum(n, arr) << endl;
    return 0;
}