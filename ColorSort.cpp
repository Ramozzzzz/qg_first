#include <iostream>
#include<fstream>
#include<string>
#include"sort.h"
#include"OutPut.h"

void ColorSort(int* a, int size)
{
	int p1 = 0, p2 = size - 1;
	for (int i = 0; i <=p2; i++)
	{
		if (a[i] == 0)
		{
			swap(a[i], a[p1]);
			p1++;
		}
		else if (a[i] == 2)
		{
			swap(a[i], a[p2]);
			p2--;
			i--;
		}
	}
}