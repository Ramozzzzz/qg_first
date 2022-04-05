#include <iostream>
#include<fstream>
#include<string>
#include"sort.h"
#include"OutPut.h"

int Find(int* a, int begin, int end,int i)
{	
    int mid;
    mid = Partition2(a, begin, end);
    int length = end - mid + 1;
    if (length > i)
    {
        return Find(a,mid + 1, end, i);
    }
    if (length < i)
    {
        return Find(a, begin, mid - 1, i-length);
    }
    return a[mid];
}