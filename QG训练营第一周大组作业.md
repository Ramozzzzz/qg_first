# QG训练营第一周大组作业

##### 问题描述：

建立单链表

##### 思路分析：

为指向链表的一个指针开辟一块内存，然后再开辟一块内存并使结构体内的next指针变量指向新开辟的内存，以此类推。

##### 代码实现：

`     cout << "若停止输入则输入0"<<endl;
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
        }`

##### 测试结果：

<img src="C:\Users\Ramo\Desktop\QQ截图20220320190021.png" alt="QQ截图20220320190021" style="zoom:50%;" />



##### 问题描述：

建立双向链表

##### 思路分析：

在一个链表节点中既含有指向下一个节点的next指针变量，也有指向上一个节点的指针变量（头节点指向为NULL）。在建立链表的时候需要另设一个指针变量以便实现前一节点的赋值操作。

##### 代码实现：

`		cout << "若停止输入则输入0" << endl;
	while (1)
	{
		cin >> p2->data;
		if (i == 0)   //当为头结点时，previous为空
		{
			p2->previous = NULL;
			i++;
		}
		else
		{
			p2->previous = p3;    //否则将上一节点的地址赋值给previous
		}
		if (p2->data == 0)
		{
			p2->next = NULL;
			break;
		}
		else
		{
			p3 = p2;
			p2->next = (dlist*)malloc(sizeof(dlist));
			p2 = p2->next;
		}
	}`

##### 测试结果：

<img src="C:\Users\Ramo\Desktop\QQ截图20220320190917.png" alt="QQ截图20220320190917" style="zoom:50%;" />

##### 问题描述：

寻找单链表的中间节点

##### 思路分析：

首先使用两个指针变量（设为p1和p2）同时指向链表的头节点，p1前进两次后p2前进一次，当p1指向末节点时，则p2指向了中间节点。

##### 代码实现：

`		cout << "若停止输入则输入0" << endl;
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
}`

##### 测试结果：<img src="C:\Users\Ramo\Desktop\QQ截图20220320191506.png" alt="QQ截图20220320191506" style="zoom:50%;" />

##### 问题描述：

单链表反转

##### 思路分析：

使用三个指针变量，分别指向链表的头三个节点。将前一节点的地址赋值给下一节点的next变量。同时原头节点next变量赋值为NULL，变为末节点，原末节点变为头节点。

##### 代码实现：

`		cout << "若停止输入则输入0" << endl;
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
    }`

##### 测试结果：

<img src="C:\Users\Ramo\Desktop\QQ截图20220320192142.png" alt="QQ截图20220320192142" style="zoom:50%;" />

##### 问题描述：

判断单链表是否成环

##### 思路分析：

首先使用两个指针变量（设为p1和p2）同时指向链表的头节点，p1前进两次后p2前进一次。若链表成环则p1和p2终会指向同一节点，即所指向的地址相同。若不成环则在遍历链表后结束。

##### 代码实现：

` list *p10 = p9,*p11=p9;
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
    }`

##### 测试结果：

<img src="C:\Users\Ramo\Desktop\QQ截图20220320192526.png" alt="QQ截图20220320192526" style="zoom: 50%;" />







