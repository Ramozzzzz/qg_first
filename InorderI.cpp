#include"Tree.h"

void Tree::InorderI(BST*& b)   //µİ¹é°æÏÈĞò
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