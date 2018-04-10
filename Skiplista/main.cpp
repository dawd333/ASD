#include <iostream>
using namespace std;

struct SLNode
{
    int val;
    SLNode** next;
};

struct Skiplist
{
    SLNode* head;
    SLNode* last;
    int lvl;
    int max_lvl;
};

int getlevel (double p, int max_lvl)
{
    int lvl = 1;
    while (random() <p) lvl++;

    return min(max_lvl,lvl);
}

SLNode* Find (Skiplist* S, int key)
{
    SLNode* tmp = S->head;

    for (int i = S->max_lvl-1;i>=0;i--)
    {
        while (tmp->next[i]->val > key) tmp = tmp->next[i];
    }
    tmp = tmp->next[0];
    if (tmp>val == key) return tmp;
    return NULL;
}

SLNode* Insert (Skiplist* S, int key)
{
    int h=getlevel(0.5,S->max_lvl);

    SLNode* el = new SLNode();
    el->next = new SLNode*[h];
    el->val = key;

    SLNode* tmp = S->head;

    for (int i=S->max_lvl-1;i>=0;i--)
    {
        while (tmp ->next[i]->val < key) tmp = tmp->next[i];
        if (i<h)
        {
            el->next[i] = tmp->next[i];
            tmp->next[i] = el;
        }
    }
}

SLNode* Delete (Skiplist* S, int key)
{
    SLNode* tmp = S->head;
    SLNode* c;

    for (int i=S->max_lvl-1;i>=0;i--)
    {
        while (tmp->next[i] !=NULL && tmp->next[i]->val < key) tmp=tmp->next[i];

        if (tmp->next[i]->val == key)
        {
            c = tmp->next;
            tmp->next[i] = c->next[i];
        }
    }
    delete c;
}



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
