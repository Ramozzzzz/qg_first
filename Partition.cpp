#include<iostream>
#include<time.h>
using namespace std;

int Partition(int* a, int begin, int end)
{
	int i = begin, j = begin;
	int standard = a[end];
	while (j < end)
	{
		if (a[j] < standard)
		{
			swap(a[i], a[j]);
			i++;
		}
		j++;
	}
	swap(a[i], a[end]);
	return i;
}