#include <iostream>
#include"list.h"
using namespace std;

void middle(list *p4)
{
    list* p5=p4, * head3=p4;
    cout << "��ֹͣ����������0" << endl;
    while (1)                           //����������
    {
        cin >> p4->data1;
        if (p4->data1 == 0)
        {
            p4->next = NULL;
            break;
        }
        else
        {
            p4->next = (list*)malloc(sizeof(list));
            p4 = p4->next;
        }
    }
    for (int i=1; p5->next; p5 = p5->next)
    {
        if (i % 2 == 0)      //p5Ϊ��ָ�룬head3Ϊ��ָ�롣p5ǰ�����Σ�head3ǰ��һ��
        {
            head3 = head3->next;    
        }
        i++;
    }
    cout << "�õ�������м�ڵ�����Ϊ:" << head3->data1<<endl << endl;
}