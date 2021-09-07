#include <stdio.h> 
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void show(int *data,int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d\t",data[i]);
    }
    printf("\n");
    
}

void swaps(int *a,int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(int *data,int len)
{
    

    int k=0;
    while (1)
    {
        bool flags = true;
        for (int i = 0; i < len-1-k; i++)
        {
            if (data[i] <= data[i+1])
                continue;
            
            swaps(&data[i],&data[i+1]);
            flags = false;
        }

        if (flags)
            break;
        
        k++;
        
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

    printf("冒泡序列:");
    bubbleSort(data,10);
    show(data,10);

    return 0;
}
