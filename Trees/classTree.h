#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void createTree()
{

    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    node *root = new node(data);
    root->left = createTree();
    root->right = createTree();
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

int count(node *root)
{
    if (!root)
    {
        return;
    }

    return count(root->left) + count(root->right) + 1;
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

int diameter(node *root)
{
    if (!root)
    {
        return 0;
    }

    int op1 = height(root->left) + (root->right);
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);

    return max(op1, max(op2, op3));
}

class pair
{
    int height;
    int dia;
};

pair fastDia(node *root)
{
    if (!root)
    {
        pair ans;
        ans.height = ans.dia = 0;
        return ans;
    }

    pair left = fastDia(root->left);
    pair right = fastDia(root->right);

    pair ans;

    ans.height = max(left.height, right.height) + 1;

    int op1 = left.height + right.height;
    int op2 = left.dia;
    int op3 = right.dia;
    ans.dia = max(op1, max(op2, op3));
    return ans;
}

void mirror(node *root)
{
    if (!root)
    {
        return;
    }
    swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
}

node *searchInBT(node *root, int key)
{
    if (!root)
    {
        return NULL;
    }

    if (root->data == key)
    {
        return root;
    }

    node *left_ans = searchInBT(root->left);
    if (left_ans != NULL)
    {
        return left_ans;
    }

    return searchInBT(root->right);
}

void levelOrder(node *root)
{

    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *x = q.front();
        q.pop();

        if (x != NULL)
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
}

node *levelOrderInput()
{

    int data, l, r;
    cout << "entert the data of the root";
    cin >> data;
    node *root = new node(data);
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *x = q.front();
        q.pop();
        cout << "Enter the left and right child of" << x->data << endl;
        cin >> l >> r;
        if (l != -1)
        {
            x->left = new node(l);
            q.push(x->left);
        }
        if (r != -1)
        {
            x->right = new node(r);
            q.push(x->right);
        }
    }
}

// Creating a tree from preOrder and inOrder

// Pre: 8 10 1 6 4 7 3 13 14
// IN: 1 10 4 6 7 8 3 13 14

node *create(int s, int e)
{
    if (s > e)
    {
        return NULL;
    }
    node *root = new node(pre(i++));

    int k = -1;
    for (int j = s; j < = e; j++)
    {
        if (root->data == in[j])
        {
            k = j;
            break;
        }
    }

    root->left = create(s, k - 1);
    root->right = create(k + 1, e);
    return root;
}
