#include <stdio.h>
#include <limits.h>


#define MAXVEX 100
int visited[MAXVEX];
typedef char VertexType[10];
typedef struct vertex
{
    int adjvex;
    VertexType data;
}VType;

typedef struct graph
{
    int n,e;
    VType vexs[MAXVEX]; 
    int edges[MAXVEX][MAXVEX];   
}MatGraph;

MatGraph GreateGraph(MatGraph g,int A[][MAXVEX],int n,int e)
{
    int i,j;
    g.n = n;
    g.e = e;
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
            g.edges[i][j] = A[i][j]; 
    }
    return g;
}
void DisGraph(MatGraph g)
{
    for (int i = 0; i < g.n; i++)
    {
        for (int j = 0; j < g.n; j++)
        {
            if (g.edges[i][j]<INT_MAX)
                printf("%4d",g.edges[i][j]);
            else
                printf("%4s","∞");
        }
        printf("\n");
        
    }
    
}
//无向图求顶点度
int Degress1(MatGraph g,int v)
{
    int i, d = 0;
    if (v<0 || v>=g.n)
        return -1;
    for ( i = 0; i < g.n; i++)
    {
        if (g.edges[v][i]>0 && g.edges[v][i]<INT_MAX)
            d++;
    }
    return d;
    
}
//有向图求顶点度
int Degress2(MatGraph g,int v)
{
    int d1=0,d2=0,i,d;
    if (v<0 || v>=g.n)
        return -1;
    //求出度
    for ( i = 0; i < g.n; i++)
    {
        if (g.edges[v][i]>0 && g.edges[v][i]<INT_MAX)
            d1++;
    }
    //求入度
    for ( i = 0; i < g.n; i++)
    {
        if (g.edges[i][v]>0 && g.edges[i][v]<INT_MAX)
            d2++;
    }
    d = d1+d2;
    return d;
}
//深度优先遍历
void DFS(MatGraph g,int v)
{
    printf("%d ",v);
    visited[v] = 1;
    for (int i = 0; i < g.n; i++)
    {
        if (g.edges[v][i]!=0 && g.edges[v][i]!=INT_MAX && visited[i]==0)
            DFS(g,i);  
    }
    
}
//广度优先遍历
void BFS(MatGraph g,int v)
{
    int w,rear=0,front=0;
    int Qu[MAXVEX];
    for (int i = 0; i < g.n; i++)
        visited[i]=0;
    printf("%d ",v);
    visited[v]=1;
    Qu[rear]=v;
    rear = (rear+1)%MAXVEX;
    while (front != rear)
    {
        w = Qu[front];
        front = (front+1)%MAXVEX;
        for (int i = 0; i < g.n; i++)
        {
            if (g.edges[w][i]!=0 && g.edges[w][i]!=INT_MAX && visited[i]==0)
            {
                printf("%d ",i);
                visited[i] = 1;
                Qu[rear] = i;
                rear = (rear+1)%MAXVEX;
            }
            
        }
        
    }
    
    
}
//求最小生成树
void Prim(MatGraph g,int v)
{
    int lowcost[MAXVEX];
    int closest[MAXVEX];
    int min,i,j,k;
    for ( i = 0; i < g.n; i++)
    {
        lowcost[i]=g.edges[v][i];
        closest[i]=v;
    }
    for ( i = 1; i < g.n; i++)
    {
        min = INT_MAX;k=-1;
        for ( j = 0; j < g.n; j++)
        {
            if (lowcost[j]!=0 && lowcost[j]<min)
            {
                min = lowcost[j];
                k=j;
            }
            
        }
        printf(" 边(%d,%d),权值为%d\n",closest[k],k,min);
        lowcost[k]=0;
        for ( j = 0; j < g.n; j++)
        {
            if (lowcost[j]!=0 && g.edges[k][j]<lowcost[j])
            {
                lowcost[j]=g.edges[k][j];
                closest[j]=k;
            }
            
        }
        
        
    }
    
    
}