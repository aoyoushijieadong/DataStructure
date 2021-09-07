#include "dlinklist.h"

void show(int data)
{
    printf("%d\t",data);
}

int main(int argc, char const *argv[])
{
    node *head = initList();

    int n;
    scanf("%d",&n);


    for (int i = 1; i <= n; i++)
    {
        node *new = newNode(i);
        listAddTail(head,new);
    }
    listForeach(head,show);

    printf("c输入想要删除的节点:\n");
    while (1)
    {
        scanf("%d",&n);
        if (n==0)
            break;
        
        node *p=findNode(head,n);
        if (p==NULL)
        {
            printf("查无此点\n");
            continue;
        }    
    
        listRemove(p);
        free(p);
        
        listForeach(head,show);
        
    }
    
    head = destroy(head);


    return 0;
}
