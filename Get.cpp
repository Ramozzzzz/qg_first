#include <iostream>
#include "Chainstack.h"

using namespace std;

void Chainstack::Get(LinkStack& L)   //��ѯ����
{
	cout << "������Ҫ��ѯ���ݵı��" << endl;
	int num;
	cin >> num;
	if (L.top == NULL)
	{
		cout << "��ǰջ��������" << endl;
		return;
	}
	else if (num > L.count)
	{
		cout << "ջ����������С������ֵ" << endl;
		return;
	}
	LinkStack tmp = L;
	int i = 0;
	while (i < num-1)
	{
		L.top = L.top->next;
		i++;
	}
	cout <<"�ñ������Ϊ��" << L.top->data << endl;
	L.top = tmp.top;
}