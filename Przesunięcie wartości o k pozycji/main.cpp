#include <iostream>
using namespace std;

void przesuniecie (int t[],int n,int k)
{
    int tmp = t[0];
    int from=0,to=0;

    for (int i=0;i<n-1;i++)
    {
        while ((from+k)%n != to) from++;
        t[to] = t[from];
        to = from;
        from = 0;
    }
    t[to] = tmp;
}

int main()
{
    int tab[7]={0,1,2,3,4,5,6};

    cout<<"Przed: ";
    for (int i=0;i<7;i++)
    {
        cout<<tab[i]<<" ";
    }

    przesuniecie(tab,7,4);

    cout<<"Po: ";
    for (int i=0;i<7;i++)
    {
        cout<<endl<<tab[i]<<" ";
    }

    return 0;
}
