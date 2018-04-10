#include <iostream>
using namespace std;

int left (int i) {return 2*i+1;}
int right (int i) {return 2*i+2;}
int parent (int i) {return (i-1)/2;}

void heapify (int t[], int n, int i)
{
    int ind_max = i;
    if (left(i) < n && t[left(i)] > t[ind_max]) ind_max = left(i);
    if (right(i) < n && t[right(i)] > t[ind_max]) ind_max = right(i);
    if (ind_max != i)
    {
        int tmp = t[i];
        t[i] = t[ind_max];
        t[ind_max] = tmp;
        heapify(t,n,ind_max);
    }
}

void build_heap (int t[],int n)
{
    for (int i=parent(n-1);i>=0;i--) heapify(t,n,i);
}

void increase_key (int t[],int n,int i,int val)
{
    t[i] = val;
    build_heap(t,n);
}

int extract_max (int t[],int n)
{
    int tmp = t[0];
    t[0] = t[n-1];
    build_heap(t,n-1);
    return tmp;
}

void new_el (int t[],int n,int val)
{
    t[n] = val;
    build_heap (t,n+1);
}

int main()
{
    int tab [11] = {65,32,1,4,8,12,54,13,22,140};

    cout << "Przed: " ;
    for (int i=0;i<10;i++)
    {
        cout<< tab[i] << " ";
    }

    build_heap(tab,10);

    cout << endl << "Po naprawie: " ;
    for (int i=0;i<10;i++)
    {
        cout<< tab[i] << " ";
    }

    increase_key(tab,10,3,70);

    cout << endl << "Po wymianie: " ;
    for (int i=0;i<10;i++)
    {
        cout<< tab[i] << " ";
    }

    int top = extract_max(tab,10);

    cout << endl << "Najwieksza wartosc kopca: " << top << " Po wyjeciu: " ;
    for (int i=0;i<9;i++)
    {
        cout<< tab[i] << " ";
    }

    int nowy = 50;
    new_el(tab,9,nowy);

    cout << endl << "Nowy element kopca: " << nowy << " Po dodaniu: " ;
    for (int i=0;i<10;i++)
    {
        cout<< tab[i] << " ";
    }

    return 0;
}
