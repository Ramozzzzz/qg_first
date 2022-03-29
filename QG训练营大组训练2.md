### QG训练营大组训练2

#### 问题描述：

实现链栈

#### 思路分析

定义两个结构体，前者为节点后者指向栈顶。

#### 代码实现：

`void Chainstack::Push(LinkStack& L)  //入栈函数
{
	while (1)
	{
		string i;
		cout << "请输入要入栈的数据" << endl;
		cin >> i;
		for (int j = 0; j < i.length(); j++)   //输入诊断
		{
			if (i[j] < 48 || i[j]>57)
			{
				cout << "输入的数据有误" << endl;
				return;
			}
		}
		StackNode* p;
		p = (StackNode*)malloc(sizeof(StackNode));
		try             //输入诊断
		{
			p->data = stoi(i);
		}
		catch (const std::exception&)
		{
			cout << "输入数据异常,请重新输入" << endl;
			continue;
		}
		p->next = L.top;
		L.top = p;
		L.count++;
		cout << "入栈成功,是否继续输入？(输入y或Y继续以输入，否则结束输入)" << endl;
		char c;
		cin >> c;
		if (c == 'y'||c=='Y')
		{
			continue;
		}
		else
		{
			cout << "已结束输入" << endl;
			return;
		}
	}
}`

`void Chainstack::Out(LinkStack& L)  //出栈函数
{
	LinkStack tmp = L;
	if (L.top == NULL)
	{
		cout << "栈中无数据" << endl;
		return;
	}
	cout << "出栈成功，出栈数据为：" << L.top->data << endl;
	L.top = L.top->next;
	free(tmp.top);
	L.count--;
}`

`void Chainstack::Get(LinkStack& L)   //查询函数
{
	cout << "请输入要查询数据的编号" << endl;
	int num;
	cin >> num;
	if (L.top == NULL)
	{
		cout << "当前栈中无数据" << endl;
		return;
	}
	else if (num > L.count)
	{
		cout << "栈中数据数量小于所给值" << endl;
		return;
	}
	LinkStack tmp = L;
	int i = 0;
	while (i < num-1)
	{
		L.top = L.top->next;
		i++;
	}
	cout <<"该编号数据为：" << L.top->data << endl;
	L.top = tmp.top;
}`

#### 测试结果：

