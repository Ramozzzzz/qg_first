#include<iostream>
#include<time.h>
#include"sort.h"
using namespace std;

void RadixCountSort(int* a, int size)
{
	clock_t start = clock();
	int d = 1;
	while (d < 100000)   //最高五位数
	{
		int* temp = (int*)malloc(size * sizeof(int));
		int* result = (int*)malloc(size * sizeof(int));
		int count[10] = { 0,0,0,0,0,0,0,0,0,0 };   //计数数组
		for (int i = 0; i < size; i++)
		{
			temp[i] = (a[i]/d) % 10;
		}
		for (int i = 0; i < 10; i++)
		{
			count[i] = 0;
		}
		for (int i = 0; i < size; i++)
		{
			count[temp[i]]++;
		}
		for (int i = 1; i < 10; i++)
		{
			count[i] += count[i - 1];
		}
		for (int i = size-1; i >=0; i--)  //倒序排列
		{
			result[count[temp[i]] - 1] = a[i];
			count[temp[i]]--;
		}
		for (int i = 0; i < size; i++)
		{
			a[i] = result[i];
		}
		d *= 10;
	}
	clock_t diff = clock() - start;
	cout << "排序用时为：" << diff << "ms" << endl;
}