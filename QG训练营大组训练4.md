### QG训练营大组训练4

#### 问题描述：

实现二叉排序树的基本操作。

#### 思路分析：

##### 插入：

首次插入则直接开辟空间存储数据，非首次则通过递归方式寻找到对应父节点，若输入数据大于父节点数据，则插入右侧，若小于父节点则插入左侧。

##### 删除：

首先寻找要删除的节点，若要删除数据大于当前节点，则进入左孩子，否则进入右孩子，直至找到要删除节点。若对应节点的左孩子为空释放该节点并将右孩子上移，右孩子为空则左孩子上移。若左右孩子都不为空，当左孩子的右孩子不为空，则右孩子的地址赋值给左孩子，父节点数据变为左孩子的数据。

##### 先序遍历：

递归法则先输出父节点再从左到右输出子节点，非递归法则按一定的次序入栈并按一定的顺序出栈。

##### 中序遍历：

递归法先输出左侧节点再输出父节点最后输出右节点，非递归法同样按照一定次序入栈出栈。

##### 后序遍历：

递归法先输出左侧节点后输出右侧节点最后输出中间节点，非递归法同样按照一定次序入栈出栈。

##### 层序遍历：

使用队列控制，一次输出每一层的数据。

#### 代码实现：

##### 插入：

`int Tree::Insert(BST *&b, int i)
{
	if (b == NULL)
	{
		b = (Tree::BST*)malloc(sizeof(Tree::BST));
		b->data = i;
		b->left = NULL;
		b->right = NULL;
		return 1;
	}
	 if (b->data == i)
	{
		return 0;
	}
	else if (i < b->data)
	{
		return Insert(b->left, i);
	}
	else if (i > b->data)
	{
		return Insert(b->right, i);
	}
}`

##### 构造：

`void Tree::Create(BST* &b)  //构造二叉树
{
	cout << "请输入要输入的数据" << endl;
	while (1)
	{
		int num;
		string str;
		bool bo;
		cin >> str;
		try             //输入诊断
		{
			num = stoi(str);
		}
		catch (const std::exception&)
		{
			cout << "输入数据异常,请重新输入" << endl;
			continue;
		}
		Insert(b, num);
		bo = CorB();
		if (bo==true)
		{
			continue;
		}
		else
		{
			break;
		}
	}
}`

##### 删除：

`void Tree::Delete(BST*& b,int num)   //删除二叉树中的节点
{
	if (b == NULL)
	{
		cout << "节点无数据" << endl;
		return;
	}
	else if (num > b->data)   //要删除数据比节点大，进入左孩子
	{
		Delete(b->right,num);
	}
	else if (num < b->data)   //要删除数据比节点小，进入右孩子
	{
		Delete(b->left,num);
	}
	else if (num == b->data)
	{
		if (b->left == NULL)
		{
			BST* temp = b;
			b = b->right;
			free(temp);
		}
		else if (b->right == NULL)
		{
			BST* temp = b;
			b = b->left;
			free(temp);
		}
		else    //左右孩子都不为空
		{
			BST* temp = b->left;
			if (temp->right != NULL)
			{
				temp = temp->right;
			}
			b->data = temp->data;
			Delete(b->left, temp->data);
		}
	}
}`

##### 查找：

`void Tree::Search(BST* &b)
{
	while (1)
	{
		BST* temp = b;
		bool bo;
		int num;
		cout << "请输入要查询的数据" << endl;
		cin >> num;
		while (temp != NULL && temp->data != num)
		{
			if (num > temp->data)
			{
				temp = temp->right;
			}
			else if (num < temp->data)
			{
				temp = temp->left;
			}
		}
		if (temp != NULL)
		{
			cout << "查询到对应的数据：" << temp->data << endl;
		}
		else if (temp == NULL)
		{
			cout << "未查询到对应数据" << endl;
		}
		bo = CorB();
		if (bo == true)
		{
			continue;
		}
		else
		{
			break;
		}
	}
	`

##### 先序遍历：

递归：

`void Tree::PreorderI(BST *&b)
{
    BST* temp = b;
    if (temp != NULL)
    {
        cout << b->data << " ";
        PreorderI(b->left);
        PreorderI(b->right);
    }
    else
    {
        return;
    }
}`

