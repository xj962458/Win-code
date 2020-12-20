// 文件unconnected_graph_search.cpp
#include <stdio.h>
#include <malloc.h>
#define MAXV 100 //最大顶点个数

typedef char InfoType;    //定义图结点数据域类型
int visited1[MAXV] = {0}; //全局数组1,为深度优先遍历算法使用
int visited2[MAXV] = {0}; //全局数组2,为广度优先遍历算法使用

//以下定义邻接表类型
typedef struct ANode
{
    int adjvex;            //该边的邻接点编号
    struct ANode *nextarc; //指向下一条边的指针
    int weight;            //该边的相关信息，如权值（用整型表示）
} ArcNode;                 //边节点类型

typedef struct Vnode
{
    InfoType info;     //顶点其他信息
    int count;         //存放顶点入度,仅仅用于拓扑排序
    ArcNode *firstarc; //指向第一条边
} VNode;               //邻接表头节点类型

typedef struct
{
    VNode adjlist[MAXV]; //邻接表头节点数组
    int n, e;            //图中顶点数n和边数e
} AdjGraph;              //完整的图邻接表类型

//创建图的邻接表
void CreateAdj(AdjGraph *&G, int A[MAXV][MAXV], int n, int e)
{
    int i, j;
    ArcNode *p;
    G = (AdjGraph *)malloc(sizeof(AdjGraph));
    for (i = 0; i < n; i++) //给邻接表中所有头节点的指针域置初值
        G->adjlist[i].firstarc = NULL;
    for (i = 0; i < n; i++) //检查邻接矩阵中每个元素
        for (j = n - 1; j >= 0; j--)
            if (A[i][j] != 0 && A[i][j] != 0) //存在一条边
            {
                p = (ArcNode *)malloc(sizeof(ArcNode)); //创建一个节点p
                p->adjvex = j;
                p->weight = A[i][j];
                p->nextarc = G->adjlist[i].firstarc; //采用头插法插入节点p
                G->adjlist[i].firstarc = p;
            }
    G->n = n;
    G->e = n;
}

//输出邻接表G
void DispAdj(AdjGraph *G)
{
    ArcNode *p;
    for (int i = 0; i < G->n; i++)
    {
        p = G->adjlist[i].firstarc;
        printf("%3d: ", i);
        while (p != NULL)
        {
            printf("%3d[%d]→", p->adjvex, p->weight);
            p = p->nextarc;
        }
        printf("∧\n");
    }
}

//销毁图的邻接表
void DestroyAdj(AdjGraph *&G)
{
    ArcNode *pre, *p;
    for (int i = 0; i < G->n; i++) //扫描所有的单链表
    {
        pre = G->adjlist[i].firstarc; //p指向第i个单链表的首节点
        if (pre != NULL)
        {
            p = pre->nextarc;
            while (p != NULL) //释放第i个单链表的所有边节点
            {
                free(pre);
                pre = p;
                p = p->nextarc;
            }
            free(pre);
        }
    }
    free(G); //释放头节点数组
}

//递归深度优先遍历算法
void DFS(AdjGraph *G, int v)
{
    ArcNode *p;
    visited1[v] = 1;            //置已访问标记
    printf("%3d", v);           //输出被访问顶点的编号
    p = G->adjlist[v].firstarc; //p指向顶点v的第一条弧的弧头结点
    while (p != NULL)
    {
        if (visited1[p->adjvex] == 0) //若p->adjvex顶点未访问,递归访问它
            DFS(G, p->adjvex);
        p = p->nextarc; //p指向顶点v的下一条弧的弧头结点
    }
}

//广度优先遍历算法
void BFS(AdjGraph *G, int v)
{
    ArcNode *p;
    int queue[MAXV], front = 0, rear = 0; //定义环形队列并初始化
    int visited[MAXV];                    //定义存放顶点的访问标志的数组
    int w, i;
    for (i = 0; i < G->n; i++)
        visited[i] = 0; //访问标志数组初始化
    printf("%3d", v);   //输出被访问顶点的编号
    visited[v] = 1;     //置已访问标记
    rear = (rear + 1) % MAXV;
    queue[rear] = v;      //v进队
    while (front != rear) //若队列不空时循环
    {
        front = (front + 1) % MAXV;
        w = queue[front];           //出队并赋给w
        p = G->adjlist[w].firstarc; //找顶点w的第一个相邻点
        while (p != NULL)
        {
            if (visited[p->adjvex] == 0) //若相邻点未被访问
            {
                printf("%3d", p->adjvex); //访问相邻点
                visited[p->adjvex] = 1;   //置该顶点已被访问的标志
                rear = (rear + 1) % MAXV; //该顶点进队
                queue[rear] = p->adjvex;
            }
            p = p->nextarc; //找下一个相邻点
        }
    }
    printf("\n");
}

// 深度优先遍历非连通无向图算法
void DFS_NC(AdjGraph *G)
{
    int i;
    for (i = 0; i < G->n; i++) //遍历所有未访问过的顶点
        if (visited1[i] == 0)  //未被访问过的顶点，则调用DFS
            DFS(G, i);
}

// 广度优先遍历非连通无向图算法
void BFS_NC(AdjGraph *G)
{
    int i;
    for (i = 0; i < G->n; i++) //遍历所有未访问过的顶点
        if (visited2[i] == 0)  //未被访问过的顶点，则调用BFS
            BFS(G, i);
}
