#include "avl.h"


linktree avlRotateRight(linktree root)
{
    linktree tmp = root->lchild;
    root->lchild = tmp->rchild;
    tmp->rchild = root;

    root->height =  MAX(height(root->lchild),height(root->rchild))+1;
    tmp->height = MAX(height(tmp->lchild),height(tmp->rchild))+1;
    return tmp;
}

linktree avlRotateLeft(linktree root)
{
    linktree tmp = root->rchild;
    root->rchild = tmp->lchild;
    tmp->lchild = root;

    root->height =  MAX(height(root->lchild),height(root->rchild))+1;
    tmp->height = MAX(height(tmp->lchild),height(tmp->rchild))+1;
    return tmp;
}
linktree avlRotateLeftRight(linktree root)
{
    root->lchild = avlRotateLeft(root->lchild);
    root = avlRotateRight(root);

    return root;
}
linktree avlRotateRightLeft(linktree root)
{
    root->rchild = avlRotateRight(root->rchild);
    root = avlRotateLeft(root);

    return root;
}