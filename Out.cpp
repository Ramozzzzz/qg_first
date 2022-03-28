#include<iostream>
#include "Chainstack.h"

using namespace std;

char Chainstack::Out(LinkStack& L)
{
	char symbol;
	LinkStack tmp1 = L;
	symbol = L.top->data;
	L.top = L.top->next;
	free(tmp1.top);
	L.count--;
	if (symbol == '(' || symbol == ')')		//若为左右括号则返回空格
	{
		return ' ';
	}
	else
	{
		return symbol;
	}
}