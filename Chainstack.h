#pragma once
#include<iostream>
class Chainstack    //¡¥’ª¿‡
{
public:
	struct StackNode
	{
		char data;
		int prio;
		StackNode* next;
	};

	struct StackNodeNum
	{
		int data;
		StackNodeNum* next;
	};

	struct LinkStack
	{
		StackNode* top;
		int count;
	};

	struct LinkStackNum
	{
		StackNodeNum* top;
		int count;
	};

	void Push(LinkStack& L,char c,int pri);
	char Out(LinkStack& L);
	int Out(LinkStackNum& L);
	void Push(LinkStackNum& L, int c);

};