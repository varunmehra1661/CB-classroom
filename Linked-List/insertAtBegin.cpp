#include <bits/stdc++.h>
#include "classLL.h"
using namespace std;

void print(node *n1)
{
    node *head = n1;
    node *temp = n1;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

node *insertAtIndex(node *n1, int x, int i)
{
    node *head = n1;

    node *newNode = new node(x);
    node *temp = head;
    int count = 1;

    while (count == i - 1)
    {
        temp = temp->next;
        count++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

node *beginInsert(node *n1, int x)
{
    node *head = n1;
    node *nHead = new node(x);
    nHead->next = head;
    head = nHead;
    return head;
}

node *endInsert(node *n1, int x)
{
    node *head = n1;
    node *temp = head;
    node *tail = new node(x);

    while (temp != NULL)
    {
        temp = temp->next;
    }
    temp->next = tail;
    return head;
}

int main()
{
    node *n1 = new node(1);
    node *n2 = new node(2);
    node *n3 = new node(3);

    // connecting the nodes
    n1->next = n2;
    n2->next = n3;

    print(n1);
    node *newH = beginInsert(n1, 100);
    cout << endl;
    print(newH);
    node *newT = endInsert(n1, 100);
    print(newT);
}