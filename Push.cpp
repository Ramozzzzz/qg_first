#include<iostream>
#include<string>
#include "Chainstack.h"

using namespace std;

void Chainstack::Push(LinkStack& L)
{
	while (1)
	{
		string i;
		cout << "请输入要入栈的数据" << endl;
		cin >> i;
		for (int j = 0; j < i.length(); j++)   //输入诊断
		{
			if (i[j] < 48 || i[j]>57)
			{
				cout << "输入的数据有误" << endl;
				return;
			}
		}
		StackNode* p;
		p = (StackNode*)malloc(sizeof(StackNode));
		try             //输入诊断
		{
			p->data = stoi(i);
		}
		catch (const std::exception&)
		{
			cout << "输入数据异常,请重新输入" << endl;
			continue;
		}
		p->next = L.top;
		L.top = p;
		L.count++;
		cout << "入栈成功,是否继续输入？(输入y或Y继续以输入，否则结束输入)" << endl;
		char c;
		cin >> c;
		if (c == 'y'||c=='Y')
		{
			continue;
		}
		else
		{
			cout << "已结束输入" << endl;
			return;
		}
	}
}