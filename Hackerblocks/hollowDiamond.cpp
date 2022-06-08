#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    int i, j, rows;
    cin >> rows;

    // print upper triangle
    for (i = 1; i <= rows; i++)
    {
        for (j = rows; j > i; j--)
        {
            cout << "*"; // print space
        }
        cout << "*"; // print star
        for (j = 1; j < (i - 1) * 2; j++)
        {
            cout << " ";
        }
        for (j = rows; j > i; j--)
        {
            cout << "*"; // print space
        }
        if (i == 1)
        {
            cout << "\n";
        }
        else
        {
            cout << "*\n";
        }
    }
    // print lower triangle
    for (i = rows - 1; i >= 1; i--)
    {
        for (j = rows; j > i; j--)
        {
            cout << "*"; // print space
        }
        cout << "*"; // print star
        for (j = 1; j < (i - 1) * 2; j++)
        {
            cout << " ";
        }
        for (j = rows; j > i; j--)
        {
            cout << "*"; // print space
        }
        if (i == 1)
        {
            cout << "\n";
        }
        else
        {
            cout << "*\n";
        }
    }
    getch();
    return 0;
}