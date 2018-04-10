#include <iostream>
using namespace std;

struct node
{
    int klucz;
    node* next;
};

node* list_find_min (node** head)
{
    if (&head==NULL) return NULL;
    int  mini = (*head)->klucz;
    node* tmp = *head;
    node* n = NULL;

    while (tmp->next != NULL)
    {
        if (tmp->next->klucz < mini)
        {
            mini = tmp->next->klucz;
            n = tmp;
        }
        tmp = tmp->next;
    }
    node* res= *head;
    if (n==NULL)
    {
        res= *head;
        *head = (*head) -> next;
    }
    else
    {
      res = n ->next;
      n->next = n->next ->next;
    }
    res->next = NULL;
    return res;
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

    node* mini = list_find_min(&head);
    cout <<"Minimum: "<<mini->klucz<<endl;

    cout << "Po: "<<endl;
    tmp=head;

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
