#include <bits/stdc++.h>
using namespace std;

int main()
{
    int *a = new int;
    *a = 10;

    cout << a << endl;  // address
    cout << *a << endl; // 10

    float *f = new float;
    *f = 100.01;

    cout << *f << endl;

    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    delete a;
    a = NULL; // to avoid the garbage value;
    delete[] arr;
    arr = NULL;
}