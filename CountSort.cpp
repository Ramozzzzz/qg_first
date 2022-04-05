#include<iostream>
#include<fstream>
#include<time.h>
#include"sort.h"
using namespace std;

void CountSort(int* a, int size, int max)
{
	
	int* count = (int*)malloc((max+1) * sizeof(int));   //��������
	int* result = (int*)malloc(size * sizeof(int));    //�������
	clock_t start = clock();
	for (int i = 0; i < max + 1; i++)  //���������ʼ��
	{
		count[i] = 0;
	}
	for (int i = 0; i < size; i++)   //ͳ�����ݳ��ִ���
	{
		count[a[i]]++;
	}
	for (int i = 1; i < max + 1; i++)   //ת��Ϊ�ۼ�����
	{
		count[i] += count[i - 1];
	}
	for (int i = 0; i < size; i++)   //���������������
	{
		result[count[a[i]] - 1] = a[i];
		count[a[i]]--;
	}
	for (int i = 0; i < size; i++)   //���Ƶ�ԭ����
	{
		a[i] = result[i];
	}
	clock_t diff = clock() - start;
	cout << "������ʱΪ��" << diff << "ms" << endl;
}