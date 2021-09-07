#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>

typedef struct seqStack
{
   int *data;
   int size ;
   int top;
}seqStack;

seqStack *initStack(int size)
{
    seqStack *s = (seqStack *)malloc(sizeof(seqStack));
    if (s != NULL)
    {
        s->data = calloc(size,sizeof(int));
        if (s == NULL)
        {
            free(s);
            return NULL;
        }
        s->size = size;
        s->top = -1;
        
    }
    return s;
}

bool isFull(seqStack *s)
{
    return s->top == s->size-1;
}

bool push(seqStack *s,int data)
{
    if (isFull(s))
        return false;
    s->data[++s->top]=data;
    return true;
}

bool isEmpty(seqStack *s)
{
    return s->top == -1;
}

bool top(seqStack *s,int *m)
{
    if (isEmpty(s))
        return false;
    *m = s->data[s->top];
    return true;
    
}

bool pop(seqStack *s,int *m)
{
    if (!top(s,m))
        return false;
    
    s->top--;
    return true;
    
}


int main(int argc, char const *argv[])
{
    seqStack *stack = initStack(10);
    if (stack != NULL)
        printf("初始化栈成功\n");
    else
    {
        perror("初始化栈失败");
        exit(0);
    }
    
    push(stack,1);
    push(stack,2);
    push(stack,3);
    push(stack,4);
    push(stack,5);

    int n;
    top(stack,&n);
    printf("取得栈顶元素%d\n",n);
   
    while (!isEmpty(stack))
    {
        // if (stack->top==-1)
        //     break;

        int m;
        pop(stack,&m);
        printf("%d\n",m);
    }
    

    return 0;
}
