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
		MergeSort(a, begin, mid, temp);  //���������
		MergeSort(a, mid + 1, end, temp);   //�����Ұ���
		MergeArray(a, begin, mid, end, temp);  //����ϲ�
	}
	clock_t diff = clock() - start;
	cout << "������ʱΪ��" << diff << "ms" << endl;
}