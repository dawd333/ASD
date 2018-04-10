#include <iostream>
using namespace std;

struct node
{
    int klucz;
    node* next;
};

node* list_insert (node* head, node* n)
{
    if (head==NULL || n->klucz < head->klucz )
    {
        n->next= head;
        return n;
    }
    node* p=head;
    while (p->next != NULL )
    {
        if (p->next->klucz > n->klucz) break;
        p=p->next;
    }
    n->next = p->next;
    p->next = n;
    return head;
}

int main()
{
    node*head = new node;
    head->klucz=2;
    node*second = new node;
    second->klucz=3;
    node*third = new node;
    third->klucz=15;
    node*last = new node;
    last->klucz=19;
    head->next = second;
    second->next = third;
    third->next = last;
    last->next = NULL;

    node*nowy = new node;
    nowy->klucz = 1;
    nowy->next = NULL;

    cout << "Przed: "<<endl;
    node *tmp=head;

    if (tmp==NULL)
    {
        cout<<"Brak"<<endl;
    }
    if (tmp!=NULL)
    {
        cout <<  tmp->klucz << endl;
        while (tmp->next != NULL)
        {
            cout<<tmp->next->klucz<<endl;
            tmp=tmp->next;
        }
    }

    node* newhead = list_insert(head,nowy);
    cout <<"Nowa glowa "<<newhead->klucz<<endl;

    cout << "Po: "<<endl;
    tmp=newhead;

    if (tmp==NULL)
    {
        cout<<"Brak"<<endl;
    }
    if (tmp!=NULL)
    {
        cout <<  tmp->klucz << endl;
        while (tmp->next != NULL)
        {
            cout<<tmp->next->klucz<<endl;
            tmp=tmp->next;
        }
    }

    delete head,second,third,last,nowy;

    return 0;
}
