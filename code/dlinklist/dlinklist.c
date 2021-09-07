
#include "dlinklist.h"

node * initList()
{
    node *head = calloc(1,sizeof(node));
    if (head != NULL)
    {
        head->prev=head;
        head->next=head;
    }
    return head;
    
}

void listAdd(node *head,node *new)
{
    new->prev = head;
    new->next = head->next;

    head->next=new;
    new->next->prev=new;
    
}

void listAddTail(node *head,node *new)
{
    new->prev = head->prev;
    new->next = head;

    head->prev->next = new;
    head->prev = new;

}

node * newNode(int data)
{
    node *new = calloc(1,sizeof(node));
    if (new != NULL)
    {
        new->next=new;
        new->prev=new;
        new->data=data;
    }
    
    return new;
    
}
void listForeach(node *head,void (*p)(int data))
{
    node *tmp;
    for (tmp=head->next;tmp!=head;tmp=tmp->next)
    {
        p(tmp->data);
    }
    printf("\n");
}

void listRemove(node *p)
{
    if (p == NULL)
        return;
    p->prev->next = p->next;
    p->next->prev= p->prev;

    p->prev=p;
    p->next=p;
    
}

node *findNode(node *head,int data)
{
    node *p;
    for (p=head->next;p!=head;p=p->next)
    {
        if (p->data==data)
            return p;
    }
    return NULL;
    
}
//销毁链表，彻底释放所有内存
node *destroy(node *head)
{
    destroyInit(head);
    free(head);
    return NULL;
}
//销毁链表，使得head回归初始状态
void destroyInit(node *head)
{
    node *p = head->next;
    while (p != head)
    {
        listRemove(p);
        free(p);
        p=head->next;
    }

}