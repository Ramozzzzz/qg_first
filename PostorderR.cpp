#include"Chainstack.h"

void Tree::PostorderR(BST*& b)
{
	if (b != NULL)
	{
		Chainstack C;
		Chainstack::LinkStack L;
		L.top = NULL;
		BST* temp = b ,*temp1 = b, *temp2 = NULL;
		C.Push(L, temp);
		while (L.top != NULL)
		{
			temp1 = C.Top(L);
			if ((temp1->left == NULL && temp1->right == NULL) ||((temp2 == temp1->left || temp2 == temp1->right) && temp2 != NULL))
			{
				cout << temp1->data<<" ";
				C.Out(L);
				temp2 = temp1;
			}
			else
			{
				if (temp1->right != NULL)
				{
					C.Push(L, temp1->right);
				}
				if (temp1->left != NULL)
				{
					C.Push(L, temp1->left);
				}
			}
		}
		/*stack<BST*>s;
		BST* cur = b, * pre = NULL, * temp = b;
		s.push(temp);
		while (!s.empty())
		{
			cur = s.top();
			if ((cur->left == NULL && cur->right == NULL) ||
				((pre == cur->left || pre == cur->right) && pre != NULL))
			{
				cout << cur->data << " ";
				s.pop();
				pre = cur;
			}
			else
			{
				if (cur->right != NULL)
					s.push(cur->right);
				if (cur->left != NULL)
					s.push(cur->left);
			}
		}*/
	}
}