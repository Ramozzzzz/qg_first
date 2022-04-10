#include "Tree.h"
#include"Chainstack.h"

void Tree::PreorderR(BST*& b)
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
				C.Push(L,temp);
				cout << temp->data << " ";
				temp = temp->left;
			}
			if (L.top != NULL)
			{
				temp = C.Top(L);
				C.Out(L);
				temp = temp->right;
			}
		}
	}
}