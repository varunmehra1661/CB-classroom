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

class Stack
{
    node *head;
    Stack()
    {
        head = NULL;
    }
    void push(int data)
    {
        if (!head)
        {
            head = new node(data);
        }

        node *newNode = new node(data);
        newNode->next = head;
        head = newNode;
    }

    void pop()
    {
        if (!head)
        {
            return;
        }
        if (!head->next)
        {
            delete head;
            head = NULL;
        }
        node *temp = head;
        head = head->next;
        delete temp;
    }

    bool empty()
    {
        return head == NULL;
    }

    int top()
    {
        return head->data;
    }
};