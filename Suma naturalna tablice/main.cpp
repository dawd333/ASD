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

void natural_merge (int t[], int N)
{
    int l,p,q;

    while (1)
    {
        l=0;
        while (l<N)
        {
            p=l+1;
            while (p<N && t[p-1]<=t[p]) p++;

            q=p+1;
            while (q<N && t[q-1]<=t[q]) q++;

            if (p<N) scal(t,l,p,q-1);

            if (l==0 && p==N) return;
            l=q;
        }
    }
}

int main()
{
    int tab [10] = {2,13,17,9,10,17,27,16,19,28};
    cout<<"Przed: ";
    for (int i=0;i<10;i++)
    {
        cout<<tab[i]<<" ";
    }
    cout<<endl;

    natural_merge (tab,10);

    cout<<"Po: ";
    for (int i=0;i<10;i++)
    {
        cout<<tab[i]<<" ";
    }

    return 0;
}
