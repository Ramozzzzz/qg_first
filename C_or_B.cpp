#include"Tree.h"

bool Tree::CorB()  //�Ƿ��������
{
	cout << "����ɹ�����������������y����ֹͣ����������n" << endl;
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
		cout << "�������,�Զ��˳�" << endl;
		return false;
	}
}