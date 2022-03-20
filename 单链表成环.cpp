#include <iostream>
#include"list.h"
using namespace std;

void loop(list* p9)
{
    list *p10 = p9,*p11=p9;
    char w1,w2='n';
    cout << "若停止输入则输入0" << endl;
    while (1)        //建立环形链表
    {
        cin >> p9->data1;
        if (p9->data1 == 0)
        {
            cout << "是否建立环形链表？(y/n)" << endl;
            cin >> w1;
            if (w1 == 'y')
            {
                p9->next = p10;     //建立则将头节点地址赋值给末节点的next
                break;
            }
            else if (w1 == 'n')
            {
                p9->next = NULL;    //否则赋值为NULL
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
        if (i % 2 == 0)      //p10为快指针，p11为慢指针。p10前进两次，p11前进一次
        {
            if (p10 == p11)
            {
                cout << "该链表为环形链表" << endl;
                w2 = 'y';       //标志着该链表为环形链表
                break;
            }
            p11 = p11->next;
        }
        
        i++;
    }
    if (w2=='n')
    {
        cout << "该链表不为环形链表" << endl;
    }
}