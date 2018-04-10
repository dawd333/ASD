#include <iostream>
using namespace std;

int find_min (int tab[],int s, int e)
{
    int mini = tab[s];
    int index = s;

    for (int i=s+1;i<e;i++)
    {
        if (tab[i]<mini)
        {
            mini = tab[i];
            index = i;
        }
    }
    return index;
}

void selection_sort (int tab[], int n)
{
    for (int i=0;i<n;i++)
    {
        int tmp= tab[i];
        int index = find_min(tab,i,n);
        tab[i]= tab[index];
        tab[index] = tmp;
    }
}

int main()
{
    int tab[10]={4,5,7,13,87,2,53,1,9,7};

    cout<<"Przed:"<<endl;
    for (int i=0;i<10;i++)
    {
        cout<<tab[i]<<endl;
    }

    selection_sort(tab,10);

    cout<<"Po:"<<endl;
    for (int i=0;i<10;i++)
    {
        cout<<tab[i]<<endl;
    }

    return 0;
}
