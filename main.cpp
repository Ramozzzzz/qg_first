#include <iostream>
#include "Chainstack.h"

using namespace std;

int main()
{
    Chainstack::LinkStack s;
    s.count = 0;
    s.top = NULL;
    Chainstack c;
    Menu(c,s);
}


