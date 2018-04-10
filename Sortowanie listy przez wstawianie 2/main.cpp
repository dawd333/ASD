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

node* list_insert_sort (node *head)
{
    if (head==NULL) return NULL;

    node*shead = NULL;
    while (head!=NULL)
    {
        node* tmp=head;
        head=head->next;
        shead= list_insert(shead,tmp);
    }
    return shead;
}

int main()
{
    node*head = new node;
    head->klucz=20;
    node*second = new node;
    second->klucz=3;
    node*third = new node;
    third->klucz=10;
    node*last = new node;
    last->klucz=1;
    head->next = second;
    second->next = third;
    third->next = last;
    last->next = NULL;

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

    node* newhead = list_insert_sort(head);

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

    delete head,second,third,last;

    return 0;
}
