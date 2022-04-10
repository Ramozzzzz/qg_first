#pragma once
#include<iostream>
#include<stack>
#include<queue>

using namespace std;

class Tree
{
public:
	struct BST
	{
		int data;
		BST* left, * right;
	};

	bool CorB();

	void Create(BST *&b);
	int Insert(BST *&b,int i);
	void Search(BST* &b);
	void Delete(BST*& b,int num);

	void PreorderI(BST*& b);
	void InorderI(BST*& b);
	void PostorderI(BST*& b);

	void PreorderR(BST*& b);
	void InorderR(BST*& b);
	void PostorderR(BST*& b);

	void LevelOrder(BST* b);
};