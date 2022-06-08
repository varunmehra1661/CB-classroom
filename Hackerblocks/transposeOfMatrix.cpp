#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int A[n][n], i, j;
    // cout << "Enter elements of matrix : ";
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cin >> A[i][j];

    // cout << "Transpose of Matrix : \n ";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << A[j][i] << " ";
        }
        cout << endl;
    }
    cout << "\n ";
    return 0;
}