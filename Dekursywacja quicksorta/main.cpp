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

void qsort_stack (int tab[],int l,int p)
{
    stack s;
    s.push(l);
    s.push(p);

    while (!s.Empty())
    {
        p=s.pop;
        l=s.pop;

        while (l<p)
        {
            int q = partition_horae (tab,l,p);
            s.push(l);
            s.push(q);
            l=q+1;
        }
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
