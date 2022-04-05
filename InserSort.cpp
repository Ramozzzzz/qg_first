#include<iostream>
#include<time.h>
using namespace std;

void insertSort(int* a, int n) 
{
	clock_t start = clock();
	
	for (int i = 1; i < n; i++)
	{
		int j = i - 1, tmp = a[i];
		while (j >= 0 && a[j] > tmp)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = tmp;
	}
	clock_t diff = clock() - start;
	cout << "ÅÅÐòÓÃÊ±Îª£º" << diff << "ms" << endl;	
}