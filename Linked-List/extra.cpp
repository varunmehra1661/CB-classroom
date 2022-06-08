#include <bits/stdc++.h>
using namespace std;
int main()
{
    int *num = new int[4];
    cout << num << endl;
    delete[] num;
    delete num;
    cout << num;
}
