#pragma once
#include<iostream>
using namespace std;

struct dlist
{
	dlist* previous;
	int data;
	dlist* next;
};


struct list
{
	int data1;
	list* next;
};

void one(list* p1);
void two(dlist* p2);
void middle(list* p4);
void turn(list* p6);
void loop(list* p9);
void exchange(list* p12);