#include "linkstack.h"

int main(void)
{
    linkstack *stack = initStack();
    if (stack != NULL)
        printf("初始化空链式栈成功\n");
    else
    {

        printf("初始化空链式栈失败\n");
        exit(0);
    }
    
    int n,m;
    node *p;
    while (1)
    {

        m = scanf("%d",&n);
        if (m!=1||getchar()!='\n')
        {
            while (getchar() != '\n');
            printf("输入有误请重新输入！！！\n");
            continue;
        }

        if (n == 0)
            break;
        
        p = newNode(n);
        if (p!=NULL)
            push(stack,p);
        
    }
    
    p = top(stack);
    if (p!=NULL)
        printf("栈顶元素为%d\n",p->data);
    
    while (!isEmpty(stack))
    {
        p = pop(stack);
        printf("%d\n",p->data);
        free(p);
        
    }
    

   

    return 0;
}