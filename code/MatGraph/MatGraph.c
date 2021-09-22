#include "MatGraph.h"

int main(int argc, char const *argv[])
{
    MatGraph g;
    int n = 5,e = 7,i;
    int A[MAXVEX][MAXVEX]={
        {0,1,2,6,INT_MAX},
        {INT_MAX,0,INT_MAX,4,5},
        {INT_MAX,INT_MAX,0,INT_MAX,3},
        {INT_MAX,INT_MAX,INT_MAX,0,INT_MAX},
        {INT_MAX,INT_MAX,INT_MAX,7,0}
    };

    g = GreateGraph(g,A,n,e);
    printf("图G的存储结构:\n");
    DisGraph(g);
    printf("图G中所有顶点的度:\n");
    printf("  顶点\t度\n");
    for (int i = 0; i < n; i++)
    {
        if (Degress2(g,i)!=-1)
            printf("  %d\t%d\n",i,Degress2(g,i));
    }
    for (int i = 0; i < g.n; i++)
        visited[i]=0;
    printf("各种遍历序列:\n");
    printf("深度优先遍历DFS:");DFS(g,0);printf("\n");
    printf("广度优先遍历BFS:");BFS(g,0);printf("\n");
    printf("最小生成树:\n");
    Prim(g,0);
    return 0;
}
