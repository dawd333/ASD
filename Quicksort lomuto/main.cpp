#include <iostream>
using namespace std;

int partition_lomuto (int tab[], int l, int r)
{
    int q = tab[r];
    int i=l-1;
    int tmp;

    for (int j=l;j<r;j++)
    {
        if (tab[j] <= q)
        {
            i++;
            tmp = tab[i];
            tab[i] = tab[j];
            tab[j] = tmp;
        }
    }
    tmp = tab[r];
    tab[r] = tab[i+1];
    tab[i+1] = tmp;
    return i+1;
}

void quicksort_lomuto (int tab[], int l, int r)
{
    while(l<r)
    {
        int q=partition_lomuto(tab,l,r);

        if (q-l < q-r)
        {
            quicksort_lomuto(tab,l,q-1);
            l=q+1;
        }
        else
        {
            quicksort_lomuto(tab,q+1,r);
            r=q-1;
        }

    }
}

int main()
{
    int tab[10]={6,10,62,142,2,65,15,86,13,26};
    cout<<"Przed: ";
    for (int i=0;i<10;i++)
    {
        cout<<tab[i]<<" ";
    }

     quicksort_lomuto(tab,0,9);

    cout<<"Po: ";
    for (int i=0;i<10;i++)
    {
        cout<<tab[i]<<" ";
    }

    return 0;
}
