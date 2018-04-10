#include <iostream>
using namespace std;

void insert_sort (int t[], int n)
{
    int j;
    for (int i=1;i<n;i++)
    {
        j=i;
        int tmp=t[i];
        while (j>0)
        {
            if (tmp<t[j-1])
            {
                t[j]=t[j-1];
                j--;
            }
            else
            {
                t[j]=tmp;
                break;
            }
        }
        if (j==0);
        {
            t[j]=tmp;
        }
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

    insert_sort(tab,10);

    cout<<"Po:"<<endl;
    for (int i=0;i<10;i++)
    {
        cout<<tab[i]<<endl;
    }

    return 0;
}
