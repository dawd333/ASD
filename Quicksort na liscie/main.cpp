#include <iostream>
//z wartownikami wszedzie
using namespace std;

struct node
{
    int val;
    node* next;
};

void Partition (node*head , node*l, node*e, node*g)
{
    int q = head->next->val;

    while (head->next != NULL)
    {
        node*tmp = head->next;
        head->next = tmp->next;
        tmp ->next = NULL;

        if (tmp->val < q)
        {
            tmp->next = l->next;
            l->next = tmp;
        }
        else if (tmp->val > q)
        {
            tmp->next = g->next;
            g->next = tmp;
        }
        else
        {
            tmp->next = e->next;
            e->next = tmp;
        }
    }
}

void list_quicksort (node*head)
{
    if (head->next == NULL) return;
    node l,e,g;
    l.next = NULL;
    e.next = NULL;
    g.next = NULL;

    Partition(head,&l,&e,&g);

    list_quicksort(&l);
    list_quicksort(&g);

    if (l.next !=NULL)
    {
        head->next = l.next;
        node*p = l.next;
        while (p->next != NULL) p=p->next;
        p->next=e.next;
    }
    else
    {
        head->next = e.next;
    }

    if (g.next !=NULL)
    {
        node*p = e.next;
        while (p->next !=NULL) p=p->next;
        p->next = g.next;
    }
}

int main()
{
    node*head = new node;
    node*first = new node;
    first->val='27a';
    node*second = new node;
    second->val='33a';
    node*third = new node;
    third->val=1;
    node*last = new node;
    last->val=19;
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = last;
    last->next = NULL;

    cout << "Przed: "<<endl;
    node *tmp=head->next;

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

    list_quicksort(head);

    cout << "Po: "<<endl;
    tmp=head->next;

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

    return 0;
}
