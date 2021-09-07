#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct seqQueue
{
    int *data;
    int capacity;
    int front;
    int rear;
}seqQueue;

seqQueue *initQueue(int capacity)
{
    seqQueue *queue = (seqQueue *)calloc(1,sizeof(seqQueue));
    if (queue != NULL)
    {
        queue->data = (int *)calloc(capacity+1,sizeof(int));
        if (queue->data == NULL)
        {
            free(queue);
            return NULL;
        }
        queue->capacity = capacity+1;
        queue->front = queue->rear = 0;        
    }
    return queue;
    
}

bool isFull(seqQueue *queue)
{
    return (queue->rear+1)%queue->capacity == queue->front;
}

bool enQueue(seqQueue *queue,int data)
{
    if (isFull(queue))
        return false;
    
    queue->data[queue->rear]=data;
    queue->rear = (queue->rear+1)%queue->capacity;
    return true;
    
}

bool isEmpty(seqQueue *queue)
{
    return queue->front == queue->rear;
}

bool outQueue(seqQueue *queue,int *pm)
{
    if (isEmpty(queue))
        return false;
    *pm = queue->data[queue->front];
    queue->front = (queue->front+1)%queue->capacity;
    return true;
}

void show(seqQueue *queue)
{
    if (isEmpty(queue))
        return ;
    for (int i = queue->front;i != queue->rear;i = (i+1)%queue->capacity)
    {
        printf("%d ",queue->data[i]);
    }
    printf("\n");
     
}

int main(int argc, char const *argv[])
{
    seqQueue *queue = initQueue(10);
    if (queue != NULL)
        printf("初始化空循环队列成功\n");
    else
    {
        printf("初始化空循环队列失败\n");
        exit(0);
    } 

    int n;
    while (1)
    {
        if (scanf("%d",&n)==1)
        {
            if(!enQueue(queue,n))
            {
                printf("入队失败\n");
                continue;
            }   

        }
        else
        {
            while (getchar() != '\n');
            
            int m;
            if(!outQueue(queue,&m))
            {
                printf("出队失败\n");
                continue;
            }
        }
        show(queue);
    }
    

    return 0;
}
