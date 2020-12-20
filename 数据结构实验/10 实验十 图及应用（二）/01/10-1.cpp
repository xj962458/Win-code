#include"graph.cpp"
int main()
{
    MatGraph g;
    AdjGraph *G;
    int A[MAXV][MAXV] = {
        {0, 4, 6, 6, INF, INF, INF},
        {INF, 0, 1, INF, 7, INF, INF},
        {INF, INF, 0, INF, 6, 4, INF},
        {INF, INF, 2, 0, INF, 5, INF},
        {INF, INF, INF, INF, 0, INF, 6},
        {INF, INF, INF, INF, 1, 0, 8},
        {INF, INF, INF, INF, INF, INF, 0}

    };
    int n = 7, e = 12;
    CreateMat(g, A, n, e);
    printf("(1)ͼG���ڽӾ���:\n");
    DispMat(g);
    CreateAdj(G, A, n, e);
    printf("(2)ͼG���ڽӱ�:\n");
    DispAdj(G);
    printf("(3)����ͼG���ڽӱ�\n");
    DestroyAdj(G);
    return 0;
}
