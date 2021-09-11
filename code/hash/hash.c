#include "Hash.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void main()
{
    // P257HashMain();

    P259HashMain();

}

void P257HashMain()
{
    int data[12]={19,1,23,14,55,68,11,82,36,13,42,77};
    int m=11,n=12;
    HashNode ht[11];
    CreatHash(ht,data,m,m,n);

    PrintHash(ht,11);
}

void P259HashMain()
{
    int data[8]={5,21,17,9,15,36,41,24};
    int m=5,n=8;
    HashNode ht[5];
    CreatLinkHash(ht,data,m,m,n);
   
    PrintLinkHash(ht,m);

}

//m为表长，p为小于m的质数
void Hash1(HashNode HT[],KeyType key, int p,int m)
{
    int i,j;
    j=key%p;i=j-1;
    if (i==-1)
        i=m-1;
    while((HT[j].key!=-10000)&& (HT[j].key!=key)&&(j!=i))
    j=(j+1) % m;    /*　解决冲突　*/
    if(HT[j].key==key)printf("\n成功查找到%d,位置在:%d\n",key,j);
    else if(j==i)printf("溢出\n");      /*　溢出　*/
    else HT[j].key=key;   /*　插入key   */
}

int GetHashP(int ListLen)
{
    int i,j,m,flag=0;

    for(j=ListLen-1;j>=2;j--)
    {
        m=sqrt(j);
        for(i=2;i<m;i++)
        if(j%i==0)break;
        if(i==m)break;
    }
    return j;
}

//m为表长，n为初始数据个数
void CreatHash(HashNode *HT,KeyType *Key,int p,int m,int n)
{
    int i;
    for(i=0;i<m;i++)
    {
        HT[i].key=-10000;      //
    }
    for(i=0;i<n;i++)
    {
        Hash1(HT,Key[i],p,m);
//        if(Key[i]%m==0)HT[Key[i]%m].next=0;
//        else HT[Key[i]%m-1].next=HT+i;
    }
}

void PrintHash(HashNode *HT,int m)
{
    int i=0;
    for(i=0;i<m;i++)
        printf("%d ",HT[i].key);
}

void LinkHash(KeyType k, HashNode HT[], int p)
{
    int j;
    HashNode *q,*r,*s;
    j=k%p;
    if(HT[j].key==0)
    {
        HT[j].key=k;
        HT[j].next=NULL;
    }
    else if (HT[j].key==k)
    {
        printf("成功查找到 %d",k);
        printf("位置在:%d",j);
    }
    else
    {
        q=HT[j].next;
        r=q;
        while((q!=NULL)&&(q->key!=k))
        {
            r=q;q=q->next;
        }
        if(q==NULL)
        {
            s=(HashNode*)malloc(sizeof(HashNode));
            s->key=k;
            s->next=NULL;
            if(!HT[j].next)
                HT[j].next=s;//教材上此处有误，需要增加一个是否在哈希存储区的判断
            else 
                r->next=s;
        }
        else
        {
            printf("成功查找到 %d",k);
            printf("位置在:%d",j);
        }
    }
}

//m为表长，n为初始数据个数
void CreatLinkHash(HashNode *HT,KeyType *Key,int p,int m,int n)
{
    int i;
    for(i=0;i<m;i++)
    {
        HT[i].key=0;
        HT[i].next = NULL;
    }
    for(i=0;i<n;i++)
    {
        LinkHash(Key[i],HT,p); 
    }
}

//输出外链Hash表
void PrintLinkHash(HashNode *HT,int n)
{
    int i=0;
    HashNode *p;
    for(i=0;i<n;i++)
    {
        // printf("LINE:%d\n",__LINE__);
        p=&HT[i];
        while (p)
        {
            printf("%d ",p->key);
            p=p->next;
        }
    
        
    //     do
    //     {
    //         printf("%d ",p->key);
    //         p=p->next;
    //     }while(p);
    // }
    
}
