
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    char data;
    struct node *next;
}node;

typedef struct linkstack
{
   node *top;
   int size;
}linkstack;

linkstack *initStack()
{
    linkstack *stack = (linkstack *)calloc(1,sizeof(linkstack));
    if (stack != NULL)
    {
        stack->top = NULL;
        stack->size = 0;
    }
    return stack;
    
}

node *newNode(int data)
{
    node *new = (node *)calloc(1,sizeof(node));
    if (new != NULL)
    {
        new->data = data;
        new->next = NULL;
    }
    return new;
}

void push(linkstack *stack,node *new)
{
     new->next = stack->top;
     stack->top = new;
     stack->size++;
}

bool isEmpty(linkstack *stack)
{
    return stack->size == 0;
}

node *pop(linkstack *stack)
{
    if (isEmpty(stack))
        return  NULL;
    node *p = stack->top;
    stack->top = p->next;
    p->next = NULL;
    stack->size--;
    return p;
}


int main(void)
{
    linkstack *stack = initStack();

    int n;
    scanf("%d",&n);

    int m = abs(n);
    while (m > 0)
    {
        node *new = newNode(m%16);
        push(stack,new);
        m /= 16;
    }


    printf("%c0x",n<0 ? '-':'\r');

    while (!isEmpty(stack))
    {
        node *p = pop(stack);
        if(p != NULL)
        {
            printf("%c",p->data<9 ? p->data+48 : p->data%10+'A');
        }
        free(p);
    }
    
    printf("\n");
}

