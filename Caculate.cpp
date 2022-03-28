#include<iostream>
#include <string>
#include "Chainstack.h"
#include "Caculator.h"
using namespace std;

int Caculator::Caculate(int a,int b,char c)     //计算传入的值
{
	int result;
	if (c == '+')
	{
		result = a + b;
	}
	else if (c == '-')
	{
		result = a - b;
	}
	else if (c == 'x' || c == 'X' || c == '*')
	{
		result = a * b;
	}
	else if (c == '/')
	{
		result = a / b;
	}
	return result;
}