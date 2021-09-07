#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef DATATYPE
#define DATATYPE int
#endif

typedef DATATYPE datatype;

typedef struct linknode 
{
    datatype data;
    struct linknode *next;
}linknode;


typedef struct linkQueue
{
    linknode *front;
    linknode *rear;
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


bool queueIsEmpty(linkQueue *queue)
{
    return queue->size == 0;
}

bool enQueue(linkQueue *queue,datatype data)
{
    linknode *new = (linknode *)calloc(1,sizeof(linknode));
    if (new == NULL)
        return false;
    new->data = data;
    new->next = NULL;

    if (queueIsEmpty(queue))
    {
        queue->rear = new;
        queue->front = new;
    }    
    else
    {
        queue->rear->next = new;
        queue->rear = new;
    }    
    
    queue->size++;

    return true;
 
}

// void show(linkQueue *queue)
// {
//     if (queueIsEmpty(queue))
//         return;

//     for (linknode *p = queue->front;p != NULL;p=p->next)
//     {
//         printf("%d ",p->data);
//     }
//     printf("\n");
     
// }

// bool front(linkQueue *queue,datatype *pm)
// {
//     if (isEmpty(queue))
//         return false;

//     *pm = queue->front->data;
//     return true;

// }

bool outQueue(linkQueue *queue,datatype *pm)
{
    if (queueIsEmpty(queue))
        return false;;
    
    linknode *p = queue->front;
    queue->front = p->next;
    p->next =NULL;
    queue->size--;
    *pm = p->data;

    return true;
    
    
}