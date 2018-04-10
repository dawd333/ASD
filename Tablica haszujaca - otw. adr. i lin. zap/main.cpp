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

int deleteHT (HT* t, int x)
{
    int a = findHT(t,x);
    if (a==-1) return -1;
    t->T[a].was=3;
    return 0;
}

int insertHT (HT* t, int x)
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

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
