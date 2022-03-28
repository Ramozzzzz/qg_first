#include<iostream>
#include "Chainstack.h"

using namespace std;

void Chainstack::Out(LinkStack& L)
{
	LinkStack tmp = L;
	if (L.top == NULL)
	{
		cout << "栈中无数据" << endl;
		return;
	}
	cout << "出栈成功，出栈数据为：" << L.top->data << endl;
	L.top = L.top->next;
	free(tmp.top);
	L.count--;
}