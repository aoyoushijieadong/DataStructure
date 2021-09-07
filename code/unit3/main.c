
struct student
{
    unsigned int ID;
    int age;
    char *name;   
};

#define DATATYPE struct student
#include "main.h"

void showinfo(struct student *p)
{
    printf("ID:%d,姓名:%s,年龄:%d\n",p->ID,p->name,p->age);
}

void showval(int *data)
{
    printf("%d\n",*data);
}

bool equal(struct student a,struct student b)
{
    return a.ID == b.ID;
}
int main()
{
    linklist head = initList();
    
    struct student Jack = {1,20,"Jack"};
    struct student Rose = {2,21,"Rose"};
    struct student Bill = {3,21,"Bill"};

    linklist new = newNode(Jack);
    // linklist new = newNode(10);
    listAddTail(head,new);

    new = newNode(Rose);
    //  new = newNode(20);
    listAddTail(head,new);

     new = newNode(Bill);
    //  new = newNode(20);
    listAddTail(head,new);

    listForEach(head,showinfo);
    // listForEach(head,showval);

    linklist p = findNode(head,Rose,equal);
    if (p!=NULL)
    {
        printf("找到了，并删除\n");
        listDelNode(p);
        free(p);
    }
    else
        printf("找不到\n");

    p = findNode(head,Rose,equal);
    if (p!=NULL)
    {
        printf("找到了，并删除\n");
        listDelNode(p);
        free(p);
    }
    else
        printf("找不到\n");
}