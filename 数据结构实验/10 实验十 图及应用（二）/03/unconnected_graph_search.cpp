// �ļ�unconnected_graph_search.cpp
#include <stdio.h>
#include <malloc.h>
#define MAXV 100 //��󶥵����

typedef char InfoType;    //����ͼ�������������
int visited1[MAXV] = {0}; //ȫ������1,Ϊ������ȱ����㷨ʹ��
int visited2[MAXV] = {0}; //ȫ������2,Ϊ������ȱ����㷨ʹ��

//���¶����ڽӱ�����
typedef struct ANode
{
    int adjvex;            //�ñߵ��ڽӵ���
    struct ANode *nextarc; //ָ����һ���ߵ�ָ��
    int weight;            //�ñߵ������Ϣ����Ȩֵ�������ͱ�ʾ��
} ArcNode;                 //�߽ڵ�����

typedef struct Vnode
{
    InfoType info;     //����������Ϣ
    int count;         //��Ŷ������,����������������
    ArcNode *firstarc; //ָ���һ����
} VNode;               //�ڽӱ�ͷ�ڵ�����

typedef struct
{
    VNode adjlist[MAXV]; //�ڽӱ�ͷ�ڵ�����
    int n, e;            //ͼ�ж�����n�ͱ���e
} AdjGraph;              //������ͼ�ڽӱ�����

//����ͼ���ڽӱ�
void CreateAdj(AdjGraph *&G, int A[MAXV][MAXV], int n, int e)
{
    int i, j;
    ArcNode *p;
    G = (AdjGraph *)malloc(sizeof(AdjGraph));
    for (i = 0; i < n; i++) //���ڽӱ�������ͷ�ڵ��ָ�����ó�ֵ
        G->adjlist[i].firstarc = NULL;
    for (i = 0; i < n; i++) //����ڽӾ�����ÿ��Ԫ��
        for (j = n - 1; j >= 0; j--)
            if (A[i][j] != 0 && A[i][j] != 0) //����һ����
            {
                p = (ArcNode *)malloc(sizeof(ArcNode)); //����һ���ڵ�p
                p->adjvex = j;
                p->weight = A[i][j];
                p->nextarc = G->adjlist[i].firstarc; //����ͷ�巨����ڵ�p
                G->adjlist[i].firstarc = p;
            }
    G->n = n;
    G->e = n;
}

//����ڽӱ�G
void DispAdj(AdjGraph *G)
{
    ArcNode *p;
    for (int i = 0; i < G->n; i++)
    {
        p = G->adjlist[i].firstarc;
        printf("%3d: ", i);
        while (p != NULL)
        {
            printf("%3d[%d]��", p->adjvex, p->weight);
            p = p->nextarc;
        }
        printf("��\n");
    }
}

//����ͼ���ڽӱ�
void DestroyAdj(AdjGraph *&G)
{
    ArcNode *pre, *p;
    for (int i = 0; i < G->n; i++) //ɨ�����еĵ�����
    {
        pre = G->adjlist[i].firstarc; //pָ���i����������׽ڵ�
        if (pre != NULL)
        {
            p = pre->nextarc;
            while (p != NULL) //�ͷŵ�i������������б߽ڵ�
            {
                free(pre);
                pre = p;
                p = p->nextarc;
            }
            free(pre);
        }
    }
    free(G); //�ͷ�ͷ�ڵ�����
}

//�ݹ�������ȱ����㷨
void DFS(AdjGraph *G, int v)
{
    ArcNode *p;
    visited1[v] = 1;            //���ѷ��ʱ��
    printf("%3d", v);           //��������ʶ���ı��
    p = G->adjlist[v].firstarc; //pָ�򶥵�v�ĵ�һ�����Ļ�ͷ���
    while (p != NULL)
    {
        if (visited1[p->adjvex] == 0) //��p->adjvex����δ����,�ݹ������
            DFS(G, p->adjvex);
        p = p->nextarc; //pָ�򶥵�v����һ�����Ļ�ͷ���
    }
}

//������ȱ����㷨
void BFS(AdjGraph *G, int v)
{
    ArcNode *p;
    int queue[MAXV], front = 0, rear = 0; //���廷�ζ��в���ʼ��
    int visited[MAXV];                    //�����Ŷ���ķ��ʱ�־������
    int w, i;
    for (i = 0; i < G->n; i++)
        visited[i] = 0; //���ʱ�־�����ʼ��
    printf("%3d", v);   //��������ʶ���ı��
    visited[v] = 1;     //���ѷ��ʱ��
    rear = (rear + 1) % MAXV;
    queue[rear] = v;      //v����
    while (front != rear) //�����в���ʱѭ��
    {
        front = (front + 1) % MAXV;
        w = queue[front];           //���Ӳ�����w
        p = G->adjlist[w].firstarc; //�Ҷ���w�ĵ�һ�����ڵ�
        while (p != NULL)
        {
            if (visited[p->adjvex] == 0) //�����ڵ�δ������
            {
                printf("%3d", p->adjvex); //�������ڵ�
                visited[p->adjvex] = 1;   //�øö����ѱ����ʵı�־
                rear = (rear + 1) % MAXV; //�ö������
                queue[rear] = p->adjvex;
            }
            p = p->nextarc; //����һ�����ڵ�
        }
    }
    printf("\n");
}

// ������ȱ�������ͨ����ͼ�㷨
void DFS_NC(AdjGraph *G)
{
    int i;
    for (i = 0; i < G->n; i++) //��������δ���ʹ��Ķ���
        if (visited1[i] == 0)  //δ�����ʹ��Ķ��㣬�����DFS
            DFS(G, i);
}

// ������ȱ�������ͨ����ͼ�㷨
void BFS_NC(AdjGraph *G)
{
    int i;
    for (i = 0; i < G->n; i++) //��������δ���ʹ��Ķ���
        if (visited2[i] == 0)  //δ�����ʹ��Ķ��㣬�����BFS
            BFS(G, i);
}
