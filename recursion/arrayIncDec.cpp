#include <bits/stdc++.h>
using namespace std;

void sort(int n, int arr[])
{
    if (n == 0 || n == 1)
    {
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    return sort(n - 1, arr);
}

void printI(int n, int arr[])
{
    if (n == 0)
    {
        return;
    }
    cout << arr[0];
    printI(n - 1, arr + 1);
}
void printD(int n, int arr[])
{
    if (n == 0)
    {
        return;
    }

    printD(n - 1, arr + 1);
    cout << arr[0];
}

int main()
{
    int arr[] = {1, 3, 2, 6, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(n, arr);
    printI(n, arr);
    cout << endl;
    printD(n, arr);
    return 0;
}