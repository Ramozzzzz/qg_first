#include<iostream>
#include<string>
#include "Chainstack.h"

using namespace std;

void Chainstack::Push(LinkStackNum& L, int c)   //ÊýÖµÈëÕ»
{
	StackNodeNum* p;
	p = (StackNodeNum*)malloc(sizeof(StackNodeNum));
	p->data = c;
	p->next = L.top;
	L.top = p;
	L.count++;
}