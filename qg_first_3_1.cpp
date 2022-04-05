#include <iostream>
#include <time.h>
#include<fstream>
using namespace std;

void NumCreate(int k);
void NumCreate(int k,int i);
void NumCreate2();

int main()
{
	int i,k;
	cout << "请选择要输出的随机数数量" << endl << "1.输出10000个随机数" << endl << "2.输出50000个随机数" << endl << "3.输出200000个随机数" << endl << "4.输出100*100k个随机数" << endl << "5.输出10000个只包含0,1,2的随机数" << endl;;
	cin >> i;
	switch (i)
	{
	case 1:
		k = 10000;
		NumCreate(k);
		break;
	case 2:
		k = 50000;
		NumCreate(k);
		break;
	case 3:
		k = 200000;
		NumCreate(k);
		break;
	case 4:
		NumCreate2();
		break;
	case 5:
		k = 10000;
		NumCreate(k, 1);
	}
	cout << "文件输出完毕" << endl;
}

