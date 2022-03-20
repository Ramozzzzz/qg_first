#include <iostream>
#include"list.h"
using namespace std;

void turn(list* p6)
{
    list* p7 = p6;
    cout << "若停止输入则输入0" << endl;
    while (1)                       //建立单链表
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
    p6->next = NULL;        //p6指向的头节点变为末节点，next变为NULL
    list* p8 = p7->next;
    while (p8)                      
    {
        p7->next = p6;      //将上一节点的地址赋值给p7指向的节点的next
        p6 = p7;
        p7 = p8;
        p8 = p8->next;
    }
    p8 = p6;
    for (; p8; p8 = p8->next)
    {
        cout << p8->data1 << " ";       //输出反转后的链表
    }
}