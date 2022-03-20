#include<iostream>
#include"list.h"
using namespace std;


void two(dlist *p2)
{
	dlist* p3=p2, * head2=p2;
	int i = 0;    //表示是否为头节点
	cout << "若停止输入则输入0" << endl;
	while (1)
	{
		cin >> p2->data;
		if (i == 0)   //当为头结点时，previous为空
		{
			p2->previous = NULL;
			i++;
		}
		else
		{
			p2->previous = p3;    //否则将上一节点的地址赋值给previous
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
	for (; head2->next; head2 = head2->next)    //正向输出链表
	{
		cout << head2->data<<" ";
	}
	cout << endl << endl;
	for (head2=head2->previous; head2; head2 = head2->previous)   //反向输出链表
	{
		cout << head2->data<<" ";
	}
	cout << endl << endl;
}