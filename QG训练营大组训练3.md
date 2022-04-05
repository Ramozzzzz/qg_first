### QG训练营大组训练3

#### 问题描述：

实现插入(InsertSort)，归并(MergeSort) ，快排(QuickSort)(递归版)，计数(CountSort)和基数计数排序(RadixCountSort)。

编写测试程序，输出上述排序函数在不同的大数据量下的用时，有三个层次（10000、50000、200000）。

编写测试程序，输出上述排序函数在大量小数据量下的排序用时（如100个数据*100k次排序）。

#### 思路分析：

将各个排序算法分文件存储，在main函数中集中调用。

#### 代码实现：

插入排序：

`void insertSort(int* a, int n) 
{
	clock_t start = clock();

	for (int i = 1; i < n; i++)
	{
		int j = i - 1, tmp = a[i];
		while (j >= 0 && a[j] > tmp)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = tmp;
	}
	clock_t diff = clock() - start;
	cout << "排序用时为：" << diff << "ms" << endl;	
}`

快速排序：

`void QuickSort_Recursion(int* a, int begin, int end)
{	
	clock_t start = clock();
	if (begin < end)
	{
		int mid = Partition(a, begin, end);
		QuickSort_Recursion(a, begin, mid - 1);
		QuickSort_Recursion(a, mid + 1, end);
	}
	clock_t diff = clock() - start;
	cout << "排序用时为：" << diff << "ms" << endl;	
}`

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

归并排序：

`void MergeSort(int* a, int begin, int end, int* temp)
{
	clock_t start = clock();
	int mid;
	if (begin < end)
	{
		mid = (end + begin) / 2;
		MergeSort(a, begin, mid, temp);  //数组左半区
		MergeSort(a, mid + 1, end, temp);   //数组右半区
		MergeArray(a, begin, mid, end, temp);  //数组合并
	}
	clock_t diff = clock() - start;
	cout << "排序用时为：" << diff << "ms" << endl;
}`

`void MergeArray(int* a, int begin, int mid, int end, int* temp)
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
}`

计数排序：

`void CountSort(int* a, int size, int max)
{
	
	int* count = (int*)malloc((max+1) * sizeof(int));   //计数数组
	int* result = (int*)malloc(size * sizeof(int));    //结果数组
	clock_t start = clock();
	for (int i = 0; i < max + 1; i++)  //计数数组初始化
	{
		count[i] = 0;
	}
	for (int i = 0; i < size; i++)   //统计数据出现次数
	{
		count[a[i]]++;
	}
	for (int i = 1; i < max + 1; i++)   //转换为累计数组
	{
		count[i] += count[i - 1];
	}
	for (int i = 0; i < size; i++)   //输出结果至结果数组
	{
		result[count[a[i]] - 1] = a[i];
		count[a[i]]--;
	}
	for (int i = 0; i < size; i++)   //复制到原数组
	{
		a[i] = result[i];
	}
	clock_t diff = clock() - start;
	cout << "排序用时为：" << diff << "ms" << endl;
}`

基数排序：

`void RadixCountSort(int* a, int size)
{
	clock_t start = clock();
	int d = 1;
	while (d < 100000)   //最高五位数
	{
		int* temp = (int*)malloc(size * sizeof(int));
		int* result = (int*)malloc(size * sizeof(int));
		int count[10] = { 0,0,0,0,0,0,0,0,0,0 };   //计数数组
		for (int i = 0; i < size; i++)
		{
			temp[i] = (a[i]/d) % 10;
		}
		for (int i = 0; i < 10; i++)
		{
			count[i] = 0;
		}
		for (int i = 0; i < size; i++)
		{
			count[temp[i]]++;
		}
		for (int i = 1; i < 10; i++)
		{
			count[i] += count[i - 1];
		}
		for (int i = size-1; i >=0; i--)  //倒序排列
		{
			result[count[temp[i]] - 1] = a[i];
			count[temp[i]]--;
		}
		for (int i = 0; i < size; i++)
		{
			a[i] = result[i];
		}
		d *= 10;
	}
	clock_t diff = clock() - start;
	cout << "排序用时为：" << diff << "ms" << endl;
}`

##### 测试结果：

![](https://img-blog.csdnimg.cn/d2d8e8f8c0c5463bb0468813d881c6b2.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAUmFtb3p6eg==,size_15,color_FFFFFF,t_70,g_se,x_16)

![](https://img-blog.csdnimg.cn/37a80087188041aabeab879fd72be328.png)