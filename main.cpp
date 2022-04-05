#include <iostream>
#include<fstream>
#include<string>
#include"sort.h"
#include"OutPut.h"
using namespace std;

int main()
{
	OutPut o;
	while (1)
	{
		int size=0, j,k,tmp;
		int n = 0;

		ifstream ins;
		ins.open("d:\ ran_num1.txt", ios::in);
		if (!ins.is_open())
		{
			cout << "error" << endl;
			continue;
		}
		while (ins >> tmp)  //检测文件中的数据量
		{
			size++;     
		}
		ins.clear();     //重置至文件头部
		ins.seekg(0);
		int* a = (int*)malloc(size * sizeof(int));    //为数组a，b开辟大小合适的空间
		int* b = (int*)malloc(size * sizeof(int));
		while (ins >> a[n])
		{
			n++;
		}

		cout << "请选择" << endl << "1.插入排序" << endl << "2.归并排序" << endl << "3.快速排序（递归）" << endl << "4.计数排序" << endl << "5.基数排序" << endl << "6.颜色排序" << endl << "7.寻找第n大的元素" << endl;
		cin >> j;
		switch (j)
		{
		case 1:
			insertSort(a, size);
			break;
		case 2:
			MergeSort(a, 0, size - 1, b);
			break;
		case 3:
			QuickSort_Recursion(a, 0, size - 1);
			break;
		case 4:
			CountSort(a, size, 100000);
			break;
		case 5:
			RadixCountSort(a, size);
			break;
		case 6:
			ColorSort(a, size);
			break;
		case 7:
			int c;
			cout << "输入要查询第几大的数:" << endl;
			cin >> c;
			cout << Find(a, 0, size - 1, c) << endl;
		}
		cout << "1.输出排序结果" << endl << "2.输出到文件 d:\result.txt" << endl;
		cin >> k;
		switch (k)
		{
		case 1:
			o.Print(a, size);
			break;
		case 2:
			o.OutPutFile(a,size);
			break;
		}
		free(a);
		free(b);
		system("pause");
		system("cls");
	}
}

