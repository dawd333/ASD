#include <iostream>
using namespace std;

struct Data
{
    char* first_name;
    char* last_name;
    int age;
};

int good_hash (Data* x)
{
    int i,h=0;

    int s = strlen (x->first_name);
    for (int i=0;i<s;i++) h+=(i+1) * x->first_name[i];

    s = strlen (x->last_name);
    for (int i=0;i<s;i++) h+=(i+1) * x->last_name[i];

    h*=x->age;

    return h;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
