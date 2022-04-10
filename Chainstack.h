#pragma once
#include<iostream>
#include"Tree.h"

class Chainstack
{
public:
	struct StackNode
	{
		Tree::BST *data;
		StackNode* next;
	};

	struct LinkStack
	{
		StackNode* top;
	};

	void Push(LinkStack& L,Tree::BST *b);
	Tree::BST* Top(LinkStack& L);
	void Out(LinkStack& L);
};


