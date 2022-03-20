#include<iostream>
#include"list.h"
using namespace std;

int main()
{
	list* p1;							//单向链表
	p1 = (list*)malloc(sizeof(list));
	
	dlist* p2, * head2,*p3;						//双向链表
	p2 = (dlist*)malloc(sizeof(dlist));

	list* p4;					//单链表的中点
	p4 = (list*)malloc(sizeof(list));

	list* p6;
	p6= (list*)malloc(sizeof(list));    //单链表反转

	list* p9;
	p9 = (list*)malloc(sizeof(list));		//判断是否成环

	cout << "输入对应数字进入对应功能" << endl;
	cout << "1.建立并输出单链表" << endl << "2.建立并正、反两向输出双向链表" << endl << "3.建立单链表并寻找中间节点" << endl<<"4.单链表反转"<<endl<<"5.单链表成环"<<endl;
	int i;
	while (1)
	{
		cin >> i;
		switch (i)
		{
			case 1:
				one(p1);
				break;
			case 2:
				two(p2);
				break;
			case 3:
				middle(p4);
				break;
			case 4:
				turn(p6);
				break;
			case 5:
				loop(p9);
		}

	}
}