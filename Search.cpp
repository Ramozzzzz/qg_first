#include"Tree.h"

void Tree::Search(BST* &b)
{
	while (1)
	{
		BST* temp = b;
		bool bo;
		int num;
		cout << "请输入要查询的数据" << endl;
		cin >> num;
		while (temp != NULL && temp->data != num)
		{
			if (num > temp->data)
			{
				temp = temp->right;
			}
			else if (num < temp->data)
			{
				temp = temp->left;
			}
		}
		if (temp != NULL)
		{
			cout << "查询到对应的数据：" << temp->data << endl;
		}
		else if (temp == NULL)
		{
			cout << "未查询到对应数据" << endl;
		}
		bo = CorB();
		if (bo == true)
		{
			continue;
		}
		else
		{
			break;
		}
	}
	
}