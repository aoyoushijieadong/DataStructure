#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#ifndef DATATYPE
#define DATATYPE int
#endif

typedef DATATYPE datatype;

typedef struct node
{
    datatype data;
    struct node *next;
}node;

typedef struct linkstack
{
    struct node *top;
    int size;
}linkstack;

static linkstack *initStack()
{
    linkstack *stack = (linkstack *)calloc(1,sizeof(linkstack));
    if (stack != NULL)
    {
        stack->top = NULL;
        stack->size =0;
    }
    return stack;
}

static node *newNode(datatype data)
{
    node *new = (node *)calloc(1,sizeof(node));
    if (new != NULL)
    {
        new->data = data;
        new->next = NULL;
    }
    return new;

}

static bool push(linkstack *stack,node *new)
{
    new->next = stack->top;
    stack->top = new;
    stack->size++;
    return true;
}

static node *top(linkstack *stack)
{
    return stack->top;
}

static node *pop(linkstack *stack)
{
    node *p = top(stack);
    if (p==NULL)
        return NULL;
    stack->top = p->next;
    stack->size--;
    p->next = NULL;
    return p;
    
}
static bool isEmpty(linkstack *stack)
{
    return stack->size == 0;
}