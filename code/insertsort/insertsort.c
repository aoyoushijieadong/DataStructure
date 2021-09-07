#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comp_count = 0;
int swap_count = 0;

void show(int *data,int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d\t",data[i]);
    }
    printf("\n");
    
}

void insertionSort(int *data,int len)
{
    for (int i = 1; i < len; i++)
    {
        comp_count++;
        int tmp = data[i];
        for (int j = i-1; j >= 0; j--)
        {
            if (data[j]<tmp)
                break;
            else
            {
                swap_count++;
                data[j+1]=data[j];
                data[j] = tmp;
            }
            
        }
        
    }
    
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int data[10];
    for (int i = 0; i < 10; i++)
    {
        data[i] = rand()%100;
    }
    printf("随机序列:");
    show(data,10);
    
    insertionSort(data,10);
    printf("插入序列:");
    show(data,10);

    printf("总共比较次数:%d\n",comp_count);
    printf("总共移动次数:%d\n",swap_count);
    return 0;
}
