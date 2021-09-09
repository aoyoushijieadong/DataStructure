#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void swap(int *a,int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// int pratition(int data[],int len)
// {
//     if (len <= 1 )
//         return 0;
//     int i = 0,j = len-1;
//     while (i<j)
//     {
//         while(data[i]<=data[j] && i<j)
//             j--;
//         if (i == j)
//             break;
//         swap(&data[i],&data[j]);

//         while (data[i]<=data[j] && i<j)
//             i++;
//         if (i == j)
//             break;
//         swap(&data[i],&data[j]);
        
//     }

//     return i;
    
// }

// void quickSort(int data[],int len)
// {
//     if (len <= 1)
//         return;
//     int pivot = pratition(data,len);

//     quickSort(data,pivot);
//     quickSort(data+pivot+1,len-1-pivot);
//     return ;
// }


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
            if (data[j]<tmp)
                break;
            data[j+delta] = data[j];
        }
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

//融合begin到end的所有文件，并入文件begin
void merge(int begin,int end)
{
    if (end-begin <= 0)
        return;
    //融合begin+1到end的所有文件，并入文件begin+1
    merge(begin+1,end);

    //合并begin和begin+1
    char f1[10],f2[10];
    bzero(f1,10);
    bzero(f2,10);
    snprintf(f1,10,"%d.txt",begin);
    snprintf(f2,10,"%d.txt",begin+1);

    FILE *fp1 = fopen(f1,"r");
    FILE *fp2 = fopen(f2,"r");

    int n1,n2;
    if (fscanf(fp1,"%d",&n1) == EOF)
    {
        fclose(fp1);
        fclose(fp2);

        remove(f1);
        rename(f2,f1);
        return;
    }
    if (fscanf(fp2,"%d",&n2) == EOF)
    {
        fclose(fp1);
        fclose(fp2);

        remove(f2);
        return;
    }
    
    //临时存放合并的数据，最后更名为begin
    FILE *tmp = fopen("tmp.txt","w+");
    int fp1_done = false;
    int fp2_done = false;
    while (1)
    {

        if(n1<n2)
        {
            fprintf(tmp,"%d\n",n1);
            if (fscanf(fp1,"%d",&n1) == EOF)
            {
                fprintf(tmp,"%d\n",n2);
                fp1_done = true;
                break;
            }
           
        }
        else
        {
            fprintf(tmp,"%d\n",n2);
            if (fscanf(fp2,"%d",&n2) == EOF)
            {
                fprintf(tmp,"%d\n",n1);
                fp2_done = true;
                break;
            }
            
        }
    }
    //将剩余的数据置入tmp中
    if (fp1_done)
    {
        while (fscanf(fp2,"%d",&n2) != EOF)
        {
            fprintf(tmp,"%d\n",n2);
        }
        
    }
    else
    {
        while (fscanf(fp1,"%d",&n1) != EOF)
        {
            fprintf(tmp,"%d\n",n1);
        }
        
    }
    
    //删除原有文件，并将tmp更名为begin
    fclose(fp1);
    fclose(fp2);

   if(remove(f1) == -1)
    {
        printf("删除文件%s失败:%s\n", f1, strerror(errno));
        exit(0);
    }
    if(remove(f2) == -1)
    {
        printf("删除文件%s失败:%s\n", f2, strerror(errno));
        exit(0);
    }

    fclose(tmp);
    rename("tmp.txt", f1);
    return;
    
    
}

int main(int argc, char const *argv[])
{
    //打开一个包含百万数据级别的文件
    FILE *src = fopen("number.txt","r");
    if (src == NULL)
    {
        perror("打开文件失败");
        exit(0);
    }

    //1、将原始数据文件，分割成N个有序的子文件
    bool done = false;
    char file[20];
    int N = 0;
    int wanted = 100*1000; //假设每次只能读取10万个数据
    int infact = wanted ;
    while (1)
    {
        //试图从文件读取wanted个数据
        int *data = calloc(wanted,sizeof(int));
        for (int i = 0; i < wanted; i++)
        {
            if (fscanf(src,"%d",&data[i])==EOF)
            {
                done = true;
                infact = i;
                break;
            }
        }

        //对读取到的infact个数据进行排序
        shellSort(data,infact);

        //创建临时文件，存放部分数据
        bzero(file,20);
        snprintf(file,20,"%d.txt",++N);
        FILE *fp = fopen(file,"w");

        //将排好序的部分数据写入临时文件，保存起来
        for (int i = 0; i < infact; i++)
        {
            fprintf(fp,"%d\n",data[i]);
        }
        free(data);
        fclose(fp);

        if (done)
            break;
     
    }
    fclose(src);
    
    //2、将N个有序子文件，合并成一个有序文件
    merge(1,N);
    return 0;
}
