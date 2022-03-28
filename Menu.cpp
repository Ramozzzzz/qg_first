#include<iostream>
#include "Chainstack.h"

using namespace std;

void Menu(Chainstack c, Chainstack::LinkStack &L)
{
	cout << "输入数字以执行相应的功能" << endl;
	cout << "1.入栈" << endl << "2.查询" << endl << "3.出栈"  << endl;
	int i;
	while (1)
	{
		cin >> i;
		switch (i)
		{
		case 1:
			c.Push(L);
			break;
		case 2:
			c.Get(L);
			break;
		case 3:
			c.Out(L);
			break;
		}
	}
}