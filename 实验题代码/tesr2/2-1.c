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
    if (head != NULL)
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
        new->data = data;
        new->prev = new;
        new->next = new;
    }
    return new;
}

void insertTail(node *head,node *new)
{
    if (head == NULL||new == NULL)
        return;
    
    new->prev = head->prev;
    new->next = head;
    
    head->prev->next = new;
    head->prev = new;
    
    
}

bool isEmpty(node *head)
{
    return head->next == head;
}

void show(node *head)
{
    if (isEmpty(head))
        return;

    node *p;
    for (p=head->next;p!=head;p=p->next)
    {
        printf("%d\t",p->data);
    }
    printf("\n");
    
}

// void showOdd(node *head)
// {
//     node *p;
//     for (p=head->next;p!=head;p=p->next)
//     {
//         if ((p->data)%2 != 0 )
//         {
//             printf("%d\t",p->data);
//         }
//     }
     
// }

// void showEven(node *head)
// {
//     node *p;
//     for (p=head->prev;p!=head;p=p->prev)
//     {
//         if ((p->data)%2 == 0 )
//         {
//             printf("%d\t",p->data);
//         }
//     }
    
// }

void rerange(node *old_head,node *new_head)
{
    node *p = old_head->next;
    while (p->next!=old_head && p->next->next!=old_head)
    {
        node *new = newNode(p->data);
        insertTail(new_head,new);
        p=p->next->next;
    }
    
    //判断最后一个元素的奇偶性
    //最后一个元素为奇数
    if (p->next == old_head)
    {
        node *new = newNode(p->data);
        insertTail(new_head,new);
        p=p->prev;
        //将旧链表中偶数元素插到新链表尾部
        while (p->prev->prev != old_head)
        {
            node *new = newNode(p->data);
            insertTail(new_head,new);
            p=p->prev->prev;
        }
        node *new1 = newNode(p->data);
        insertTail(new_head,new1);
    }
    //最后一个元素为奇数
    else
    {
        node *new = newNode(p->data);
        insertTail(new_head,new);
        p = p->next;

        while (p->prev->prev != old_head)
        {
            node *new = newNode(p->data);
            insertTail(new_head,new);
            p=p->prev->prev;
            
        }
        node *new1 = newNode(p->data);
        insertTail(new_head,new1);

    }
    

}

int main(int argc, char const *argv[])
{
    node *head = initList();
    if (head)
    {
        printf("链表初始化成功\n");
    }
    else
    {
        perror("链表初始化失败");
        exit(0);
    }
    
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        node *new = newNode(i);

        insertTail(head,new);
    }
    
    show(head);

    // showOdd(head);

    // showEven(head);

    // printf("\n");

    node *new_head = initList();
    rerange(head,new_head);

    show(new_head);

    return 0;
}
