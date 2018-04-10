#include <iostream>
using namespace std;

bool novalid (char* s) // string s
{
    int length = strlen(s);
    int k=0;
    for (int i=0;i<length;i++)
    {
        if (s[i]='(') k++;
        else (s[i]=')') k--;
        if (k<0) return false;
    }
    if (k==0) return true;
    else return false;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
