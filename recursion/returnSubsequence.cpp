#include <bits/stdc++.h>
using namespace std;
void subsequence(char input[], char output[], int i, int j)
{
    if (input[i] == '\0')
    {
        output[j] = '\0';
        cout << output << endl;
        return;
    }

    subsequence(input, output, i + 1, j);
    output[j] = input[i];
    subsequence(input, output, i + 1, j + 1);
}

int main()
{
    char str[] = "a";
    char output[100];
    subsequence(str, output, 0, 0);

    return 0;
}