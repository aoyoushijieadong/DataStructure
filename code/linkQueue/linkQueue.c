#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node 
{
    int data;
    struct node *next;
}node;

typedef struct linkQueue
{
    node *front;
    node *rear;
    int size;
}linkQueue;

linkQueue *initQueue()
{
    linkQueue *queue = (linkQueue *)calloc(1,sizeof(linkQueue));
    if (queue != NULL)
    {
        queue->front = NULL;
        queue->rear = NULL;
        queue->size = 0;
    } 
    return queue;
}

node *newNode(int data)
{
    node *new = (node *)calloc(1,sizeof(node));
    if (new != NULL)
    {
        new->data = data;
        new->next = NULL;
    }
    return new;
    
}

bool isEmpty(linkQueue *queue)
{
    return queue->size == 0;
}

void enQueue(linkQueue *queue,node *new)
{
    if (isEmpty(queue))
        queue->rear = new;
    else
        new->next=queue->front;
    
    queue->front = new;
    queue->size++;

    return;
 
}

void show(linkQueue *queue)
{
    if (isEmpty(queue))
        return;

    for (node *p = queue->front;p != NULL;p=p->next)
    {
        printf("%d ",p->data);
    }
    printf("\n");
     
}

bool front(linkQueue *queue,int *pm)
{
    if (isEmpty(queue))
        return false;

    *pm = queue->front->data;
    return true;

}

node *outQueue(linkQueue *queue)
{
    if (isEmpty(queue))
        return NULL;
    
    node *p = queue->front;
    queue->front = p->next;
    p->next =NULL;
    queue->size--;

    return p;
    
    
}

int main(int argc, char const *argv[])
{
    linkQueue *queue = initQueue();
    if (queue != NULL)
        printf("初始化空链式队列成功\n");
    else
    {
        printf("初始化空链式队列失败\n");
        exit(0);
    }

    for (int i = 1; i <= 5; i++)
    {
        node *new = newNode(i);
        enQueue(queue,new);
    }
    show(queue);
    
    int m;
    if(front(queue,&m))
        printf("队头元素为%d\n",m);
    
    while (!isEmpty(queue))
    {
        node *tmp = outQueue(queue);
        if (tmp == NULL)
        {
            printf("出队失败\n");
            exit(0);
        }
        printf("出队节点:%d\t",tmp->data);
        free(tmp);
    }
    

    return 0;
}
