#include <iostream>
using namespace std;

struct BSTNode
{
    BSTNode*parent;
    BSTNode*left;
    BSTNode*right;
    int val;
};

void wypisz (BSTNode* root)
{
    if (root !=NULL)
    {
        wypisz(root->left);
        cout<<root->val<<" ";
        wypisz(root->right);
    }
}

BSTNode* Find (BSTNode* root, int key)
{
    while (root!=NULL)
    {
        if (root->val = key) return root;
        else if (root->val > key) root= root->left;
        else root = root->right;
    }
    return NULL;
}

BSTNode* Min (BSTNode* root)
{
    BSTNode* prev;

    while (root !=NULL)
    {
        prev = root;
        root = root->left;
    }
    return prev;
}

BSTNode* Max (BSTNode* root)
{
    BSTNode* prev;

    while (root !=NULL)
    {
        prev = root;
        root = root->right;
    }
    return prev;
}

BSTNode* Insert (BSTNode* root , BSTNode* nowy)
{
    if (root == NULL) return nowy;
    BSTNode*prev = NULL;
    BSTNode* tmp = root;
    int key = nowy->val;

    while (tmp != NULL)
    {
        prev = tmp;
        if (tmp->val > key) tmp = tmp->left;
        else if (tmp->val < key) tmp = tmp->right;
        else return root;
    }
    if (prev->val < key) prev->left = nowy;
    else prev->right = nowy;
    nowy->parent = prev;
    return root;
}

BSTNode* Successor (BSTNode* n)
{
    if (n==NULL) return NULL;
    if (n->right !=NULL) return Min(n->right)
    else
    {
        BSTNode*tmp = n;
        while (n->parent!=NULL)
        {
            n = n->parent;
            if (n->left == tmp) return n;
            tmp = n;
        }
        return NULL;
    }
}

BSTNode* Predecessor (BSTNode* n)
{
    if (n==NULL) return NULL;
    if (n->left !=NULL) return Max(n->left)
    else
    {
        BSTNode*tmp = n;
        while (n->parent!=NULL)
        {
            n = n->parent;
            if (n->right == tmp) return n;
            tmp = n;
        }
        return NULL;
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
