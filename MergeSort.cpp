#include<iostream>
#include<time.h>
#include"sort.h"
using namespace std;

void MergeSort(int* a, int begin, int end, int* temp)
{
	clock_t start = clock();
	int mid;
	if (begin < end)
	{
		mid = (end + begin) / 2;
		MergeSort(a, begin, mid, temp);  //数组左半区
		MergeSort(a, mid + 1, end, temp);   //数组右半区
		MergeArray(a, begin, mid, end, temp);  //数组合并
	}
	clock_t diff = clock() - start;
	cout << "排序用时为：" << diff << "ms" << endl;
}