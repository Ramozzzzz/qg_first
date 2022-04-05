#include<iostream>
#include<time.h>
#include"sort.h"
using namespace std;

void QuickSort_Recursion(int* a, int begin, int end)
{	
	clock_t start = clock();
	if (begin < end)
	{
		int mid = Partition(a, begin, end);
		QuickSort_Recursion(a, begin, mid - 1);
		QuickSort_Recursion(a, mid + 1, end);
	}
	clock_t diff = clock() - start;
	cout << "ÅÅÐòÓÃÊ±Îª£º" << diff << "ms" << endl;	
}