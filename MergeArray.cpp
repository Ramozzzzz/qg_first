#include<iostream>
#include<time.h>
using namespace std;

void MergeArray(int* a, int begin, int mid, int end, int* temp)
{
	int i = begin, j = begin, k = mid + 1;
	while (i != mid + 1 && k != end + 1)
	{
		if (a[i] > a[k])
		{
			temp[j++] = a[k++];
		}
		else
		{
			temp[j++] = a[i++];
		}
	}
	while (i != mid + 1)
	{
		temp[j++] = a[i++];
	}
	while (k != end + 1)
	{
		temp[j++] = a[k++];
	}
	for (i = begin; i <= end; i++)
	{
		a[i] = temp[i];
	}
}