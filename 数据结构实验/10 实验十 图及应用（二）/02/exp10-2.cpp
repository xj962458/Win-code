//�ļ���:exp8-2.cpp
#include"graph_search.cpp"
int main()
{
    AdjGraph *G;
    int A[MAXV][MAXV] = {
        {0, 4, 6, 6, INF, INF, INF},
        {INF, 0, 1, INF, 7, INF, INF},
        {INF, INF, 0, INF, 6, 4, INF},
        {INF, INF, 2, 0, INF, 5, INF},
        {INF, INF, INF, INF, 0, INF, 6},
        {INF, INF, INF, INF, 1, 0, 8},
        {INF, INF, INF, INF, INF, INF, 0}};
    int n = 7, e = 12; //ͼ8.1�е�����
    CreateAdj(G, A, n, e);
    printf("ͼG���ڽӱ�:\n");
    DispAdj(G);
    printf("�Ӷ���0��ʼ��DFS(�ݹ��㷨):\n");
    DFS(G, 0);
    printf("\n");
    printf("�Ӷ���0��ʼ��DFS(�ǵݹ��㷨):\n");
    DFS1(G, 0);
    printf("�Ӷ���0��ʼ��BFS:\n");
    BFS(G, 0);
    DestroyAdj(G);
    return 0;
}
