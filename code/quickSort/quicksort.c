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

void swap(int *a,int *b)
{
    swap_count++;
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int data[],int len)
{
    if (len <= 1)
        return 0;
    
    int i = 0,j = len-1;
    while (i<j)
    {
        comp_count++;
        while(data[i]<=data[j] && i<j)
            j--;

        if (i == j)
            break;
        swap(&data[i],&data[j]);

        comp_count++;
        while (data[i]<=data[j] && i<j)
            i++;
        if (i == j)
            break;
        swap(&data[i],&data[j]);
        
    }
    return i;
    
}

void quickSort(int data[],int len)
{
    if (len <= 1)
        return;

    
    int pivot = partition(data,len);
    quickSort(data,pivot);
    quickSort(data+pivot+1,len-1-pivot);
    
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
    quickSort(data,n);
    show(data,n);

    printf("总共比较次数: %d\n", comp_count);
    printf("总共交换次数: %d\n", swap_count);

    return 0;
}
