#include "kernel_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
typedef struct node 
{
    int data;

    struct list_head list;
}listnode,*linklist;

linklist initList()
{
    linklist head = malloc(sizeof(listnode));
    if (head != NULL)
    {
        // head->list.prev = &head->list;
        // head->list.next = &head->list;
        INIT_LIST_HEAD(&head->list);
    }
    return head;
    
}
linklist newNode(int data)
{
    linklist new = malloc(sizeof(listnode));
    if (new != NULL)
    {
        INIT_LIST_HEAD(&new->list);
        new->data = data;
    }
    return new;

}
void show(linklist head)
{
    struct list_head *pos;
    list_for_each(pos,&head->list)
    {
        struct node *p;
        p = list_entry(pos,struct node,list);
        printf("%d\t",p->data);
    }
    printf("\n");
}

linklist findNode(linklist head,int data)
{
    linklist pos;
    list_for_each_entry(pos,&head->list,list)
    {
        if (pos->data == data)
        {
            return pos;
        }
        
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    //初始化一个带头结点的空链表
    linklist head = initList();
    if (head != NULL)
    {
        printf("初始化空链表成功\n");
    }
    else 
    {
        perror("初始化空链表失败\n");
        exit(0);
    }
    
    for (int i = 1; i <= 5; i++)
    {
        linklist new = newNode(i);
        list_add_tail(&new->list,&head->list);

    }
    //遍历链表
    show(head);

    int n;
    while (1)
    {
        scanf("%d",&n);

        if (n == 0)
            break;

        linklist p = findNode(head,n); 
        if (p==NULL)
            printf("找不到你想要删除的节点\n");
        else{
            list_del(&p->list);
            free(p);
            show(head);
        }
        
    }
    
    //链表的逆转
    struct list_head *m = head->list.next;
    struct list_head *p = head->list.prev;
    for (;m != p;m=head->list.next)
    {
        list_move(m,p);
    }
    show(head);
    for (m=head->list.next,p=head->list.prev; m!=p;p=head->list.prev)
    {
        list_move_tail(p,m);
    }
    show(head);

    linklist new_head = initList();
    for (int i = 6; i <= 10; i++)
    {
        linklist new = newNode(i);
        list_add_tail(&new->list,&new_head->list);

    }
    show(new_head);
    list_splice(&head->list,&new_head->list);
    show(new_head);
    return 0;
}
