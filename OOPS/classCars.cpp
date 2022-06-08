#include <bits/stdc++.h>
using namespace std;
class Cars
{
public:
    char name[100];
    int seats;
    float mil;
    int price;

    // paramterized constructor
    Cars(char *n, int s, float m, int p)
    {
        strcpy(name, n);
        seats = s;
        mil = m;
        price = p;
    }

    Cars(Cars &x)
    {
        // creating self made copy-constructors
        strcpy(name, x.name);
        seats = x.seats;
        mil = x.mil;
        price = x.price;
    }

    // operator overloading

    // copy assign
    void operator=(Cars x)
    {
        strcpy(name, x.name);
        seats = x.seats;
        mil = x.mil;
        price = x.price;
    }

    // concat
    void operator+=(Cars x)
    {
        strcpy(name, x.name);
        seats = x.seats;
        mil = x.mil;
        price = x.price;
    }

    // Destructor
    ~Cars()
    {
        cout << name << endl;
    }

    void print()
    {
        cout << name << endl;
        cout << seats << endl;
        cout << mil << endl;
        cout << price << endl;
    }
};

int main()
{
    Cars A("BMW", 2, 8, 2);
    Cars B("Maruti", 2, 8, 2);
    A = B;     // copy assignment operator
    Cars C(B); // copy constructor
    A.print();
    B.print();
    C.print();
}