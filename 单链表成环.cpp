#include <iostream>
#include"list.h"
using namespace std;

void loop(list* p9)
{
    list *p10 = p9,*p11=p9;
    char w1,w2='n';
    cout << "��ֹͣ����������0" << endl;
    while (1)        //������������
    {
        cin >> p9->data1;
        if (p9->data1 == 0)
        {
            cout << "�Ƿ�����������(y/n)" << endl;
            cin >> w1;
            if (w1 == 'y')
            {
                p9->next = p10;     //������ͷ�ڵ��ַ��ֵ��ĩ�ڵ��next
                break;
            }
            else if (w1 == 'n')
            {
                p9->next = NULL;    //����ֵΪNULL
                break;
            }
        }
        else
        {
            p9->next = (list*)malloc(sizeof(list));
            p9 = p9->next;
        }
    }
    for (int i = 1; p10->next; p10 = p10->next)
    {
        if (i % 2 == 0)      //p10Ϊ��ָ�룬p11Ϊ��ָ�롣p10ǰ�����Σ�p11ǰ��һ��
        {
            if (p10 == p11)
            {
                cout << "������Ϊ��������" << endl;
                w2 = 'y';       //��־�Ÿ�����Ϊ��������
                break;
            }
            p11 = p11->next;
        }
        
        i++;
    }
    if (w2=='n')
    {
        cout << "������Ϊ��������" << endl;
    }
}