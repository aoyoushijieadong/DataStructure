#include "avl.h"

#define TREENODE treenode // 声明自定义的二叉树节点为TREENODE
#include "drawtree.h" // 包含画树代码

linktree newNode(datatype data)
{
    linktree new = (linktree)calloc(1,sizeof(treenode));
    if (new != NULL)
    {
        new->data = data;
        new->lchild = NULL;
        new->rchild = NULL;
        new->height = 1;
    }
     
    return new;
    
}

linktree avlInsert(linktree root,linktree new)
{
    if (root == NULL)
        return new;
    //插入节点    
    if (new->data < root->data)
        root->lchild = avlInsert(root->lchild,new);
    else if (new->data > root->data)
        root->rchild = avlInsert(root->rchild,new);
    else
    {
        printf("%d已经存在\n",new->data);
        free(new);
    }

    //判断数是否平衡
    //左不平衡
    if (height(root->lchild)-height(root->rchild)>1)
    {
        //左左不平衡
        if (new->data < root->lchild->data)
            root = avlRotateRight(root);
        //左右不平衡
        else
            root = avlRotateLeftRight(root);

    }
    else if (height(root->rchild)-height(root->lchild)>1)
    {
         //右右不平衡
        if (new->data > root->rchild->data)
            root = avlRotateLeft(root);
        //右左不平衡
        else
            root = avlRotateRightLeft(root);
    }
    
    // //更新根节点的树深
    root->height = MAX(height(root->lchild),height(root->rchild))+1;
    
    return root; 
}

linktree avlRemove(linktree root,datatype data)
{
    if (root == NULL)
        return NULL;
    
    if (data < root->data)
        root->lchild = avlRemove(root->lchild,data);
    else if (data > root->data)
        root->rchild = avlRemove(root->rchild,data);
    else
    {
        linktree p;
        if(root->lchild != NULL)
        {
            for(p = root->lchild;p->rchild != NULL;p = p->rchild);
            root->data = p->data;
            root->lchild = avlRemove(root->lchild,p->data);
        }
        else if(root->rchild != NULL)
        {
            for(p = root->rchild;p->lchild != NULL;p = p->lchild);
            root->data = p->data;
            root->rchild = avlRemove(root->rchild,p->data);
        }
        else
        {
            free(root);
            return NULL;
        }
         
    }
    //判断删除节点后树是否平衡
    if (height(root->lchild)-height(root->rchild) > 1)
    {
        //左右不平衡
        if (height(root->lchild->lchild) < height(root->lchild->rchild))
            root = avlRotateLeftRight(root);
        //左左不平衡
        else
            root = avlRotateRight(root);
    }
    else if (height(root->rchild)-height(root->lchild) > 1)
    {
        //左右不平衡
        if (height(root->rchild->rchild) < height(root->rchild->lchild))
            root = avlRotateRightLeft(root);
        //左左不平衡
        else
            root = avlRotateLeft(root);
    }

    //更新根节点的树深
    root->height = MAX(height(root->lchild),height(root->rchild))+1;
    return root;
}

int main(int argc, char const *argv[])
{
    linktree root = NULL;
    int n;
    while (1)
    {
        scanf("%d",&n);

        if (n == 0)
            break;

        if (n > 0)
        {
            linktree new = newNode(n);
            if (new != NULL)
                root = avlInsert(root,new);
            
        }
        if (n < 0)
        {
            root = avlRemove(root,-n);
        }
        
        draw(root);
         
    }
    
    return 0;
}
