#include <iostream>
#include <time.h>
#include<fstream>
using namespace std;

void NumCreate(int k)
{
	int num;
	ofstream outfile;
	outfile.open("D:\ ran_num1.txt");
	srand((unsigned)time(0));
	for (int j = 0; j < k; j++)
	{
		num = rand();
		cout << num << endl;
		outfile << num << endl;
	}
	outfile.close();
}

void NumCreate(int k,int i)
{
	int num;
	ofstream outfile;
	outfile.open("D:\ ran_num1.txt");
	srand((unsigned)time(0));
	for (int j = 0; j < k; j++)
	{
		num = rand();
		cout << num%3 << endl;
		outfile << num%3 << endl;
	}
	outfile.close();
}