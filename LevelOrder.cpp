#include"Tree.h"

void Tree::LevelOrder(BST* b)
{
	BST* temp = b;
	queue<BST*> que;
	que.push(temp);
	while (!que.empty())
	{
		temp = que.front();
		que.pop();
		cout << temp->data<<" ";
		if (temp->left != NULL) que.push(temp->left);
		if (temp->right != NULL) que.push(temp->right);
	}
}