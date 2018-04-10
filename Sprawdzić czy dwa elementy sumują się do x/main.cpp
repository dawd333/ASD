#include <iostream>
using namespace std;

struct HTe
{
    int key;
    int was;
};

struct HT
{
    HTe* T;
    int Size;
};

int findHT (HT* t, int x)
{
    int index = Hash (x,t->Size);

    for (int i=0;i<t->Size;i++)
    {
        int j = (index+i)% t->Size;
        int a = t->T[j].was;
        if (a==1) return -1;
        if (a==2)
        {
            if (x==t->T[j].key) return j;
        }
    }
    return -1;
}

int inserHT (HT* t, int x)
{
    int index = Hash (x,t->Size);

    for (int i=0;i<t->Size;i++)
    {
        int j = (i+index)%t->Size;

        if (t->T[j].was !=2)
        {
            t->T[j].was = 2;
            t->T[j].key = x;
            return j;
        }
    }
    return -1;
}

bool checksum (int x,int* A,int n)
{
    HT*t = new HT();
    t->T = new HTe[2*n];
    t->Size = 2*n;

    for (int i=0;i<n;i++)
    {
        if (findHT(t,A[i]) != -1) return true;
        inserHT(t,x-A[i]);
    }
    return false;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
