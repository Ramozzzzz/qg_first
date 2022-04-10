#include <iostream>
#include "Chainstack.h"

using namespace std;

void Chainstack::Get(LinkStack& L)   //查询函数
{
	cout << "请输入要查询数据的编号" << endl;
	int num;
	cin >> num;
	if (L.top == NULL)
	{
		cout << "当前栈中无数据" << endl;
		return;
	}
	else if (num > L.count)
	{
		cout << "栈中数据数量小于所给值" << endl;
		return;
	}
	LinkStack tmp = L;
	int i = 0;
	while (i < num-1)
	{
		L.top = L.top->next;
		i++;
	}
	cout <<"该编号数据为：" << L.top->data << endl;
	L.top = tmp.top;
}