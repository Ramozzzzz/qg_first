#include"Tree.h"

void Tree::InorderI(BST*& b)   //�ݹ������
{
    BST* temp = b;
    if (temp != NULL) 
    {
        InorderI(b->left);
        cout << b->data << " ";
        InorderI(b->right);
    }
    else
    {
        return;
    }
}