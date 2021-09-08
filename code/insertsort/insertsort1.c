#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int swap_count = 0;
int comp_count = 0;


void show(int *data,int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d\t",data[i]);
    }
    printf("\n");
    
}

int findNum(int *data,int len,int num)
{
    if (len == 0)
        return 0;
    
    comp_count++;
    if (num < data[0])              //当num小于数组首元素时，返回值为数组的首位
        return 0;
    else if (num > data[len-1])     //当num小于数组首元素时，返回值为数组的末位
        return len;
    
    
    int pos = 0;
    int i = 0,j = len-1;
    for (pos = (i+j)/2; i<j ; pos=(i+j)/2)
    {
        //此处加pos>0，可以避免pos=0
        if (pos > 0 && data[pos-1]<num && num<data[pos])
        {
            comp_count++;
            return pos;
        }

        if (num < data[pos])
            j = pos;
        else
            i = pos;
        comp_count++;
        //此处是为了避免程序陷入死循环
        if (pos == i )
            i++;
        
    }
    
    
    
}

void insertionSort(int *data,int len)
{
    int i,j;
    for ( i = 1; i < len; i++)
    {
        int tmp = data[i];
        //采用二分法找到合适位置
        int pos = findNum(data,i,tmp);

        //批量移动数据
        for ( j = i-1; j >= pos; j--)
        {
            data[j+1] = data[j];
            swap_count++;
        }
        data[j+1] = tmp;

    }
    
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int n;
    printf("请输入序列的个数:");
    scanf("%d",&n);
    int *data = (int *)calloc(n,sizeof(int)); 

    for (int i = 0; i < n; i++)
    {
        data[i]=rand()%100;
    }
    printf("随机序列:");
    show(data,n);

    printf("选择序列:");
    insertionSort(data,n);
    show(data,n);

    printf("总共比较次数: %d\n", comp_count);
    printf("总共交换次数: %d\n", swap_count);

    return 0;
}
