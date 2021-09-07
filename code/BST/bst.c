#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
}node;

#define DATATYPE node *
#include "queue.h"


#define TREENODE node // 声明自定义的二叉树节点为TREENODE
#include "drawtree.h" // 包含画树代码

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

node *bstInsert(node *root,node *new)
{
    if (root == NULL)
        return new;

    if (new->data < root->data)
       root->lchild = bstInsert(root->lchild,new);
    else if (new->data > root->data)
        root->rchild = bstInsert(root->rchild,new);
    else 
    {
        printf("%d已经存在\n",new->data);
        free(new);
    }

    return root;
     
}

// void bstInsert(node **root,node *new)
// {
//     if (*root == NULL)
//     {
//         *root = new;
//         return;
//     }
    
//     if (new->data < (*root)->data)
//         bstInsert(&((*root)->lchild),new);   
//     else if(new->data > (*root)->data)
//         bstInsert(&((*root)->rchild),new);
//     else
//     {
//         printf("%d已经存在\n",new->data);
//         free(new);
//     }
//     return ;   
// }

node * bstRemove(node *root,int data)
{
    if (root == NULL)
        return NULL;

    if (root->data > data)
        root->lchild = bstRemove(root->lchild,data);
    else if (root->data < data)
        root->rchild = bstRemove(root->rchild,data);
    //将当前BST的根节点删除
    else
    {
        //当前BST中有左子树
        if (root->lchild != NULL)
        {
            //寻找左子树中的最大叶子
            node *p;
            for (p=root->lchild;p->rchild!=NULL;p=p->rchild);
            
            //将根节点替换成最大叶子
            root->data = p->data;

            //删除BST中多余节点
            root->lchild = bstRemove(root->lchild,p->data);

        }
        else if (root->rchild != NULL)
        {
             //寻找右子树中的最小叶子
            node *p;
            for (p=root->rchild;p->lchild!=NULL;p=p->lchild);
            
            //将根节点替换成最大叶子
            root->data = p->data;

            //删除BST中多余节点
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

void level_order(node *root)
{
    if (root == NULL)
        return ;
    
    //准备一个空队列
    linkQueue *queue = initQueue();

    //将根节点入队
    enQueue(queue,root);

    node *p;
    while (!queueIsEmpty(queue))
    {
        outQueue(queue,&p);
        printf("%d\t",p->data);

        //依次将左右孩子入队
        if (p->lchild)
            enQueue(queue,p->lchild);
        if (p->rchild)
            enQueue(queue,p->rchild);
        
    }
    printf("\n");
    
}

void pre_order(node *root)
{
    if (root == NULL)
        return;
    printf("%d\t",root->data);
    pre_order(root->lchild);
    pre_order(root->rchild); 
}

void mid_order(node *root)
{
    if (root == NULL)
        return;
    mid_order(root->lchild);
    printf("%d\t",root->data);
    mid_order(root->rchild); 
}

void post_order(node *root)
{
    if (root == NULL)
        return;
    post_order(root->lchild);
    post_order(root->rchild); 
    printf("%d\t",root->data);
}

int main(int argc, char const *argv[])
{
    node *root = NULL;
    int n;
    while (1)
    {
        scanf("%d",&n);

        if (n == 0)
            break;

        if (n > 0)
        {
            node *new = newNode(n);

            root = bstInsert(root,new);
            // bstInsert(&root,new);
            
        }
        else if (n < 0)
        {
            root = bstRemove(root,-n);

        }
        
        draw(root);

    }
    printf("前序遍历:");
    pre_order(root);printf("\n");

    printf("中序遍历:");
    mid_order(root);printf("\n");

    printf("后序遍历:");
    post_order(root);printf("\n");

    printf("按层遍历");
    level_order(root);
    
    return 0;
}
