#include <bits/stdc++.h>
using namespace std;
#include "classLL.h"

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
node *takeInputLL()
{
    int data;
    cin >> data;
    node *head = NULL;
    node *tail = NULL;
    while (data != -1)
    {
        node *newNode = new node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}

int len(node *head)
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void reverseLL(node *head)
{
    if (head == NULL)
    {
        return;
    }
    reverseLL(head->next);
    cout << head->data << " ";
}

// reversing the original LL
// void revLL(node &head, node &tail)
// {
//     node *curr, *prev, *next;
//     curr = head;
//     prev = NULL;
//     while (curr != NULL)
//     {
//         next = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = next;
//     }
//     swap(head, tail);
// }

int main()
{
    node *head = takeInputLL();
    print(head);
    cout << endl;
    // cout << len(head);
    reverseLL(head);
}