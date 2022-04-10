#include"Tree.h"

void Tree::PreorderI(BST *&b)
{
    BST* temp = b;
    if (temp != NULL)
    {
        cout << b->data << " ";
        PreorderI(b->left);
        PreorderI(b->right);
    }
    else
    {
        return;
    }
}
