#pragma once
#include<iostream>
class Chainstack
{
public:
	struct StackNode
	{
		int data;
		StackNode* next;
	};

	struct LinkStack
	{
		StackNode* top;
		int count;
	};

	void Push(LinkStack& L);
	void Get(LinkStack& L);
	void Out(LinkStack& L);
};
void Menu(Chainstack c, Chainstack::LinkStack& L);

