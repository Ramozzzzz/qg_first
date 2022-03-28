#include<iostream>
#include <string>
#include "Chainstack.h"
#include "Caculator.h"
using namespace std;

int Caculator::Cacul(string back, Caculator num)
{
	LinkStackNum tmp2;			//数值栈
	int result=0;
	for (int i = 0; i < back.length(); i++)
	{
		if (back[i] != ' ')          //空格是原左括号位置或运算符两边的数字间隔的标志，不进入计算
		{
			if (back[i] >= '0' && back[i] <= '9')    //数字则入栈
			{
				int sum = 0;
				while (back[i] >= '0' && back[i] <= '9')
				{
					sum = sum * 10 + (back[i] - '0');
					i++;
				}
				num.Push(tmp2, sum);
			}
			else
			{
				result += num.Caculate(num.Out(tmp2), num.Out(tmp2), back[i]);  //遇到符号则运算后入栈
				num.Push(tmp2, result);
				result = 0;
			}
		}
	}
	return num.Out(tmp2);
}