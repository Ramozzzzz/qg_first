#include"Tree.h"

void Tree::Delete(BST*& b,int num)   //ɾ���������еĽڵ�
{
	if (b == NULL)
	{
		cout << "�ڵ�������" << endl;
		return;
	}
	else if (num > b->data)   //Ҫɾ�����ݱȽڵ�󣬽�������
	{
		Delete(b->right,num);
	}
	else if (num < b->data)   //Ҫɾ�����ݱȽڵ�С�������Һ���
	{
		Delete(b->left,num);
	}
	else if (num == b->data)
	{
		if (b->left == NULL)
		{
			BST* temp = b;
			b = b->right;
			free(temp);
		}
		else if (b->right == NULL)
		{
			BST* temp = b;
			b = b->left;
			free(temp);
		}
		else    //���Һ��Ӷ���Ϊ��
		{
			BST* temp = b->left;
			if (temp->right != NULL)
			{
				temp = temp->right;
			}
			b->data = temp->data;
			Delete(b->left, temp->data);
		}
	}
}