#pragma once
#include<fstream>
#include<iostream>
using namespace std;

class OutPut
{
public:
	void Print(int* a,int size)    //����ź��������
	{
		for (int i = 0; i < size; i++)
		{
			cout << a[i] << endl;
		}
	}

	void OutPutFile(int* a,int size)    //���ź��������������ļ�
	{
		int n = 0;
		ofstream outfile;
		outfile.open("D:\ result.txt");
		if (!outfile.is_open())
		{
			cout << "error" << endl;
			return;
		}
		while (n<size)
		{
			outfile << a[n]<<endl;
			n++;
		}
	}

	
};