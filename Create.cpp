#include"Tree.h"
#include<string>
void Tree::Create(BST* &b)  //构造二叉树
{
	cout << "请输入要输入的数据" << endl;
	while (1)
	{
		int num;
		string str;
		bool bo;
		cin >> str;
		try             //输入诊断
		{
			num = stoi(str);
		}
		catch (const std::exception&)
		{
			cout << "输入数据异常,请重新输入" << endl;
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