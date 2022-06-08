#include <bits/stdc++.h>
using namespace std;

string key[] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void printKeypad(int num, string str = "")
{

    // num reverse

    if (num == 0)
    {
        cout << str << endl;
        return;
    }
    int x = num % 10;
    for (int i = 0; i < key[x].size(); i++)
    {
        printKeypad(num / 10, key[x][i] + str);
    }
}

int main()
{
    int num;
    cin >> num;
    printKeypad(num);
    return 0;
}