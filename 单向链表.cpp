
#include <iostream>
#include"list.h"
using namespace std;

void one(list *p1)
{
    list* head1=p1;
    cout << "若停止输入则输入0"<<endl;
    while (1)
    {
        cin >> p1->data1;
        if (p1->data1 == 0)
        {
            p1->next = NULL;
            break;
        }
        else
        {
            p1->next = (list*)malloc(sizeof(list));
            p1 = p1->next;
        }
    }
    for (; head1->next; head1 = head1->next)
    {
        cout << head1->data1<<" ";
    }
    cout << endl << endl;
}

