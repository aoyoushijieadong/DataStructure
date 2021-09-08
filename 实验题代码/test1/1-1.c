#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node 
{
    int data;
    struct node *next;
}node;

node *initList()
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

bool insertTail(node *head,node *new)
{
    if (head == NULL||new == NULL)
        return false;

    node *p;
    for (p=head;p->next!=NULL;p=p->next);
    p->next = new;
    
    return true;
}

bool insertHead(node *head,node *new)
{
    if (head == NULL||new == NULL)
        return false;
    
    new->next=head->next;
    head->next=new;
    
}

bool isEmpty(node *head)
{
    return head->next == NULL;
}

bool show(node *head)
{
    if (isEmpty(head))
        return false;
    
    for (node *p=head->next;p!=NULL;p=p->next)
    {
        printf("%d\t",p->data);
    }
    printf("\n");

    return true;  
    
}

void reverse(node *head)
{
    if (isEmpty(head))
        return;
    node *p = head->next;
    head->next=NULL;

    while (p!=NULL)
    {
        node *tmp = p;
        p=p->next;
        insertHead(head,tmp);
    }
    
}

void destroy(node *head)
{
    if (isEmpty(head))
        return;
    

    node *tmp,*p;
    for (tmp = head,p = head->next;tmp!=NULL;tmp=p)
    {
        p=tmp->next;
        free(tmp);
    }
    
}

int main(int argc, char const *argv[])
{
    node *head = initList();

    int n;
    printf("请输入链表元素个数：");
    scanf("%d",&n);

    for (int i = 1; i <= n; i++)
    {
        node *new = newNode(i);

        // insertHead(head,new);
        insertTail(head,new);
    }
    
    if(!show(head))
    {
        printf("链表为空\n");
    }

    reverse(head);
    show(head);

    destroy(head);

    return 0;
}
