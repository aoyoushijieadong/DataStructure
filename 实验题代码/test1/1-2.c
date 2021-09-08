#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int data;
    struct node *next;
}node;

node *initList()
{
    return NULL;
}

node *newNode(int data)
{
    node *new = (node *)malloc(sizeof(node));

    if (new != NULL)
    {
        new->data = data;
        new->next = new;
    }
    
    return new;
}

node *insertTail(node *head,node *new)
{
    if (head == NULL)
        return new;
    
    node *p;
    for (p=head;p->next!=head;p=p->next);
    new->next=p->next;
    p->next = new;
    return head;

    
}

void show(node *head)
{
    if (head == NULL)
        return;
    
    node *p;
    for (p=head;p->next!=head;p=p->next)
    {
        printf("%d\t",p->data);
    }
    printf("%d\n",p->data);
    
    return;
    
}

node *listRemove(node *p)
{
    if (p == NULL)
        return NULL;
    if (p == p->next)
        return NULL;
    
    node *k;
    for (k = p->next;k->next != p;k = k->next);
    
    k->next = p->next;
    p->next = p;
    free(p);

    return k->next;
    
}

node *killThree(node *head)
{
    if (head == NULL)
        return NULL;
    node *p;
    for (p=head->next->next;p!=p->next->next;p=p->next->next)
    {
        p = listRemove(p);
    }
    
    return p;
  
}

void destroy(node *head)
{
    if (head == NULL)
        return;
    node *tmp,*p;
    for (tmp = head->next,p = tmp->next;tmp!=head;tmp = p)
    {
        p = tmp->next;
        free(tmp);
    }
    free(head);
    
}

int main(int argc, char const *argv[])
{
    node *head = initList();

    int n;
    printf("请输入链表元素个数:");
    scanf("%d",&n);

    for (int i = 1; i <= n; i++)
    {
        node *new = newNode(i);

        head = insertTail(head,new);
    }
    printf("链表中的元素:\n");
    show(head);

    head = killThree(head);

    printf("最后剩余的两个节点:\n");
    show(head);

    destroy(head);
    
    return 0;
}
