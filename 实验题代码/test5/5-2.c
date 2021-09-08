//编写一个程序，能根据依次输入的数字，创建如下二叉搜索树，并且支持删除操作。
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node 
{
    int data;
    struct node *lchild;
    struct node *rchild;
}node;

#define TREENODE node
#include "drawtree.h"

node *newNode(int data)
{
    node *new = (node *)calloc(1,sizeof(node));
    if (new != NULL)
    {
        new->data = data;
        new->lchild = NULL;
        new->rchild = NULL;
    }
    return new;
}

node * bstInsert(node *root,node *new)
{
    if (root == NULL)
        return new;

    if (new->data < root->data)
        root->lchild = bstInsert(root->lchild,new);
    else if (new->data > root->data)
        root->rchild = bstInsert(root->rchild,new);
    else
    {
        printf("%d已经存在,请重新操作！\n",new->data);
        free(new);
    }
    
    return root;
    
     
}

node *bstRemove(node *root,int data)
{
    if (root == NULL)
        return NULL;
    
    if (root->data > data)
        root->lchild = bstRemove(root->lchild,data);
    else if (root->data < data)
        root->rchild = bstRemove(root->rchild,data);
    else
    {
        if (root->lchild != NULL)
        {
            node *p;
            for (p=root->lchild;p->rchild!=NULL;p=p->rchild);
            
            root->data = p->data;

            root->lchild = bstRemove(root->lchild,p->data);
            
        }
        else if (root->rchild != NULL)
        {
            node *p;
            for (p=root->rchild;p->lchild != NULL;p=p->lchild);
            
            root->data = p->data;

            root->rchild = bstRemove(root->rchild,p->data);
            
        }
        else
        {
            free(root);
            return NULL;
        }
        
    }

    return root;
     
}

int main(int argc, char const *argv[])
{
    node *root = NULL;

    int n;
    printf("请输入数据(0为退出):\n");
    while (1)
    {
        scanf("%d",&n);

        if (n == 0)
            break;
        

        node *new = newNode(n);
        root = bstInsert(root,new);
    }
    
    draw(root);

    printf("请输入你想要删除的节点:\n");
    while (1)
    {
        scanf("%d",&n);

        if (n == 0)
            break;
        
        root = bstRemove(root,n);
  
    }
    
    draw(root);

    return 0;
}
