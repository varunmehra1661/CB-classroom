#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v;
    int i = 0;
    while (i < 50)
    {
        v.push_back(i);
        i++;
    }

    for (int i = 0; i < v.size(); i++)
    {
        cout << "Size:: " << v.size() << endl;
        cout << "Capacity:: " << v.capacity() << endl;
    }
}