#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int comp_count = 0;
int swap_count = 0;

void show(int data[],int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d\t",data[i]);
    }
    printf("\n");
    
}

void insertionSort(int data[],int len,int delta)
{
    if (len <= 1)
        return;
    
    int i,j;
    for ( i = delta; i < len*delta; i+=delta)
    {
        int tmp = data[i];
        for ( j = i-delta; j>=0 ; j-=delta)
        {
            comp_count++;
            if (data[j]<tmp)
                break;
            swap_count++;
            data[j+delta] = data[j];
        }
        swap_count++;
        data[j+delta] = tmp;
        
    }
    
}

void shellSort(int data[],int len)
{
    if (len <= 1 )
        return;
    
    for (int delta = len/2;delta > 0;delta/=2)
    {
        for (int i = 0; i < delta; i++)
        {
            insertionSort(data+i,len/delta,delta);
        }
        
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
        int exp = (int)pow(10,rand()%3+3);
        data[i]=rand()%exp;
    }
    printf("随机序列:");
    show(data,n);

    printf("选择序列:");
    shellSort(data,n);
    show(data,n);

    printf("总共比较次数: %d\n", comp_count);
    printf("总共交换次数: %d\n", swap_count);

    return 0;
}
