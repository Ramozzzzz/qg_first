#include<iostream>
#include <string>
#include "Chainstack.h"
#include "Caculator.h"
using namespace std;

string Caculator::InPut_Change(Chainstack::LinkStack& L, Caculator num)  //中缀表达式转为后缀
{
	int i = 0, length = 0;
	string back;
	LinkStack tmp2 = L;
	length = num.Length(num);    
	while (i < length)      //遍历算式
	{
		if (num.formular[i] < '0' || num.formular[i]>'9')
		{
			if (num.formular[i] == '(')    //若左括号则无条件入栈
			{
				num.Push(L, num.formular[i],9);
				i++;
				continue;
			}
			else if (num.formular[i] == ')')   //若右括号则将栈内符号依次出栈直到遇到左括号
			{
				while (L.top->data!='(')
				{
					back += num.Out(L);
					if (L.top == NULL)
					{
						break;
					}
				}
				back += num.Out(L);
				i++;
				continue;
			}
			int pri = num.Prio(num.formular[i]);  //判断运算符优先级
			if (L.top == NULL)     //若为第一个运算符则直接入栈
			{
				num.Push(L, num.formular[i], pri);
			}
			else
			{
				if (pri < L.top->prio)   //若运算符优先级高于栈顶运算符则直接入栈
				{
					num.Push(L, num.formular[i], pri);
				}
				else
				{
					while (pri >= L.top->prio)   //否则出栈直到运算符优先级低于栈顶或到达栈底
					{
						if (L.top->next == NULL)
						{
							back += num.Out(L);
							num.Push(L, num.formular[i], pri);
							break;
						}
						else
						{
							back += num.Out(L);
						}
					}
				}
			}
			i++;
		}
		else
		{
			int sum = 0;
			while (num.formular[i] >= '0' && num.formular[i] <= '9')   //数字则直接输出到字符串
			{
				sum = sum * 10 + (num.formular[i] - '0');
				i++;
			}
			back += to_string(sum)+' ';
		}
	}
	while (L.top)
	{
		back += num.Out(L);   //结束后将栈内内容全部出栈至字符串
	}
	L.top = tmp2.top;
	return back;
}