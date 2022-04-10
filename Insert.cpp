#include "Tree.h"

int Tree::Insert(BST *&b, int i)
{
	if (b == NULL)
	{
		b = (Tree::BST*)malloc(sizeof(Tree::BST));
		b->data = i;
		b->left = NULL;
		b->right = NULL;
		return 1;
	}
	 if (b->data == i)
	{
		return 0;
	}
	else if (i < b->data)
	{
		return Insert(b->left, i);
	}
	else if (i > b->data)
	{
		return Insert(b->right, i);
	}
}