![](https://img-blog.csdnimg.cn/4e92fdfefa3d408291a5fbc9e0e85ce0.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAUmFtb3p6eg==,size_20,color_FFFFFF,t_70,g_se,x_16)





#### 问题描述：

四则运算表达式求值计算器

#### 思路分析：

首先将输入的中缀表达式转换为后缀表达式，然后判断数字与符号，进行相应计算。

#### 代码实现：

`class Caculator:public Chainstack     //计算类
{
public:
	string formular;

	int Prio(char c);
	int Caculate(int a, int b, char c);
	int Length(Caculator num);
	string InPut_Change(Chainstack::LinkStack& L, Caculator num);
	int Cacul(string back,  Caculator num);

};`

`class Chainstack    //链栈类
{
public:
	struct StackNode
	{
		char data;
		int prio;
		StackNode* next;
	};

	struct StackNodeNum
	{
		int data;
		StackNodeNum* next;
	};
	
	struct LinkStack
	{
		StackNode* top;
		int count;
	};
	
	struct LinkStackNum
	{
		StackNodeNum* top;
		int count;
	};
	
	void Push(LinkStack& L,char c,int pri);
	char Out(LinkStack& L);
	int Out(LinkStackNum& L);
	void Push(LinkStackNum& L, int c);

};`

`int Caculator::Cacul(string back, Caculator num)
{
	LinkStackNum tmp2;			//数值栈
	int result=0;
	for (int i = 0; i < back.length(); i++)
	{
		if (back[i] != ' ')          //空格是原左括号位置或运算符两边的数字间隔的标志，不进入计算
		{
			if (back[i] >= '0' && back[i] <= '9')    //数字则入栈
			{
				int sum = 0;
				while (back[i] >= '0' && back[i] <= '9')
				{
					sum = sum * 10 + (back[i] - '0');
					i++;
				}
				num.Push(tmp2, sum);
			}
			else
			{
				result += num.Caculate(num.Out(tmp2), num.Out(tmp2), back[i]);  //遇到符号则运算后入栈
				num.Push(tmp2, result);
				result = 0;
			}
		}
	}
	return num.Out(tmp2);
}`

`int Caculator::Caculate(int a,int b,char c)     //计算传入的值
{
	int result;
	if (c == '+')
	{
		result = a + b;
	}
	else if (c == '-')
	{
		result = a - b;
	}
	else if (c == 'x' || c == 'X' || c == '*')
	{
		result = a * b;
	}
	else if (c == '/')
	{
		result = a / b;
	}
	return result;
}`

`string Caculator::InPut_Change(Chainstack::LinkStack& L, Caculator num)  //中缀表达式转为后缀
{
	int i = 0, length = 0;
	string back;
	LinkStack tmp2 = L;
	length = num.Length(num);    
	while (i < length)      //遍历算式
	{
		if (num.formular[i] < '0' || num.formular[i]>'9')
		{
			if (num.formular[i] == '(')    //若左括号则无条件入栈
			{
				num.Push(L, num.formular[i],9);
				i++;
				continue;
			}
			else if (num.formular[i] == ')')   //若右括号则将栈内符号依次出栈直到遇到左括号
			{
				while (L.top->data!='(')
				{
					back += num.Out(L);
					if (L.top == NULL)
					{
						break;
					}
				}
				back += num.Out(L);
				i++;
				continue;
			}
			int pri = num.Prio(num.formular[i]);  //判断运算符优先级
			if (L.top == NULL)     //若为第一个运算符则直接入栈
			{
				num.Push(L, num.formular[i], pri);
			}
			else
			{
				if (pri < L.top->prio)   //若运算符优先级高于栈顶运算符则直接入栈
				{
					num.Push(L, num.formular[i], pri);
				}
				else
				{
					while (pri >= L.top->prio)   //否则出栈直到运算符优先级低于栈顶或到达栈底
					{
						if (L.top->next == NULL)
						{
							back += num.Out(L);
							num.Push(L, num.formular[i], pri);
							break;
						}
						else
						{
							back += num.Out(L);
						}
					}
				}
			}
			i++;
		}
		else
		{
			int sum = 0;
			while (num.formular[i] >= '0' && num.formular[i] <= '9')   //数字则直接输出到字符串
			{
				sum = sum * 10 + (num.formular[i] - '0');
				i++;
			}
			back += to_string(sum)+' ';
		}
	}
	while (L.top)
	{
		back += num.Out(L);   //结束后将栈内内容全部出栈至字符串
	}
	L.top = tmp2.top;
	return back;
}`

`int Caculator::Length(Caculator num)   //计算算式长度
{
	if (num.formular.length() == 0)
	{
		return -1;
	}
	else
	{
		return num.formular.length();
	}
}`

`int main()
{
    
    while (1)
    {
        Caculator num;
        int ero=0;   //错误标记，若为1则输入错误
        cout << "请输入算式:" << endl;
        cin >> num.formular;
        for (int i = 0; i < num.formular.length(); i++)   //错误检测
        {
            if ((num.formular[i] > '9' || num.formular[i] < '0') && num.formular[i] != '*' && num.formular[i] != 'x' && num.formular[i] != 'X' && num.formular[i] != '/' && num.formular[i] != '-' && num.formular[i] != '+' && num.formular[i] != '(' && num.formular[i] != ')')
            {
                cout << "输入的数据有误,请重新输入" << endl;
                ero = 1;
            }
        }
        if (ero == 1)
        {
            continue;
        }
        Chainstack::LinkStack s1, s2;
        s1.count = 0;
        s1.top = NULL;
        s2.count = 0;
        s2.top = NULL;
        string back_expression;
        back_expression = num.InPut_Change(s1, num);
        cout << num.Cacul(back_expression, num) << endl;
    }

}`

`char Chainstack::Out(LinkStack& L)
{
	char symbol;
	LinkStack tmp1 = L;
	symbol = L.top->data;
	L.top = L.top->next;
	free(tmp1.top);
	L.count--;
	if (symbol == '(' || symbol == ')')		//若为左右括号则返回空格
	{
		return ' ';
	}
	else
	{
		return symbol;
	}
}`

`int Chainstack::Out(LinkStackNum& L)
{
	int number;
	LinkStackNum tmp1 = L;
	number = L.top->data;
	L.top = L.top->next;
	free(tmp1.top);
	L.count--;
	return number;
}`

`int Caculator::Prio(char c)   //计算运算符优先级
{
	int result;
	if (c == '*' || c == 'x' || c == 'X' || c == '/')
	{
		result = 2;
	}
	else if (c == '+' || c == '-')
	{
		result = 3;
	}
	return result;
}`

`void Chainstack::Push(LinkStack& L,char c,int pri)   //运算符入栈
{
	StackNode* p;
	p = (StackNode*)malloc(sizeof(StackNode));
	p->data = c;
	p->next = L.top;
	p->prio = pri;
	L.top = p;
	L.count++;
}`

`void Chainstack::Push(LinkStackNum& L, int c)   //数值入栈
{
	StackNodeNum* p;
	p = (StackNodeNum*)malloc(sizeof(StackNodeNum));
	p->data = c;
	p->next = L.top;
	L.top = p;
	L.count++;
}`

#### 测试结果：

![](https://img-blog.csdnimg.cn/df14250baaff40deb2dbb20f96e14c30.png)