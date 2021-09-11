#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#define NULL 0

typedef int KeyType;    /* 关键字的类型*/

/* 哈希表的最大长度*/
#define MAXSIZE 100;

typedef struct HashNode
{
    KeyType  key;
    struct HashNode *next;
}HashNode;


int GetHashP(int ListLen);

//m为表长，p为小于m的质数
void CreatHash(HashNode *HT,KeyType *Key,int p,int m,int n);

//m为表长，p为小于m的质数
void Hash1(HashNode HT[],KeyType key, int p,int m);

//外链地址法
void LinkHash(KeyType k, HashNode HT[], int p);

//m为表长，n为初始数据个数
void CreatLinkHash(HashNode *HT,KeyType *Key,int p,int m,int n);

//输出外链Hash表
void PrintLinkHash(HashNode *HT,int n);

void P257HashMain();

void P259HashMain();

void PrintHash(HashNode *HT,int m);

#endif // HASH_H_INCLUDED
