#include <iostream>
#include <time.h>
#include<fstream>
using namespace std;

void NumCreate2()
{
	int num;
	ofstream outfile;
	outfile.open("D:\ ran_num2.txt");
	srand((unsigned)time(0));
	for (int j = 0; j < 100000; j++)
	{
		for (int h = 0; h < 100; h++)
		{
			num = rand();
			cout << num << endl;
			outfile << num << endl;
		}
	}
	outfile.close();
}