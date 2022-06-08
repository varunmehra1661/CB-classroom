#include <bits/stdc++.h>
using namespace std;
int strToInteger(string str, int len)
{
    if (len == 0)
    {
        return 0;
    }
    int ld = str[len - 1] - '0';
    return ld + (10 * strToInteger(str, len - 1));
}

int main()
{
    char str[] = "45";
    int len = strlen(str);
    cout << strToInteger(str, len);

    return 0;
}