#include<iostream>
#include "Chainstack.h"

using namespace std;

Tree::BST* Chainstack::Top(LinkStack& L)
{
	if (L.top == NULL)
	{
		return NULL;
	}
	return L.top->data;
}