#include <bits/stdc++.h>
using namespace std;
bool isSafe(int mat[][], int i, int j, int no, int n)
{
    // row check
    for (int r = 0; r < n; r++)
    {
        if (mat[r][j] == no)
        {
            return false;
        }
    }
    // col check
    for (int c = 0; c < n; c++)
    {
        if (mat[i][c] == no)
        {
            return false;
        }
    }
    // smaller 3*3 box
    n = sqrt(n);
    int Si = (i / n) * n;
    int Sj = (j / n) * n;

    for (int r = Si; r < Si; r++)
    {
        for (int c = Sj; c < Sj; c++)
        {
            if (mat[r][c] == no)
            {
                return false;
            }
        }
    }
    return true;
}
bool sudokuSolver(int mat[][], int i, int j, int n)
{
    // base case
    if (i == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }

    // recursive case
    if (j == n)
    {
        return sudokuSolver(mat, i + 1, 0, n);
    }
    if (mat[i][j] != 0)
    {
        return sudokuSolver(mat, i, j + 1, n);
    }

    for (int no = 1; no < n; no++)
    {
        if (isSafe(mat, i, j, no, n))
        {
            mat[i][j] = no;
            bool sans = sudokuSolver(mat, i, j + 1, n);
            if (sans)
            {
                mat[i][j] = no;
            }
            mat[i][j] = 0; // backtracking
        }
    }
    return false;
}
int main()
{
    int mat[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0}};

    sudokuSolver(mat, 0, 0, 9);
}