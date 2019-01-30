#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 100
//结点定义
typedef char VertexType;
typedef int EdgeType;
typedef struct EdgeNode
{   int adjvex;//邻接点域，存储该顶点对应的下标
    EdgeType weight;//用于存储权值，对于非网图可以不需要
    struct EdgeNode *next;//链域，指向下一个邻接点
}EdgeNode;
typedef struct VertexNode
{   VertexType data; //顶点域，存储顶点信息
    EdgeNode *firstedge; //边表头指针
}VertexNode,AdjList[MAXVEX];
typedef struct
{   AdjList adjList;
    int numVertexes,numEdges;//图中当前顶点数和边数
}GraphAdjList;
void CreateALGraph(GraphAdjList *G)
{   int i,j,k;
    EdgeNode *e;
    //输入顶点和边数
    printf("输入顶点数和边数：\n");
    scanf("%d,%d",&G->numVertexes,&G->numEdges);
    getchar();
    printf("输入顶点字符：\n");
    for(i=0;i<G->numVertexes;i++)
    {   scanf("%c",&G->adjList[i].data);
        G->adjList[i].firstedge=NULL;
    }
    for(k=0;k<G->numEdges;k++)
    {   printf("输入边（vi,vj）上的顶点序号：\n");
        scanf("%d,%d",&i,&j);
        e = (EdgeNode*)malloc(sizeof(EdgeNode));//向内存申请空间
        //生成边表结点
        e->adjvex=j;
        e->next=G->adjList[i].firstedge;
        G->adjList[i].firstedge=e;
        e = (EdgeNode*)malloc(sizeof(EdgeNode));//向内存申请空间
        e->adjvex=i;  //生成边表结点
        e->next=G->adjList[i].firstedge;
        G->adjList[i].firstedge=e;
    }}

int main(void)
{   GraphAdjList G;
    CreateALGraph(&G);
    return 0;
}
