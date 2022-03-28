#include<iostream>
#include<string>
#include "Chainstack.h"

using namespace std;

void Chainstack::Push(LinkStack& L,char c,int pri)   //ÔËËã·ûÈëÕ»
{
	StackNode* p;
	p = (StackNode*)malloc(sizeof(StackNode));
	p->data = c;
	p->next = L.top;
	p->prio = pri;
	L.top = p;
	L.count++;
}