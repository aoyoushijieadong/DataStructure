#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "kernel_list.h"

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
    if (list_empty(&head->list))
        return ;
    struct list_head *pos;
    list_for_each(pos,&head->list)
    {
        struct node *p;
        p = list_entry(pos,struct node,list);
        printf("%d\t",p->data);
    }
    printf("\n");
}

linklist exchange(struct list_head *pos)
{
    linklist p;
    p = list_entry(pos,struct node,list);
    return p;
    
}
void rerange(linklist old_head,linklist new_head)
{
    struct list_head *p = old_head->list.next;
    linklist new,s;
    while (p->next != &old_head->list && p->next->next != &old_head->list)
    {
        //将小结构体p转换成p对应的大结构体s
        s = exchange(p);
        new = newNode(s->data);
        list_add_tail(&new->list,&new_head->list);
        p = p->next->next;
    }

    if (p->next == &old_head->list)
    {
        s = exchange(p);
        new = newNode(s->data);
        list_add_tail(&new->list,&new_head->list);
        p = p->prev;

        while (p->prev->prev != &old_head->list)
        {
            s = exchange(p);
            new = newNode(s->data);
            list_add_tail(&new->list,&new_head->list);
            p = p->prev->prev;    
        }
        s = exchange(p);
        new = newNode(s->data);
        list_add_tail(&new->list,&new_head->list);

    }
    else
    {
        s = exchange(p);
        new = newNode(s->data);
        list_add_tail(&new->list,&new_head->list);

        p = p->next;

        while (p->prev->prev != &old_head->list)
        {
            s = exchange(p);
            new = newNode(s->data);
            list_add_tail(&new->list,&new_head->list);
            p = p->prev->prev;  
        }
        s = exchange(p);
        new = newNode(s->data);
        list_add_tail(&new->list,&new_head->list);
        
    }
    
    
}

int main(int argc, char const *argv[])
{
    linklist head = initList();
    if (head != NULL)
        printf("初始化空链表成功\n");
    else
    {
        perror("初始化空链表失败");
        exit(0);
    }

    int n,m;
    printf("请输入链表元素个数n:");
    while(1)
    {
        m = scanf("%d",&n);
        if (m != 1 || getchar()!='\n'||n<=0)
        {
            while (getchar()!='\n');
            printf("输入有误请重新输入！！\n");
            continue;
        }
        else
            break;
        
    }
    for (int i = 1; i <= n; i++)
    {
        linklist new = newNode(i);
        list_add_tail(&new->list,&head->list);
    }
    show(head);
    linklist new_head = initList();
    rerange(head,new_head);
    show(new_head);

    return 0;
}
