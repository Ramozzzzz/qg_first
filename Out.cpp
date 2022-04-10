#include<iostream>
#include "Chainstack.h"

using namespace std;

void Chainstack::Out(LinkStack& L)
{
	LinkStack tmp = L;
	if (L.top == NULL)
	{
		return;
	}
	L.top = L.top->next;
	free(tmp.top);
}