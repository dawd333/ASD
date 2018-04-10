#include <iostream>
using namespace std;

struct Node
{
    Node* parent;
    int Rank;
    int val;
};

Node* Make_Set (int x)
{
    Node* node = new Node;
    node->parent = node;
    node->val = x;
    node->Rank = 0;
    return node;
}

Node* Find_Set (Node* x)
{
    if (x->parent !=x) x->parent = Find_Set(x->parent);
    return x->parent;
}

void Union (Node*x , Node*y)
{
    x=Find_Set(x);
    y=Find_Set(y);

    if (x->Rank > y->Rank)
    {
        y->parent = x;
    }
    else
    {
        x->parent = y;
        if (x->Rank = y->Rank) y->Rank++;
    }
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
