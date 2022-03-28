#pragma once
#include<iostream>
#include <string>
#include "Chainstack.h"
using namespace std;

class Caculator:public Chainstack     //º∆À„¿‡
{
public:
	string formular;

	int Prio(char c);
	int Caculate(int a, int b, char c);
	int Length(Caculator num);
	string InPut_Change(Chainstack::LinkStack& L, Caculator num);
	int Cacul(string back,  Caculator num);

};
