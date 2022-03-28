#include<iostream>
#include <string>
#include "Chainstack.h"
#include "Caculator.h"
using namespace std;

int main()
{
    
    while (1)
    {
        Caculator num;
        int ero=0;   //错误标记，若为1则输入错误
        cout << "请输入算式:" << endl;
        cin >> num.formular;
        for (int i = 0; i < num.formular.length(); i++)   //错误检测
        {
            if ((num.formular[i] > '9' || num.formular[i] < '0') && num.formular[i] != '*' && num.formular[i] != 'x' && num.formular[i] != 'X' && num.formular[i] != '/' && num.formular[i] != '-' && num.formular[i] != '+' && num.formular[i] != '(' && num.formular[i] != ')')
            {
                cout << "输入的数据有误,请重新输入" << endl;
                ero = 1;
            }
        }
        if (ero == 1)
        {
            continue;
        }
        Chainstack::LinkStack s1, s2;
        s1.count = 0;
        s1.top = NULL;
        s2.count = 0;
        s2.top = NULL;
        string back_expression;
        back_expression = num.InPut_Change(s1, num);
        cout << num.Cacul(back_expression, num) << endl;
    }
    
}
