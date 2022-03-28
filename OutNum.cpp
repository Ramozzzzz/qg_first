#include<iostream>
#include "Chainstack.h"

using namespace std;

int Chainstack::Out(LinkStackNum& L)
{
	int number;
	LinkStackNum tmp1 = L;
	number = L.top->data;
	L.top = L.top->next;
	free(tmp1.top);
	L.count--;
	return number;
}