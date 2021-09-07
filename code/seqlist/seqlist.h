#ifndef __SEQLIST_H
#define __SEQLIST_H

struct seqList
{
    int capactity;
    int last;
    int *data;
};

#include <stdio.h>
#include <stdbool.h>
// 初始化
struct seqList * initSeqList(int cap);
// 插入元素
bool insertNode(struct seqList *sl, int data);
// 删除元素
bool removeNode(struct seqList *sl, int data);
// 销毁顺序表
void destroySeqList(struct seqList *sl);
#endif // 