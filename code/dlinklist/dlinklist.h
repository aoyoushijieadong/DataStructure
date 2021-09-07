#ifndef __DLINKLIST_H
#define __DLINKLIST_H

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data; 

    // 指向相邻的节点的双向指针
    struct node * prev;
    struct node * next;

}node;
node * initList();
void listAdd(node *head,node *new);
void listAddTail(node *head,node *new);
node * newNode(int data);
void listForeach(node *head,void (*p)(int data));
void listRemove(node *p);
node *findNode(node *head,int data);
void destroyInit(node *head);
node * destroy(node *head);
#endif // !__DLINKLIST_H
