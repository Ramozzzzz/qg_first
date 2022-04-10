#include<iostream>
#include<string>
#include "Chainstack.h"

using namespace std;

void Chainstack::Push(LinkStack& L, Tree::BST* b)
{
	StackNode* p;
	p = (StackNode*)malloc(sizeof(StackNode));
	p->data = b;
	p->next = L.top;
	L.top = p;
}