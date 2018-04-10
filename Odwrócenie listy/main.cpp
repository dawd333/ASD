#include <iostream>
using namespace std;

struct node
{
    int klucz;
    node* next;
};

node* reverse_list (node* head)
{
    if (head==NULL) return NULL;
    node*rhead=NULL;
    node*tmp=NULL;
    while (head!=NULL)
    {
        tmp = head;
        head = head->next;
        tmp->next = rhead;
        rhead = tmp;
    }
    return rhead;
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

    node* newhead = reverse_list(head);

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
