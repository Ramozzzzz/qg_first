#include<iostream>
#include <string>
#include "Chainstack.h"
#include "Caculator.h"
using namespace std;

string Caculator::InPut_Change(Chainstack::LinkStack& L, Caculator num)  //��׺���ʽתΪ��׺
{
	int i = 0, length = 0;
	string back;
	LinkStack tmp2 = L;
	length = num.Length(num);    
	while (i < length)      //������ʽ
	{
		if (num.formular[i] < '0' || num.formular[i]>'9')
		{
			if (num.formular[i] == '(')    //������������������ջ
			{
				num.Push(L, num.formular[i],9);
				i++;
				continue;
			}
			else if (num.formular[i] == ')')   //����������ջ�ڷ������γ�ջֱ������������
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
			int pri = num.Prio(num.formular[i]);  //�ж���������ȼ�
			if (L.top == NULL)     //��Ϊ��һ���������ֱ����ջ
			{
				num.Push(L, num.formular[i], pri);
			}
			else
			{
				if (pri < L.top->prio)   //����������ȼ�����ջ���������ֱ����ջ
				{
					num.Push(L, num.formular[i], pri);
				}
				else
				{
					while (pri >= L.top->prio)   //�����ջֱ����������ȼ�����ջ���򵽴�ջ��
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
			while (num.formular[i] >= '0' && num.formular[i] <= '9')   //������ֱ��������ַ���
			{
				sum = sum * 10 + (num.formular[i] - '0');
				i++;
			}
			back += to_string(sum)+' ';
		}
	}
	while (L.top)
	{
		back += num.Out(L);   //������ջ������ȫ����ջ���ַ���
	}
	L.top = tmp2.top;
	return back;
}