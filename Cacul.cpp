#include<iostream>
#include <string>
#include "Chainstack.h"
#include "Caculator.h"
using namespace std;

int Caculator::Cacul(string back, Caculator num)
{
	LinkStackNum tmp2;			//��ֵջ
	int result=0;
	for (int i = 0; i < back.length(); i++)
	{
		if (back[i] != ' ')          //�ո���ԭ������λ�û���������ߵ����ּ���ı�־�����������
		{
			if (back[i] >= '0' && back[i] <= '9')    //��������ջ
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
				result += num.Caculate(num.Out(tmp2), num.Out(tmp2), back[i]);  //�����������������ջ
				num.Push(tmp2, result);
				result = 0;
			}
		}
	}
	return num.Out(tmp2);
}