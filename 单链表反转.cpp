#include <iostream>
#include"list.h"
using namespace std;

void turn(list* p6)
{
    list* p7 = p6;
    cout << "��ֹͣ����������0" << endl;
    while (1)                       //����������
    {
        cin >> p6->data1;
        if (p6->data1 == 0)
        {
            p6->next = NULL;
            break;
        }
        else
        {
            p6->next = (list*)malloc(sizeof(list));
            p6 = p6->next;
        }
    }
    p6 = p7;
    p7 = p6->next;
    p6->next = NULL;        //p6ָ���ͷ�ڵ��Ϊĩ�ڵ㣬next��ΪNULL
    list* p8 = p7->next;
    while (p8)                      
    {
        p7->next = p6;      //����һ�ڵ�ĵ�ַ��ֵ��p7ָ��Ľڵ��next
        p6 = p7;
        p7 = p8;
        p8 = p8->next;
    }
    p8 = p6;
    for (; p8; p8 = p8->next)
    {
        cout << p8->data1 << " ";       //�����ת�������
    }
}