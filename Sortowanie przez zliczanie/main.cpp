#include <iostream>
using namespace std;

void counting_sort (int A[],int n,int k)
{
    int B[n];
    int C[k];

    for (int i=0;i<k;i++)
    {
        C[i]=0;
    }

    for (int i=0;i<n;i++)
    {
        C[A[i]]++;
    }

    for (int i=1;i<k;i++)
    {
        C[i]=C[i]+C[i-1];
    }

    for (int i=n-1;i>=0;i--)
    {
        B[C[A[i]]-1] = A[i];
        C[A[i]]--;
    }

    for (int i=0;i<n;i++)
    {
        A[i]=B[i];
    }
}

int main()
{
    int tab[10] = {3,4,1,2,1,4,0,2,0,4};

    cout<<"Przed: ";
    for (int i=0;i<10;i++)
    {
        cout<<tab[i]<<" ";
    }

    counting_sort (tab,10,5);

    cout<<endl<<"Po: ";
    for (int i=0;i<10;i++)
    {
        cout<<tab[i]<<" ";
    }

    return 0;
}
