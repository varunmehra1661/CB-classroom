#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {

        this->data = data;
        next = NULL;
    }
};
// int main()
// {
//     node n(1);
//     node n2(2);
//     node n3(3);

//     // connecting the nodes
//     n.next = &n2;
//     n2.next = &n3;

//     // arrow op
//     cout << n.data << endl;
//     cout << n.next->data << endl;
//     cout << n.next->next->data << endl;
// }