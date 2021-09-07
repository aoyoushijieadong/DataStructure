#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#ifndef DATATYPE
#define DATATYPE int
#endif

typedef DATATYPE datatype;

typedef struct node
{
    datatype data;
    struct node *prev;
    struct node *next;
}listnode,*linklist;

static listnode *initList()
{
    linklist head = (listnode *)malloc(sizeof(listnode));
    if (head != 0)
    {
        head->next = head;
        head->prev = head;
    }
    return head;
}

static listnode *newNode(datatype data)
{
    listnode *new = (listnode *)malloc(sizeof(listnode));
    if (new != NULL)
    {
        new->data = data;
        new->prev = new;
        new->next = new;
        
    }
    return new;
}

static void listAddTail(listnode *head,listnode *new)
{
    new->prev = head->prev;
    new->next = head;

    head->prev->next = new;
    head->prev = new;
}
static bool isEmpty(listnode *head)
{
    return head->next == head;
}

static void listForEach(linklist head,void (*handler)(datatype *data))
{
    if(isEmpty(head))
        return;    
    for (linklist p = head->next;p!=head;p=p->next)
    {
        handler(&(p->data));
    }
    
}

static listnode *findNode(listnode *head,datatype data,bool (*equal)(datatype data1,datatype data2))
{
    for (listnode *p = head->next;p!=head;p=p->next)
    {
        if (equal(p->data,data))
        {
            return p;
        }
    }
    return NULL;
    
}
static bool listDelNode(listnode *p)
{
    if (p==NULL||isEmpty(p))
        return false ;
    
    p->next->prev=p->prev;
    p->prev->next=p->next;

    p->prev = p;
    p->next = p;

    return true;
    
}