非递归：

`void Tree::PreorderR(BST*& b)
{
	if (b != NULL)
	{
		BST* temp = b;
		Chainstack C;
		Chainstack::LinkStack L;
		L.top = NULL;
		while (temp != NULL || L.top != NULL)
		{
			while (temp != NULL)
			{
				C.Push(L,temp);
				cout << temp->data << " ";
				temp = temp->left;
			}
			if (L.top != NULL)
			{
				temp = C.Top(L);
				C.Out(L);
				temp = temp->right;
			}
		}
	}
}`

##### 中序遍历：

递归：

`void Tree::InorderI(BST*& b)   //递归版先序
{
    BST* temp = b;
    if (temp != NULL) 
    {
        InorderI(b->left);
        cout << b->data << " ";
        InorderI(b->right);
    }
    else
    {
        return;
    }
}`

非递归：

`void Tree::InorderR(BST*& b)   //非递归版先序
{
	if (b != NULL)
	{
		BST* temp = b;
		Chainstack C;
		Chainstack::LinkStack L;
		L.top = NULL;
		while (temp != NULL || L.top != NULL)
		{
			while (temp != NULL)
			{
				C.Push(L, temp);
				temp = temp->left;
			}
			if (L.top != NULL)
			{
				temp = C.Top(L);
				cout << temp->data << " ";
				C.Out(L);
				temp = temp->right;
			}
		}`

##### 后序遍历：

递归：

`void Tree::PostorderI(BST*& b)
{
    BST* temp = b;
    if (temp != NULL)
    {
        PostorderI(b->left);
        PostorderI(b->right);
        cout << b->data << " ";
    }
    else
    {
        return;
    }
}`

非递归：

`void Tree::PostorderR(BST*& b)
{
	if (b != NULL)
	{
		Chainstack C;
		Chainstack::LinkStack L;
		L.top = NULL;
		BST* temp = b ,*temp1 = b, *temp2 = NULL;
		C.Push(L, temp);
		while (L.top != NULL)
		{
			temp1 = C.Top(L);
			if ((temp1->left == NULL && temp1->right == NULL) ||((temp2 == temp1->left || temp2 == temp1->right) && temp2 != NULL))
			{
				cout << temp1->data<<" ";
				C.Out(L);
				temp2 = temp1;
			}
			else
			{
				if (temp1->right != NULL)
				{
					C.Push(L, temp1->right);
				}
				if (temp1->left != NULL)
				{
					C.Push(L, temp1->left);
				}
			}
		}`

##### 层序遍历：

`void Tree::LevelOrder(BST* b)
{
	BST* temp = b;
	queue<BST*> que;
	que.push(temp);
	while (!que.empty())
	{
		temp = que.front();
		que.pop();
		cout << temp->data<<" ";
		if (temp->left != NULL) que.push(temp->left);
		if (temp->right != NULL) que.push(temp->right);
	}
}`

#### 测试结果：

![](https://img-blog.csdnimg.cn/1cf3478535b845b4b0959944fca91e17.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAUmFtb3p6eg==,size_17,color_FFFFFF,t_70,g_se,x_16)

![](https://img-blog.csdnimg.cn/096b3e7dffaa439a8662145da7e52f93.png)

![](https://img-blog.csdnimg.cn/b06c082813674d998ad99e68ac6fd026.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAUmFtb3p6eg==,size_18,color_FFFFFF,t_70,g_se,x_16)

![](https://img-blog.csdnimg.cn/cfb60c4b5182430dac5a767d316121e2.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAUmFtb3p6eg==,size_13,color_FFFFFF,t_70,g_se,x_16)

![](https://img-blog.csdnimg.cn/710f0f6ab39b4a39959c7b5b970e3b86.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAUmFtb3p6eg==,size_13,color_FFFFFF,t_70,g_se,x_16)

![](https://img-blog.csdnimg.cn/bed902e3fa294dc08a59c87d0e819b37.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAUmFtb3p6eg==,size_13,color_FFFFFF,t_70,g_se,x_16)

![](https://img-blog.csdnimg.cn/34b2e6d759a64d4f8c8c96e29dce9cd2.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAUmFtb3p6eg==,size_12,color_FFFFFF,t_70,g_se,x_16)