#include "seqlist.h"

struct seqList * initSeqList(int cap)
{
    struct seqList *sl = calloc(1,sizeof(struct seqList));

    if (sl != NULL)
    {
        sl->capactity = cap;
        sl->last =-1;
        sl->data = calloc(cap,sizeof(int));
        
        if (sl->data == NULL)
        {
            free(sl);
            return NULL;
        }
        
    }
    return sl;
}

bool inserNode(struct seqList *sl,int data)
{
    // 判定是否有位置
    

    // 妥善地放入新的元素
    



}
bool removeNode(struct seqList *sl,int data)
{

}

void destroySeqList(struct seqList *sl)
{

}
