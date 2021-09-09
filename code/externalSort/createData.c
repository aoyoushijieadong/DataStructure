#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    FILE *fp = fopen("number.txt","w");
    if (fp == NULL)
    {
        perror("打开文件失败");
        exit(0);
    }

    srand(time(NULL));

    for (int i = 0; i < 1000*1000; i++)
    {
        int exp = (int)pow(10,rand()%8+3);
        fprintf(fp,"%d\n",rand()%exp);
    }

    fclose(fp);
    

    return 0;
}
