#include<iostream>
#include"list.h"
using namespace std;


void two(dlist *p2)
{
	dlist* p3=p2, * head2=p2;
	int i = 0;    //��ʾ�Ƿ�Ϊͷ�ڵ�
	cout << "��ֹͣ����������0" << endl;
	while (1)
	{
		cin >> p2->data;
		if (i == 0)   //��Ϊͷ���ʱ��previousΪ��
		{
			p2->previous = NULL;
			i++;
		}
		else
		{
			p2->previous = p3;    //������һ�ڵ�ĵ�ַ��ֵ��previous
		}
		if (p2->data == 0)
		{
			p2->next = NULL;
			break;
		}
		else
		{
			p3 = p2;
			p2->next = (dlist*)malloc(sizeof(dlist));
			p2 = p2->next;
		}
	}
	cout << endl;
	for (; head2->next; head2 = head2->next)    //�����������
	{
		cout << head2->data<<" ";
	}
	cout << endl << endl;
	for (head2=head2->previous; head2; head2 = head2->previous)   //�����������
	{
		cout << head2->data<<" ";
	}
	cout << endl << endl;
}