#include"Tree.h"

void Tree::Search(BST* &b)
{
	while (1)
	{
		BST* temp = b;
		bool bo;
		int num;
		cout << "������Ҫ��ѯ������" << endl;
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
			cout << "��ѯ����Ӧ�����ݣ�" << temp->data << endl;
		}
		else if (temp == NULL)
		{
			cout << "δ��ѯ����Ӧ����" << endl;
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