#include "unconnected_graph_search.cpp"
int main()
{
    AdjGraph *G;
    int A[][MAXV] =
        {{0, 0, 1, 0, 0, 1, 0},
         {0, 0, 0, 1, 1, 0, 0},
         {1, 0, 0, 0, 0, 0, 0},
         {0, 1, 0, 0, 0, 0, 0},
         {0, 1, 0, 0, 0, 0, 0},
         {1, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0}};
    int n = 7, e = 4;
    CreateAdj(G, A, n, e);
    printf("图G的邻接表:\n");
    DispAdj(G);
    printf("深度优先遍历序列为:\n");
    DFS_NC(G);
    printf("\n");
    printf("广度优先遍历序列为:\n");
    BFS_NC(G);
    DestroyAdj(G);
    return 0;
}