#include<iostream>
#include <string>
#include "Chainstack.h"
#include "Caculator.h"
using namespace std;

int Caculator::Prio(char c)   //������������ȼ�
{
	int result;
	if (c == '*' || c == 'x' || c == 'X' || c == '/')
	{
		result = 2;
	}
	else if (c == '+' || c == '-')
	{
		result = 3;
	}
	return result;
}