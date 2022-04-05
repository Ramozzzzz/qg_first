#include <iostream>
#include<fstream>
#include<string>
#include"sort.h"
#include"OutPut.h"

int Partition2(int *a, int begin, int end) 
{
	srand((unsigned)time(NULL));
	int idx = (rand() % (end - begin + 1)) + begin;
	int tmp = a[begin];
	a[begin] = a[idx];
	a[idx] = tmp;
	tmp = a[begin];
	while (begin < end) 
	{
		while (begin < end && a[end] >= tmp)
		{
			end--;
		}
		if (begin < end) 
		{
			a[begin] = a[end];
			begin++;
		}
		while (begin < end && a[begin] <= tmp)
		{
			begin++;
		}
		if (begin < end) 
		{
			a[end] = a[begin];
			end--;
		}
	}
	a[begin] = tmp;
	return begin;
}