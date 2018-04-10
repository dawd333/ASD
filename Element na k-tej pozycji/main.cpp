#include <iostream>

using namespace std;

int partition_horae(int tab[], int l, int r)
{
    int q = tab[l];
    int i = l - 1;
    int j = r + 1;
    while (true)
    {
        do j--;
        while (tab[j] > q);
        do i++;
        while (tab[i] < q);
        if (i < j)
            swap(tab[i], tab[j]);
        else
            return j;
    }
}

int Select (int t[],int n, int k)
{
    if (n==1) return t[0];

    int q = partition_horae(t,0,n-1);
    if (q==k) return t[q];
    else if (k<q) return Select(t,q,k);
    else return Select(t+q+1,n-(q+1),k-(q+1));
}

int main()
{
    int tab[10]={6,10,62,142,2,65,15,86,13,26};
    cout<<"Przed: ";
    for (int i=0;i<10;i++)
    {
        cout<<tab[i]<<" ";
    }

    int siedem = Select(tab,10,7-1); // poniewaz to znajdzie nam element na 7 indeksie tablicy czyli 8 po to jest -1

    cout<<"Siodmy element w posortowanej tablicy: "<<siedem;

    return 0;
}
