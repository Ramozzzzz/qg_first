#include"Tree.h"

void Tree::Delete(BST*& b,int num)   //删除二叉树中的节点
{
	if (b == NULL)
	{
		cout << "节点无数据" << endl;
		return;
	}
	else if (num > b->data)   //要删除数据比节点大，进入左孩子
	{
		Delete(b->right,num);
	}
	else if (num < b->data)   //要删除数据比节点小，进入右孩子
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
		else    //左右孩子都不为空
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