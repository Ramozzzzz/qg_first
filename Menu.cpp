#include<iostream>
#include "Chainstack.h"

using namespace std;

void Menu(Chainstack c, Chainstack::LinkStack &L)
{
	cout << "����������ִ����Ӧ�Ĺ���" << endl;
	cout << "1.��ջ" << endl << "2.��ѯ" << endl << "3.��ջ"  << endl;
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