#include"Tree.h"
#include"Chainstack.h"

void Tree::InorderR(BST*& b)   //·ÇµÝ¹é°æÏÈÐò
{
	if (b != NULL)
	{
		BST* temp = b;
		Chainstack C;
		Chainstack::LinkStack L;
		L.top = NULL;
		while (temp != NULL || L.top != NULL)
		{
			while (temp != NULL)
			{
				C.Push(L, temp);
				temp = temp->left;
			}
			if (L.top != NULL)
			{
				temp = C.Top(L);
				cout << temp->data << " ";
				C.Out(L);
				temp = temp->right;
			}
		}
		/*stack<BST*>s;
		while (temp != NULL || !s.empty())
		{
			while (temp != NULL)
			{
				s.push(temp);
				temp = temp->left;
			}
			if (!s.empty())
			{
				temp = s.top();
				cout << temp->data << " ";
				s.pop();
				temp = temp->right;
			}
		}*/
	}
}
