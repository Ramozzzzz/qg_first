#include<iostream>
#include <string>
#include "Chainstack.h"
#include "Caculator.h"
using namespace std;

int Caculator::Length(Caculator num)   //计算算式长度
{
	if (num.formular.length() == 0)
	{
		return -1;
	}
	else
	{
		return num.formular.length();
	}
}