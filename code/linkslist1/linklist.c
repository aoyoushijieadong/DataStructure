#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *initLinklinst()
{
    node *head = (node *)malloc(sizeof(node));

    if (head != NULL)
    {
        head->next = NULL;
    }
    
    return head;
}

node *newNode(int data)
{
    node *new = (node *)malloc(sizeof(node));

    if (new != NULL)
    {
        new->data = data;
        new->next = NULL;
    }
    
    return new;
}

void insertHead(node *head,node *new)
{
    new->next = head->next;
    head->next = new;
}

bool isEmpty(node *head)
{
    return head->next == NULL;
}

void show(node *head)
{
    if (isEmpty(head))
        return;
    
    for (node *p = head->next; p != NULL;p = p->next)
    {
        printf("%d\t",p->data);
    }
    printf("\n");
    
}

node *linklistRemove(node *head,int data)
{
    // node *p;
    // for (p = head;p->next != NULL;p = p->next)
    // {
    //     if (p->next->data == data)
    //     {
    //         node *tmp = p->next;
    //         p->next = p->next->next;
    //         return tmp;
    //     }
        
    // }
    // return NULL;

    node *tmp;
    for (node *p = head;p != NULL;p = p->next)
    {
        if (p->next !=NULL &&p->next->data == data)
        {
            tmp = p->next;
            p->next = p->next->next;
            tmp->next = NULL;
            return tmp;
        }
        
    }
    return NULL;
}

node *destroy(node *head)
{

    if (isEmpty(head))
            return NULL;
    //销毁头结点
    // for (node *tmp = head,*p=tmp->next;tmp != NULL;tmp = p)
    // {
    //     p = tmp->next;
    //     free(tmp);
    // }
    
    // return NULL;
    
    //保留头结点
    for (node *tmp = head->next,*p=tmp->next;tmp != NULL;tmp = p)
    {
        if (tmp == head->next)
        {
            head->next=NULL;
        }
        
        p = tmp->next;
        free(tmp);
    }
    
    return head;
}


int main(int argc, char const *argv[])
{
    node *head = initLinklinst();    
    
    for (int i = 1; i <= 5 ; i++)
    {
        node *new = newNode(i);

        insertHead(head,new);
    }

    show(head);

    int n;
    printf("请输入你想要删除的节点:\n");
    while (1)
    {
        scanf("%d",&n);

        if (n == 0)
            break;

        node *p = linklistRemove(head,n); 
        if (p == NULL)
        {
            printf("没有该结点，请重新输入\n");
            continue;    
        }     
        free(p);
        show(head);
    }
    
    head = destroy(head);

    
    return 0;
}
