#include"Tree.h"
#include<string>
void Tree::Create(BST* &b)  //���������
{
	cout << "������Ҫ���������" << endl;
	while (1)
	{
		int num;
		string str;
		bool bo;
		cin >> str;
		try             //�������
		{
			num = stoi(str);
		}
		catch (const std::exception&)
		{
			cout << "���������쳣,����������" << endl;
			continue;
		}
		Insert(b, num);
		bo = CorB();
		if (bo==true)
		{
			continue;
		}
		else
		{
			break;
		}
	}
}