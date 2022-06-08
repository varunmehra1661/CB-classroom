#include <bits/stdc++.h>
using namespace std;
bool issafetoput(int board[][100], int i, int j, int n)
{
    // check row and column
    for (int r = 0; r < n; ++r)
    {
        if (board[r][j] == 1)
        {

            return false;
        }
    }
    for (int c = 0; c < n; ++c)
    {
        if (board[i][c] == 1)
        {
            return false;
        }
    }
    // check upper right diagonal
    int x = i, y = j;
    while (i >= 0 and j < n)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        i--;
        j++;
    }
    // check upper left diagonal
    i = x;
    j = y;
    while (i >= 0 and j >= 0)
    {

        if (board[i][j] == 1)
        {
            return false;
        }
        i--;
        j--;
    }
    return true;
}
bool nqueen(int board[][100], int i, int n)
{

    // base case
    if (i == n)
    {
        // print the board
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                // cout<<board[i][j]<<" ";
                if (board[i][j] == 1)
                {
                    cout << 'Q' << " ";
                }
                else
                {
                    cout << "_"
                         << " ";
                }
            }
            cout << endl;
        }
        cout << endl;
        return true; // true to print one path and false to print one path
    }

    // recursive case
    for (int j = 0; j < n; ++j)
    {

        if (issafetoput(board, i, j, n) == true)
        {

            board[i][j] = 1;
            bool kyabaatbani = nqueen(board, i + 1, n);
            if (kyabaatbani == true)
            {
                return true;
            }
            board[i][j] = 0;
        }
    }
    return false;
}

int main()
{
    int board[100][100] = {0};
    int n;
    cin >> n;
    nqueen(board, 0, n);

    return 0;
}