#include<iostream>
#include"list.h"
using namespace std;

int main()
{
	list* p1;							//��������
	p1 = (list*)malloc(sizeof(list));
	
	dlist* p2, * head2,*p3;						//˫������
	p2 = (dlist*)malloc(sizeof(dlist));

	list* p4;					//��������е�
	p4 = (list*)malloc(sizeof(list));

	list* p6;
	p6= (list*)malloc(sizeof(list));    //������ת

	list* p9;
	p9 = (list*)malloc(sizeof(list));		//�ж��Ƿ�ɻ�

	cout << "�����Ӧ���ֽ����Ӧ����" << endl;
	cout << "1.���������������" << endl << "2.�������������������˫������" << endl << "3.����������Ѱ���м�ڵ�" << endl<<"4.������ת"<<endl<<"5.������ɻ�"<<endl;
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