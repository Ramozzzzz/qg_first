#include<iostream>
#include<fstream>
#include<time.h>
#include"sort.h"
using namespace std;

void CountSort(int* a, int size, int max)
{
	
	int* count = (int*)malloc((max+1) * sizeof(int));   //计数数组
	int* result = (int*)malloc(size * sizeof(int));    //结果数组
	clock_t start = clock();
	for (int i = 0; i < max + 1; i++)  //计数数组初始化
	{
		count[i] = 0;
	}
	for (int i = 0; i < size; i++)   //统计数据出现次数
	{
		count[a[i]]++;
	}
	for (int i = 1; i < max + 1; i++)   //转换为累计数组
	{
		count[i] += count[i - 1];
	}
	for (int i = 0; i < size; i++)   //输出结果至结果数组
	{
		result[count[a[i]] - 1] = a[i];
		count[a[i]]--;
	}
	for (int i = 0; i < size; i++)   //复制到原数组
	{
		a[i] = result[i];
	}
	clock_t diff = clock() - start;
	cout << "排序用时为：" << diff << "ms" << endl;
}