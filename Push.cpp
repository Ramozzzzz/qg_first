#include<iostream>
#include<string>
#include "Chainstack.h"

using namespace std;

void Chainstack::Push(LinkStack& L)
{
	while (1)
	{
		string i;
		cout << "������Ҫ��ջ������" << endl;
		cin >> i;
		for (int j = 0; j < i.length(); j++)   //�������
		{
			if (i[j] < 48 || i[j]>57)
			{
				cout << "�������������" << endl;
				return;
			}
		}
		StackNode* p;
		p = (StackNode*)malloc(sizeof(StackNode));
		try             //�������
		{
			p->data = stoi(i);
		}
		catch (const std::exception&)
		{
			cout << "���������쳣,����������" << endl;
			continue;
		}
		p->next = L.top;
		L.top = p;
		L.count++;
		cout << "��ջ�ɹ�,�Ƿ�������룿(����y��Y���������룬�����������)" << endl;
		char c;
		cin >> c;
		if (c == 'y'||c=='Y')
		{
			continue;
		}
		else
		{
			cout << "�ѽ�������" << endl;
			return;
		}
	}
}