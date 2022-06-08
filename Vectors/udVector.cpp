#include <bits/stdc++.h>
using namespace std;
class Vector
{
public:
    int *arr;
    int cs;
    int mx;

    Vector(int s = 2)
    {
        cs = 1;
        mx = 2;
        arr = new int[s];
    }

    void pushb(int e)
    {
        if (cs == mx)
        {
            int *oldarr = arr;
            int oldms = mx;
            arr = new int[mx * 2];
            mx *= 2;
            for (int i = 0; i < oldms; i++)
            {
                arr[i] = oldarr[i];
            }
            delete[] oldarr;
            arr[cs] = e;
            cs++;
        }
    }
    void popb()
    {
        if (cs > 0)
        {
            cs--;
        }
    }
    int cap()
    {
        return mx;
    }
    int si()
    {
        return cs;
    }

    int operator[](int i)
    {
        return arr[i];
    }
};

int main()
{
    Vector v;
    for (int i = 0; i <= 5; i++)
    {
        v.pushb(i);
    }

    for (int i = 0; i < v.si(); i++)
    {
        cout << v[i] << " ";
    }

    cout << endl;
    cout << "Size :: " << v.si() << endl;
    cout << "Capacity :: " << v.cap() << endl;
}