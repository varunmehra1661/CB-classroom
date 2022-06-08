#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};
class Pair
{
public:
    bool isBalanced;
    int height;
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
void preOrder(node *root)
{
    if (!root)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node *root)
{
    if (!root)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void inOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// print in the range of [k1,k2]
void printRange(node *root, int k1, int k2)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data >= k1 && root->data <= k2)
    {
        cout << root->data << " ";
    }
    printRange(root->right, k1, k2);
    printRange(root->left, k1, k2);
}

// LL from BST
class LinkedList
{
    node *head;
    node *tail;
    // public:
    //     int data;
    //     LinkedList *next;
    //     LinkedList(int d)
    //     {
    //         data = d;
    //         next = NULL;
    //     }
};

// create balanced BST from array
node *createBST(int *a, int s, int e)
{
    if (s > e)
    {
        return NULL;
    }

    int mid = (s + e) / 2;
    node *root = new node(mid);
    root->left = createBST(a, s, mid - 1);
    root->right = createBST(a, mid + 1, e);

    return root;
}

// to check if the tree is BST or not
bool isBST(node *root, int mi = INT_MIN, int mx = INT_MAX)
{
    if (!root)
    {
        return true;
    }

    if (root->data >= mi && root->data <= mx && isBST(root->left, mi, root->data) && isBST(root->right, root->data, mx))
    {
        return true;
    }
    else
    {
        return false;
    }
}

Pair BalancedOrNot(node *root)
{

    Pair left = BalancedOrNot(root->left);
    Pair right = BalancedOrNot(root->right);

    Pair p;
    p.height = max(left.height, right.height) + 1;
    if (abs(left.height - right.height) <= 1 && left.isBalanced && right.isBalanced)
    {
        p.isBalanced = true;
    }
    else
    {
        p.isBalanced = false;
    }
    return p;
}

int height(node *root)
{
    if (!root)
    {
        return;
    }

    int lH = height(root->left);
    int rH = height(root->right);
    return max(lH, rH) + 1;
}

bool isHBalanced(node *root)
{
    if (!root)
    {
        return true;
    }

    int leftH = height(root->left);
    int rightH = height(root->right);

    if (abs(leftH - rightH) <= 1 && isHBalanced(root->left) && isHBalanced(root->right))
    {
        return true;
    }
    return false;
}

int main()
{
    node *root = NULL;
    root = buildBST();
    cout << endl;

    cout << endl;

    cout << endl;
}