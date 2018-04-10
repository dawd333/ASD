#include <iostream>
using namespace std;

struct stack
{
    void push(int tmp);
    int pop();
    bool empty();
};

struct kolejka
{
    stack s;
    stack tmp;
};

void push (kolejka &a, int d)
{
    a.s.push (d);
}

bool empty (const kolejka &a)
{
    if (a.s.empty() && a.tmp.empty()) return true;
    return false;
}

int pop (kolejka &a)
{
    if (empty(&a)) return -1;

    else if (a.tmp.empty())
    {
        while (a.s.empty() != true)
        {
            a.tmp.push(a.s.pop());
        }
    }
    return a.tmp.pop();
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
