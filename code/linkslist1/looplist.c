#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node 
{
    int data;
    struct node *next;
}node;

node *initlist()
{
    node *head = malloc(sizeof(node));

    if (head != NULL)
    {
        head->next = head;
    }
    
    return head;
}

node *newNode(int data)
{
    node *new = malloc(sizeof(node));

    if (new != NULL)
    {
        new->data = data;
        new->next = new;
    }
    return new;
}

void insertHead(node *head,node *new)
{
    new->next = head->next;
    head->next = new;

}

void insertTail(node *head,node *new)
{
    if (head == NULL)
        return;
    
    node *p;
    for (p=head;p->next!=head;p=p->next);

    p->next=new;
    new->next=head;  
    
}

bool isEmpty(node *head)
{
    return head->next == head;
}

void show(node *head)
{
    if (isEmpty(head))
        return;
    for (node *p=head->next;p != head;p = p->next)
    {
        printf("%d\t",p->data);
    }

    printf("\n");
    
    
}

node *linklistRemove(node *head,int data)
{
    if (isEmpty(head))
        return NULL;
    
    for (node *p = head;p->next != head;p = p->next)
    {
        if (p->next->data == data)
        {
            node *tmp = p->next;
            p->next = p->next->next;
            tmp->next=tmp;
            return tmp;
        }
        
    }
    
    return NULL;

    // node *tmp ,*p;
    // for (p = head,tmp=p->next;tmp!=head;p=p->next,tmp=tmp->next)
    // {
    //     if (tmp->data == data)
    //     {
    //         p->next = tmp->next;
    //         tmp->next = tmp;
    //         return tmp;
    //     }
        
    // }
    // return NULL;
    
}

node *destroy(node *head)
{
    // node *tmp,*n;
    // for (tmp = head->next,n==tmp->next;tmp !=head;tmp = n)
    // {
    //     n = tmp->next;
    //     free(tmp);
    // }
    // free(head);

    while (head->next != head)
    {
        node *tmp = head->next;

        head->next = tmp->next;

        free(tmp);
    }
    free(head);

    return NULL;
    
}

int main(int argc, char const *argv[])
{
    node *head = initlist();

    for (int i = 1; i <= 5; i++)
    {
        node *new = newNode(i);

        // insertHead(head,new);
        insertTail(head,new);
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
