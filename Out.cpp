#include<iostream>
#include "Chainstack.h"

using namespace std;

void Chainstack::Out(LinkStack& L)
{
	LinkStack tmp = L;
	if (L.top == NULL)
	{
		cout << "ջ��������" << endl;
		return;
	}
	cout << "��ջ�ɹ�����ջ����Ϊ��" << L.top->data << endl;
	L.top = L.top->next;
	free(tmp.top);
	L.count--;
}