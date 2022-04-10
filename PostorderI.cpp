#include"Tree.h"

void Tree::PostorderI(BST*& b)
{
    BST* temp = b;
    if (temp != NULL)
    {
        PostorderI(b->left);
        PostorderI(b->right);
        cout << b->data << " ";
    }
    else
    {
        return;
    }
}