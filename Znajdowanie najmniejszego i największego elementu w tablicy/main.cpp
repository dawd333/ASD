#include <iostream>
using namespace std;

struct wynik
{
    int najmniejszy;
    int najwiekszy;
};

wynik* naj_tablica (int t[],int n)
{
    wynik* result = new wynik;

    int t1[n/2];
    int t2[n/2];
    for (int i=0;i<n/2;i++)
    {
        t1[i]=0;
        t2[i]=0;
    }

    for (int i=0,j=0;i<n;i+=2,j++)
    {
        if (t[i]<t[i+1])
        {
            t1[j]=t[i];
            t2[j]=t[i+1];
        }
        else
        {
            t1[j]=t[i+1];
            t2[j]=t[i];
        }
    }
    result->najmniejszy=t1[0];
    result->najwiekszy=t2[0];

    for (int i=1;i<n/2;i++)
    {
        if (t1[i]<result->najmniejszy) result->najmniejszy = t1[i];
        if (t2[i]>result->najwiekszy) result->najwiekszy = t2[i];
    }

    if (n%2!=0)
    {
        if (t[n-1]<result->najmniejszy) result->najmniejszy = t[n-1];
        if (t[n-1]>result->najwiekszy) result->najwiekszy = t[n-1];
    }

    return result;
}

int main()
{
    int tab[10]={5,8,45,76,64,7,2,8,145,60};

    wynik* result = naj_tablica(tab,10);

    cout<<"Najmniejsza: "<<result->najmniejszy<<endl;
    cout<<"Najwieksza: "<<result->najwiekszy<<endl;

    return 0;
}
