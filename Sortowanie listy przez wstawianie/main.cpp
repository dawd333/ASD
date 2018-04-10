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

node* list_insert_sort (node* head)
{
    if (head==NULL) return NULL;
    node*shead;
    shead=list_find_min(&head);
    node*p = shead;
    while (head!=NULL)
    {
        p->next = list_find_min(&head);
        p=p->next;
    }
    return shead;
}

int main()
{
    node*head = new node;
    head->klucz=27;
    node*second = new node;
    second->klucz=33;
    node*third = new node;
    third->klucz=1;
    node*last = new node;
    last->klucz=19;
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
