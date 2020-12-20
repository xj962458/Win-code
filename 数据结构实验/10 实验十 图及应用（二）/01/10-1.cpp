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
    printf("(1)图G的邻接矩阵:\n");
    DispMat(g);
    CreateAdj(G, A, n, e);
    printf("(2)图G的邻接表:\n");
    DispAdj(G);
    printf("(3)销毁图G的邻接表\n");
    DestroyAdj(G);
    return 0;
}
