#include <bits/stdc++.h>
using namespace std;

// 8 3 10 1 6 14 4 7 13 -1

class node
{
public:
    int data;
    node *right;
    node *left;

    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

node *insertInBST(node *root, int data)
{
    if (root == NULL)
    {
        root = new node(data);
        return root;
    }

    if (root->data > data)
    {
        root->left = insertInBST(root->left, data);
    }
    else
    {
        root->right = insertInBST(root->right, data);
    }
    return root;
}

node *buildBST()
{
    node *root = NULL;
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertInBST(root, data);
        cin >> data;
    }

    return root;
}

void levelOrderOutput(node *root)
{
    queue<node *> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *x = q.front();
        q.pop();

        if (x)
        {
            cout << x->data << " ";
            if (x->left)
            {
                q.push(x->left);
            }

            if (x->right)
            {
                q.push(x->right);
            }
        }

        else
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
    }
}

class LinkedList
{
public:
    node *head;
    node *tail;
};

LinkedList BSTtoLL(node *root)
{
    LinkedList l;
    if (root->left == NULL and root->right == NULL)
    {
        l.head = l.tail = root;
        return l;
    }

    else if (root->left and !root->right)
    {
        LinkedList left = BSTtoLL(root->left);
        left.tail->right = root;
        l.head = left.head;
        l.tail = root;

        return l;
    }

    else if (!root->left and root->right)
    {
        LinkedList right = BSTtoLL(root->right);
        root->right = right.head;
        l.head = root;
        l.tail = right.tail;

        return l;
    }

    else
    {
        LinkedList left = BSTtoLL(root->left);
        LinkedList right = BSTtoLL(root->right);
        left.tail->right = root;
        root->right = right.head;
        l.head = left.head;
        l.tail = right.tail;

        return l;
    }
}

void printLL(node *head)
{
    while (head)
    {
        cout << head->data << "-->";
        head = head->right;
    }

    cout << "NULL" << endl;
}

int main()
{
    node *root = buildBST();

    levelOrderOutput(root);
    cout << endl;

    LinkedList l = BSTtoLL(root);
    printLL(l.head);
}