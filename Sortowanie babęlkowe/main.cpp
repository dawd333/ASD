#include <iostream>

using namespace std;

int main()
{
    int tab[5]={6,4,17,26,3};
    cout<<"Tablica przed:"<<endl;
    for (int i=0;i<5;i++)
    {
        cout<<tab[i]<<endl;
    }

    for (int i=4;i>0;i--)
    {
        for (int j=0;j<i;j++)
        {
            if (tab[j]>tab[j+1])
            {
                int sub = tab[j+1];
                tab[j+1] = tab[j];
                tab[j] = sub;
            }
        }
    }

    cout<<"Tablica po:"<<endl;
    for (int i=0;i<5;i++)
    {
        cout<<tab[i]<<endl;
    }

    return 0;
}
