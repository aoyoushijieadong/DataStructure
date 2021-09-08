//编程实现功能：将键盘输入的十进制数，转换为十六进制输出。
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node 
{
    int data;
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

bool push(linkstack *stack,node *new)
{
    if (stack==NULL||new==NULL)
        return false;
    
    new->next = stack->top;
    stack->top = new;
    stack->size++;
    return true;

}

bool isEmpty(linkstack *stack)
{
    return stack->size == 0;
}

void show(linkstack *stack)
{
    if (isEmpty(stack))
        return;
    
    for (node *p = stack->top;p != NULL;p=p->next)
    {
        printf("%d\t",p->data);
    }
    printf("\n");

}

node *pop(linkstack *stack)
{
    if (isEmpty(stack))
        return NULL;
    node *p = stack->top;
    stack->top = p->next;
    p->next = NULL;
    stack->size--;
    return p;

}

int main(int argc, char const *argv[])
{
    linkstack *stack = initStack();
    
    int n;
    printf("请输入栈元素(输入0为退出)\n");
    while (1)
    {
        if(scanf("%d",&n)!=1 || getchar() != '\n')
        {
            while (getchar() != '\n');
            printf("请输入有误，请重新输入！！\n");
            continue; 
        }
        if (n == 0)
            break;
        
        node *new = newNode(n);
        push(stack,new);
    }
    printf("栈元素：");
    show(stack);

    while (!isEmpty(stack))
    {
        node *tmp = pop(stack);
        if (tmp != NULL)
        {
            int m = abs(tmp->data);
            printf("%c0x",tmp->data<0 ? '-':'\r');
            printf("%x\t",m);
            free(tmp);
        }   
        
    }
    

    return 0;
}
