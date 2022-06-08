#include <bits/stdc++.h>
using namespace std;

int main()
{
    // build a 2D array
    int n, m;
    int number = 1;
    cin >> n >> m;
    int arr[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = number++;
        }
    }
    cout << endl;

    // print the 2D array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    // cout << endl;

    // staircase search
    int key;
    cin >> key;
    int i = 0, j = m - 1;
    while (i < n && j >= 0)
    {
        if (arr[i][j] == key)
        {
            cout << "Element found at : " << i << " " << j << endl;
            break;
        }
        if (key > arr[i][j])
        {
            i++;
        }
        else
        {
            j--;
        }
        if (i == n || j < 0)
        {
            cout << "Element not found" << endl;
        }

        return 0;
    }
}