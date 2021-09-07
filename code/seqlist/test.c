#include "seqlist.h"
#include <stdio.h>
int main(int argc, char const *argv[])
{
    //初始化一个空的顺序表
    struct seqlist *sl = initSeqList(10);

    //从键盘获取整数，并放入顺序表中
    int n;
    while(1)
    {
        scanf("%d",&n);

        if (n == 0)
        {
            break;
        }
        
        //插入数据
        if (n>0)
        {
            if (!insertNode(sl,n))
                printf("插入数据失败\n");
                
        }
        
        //删除数据
        if (n<0)
        {
            if (!removeNode(sl,-n))
                printf("删除数据失败\n");
            
        }
        show(sl);
        

    }

    sort(sl,INCREASE);
    show(sl);

    sort(sl,DESCEND);
    show(sl);

    destroySeqList(sl);
    return 0;
}
