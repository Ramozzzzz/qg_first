#include <iostream>
#include"list.h"
using namespace std;

void middle(list *p4)
{
    list* p5=p4, * head3=p4;
    cout << "若停止输入则输入0" << endl;
    while (1)                           //建立单链表
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
        if (i % 2 == 0)      //p5为快指针，head3为慢指针。p5前进两次，head3前进一次
        {
            head3 = head3->next;    
        }
        i++;
    }
    cout << "该单链表的中间节点数据为:" << head3->data1<<endl << endl;
}