#pragma once
#include<iostream>
#include"list.h"
using namespace std;

void exchange(list* p12)
{
    list* head = p12, * q1 = p12;
    cout << "��ֹͣ����������0" << endl;
    while (1)
    {
        cin >> p12->data1;
        if (p12->data1 == 0)
        {
            p12->next = NULL;
            break;
        }
        else
        {
            p12->next = (list*)malloc(sizeof(list));
            p12 = p12->next;
        }
    }
    list* q2 = q1->next;
    head = q2;
    q1->next = q2->next;        //ǰ�����ڵ�ĶԻ�
    q2->next = q1;
    list* q = q1;
    while (q1->next)
    {
        q1 = q->next;
        q2 = q1->next;
        q->next = q2;
        if (q2 == NULL)         //q2Ϊ��ʱ����
        {
            break;
        }
        q1->next = q2->next;
        q2->next = q1;
        q = q1;
    }
    while (head)
    {
        if (head->data1 !=0)            //�ų�������־0�ĸ���
        {
            cout << head->data1 << " ";
        }
        
        head = head->next;
    }
    cout << endl;
}