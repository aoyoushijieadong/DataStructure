#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define DEFAULT_SIZE 16

typedef struct listnode 
{
    struct listnode *next;
    int key;
    void *data;
}listnode;

typedef listnode *list;
typedef listnode *element;

typedef struct HashTable
{
    int TableSize;
    list *Thelists;
}HashTable;

int Hash(int key,int TableSize)
{
    return (key%TableSize);
}

//初始化哈希表
HashTable *InitHash(int TableSize)
{
    int i = 0;
    HashTable *hTable = NULL;

    if (TableSize <= 0)
    {
        TableSize = DEFAULT_SIZE;
    }
    
    hTable = (HashTable *)malloc(sizeof(HashTable));
    if (hTable == NULL)
    {
        printf("HashTable malloc error.\n");
        return NULL;
    }
    hTable->TableSize = TableSize;
    //为Hash桶分配内存空间，其为一个指针数组
    hTable->Thelists = (list *)malloc(sizeof(list)*TableSize);
    if (hTable->Thelists == NULL)
    {
        printf("HashTable malloc error.\n");
        free(hTable);
        return NULL;
    }
    //为Hash桶对应的指针数据初始化链表节点
    for (int i = 0; i < TableSize; i++)
    {
        hTable->Thelists[i]=(listnode *)malloc(sizeof(listnode));
        if (NULL == hTable->Thelists[i])
        {
            printf("HashTable malloc error.\n");
            free(hTable->Thelists);
            free(hTable);
            return NULL;
        }
        else
        {
            memset(hTable->Thelists[i],0,sizeof(listnode));
        }
    }
    return hTable;
    
}

element Find(HashTable *HashTable,int key)
{
    int i = 0;
    list L = NULL;
    element e =NULL;
    i = Hash(key,HashTable->TableSize);
    L = HashTable->Thelists[i];
    e = L->next;
    while (e != NULL && e->key != key)
        e = e->next;

    return e; 
}

//哈希表插入元素，元素为键值对
void Insert(HashTable *HashTable,int key,void *value)
{
    element e=NULL,tmp=NULL;
    list L=NULL;
    e = Find(HashTable,key);

    if (NULL == e)
    {
        tmp = (element)malloc(sizeof(listnode));
        if (NULL == tmp)
        {
            perror("malloc error");
            return;
        }
        L = HashTable->Thelists[Hash(key,HashTable->TableSize)];
        tmp->data = value;
        tmp->key = key;
        tmp->next = L->next;
        L->next = tmp;
        
    }
    else
        printf("the key already exist\n");
    
}
//哈希表删除元素，元素为键值对
void Delete(HashTable *HashTable,int key)
{
    element e = NULL,last = NULL;
    list L = NULL;
    int i = Hash(key,HashTable->TableSize);
    L = HashTable->Thelists[i];

    last = L;
    e = L->next;
    while (e != NULL && e->key != key)
    {
        last = e;
        e = e->next;
    }

    if (e)
    {
        last->next = e->next;
        free(e);
    }
    else
        printf("找不到元素%d\n",key);

    
}
//哈希表元素中提取数据
void *Retrieve(element e)
{
    return e ? e->data:NULL;
}

//销毁哈希表
void Destory(HashTable *HashTable)
{
    int i = 0;
    list L = NULL;
    element cur = NULL,next = NULL;
    for (int i = 0; i < HashTable->TableSize; i++)
    {
        L = HashTable->Thelists[i];
        cur = L->next;
        L->next = NULL;
        while (cur != NULL)
        {
            next = cur->next;
            free(cur);
            cur = next;
        }
        free(L);
        
    }
    free(HashTable);
}

int main(int argc, char const *argv[])
{
    char *elems[] = {"翠花","小芳","小明"};
    int i = 0;

    HashTable *HashTable = NULL;
    HashTable = InitHash(31);
    if (NULL == HashTable)
    {
        perror("InitHash error");
        exit(0);
    }
    Insert(HashTable,1,elems[0]);
    Insert(HashTable,2,elems[1]);
    Insert(HashTable,3,elems[2]);
    Delete(HashTable,1);

    for (int i = 0; i < 4; i++)
    {
        element e = Find(HashTable,i);
        if (e)
        {
            printf("%s\n",(const char *)Retrieve(e));
        }
        else
            printf("Not found [key:%d]\n",i);
    }

    Destory(HashTable);

    return 0;
}   