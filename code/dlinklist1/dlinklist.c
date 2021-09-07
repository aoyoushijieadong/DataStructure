#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>

typedef struct node 
{
    int data;
    struct node *prev;
    struct node *next;
}node;

node *initList()
{
    node *head = (node *)malloc(sizeof(node));
    if (head)
    {
        head->prev = head;
        head->next = head;
    }

    return head;
}

node *newNode(int data)
{
    node *new = (node *)malloc(sizeof(node));

    if (new != NULL)
    {
        new->data=data;
        new->prev=new;
        new->next=new;
    }

    return new;
    
}


void insertHead(node *head,node *new)
{
    new->prev = head;
    new->next = head->next;
    
    head->next = new;
    new->next->prev = new;
}

void insertTail(node *head,node *new)
{
    new->prev = head->prev;
    new->next = head;

    head->prev->next = new;
    head->prev = new;
}

node *findNode(node *head,int data)
{
    
    node *p;
    for (p=head->next;p!=head;p=p->next)
    {
        if (p->data == data)
        {
            return p;
        }
        
    }
    return NULL;
}

void removeNode(node *p)
{
    p->prev->next=p->next;
    p->next->prev=p->prev;

    p->prev=p;
    p->next=p;
}


void show(node *head)
{
    node *p;
    for (p=head->next;p!=head;p=p->next)
    {
        printf("%d\t",p->data);
    }
    printf("\n");
}

bool isEmpty(node *head)
{
    return head->next == head;
}

node *destroy(node *head)
{
    if (isEmpty(head))
        return NULL;
    
    for (node *p=head->next;p!=head;p=head->next)
    {
        removeNode(p);
        free(p);
    }
    free(head);
    
    
}

int main(int argc, char const *argv[])
{
    node *head = initList();
    if (head)
        printf("初始化链表成功\n");
    else
    {
        perror("初始化链表失败");
        exit(0);
    } 

    for (int i = 1; i <= 5; i++)
    {
        node *new = newNode(i);

        // insertHead(head,new);
        insertTail(head,new);
    }
    
    show(head);

    int n;
    
    while (1)
    {
        printf("请输入你想要删除节点的数值:");
        scanf("%d",&n);

        if (n==0)
            break;
        
        node *p = findNode(head,n);
        if (p==NULL)
        {
            printf("没有你要删除的节点!!\n");
        }
        else
        {
            removeNode(p);
            free(p);
        }
        show(head);
    }
    
    head = destroy(head);

    return 0;
}
