#include <iostream>
using namespace std;

void scal (int t[],int l,int p, int q)
{
    int tab[q-l+1];
    for (int i=0;i<q-l+1;i++)
    {
        tab[i]=0;
    }

    int i=l,j=p,k=0;

    while (i<p && j<=q)
    {
        if (t[i]<t[j])
        {
            tab[k]=t[i];
            i++;
        }
        else
        {
            tab[k]=t[j];
            j++;
        }
        k++;
    }
    while (i<p)
    {
        tab[k]=t[i];
        i++;
        k++;
    }
    while (j<=q)
    {
        tab[k]=t[j];
        j++;
        k++;
    }
    for (k=0,i=l;k<q-l+1;k++,i++)
    {
        t[i]=tab[k];
    }
}

void mergesort (int t[],int l,int q)
{
    int p=(l+q)/2;
    if (l<p) mergesort(t,l,p);
    if (p+1<q) mergesort(t,p+1,q);
    scal(t,l,p+1,q);
}

int main()
{
    int tab [10] = {5,71,56,2,10,60,54,1,2,70};
    cout<<"Przed: ";
    for (int i=0;i<10;i++)
    {
        cout<<tab[i]<<" ";
    }
    cout<<endl;

    mergesort(tab,0,9);

    cout<<"Po: ";
    for (int i=0;i<10;i++)
    {
        cout<<tab[i]<<" ";
    }


    return 0;
}
