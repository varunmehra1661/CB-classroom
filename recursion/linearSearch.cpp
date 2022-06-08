#include <bits/stdc++.h>
using namespace std;

int search(int A[], int n, int key)
{
    if (n == 0)
    {
        return -1;
    }

    if (A[n - 1] == key)
        return n - 1;
    else
        return search(A, n - 1, key);
}

int Search2(int A[], int n, int key, int i)
{
    if (i == n)
        return -1;

    if (A[i] == key)
        return i;
    else
        Search2(A, n, key, i + 1);
}

int Search3(int A[], int n, int key)
{
    if (n == 0)
        return -1;

    if (A[0] == key)
        return 0;

    int smallindex = Search3(A + 1, n - 1, key);

    if (smallindex != -1)
        return smallindex + 1;

    else
        return smallindex;
}

int main()
{
    int arr[] = {1, 4, 5, 2, 6};
    int n = sizeof(arr) / sizeof(int);
    int key;
    cin >> key;
    cout << linearS(arr, n, key);
    return 0;
}