#include "Tree.h"

using namespace std;

int main()
{
	Tree T;
	Tree::BST* B = NULL;
	int i;
	T.Create(B);
	system("cls");
	while (1)
	{
		cin.clear();
		system("cls");
		cout << "请选择要执行的功能" << endl << "1.删除节点" << endl << "2,查询节点" << endl << "3.先序遍历（递归）" << endl
			<< "4.先序遍历（非递归）" << endl << "5.中序遍历（递归）" << endl << "6.中序遍历（非递归）" << endl
			<< "7.后序遍历（递归）" << endl << "8.后序遍历（非递归）" << endl<<"9.层次遍历"<<endl<<"10.退出"<<endl;
		cin >> i;
		switch (i)
		{
		case 1:
			int j;
			cout << "请输入要删除的节点" << endl;
			cin >> j;
			T.Delete(B, j);
			break;
		case 2:
			T.Search(B);
			break;
		case 3:
			T.PreorderI(B);
			break;
		case 4:
			T.PreorderR(B);
			break;
		case 5:
			T.InorderI(B);
			break;
		case 6:
			T.InorderR(B);
			break;
		case 7:
			T.PostorderI(B);
			break;
		case 8:
			T.PostorderR(B);
			break;
		case 9:
			T.LevelOrder(B);
			break;
		case 10:
			return 1;
		}
		system("pause");
	}
	

}

