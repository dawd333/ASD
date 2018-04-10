#include <iostream>
using namespace std;

struct node
{
    int val;
    node* next;
};

node* list_merge (node* h1, node* h2, node** t)
{
    node* mh;

    if (h1->val < h2-> val)
    {
        mh=h1;
        h1=h1->next;
    }
    else
    {
        mh=h2;
        h2=h2->next;
    }
    mh->next=NULL;
    *t=mh;

    while (h1!=NULL && h2!=NULL)
    {
        if (h1->val < h2-> val)
        {
            (*t)->next=h1;
            h1=h1->next;
        }
        else
        {
            (*t)->next=h2;
            h2=h2->next;
        }
        (*t)=(*t)->next;
        (*t)->next=NULL;
    }

    if (h1!=NULL)
    {
        (*t)->next=h1;
    }
    else
    {
        (*t)->next=h2;
    }
    while ((*t)->next!=NULL)
    {
        *t=(*t)->next;
    }
    return mh;
}

int main()
{
    node*one = new node;
    one->val=5;
    node*two = new node;
    two->val=17;
    node*three = new node;
    three->val=39;
    node*uno = new node;
    uno->val=13;
    node*dos = new node;
    dos->val=27;
    node*tres = new node;
    tres->val=33;

    one->next= two;
    two->next= three;
    three->next= NULL;

    uno->next= dos;
    dos->next= tres;
    tres->next= NULL;

    cout << "Przed: "<<endl;
    node *tmp=one;

    if (tmp==NULL)
    {
        cout<<"Brak"<<endl;
    }
    if (tmp!=NULL)
    {
        cout <<  tmp->val << endl;
        while (tmp->next != NULL)
        {
            cout<<tmp->next->val<<endl;
            tmp=tmp->next;
        }
    }

    cout<<"Drugi: "<<endl;

    tmp=uno;

    if (tmp==NULL)
    {
        cout<<"Brak"<<endl;
    }
    if (tmp!=NULL)
    {
        cout <<  tmp->val << endl;
        while (tmp->next != NULL)
        {
            cout<<tmp->next->val<<endl;
            tmp=tmp->next;
        }
    }

    node* all = new node;
    all=NULL;

    node* newhead = list_merge(one,uno,&all);

    cout << "Po: "<<endl;
    tmp=newhead;

    if (tmp==NULL)
    {
        cout<<"Brak"<<endl;
    }
    if (tmp!=NULL)
    {
        cout <<  tmp->val << endl;
        while (tmp->next != NULL)
        {
            cout<<tmp->next->val <<endl;
            tmp=tmp->next;
        }
    }

    delete one,two,three,uno,dos,tres,all;

    return 0;
}
