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
node *deleteIthNode(node *head, int i)
{
    int count = 0;
    node *temp = head;

    if (i == 0)
    {
        head = temp->next;
        return head;
    }
    while (temp != NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL)
    {
        temp->next = temp->next->next;
        return head;
    }
}
int main()
{
    node *head = takeInputLL();
    print(head);
    cout << endl;
    int i;
    cout << "\nThe node you wanna delete posn :: ";
    cin >> i;
    deleteIthNode(head, i);
    print(head);
}