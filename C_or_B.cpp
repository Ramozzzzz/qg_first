#include"Tree.h"

bool Tree::CorB()  //是否继续输入
{
	cout << "输入成功，继续输入则输入y，若停止输入则输入n" << endl;
	char ch;
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
	{
		return true;
	}
	else if (ch == 'n' || ch == 'N')
	{
		return false;
	}
	else
	{
		cout << "输入错误,自动退出" << endl;
		return false;
	}
}