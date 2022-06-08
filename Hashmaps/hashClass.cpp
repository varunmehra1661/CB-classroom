#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    string key;
    int value;
    node *next;
    node(string s, int val)
    {
        key = s;
        value = val;
        next = NULL;
    }
};

class Hashmap
{
    int hashFun(string key)
    {
        int ans = 0;
        int mul = 1;
        for (int i = 0; i < key.length(); i++)
        {
            ans += (key[i] % ts) * (mul % ts);
            ans %= ts;
            mul *= 37;
            mul %= ts;
        }
        return ans % ts;
    }

    void rehash()
    {
        node **oldh = h;
        int oldts = ts;
        h = new node *[ts * 2];
        ts = ts * 2;
        cs = 0;
        for (int i = 0; i < ts; i++)
        {
            h[i] = NULL;
        }

        for (int i = 0; i < oldts; i++)
        {
            node *head = oldh[i];
            while (head)
            {
                string key = head->key;
                int value = head->value;
                insert(key, value);
                head = head->next;
            }
        }
        delete[] oldh;
    }

public:
    node **h;
    int ts;
    int cs;
    Hashmap(int s)
    {
        h = new node *[s];
        ts = s;

        // every bucket of node* should initially be NULL
        for (int i = 0; i < ts; i++)
        {
            h[i] = NULL;
        }
    }
    void insert(string key, int value)
    {
        int hash_index = hashFun(key);
        node *n = new node(key, value);
        n->next = h[hash_index];
        h[hash_index] = n;
        cs++;

        float load_factor = cs / (ts * 1.0);
        if (load_factor >= 0.6)
        {
            rehash();
        }
    }

    void print()
    {
        for (int i = 0; i < ts; i++)
        {
            node *head = h[i];
            while (head)
            {
                cout << "(" << head->key << ", " << head->value << ")";
                head = head->next;
            }
            cout << endl;
        }
    }

    node *search(string key)
    {
        int hash_index = hashFun(key);
        node *head = h[hash_index];
        while (head)
        {
            if (head->key == key)
            {
                return head;
            }
            head = head->next;
        }
        return NULL;
    }

    int &operator[](string key)
    {
        node *s = search(key);
        if (s == NULL)
        {
            insert(key, NULL);
            s = search(key);
            return s->value;
        }
        else
        {
            return s->value;
        }
    }
};